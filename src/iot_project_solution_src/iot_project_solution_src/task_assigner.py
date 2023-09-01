import time
from threading import Thread

import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from rclpy.action import ActionClient

from rosgraph_msgs.msg import Clock
from iot_project_interfaces.msg import TargetsTimeLeft
from iot_project_interfaces.srv import TaskAssignment
from iot_project_solution_interfaces.action import PatrollingAction

from geometry_msgs.msg import Point
from nav_msgs.msg import Odometry

from math_utils import get_yaw
from .drones_utils import all_positions_initialized, clustering, tsp, trivial_case, rotate_tsp_path

Coordinates = tuple[float, float, float]

# TODO
# 1) Implementare distinzione tra caso fair e caso not-fair (la rotazione del tsp schedule va messa anche in submit_task)
# 2) Ottimizzare il movimento del drone e gestire il vento
# 3) Pulire tutto da codice e librerie inutili

class TaskAssigner(Node):

    def __init__(self):

        super().__init__('task_assigner')
            
        self.task = None
        self.no_drones: int = 0
        self.targets: list[Point] = []
        self.thresholds: list[float] = []

        self.action_servers: list = []
        self.current_tasks: list =  []
        self.idle: list[bool] = []
        self.wind: list[float] = []

        self.sim_time: int = 0 # contains simulation time in nanoseconds

        self.aoi_weight: float = 0.0
        self.fairness_weight: float = 0.0
        self.violation_weight: float = 0.0

        self.fairness_threshold: float = 0.5

        self.targets_time_left: list[float] = [] # index "i" contains the remaining time of the target with id equal to "i+1" (targets' ids start from 1 in their names of the simulation)
        self.initial_targets_time: dict[Coordinates, float] = {} # contains pairs target_in_tuple_form: elapsed_time_since_target_was_last_visited
        
        self.position: list[Point] = [] # index "i" contains the coordinates (a Point) of the drone with id "i"
        self.yaw: list = []
        self.odometry_topic: list = []

        self.drone_assignment: dict[int, list[Point]] = {} # contains pairs drone_id: list_of_assigned_targets

        # Contains pairs target_in_tuple_form: target_idx where target_idx is the index of the target in the list self.targets_time_left. The target is stored as a tuple (not Point).
        # Needed to obtain the index used to retrieve the time from "self.targets_time_left" when targets will be grouped in clusters and assigned 
        # to drones (order can't be efficiently deducted anymore from "self.targets").
        # E.g. self.targets_time_left[self.target_idx_assignment[target_in_tuple_form]]
        # Not pretty but useful
        self.target_idx_assignment: dict[Coordinates, int] = {}

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

        # Storing here useful information about targets
        self.target_idx_assignment = {(target.x, target.y, target.z): idx for idx, target in enumerate(self.targets)}
        self.initial_targets_time = {(target.x, target.y, target.z): threshold for target, threshold in zip(self.targets, self.thresholds)}

        self.current_tasks = [None]*task.no_drones
        self.idle = [True]*task.no_drones
        self.wind = [task.wind_vector.x, task.wind_vector.y, task.wind_vector.z]

        self.aoi_weight = task.aoi_weight
        self.fairness_weight = task.fairness_weight
        self.violation_weight = task.violation_weight

        self.position = [None]*task.no_drones
        self.yaw = [None]*task.no_drones

        # Wait for all starting positions to be initialized.
        # We need to wait here since both the trivial and non-trivial case exploit the 
        # drones' starting positions
        while not all_positions_initialized(position=self.position):
            pass

        # We are in the trivial case. Compute the assignment of targets here
        if task.no_drones >= len(self.targets):
            self.drone_assignment = trivial_case(position=self.position, targets=self.targets, no_drones=task.no_drones)
        # We are not in the trivial case
        else:
            self.drone_assignment = clustering(no_drones=task.no_drones, targets=self.targets, position=self.position, n_init=10)
            self.drone_assignment = tsp(drone_assignment=self.drone_assignment, no_drones=task.no_drones, position=self.position,
                                        mutation_prob=0.1, max_attempts=1, max_iters=50)
            
        #path = rotate_tsp_path(self.drone_assignment[0], self.initial_targets_time, self.targets_time_left, self.target_idx_assignment, self.violation_weight, self.fairness_weight)

        # Decide what to do with respect to the fairness required by the mission.
        # If the fairness weight is above the threshold then schedule all targets in the cluster.
        # Otherwise prune each path by removing targets that are far away from every other target in the cluster
        if self.fairness_weight >= self.fairness_threshold:
            pass
        else:
            pass
                
        # Initialize number of drones
        self.no_drones = task.no_drones


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
    #
    # Executed every time all targets in "targets_to_patrol" have been visited (i.e. task completed)
    def submit_task(self, drone_id: int, targets_to_patrol: list[Point] = []):

        self.get_logger().info("Submitting task for drone X3_%s" % drone_id)
    
        while not self.action_servers[drone_id].wait_for_server(timeout_sec = 1.0):
            return

        self.idle[drone_id] = False

        if not targets_to_patrol:
            targets_to_patrol = self.drone_assignment[drone_id]

        patrol_task =  PatrollingAction.Goal()
        patrol_task.targets = targets_to_patrol

        patrol_future = self.action_servers[drone_id].send_goal_async(patrol_task)

        # This is a new construct for you. Basically, callbacks have no way of receiving arguments except
        # for the future itself. We circumvent such problem by creating an inline lambda functon which stores
        # the additional arguments ad-hoc and then calls the actual callback function
        patrol_future.add_done_callback(lambda future, d = drone_id : self.patrol_submitted_callback(future, d))


    # Callback used to verify if the action has been accepted.
    # If it did, prepares a callback for when the action gets completed
    def patrol_submitted_callback(self, future, drone_id: int):

        goal_handle = future.result()
        
        if not goal_handle.accepted:
            self.get_logger().info("Task has been refused by the action server")
            return
        
        result_future = goal_handle.get_result_async()

        # Lambda function as a callback, check the function before if you don't know what you are looking at
        result_future.add_done_callback(lambda future, d = drone_id : self.patrol_completed_callback(future, d))


    # Callback used to update the idle state of the drone when the action ends
    def patrol_completed_callback(self, future, drone_id: int):
        self.get_logger().info("Patrolling action for drone X3_%s has been completed. Drone is going idle" % drone_id)
        self.idle[drone_id] = True


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
    # Index "i" of the list self.targets_time_left contains the remaining time (in seconds) of the target with id equal to "i".
    # When there is a violation the values in the list start going below 0
    def store_targets_time_left(self, msg: TargetsTimeLeft):
        self.targets_time_left = [float(t/(10**9)) for t in msg.times]


    # Callback used to store simulation time
    def store_sim_time_callback(self, msg: Clock):
        self.sim_time = msg.clock.sec * 10**9 + msg.clock.nanosec


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