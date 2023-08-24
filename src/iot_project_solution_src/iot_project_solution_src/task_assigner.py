import time
import random

from threading import Thread

import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from rclpy.action import ActionClient

import six
import sys
sys.modules['sklearn.externals.six'] = six
from sklearn.cluster import KMeans
from mlrose import TravellingSales, TSPOpt, genetic_alg
import numpy as np

from rosgraph_msgs.msg import Clock
from iot_project_interfaces.msg import TargetsTimeLeft
from iot_project_interfaces.srv import TaskAssignment
from iot_project_solution_interfaces.action import PatrollingAction

from geometry_msgs.msg import Point
from nav_msgs.msg import Odometry
from math_utils import get_yaw, compute_closest_drone_to_target, compute_closest_drone_to_centroid, compute_closest_target_to_drone, rotate


class TaskAssigner(Node):

    def __init__(self):

        super().__init__('task_assigner')
            
        self.task = None
        self.no_drones: int = 0
        self.targets: list[Point] = []
        self.thresholds: list = []

        self.action_servers: list = []
        self.current_tasks: list =  []
        self.idle: list[bool] = []

        self.sim_time = 0
        self.targets_time_left: list[float] = []

        self.position: list[Point] = [] # index "i" contains the coordinates (a Point) of the drone with id "i"
        self.yaw: list = []
        self.odometry_topic: list = []

        self.drone_assignment: dict[int, list[Point]] = {} # contains pairs drone_id: list_of_assigned_targets
        self.centroids_targets_assignment: dict = {} # contains pairs cluster_centroid: list_of_targets_belonging_to_that_centroid

        self.task_announcer = self.create_client(
            TaskAssignment,
            '/task_assigner/get_task'
        )

        self.sim_time_topic = self.create_subscription(
            Clock,
            '/world/iot_project_world/clock',
            self.store_sim_time_callback,
            10
        )

        self.targets_time_left_topic = self.create_subscription(
            TargetsTimeLeft,
            '/task_assigner/targets_time_left',
            self.store_targets_time_left,
            10
        )


    # Function used to wait for the current task. After receiving the task, it submits
    # to all the drone topics
    def get_task_and_subscribe_to_drones(self):

        self.get_logger().info("Task assigner has started. Waiting for task info")

        while not self.task_announcer.wait_for_service(timeout_sec = 1.0):
            time.sleep(0.5)

        self.get_logger().info("Task assigner is online. Requesting patrolling task")

        assignment_future = self.task_announcer.call_async(TaskAssignment.Request())
        assignment_future.add_done_callback(self.first_assignment_callback)


    # Callback used for when the patrolling task has been assigned for the first time.
    # It configures the task_assigner by saving some useful values from the response
    # (more are available for you to read and configure your algorithm, just check
    # the TaskAssignment.srv interface).
    # The full response is saved in self.task, so you can always use that to check
    # values you may have missed. Or just save them here by editing this function.
    # Once that is done, it creates a client for the action servers of all the drones
    def first_assignment_callback(self, assignment_future):

        task: TaskAssignment.Response = assignment_future.result()

        # Subscribe Task Assigner to the Odometry topic of each drone 
        for d in range(task.no_drones):
            self.odometry_topic.append(
                self.create_subscription(
                    Odometry,
                    'X3_%d/odometry' % d,
                    self.store_position_callback,
                    10
                )
            )

        # Now create a client for the action server of each drone
        for d in range(task.no_drones):
            self.action_servers.append(
                ActionClient(
                    self,
                    PatrollingAction,
                    'X3_%d/patrol_targets' % d,
                )
            )

        self.task = task
        self.targets = task.target_positions
        self.thresholds = task.target_thresholds

        self.current_tasks = [None]*task.no_drones
        self.idle = [True]*task.no_drones

        self.position = [None]*task.no_drones
        self.yaw = [None]*task.no_drones

        # Wait for all starting positions to be initialized.
        # We need to wait here since both the trivial and non-trivial case exploit the 
        # drones' starting positions
        while not self.all_positions_initialized():
            pass

        # We are in the trivial case. Compute the assignment of targets here
        if task.no_drones >= len(self.targets):
            self.drone_assignment = self.trivial_case(task.no_drones)
        # We are not in the trivial case
        else:

            # "kmeans.labels_" contains the indexes of the cluster each sample/target belongs to
            # "kmeans.cluster_centers_" contains the coordinates of cluster centers
            kmeans = KMeans(init="random", n_clusters=task.no_drones, n_init=10)
            target_samples = np.array([[target.x, target.y, target.z] for target in self.targets])
            kmeans.fit(target_samples)
            centroid_idx: int = 0
            for centroid in kmeans.cluster_centers_:
                self.centroids_targets_assignment[tuple(centroid)] = [self.targets[label_idx] for label_idx, label in enumerate(kmeans.labels_) if label == centroid_idx]
                centroid_idx += 1
            self.drone_assignment = self.assign_drones_to_clusters(task.no_drones)

            # Solve TSP on each cluster
            # # "best_state" is the computed list of target indexes to be inspected
            for drone_id in range(task.no_drones):
                fitness_coords = TravellingSales(coords=[(drone_target.x, drone_target.y, drone_target.z) for drone_target in self.drone_assignment[drone_id]])
                problem_fit = TSPOpt(length=len(self.drone_assignment[drone_id]), fitness_fn=fitness_coords, maximize=False)
                best_state, _ = genetic_alg(problem_fit, mutation_prob=0.1, max_attempts=10, max_iters=100)
                old_assignment: list[Point] = self.drone_assignment[drone_id]
                self.drone_assignment[drone_id] = []
                for target in best_state:
                    self.drone_assignment[drone_id].append(old_assignment[target])
                closest_target_idx, _ = compute_closest_target_to_drone(self.position[drone_id], self.drone_assignment[drone_id])
                self.drone_assignment[drone_id] = rotate(self.drone_assignment[drone_id], len(self.drone_assignment[drone_id])-closest_target_idx)
                
        # Initialize number of drones
        self.no_drones = task.no_drones


    # Listen for drones positions
    def store_position_callback(self, msg: Odometry):
        drone_id: int = int(str(str(msg.header.frame_id.split(' ')[2]).split('/')[0]))
        self.position[drone_id] = msg.pose.pose.position
        self.yaw[drone_id] = get_yaw(
            msg.pose.pose.orientation.x,
            msg.pose.pose.orientation.y,
            msg.pose.pose.orientation.z,
            msg.pose.pose.orientation.w
        )

    # Listen for targets' remaining time until expiration.
    # Time is stored in seconds inside self.targets_time_left.
    # Index "i" of the list self.targets_time_left contains the remaining time of the target with id equal to "i"
    def store_targets_time_left(self, msg: TargetsTimeLeft):
        self.targets_time_left = [float(t/(10**9)) for t in msg.times]


    # This method starts on a separate thread an ever-going patrolling task, it does that
    # by checking the idle state value of every drone and submitting a new goal as soon as
    # that value goes back to True
    def keep_patrolling(self):

        def keep_patrolling_inner():
            while True:
                for d in range(self.no_drones):
                    if self.idle[d]:
                        Thread(target=self.submit_task, args=(d,)).start()
                time.sleep(0.1)

        Thread(target=keep_patrolling_inner).start()

    
    # Submits a patrol task to a single drone. Basic implementation just takes the array
    # of targets and shuffles it. Is up to you to improve this part and come up with your own
    # algorithm.
    # 
    # TIP: It is highly suggested to start working on a better scheduling of the targets from here.
    #      some drones may want to inspect only a portion of the nodes, other maybe more.
    #
    #      You may also implement a reactive solution which checks for the target violation
    #      continuously and schedules precise tasks at each step. For that, you can call again
    #      the task_announcer service to get an updated view of the targets' state; the last
    #      visit of each target can be read from the array last_visits in the service message.
    #      The simulation time is already stored in self.sim_time for you to use in case
    #      Times are all in nanoseconds.
    def submit_task(self, drone_id: int, targets_to_patrol: list[Point] = []):

        self.get_logger().info("Submitting task for drone X3_%s" % drone_id)
    
        while not self.action_servers[drone_id].wait_for_server(timeout_sec = 1.0):
            return

        self.idle[drone_id] = False

        # MIGHT REMOVE DISTINCTIONS BETWEEN TRIVIAL AND NON-TRIVIAL. ALREADY DISTINGUISHING CASES IN first_assignment_callback
        if not targets_to_patrol:
            # We are in the trivial case.
            if self.no_drones >= len(self.targets):
                targets_to_patrol = self.drone_assignment[drone_id]
            # We are not in the trivial case
            else:
                #targets_to_patrol = self.targets.copy()
                targets_to_patrol = self.drone_assignment[drone_id]
                #random.shuffle(targets_to_patrol)

        patrol_task =  PatrollingAction.Goal()
        patrol_task.targets = targets_to_patrol

        patrol_future = self.action_servers[drone_id].send_goal_async(patrol_task)

        # This is a new construct for you. Basically, callbacks have no way of receiving arguments except
        # for the future itself. We circumvent such problem by creating an inline lambda functon which stores
        # the additional arguments ad-hoc and then calls the actual callback function
        patrol_future.add_done_callback(lambda future, d = drone_id : self.patrol_submitted_callback(future, d))


    # Callback used to verify if the action has been accepted.
    # If it did, prepares a callback for when the action gets completed
    def patrol_submitted_callback(self, future, drone_id):

        goal_handle = future.result()
        
        if not goal_handle.accepted:
            self.get_logger().info("Task has been refused by the action server")
            return
        
        result_future = goal_handle.get_result_async()

        # Lambda function as a callback, check the function before if you don't know what you are looking at
        result_future.add_done_callback(lambda future, d = drone_id : self.patrol_completed_callback(future, d))


    # Callback used to update the idle state of the drone when the action ends
    def patrol_completed_callback(self, future, drone_id):
        self.get_logger().info("Patrolling action for drone X3_%s has been completed. Drone is going idle" % drone_id)
        self.idle[drone_id] = True


    # Callback used to store simulation time
    def store_sim_time_callback(self, msg):
        self.clock = msg.clock.sec * 10**9 + msg.clock.nanosec


    # Executed when self.no_drones >= len(self.targets)
    # For each target it computes the closest drone to that target. Targets are considered in order
    def trivial_case(self, no_drones: int) -> dict[int, list[Point]]:
        available_drones: dict[int, Point] = {d: self.position[d] for d in range(no_drones)}
        drone_assignment: dict[int, list[Point]] = {}
        for target in self.targets:
            drone: int = compute_closest_drone_to_target(target, available_drones)
            available_drones.pop(drone) # removes occurrence of the given key/drone
            drone_assignment[drone] = [target]
        for remaining_drone in available_drones:
            drone_assignment[remaining_drone] = []
        return drone_assignment


    # Executed when self.no_drones >= len(self.targets)
    def trivial_case_2(self, no_drones: int) -> dict[int, list[Point]]:
        drone_assignment: dict[int, list[Point]] = {}
        curr_drone_id: int = 0
        for target in self.targets:
            drone_assignment[curr_drone_id] = [target]
            curr_drone_id += 1
        for _ in range(no_drones-len(self.targets)):
            drone_assignment[curr_drone_id] = []
            curr_drone_id += 1
        return drone_assignment
    

    # Used to compute the closest drone to each cluster center
    def assign_drones_to_clusters(self, no_drones: int) -> dict[int, list[Point]]:
        available_drones: dict[int, Point] = {d: self.position[d] for d in range(no_drones)}
        drone_assignment: dict[int, list[Point]] = {}
        for centroid in self.centroids_targets_assignment: # the number of centroids is equal to the number of drones
            drone: int = compute_closest_drone_to_centroid(centroid, available_drones)
            available_drones.pop(drone) # removes occurrence of the given key/drone
            drone_assignment[drone] = self.centroids_targets_assignment[centroid]
        return drone_assignment
            

    def all_positions_initialized(self) -> bool:
        for pos in self.position:
            if not pos:
                return False
        return True
        

def main():

    time.sleep(3.0)
    rclpy.init()

    task_assigner = TaskAssigner()
    executor = MultiThreadedExecutor()
    executor.add_node(task_assigner)

    task_assigner.get_task_and_subscribe_to_drones()
    task_assigner.keep_patrolling()

    executor.spin()

    executor.shutdown()
    task_assigner.destroy_node()

    rclpy.shutdown()