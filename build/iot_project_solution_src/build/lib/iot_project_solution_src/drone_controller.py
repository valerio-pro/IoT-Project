import time

import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from rclpy.action.server import ServerGoalHandle

from geometry_msgs.msg import Point, Vector3, Twist
from nav_msgs.msg import Odometry
from iot_project_solution_interfaces.action import PatrollingAction
from iot_project_interfaces.srv import TaskAssignment

from iot_project_solution_src.math_utils import *

Coordinates = tuple[float, float, float]

# This variable is used for the drone to stay away from the ground
# Now that our movement also makes the drone fly up if necessary, the
# fly_to_altitude function should only be used to compensate if the drone is
# too close to the ground.
# This movement is necessary because rotors behave differently when close
# to the ground, so it is wise to always lift the drone up a little bit
# before doing any further movement.
DRONE_MIN_ALTITUDE_TO_PERFORM_MOVEMENT: int = 1

FLY_UP_VELOCITY: float = 1.0
ANGULAR_VELOCITY: float = 1.0

class DroneController(Node):

    def __init__(self):

        super().__init__("drone_controller")

        self.position: Point = Point(x=0.0, y=0.0, z=0.0)
        self.yaw = 0
        self.wind: list[float] = [0.0, 0.0, 0.0]

        self.cmd_vel_topic = self.create_publisher(
            Twist,
            'cmd_vel',
            10
        )

        self.odometry_topic = self.create_subscription(
            Odometry,
            'odometry',
            self.store_position_callback,
            10
        )

        self.patrol_action = ActionServer(
            self,
            PatrollingAction,
            'patrol_targets',
            self.patrol_action_callback
        )

        self.task_announcer = self.create_client(
            TaskAssignment,
            '/task_assigner/get_task'
        )


    def store_position_callback(self, msg: Odometry):
        
        self.position = msg.pose.pose.position
        self.yaw = get_yaw(
            msg.pose.pose.orientation.x,
            msg.pose.pose.orientation.y,
            msg.pose.pose.orientation.z,
            msg.pose.pose.orientation.w
        )


    def patrol_action_callback(self, msg: ServerGoalHandle):

        command_goal: PatrollingAction.Goal = msg.request
        targets = command_goal.targets

        # move to altitude
        self.fly_to_altitude()
        
        count = 0
        for target in targets:

            count += 1

            # rotate to target
            self.rotate_to_target(target)
            # move to target
            self.move_to_target(target)
            # send feedback for the target reached
            self.report_target_reached(msg, count)

        msg.succeed()

        result = PatrollingAction.Result()
        result.success = "Patrolling completed!"

        #self.get_logger().info("Patrol task completed! Sending final result...")

        return result


    def fly_to_altitude(self, altitude: int = DRONE_MIN_ALTITUDE_TO_PERFORM_MOVEMENT):

        # Skip movement if desiderd altitude is already reached
        if (self.position.z >= altitude):
            return

        # Instantiate the move_up message
        move_up = Twist()
        move_up.linear = Vector3(x=0.0, y=0.0, z=FLY_UP_VELOCITY)
        move_up.angular = Vector3(x=0.0, y=0.0, z=0.0)

        self.cmd_vel_topic.publish(move_up)

        # Loop until for the drone reaches the desired altitude
        # Note that in order for the drone to be perfectly aligned with the
        # requested height (not required for the exercise), you should keep on
        # listening to the current position and reduce the linear speed when 
        # you get close to the desired altitude
        while (self.position.z < altitude):
            self.cmd_vel_topic.publish(move_up)
            time.sleep(0.1)

        # Stop movement after the altitue has been reached
        stop_mov = Twist()
        stop_mov.linear = Vector3(x=0.0, y=0.0, z=0.0)
        stop_mov.angular = Vector3(x=0.0, y=0.0, z=0.0)
        self.cmd_vel_topic.publish(stop_mov)


    # The "eps" error was changed from 0.1 to 0.3, in most cases there is no need to be so precise since
    # there are already slight adjustments in the angle during "move_to_target". Better to start
    # moving quickly towards the target than being so precise in adjusting the angle 
    def rotate_to_target(self, target: Point, eps: float = 0.3):

        target: Coordinates = (target.x, target.y, target.z)

        # We compute the angle between the current target position and the target
        # position here
        start_position: tuple[float, float] = (self.position.x, self.position.y)
        target_angle = angle_between_points(start_position, target)

        # If the angle_to_rotate is greater than pi or smaller than -pi than we have an optimization
        # on the direction of the rotation. The angle is mapped into [-pi/2, pi/2] so that the drone will
        # rotate in the right direction. Without this optimization the rotation
        # direction of the drone was not optimal in these cases
        angle_to_rotate = target_angle - self.yaw
        print(f'ANGLE TO ROTATE BEFORE: {angle_to_rotate}')
        if angle_to_rotate > math.pi or angle_to_rotate < -math.pi:
            angle_to_rotate = math.pi - math.asin(math.sin(target_angle - self.yaw))

        print(f'ANGLE TO ROTATE AFTER: {angle_to_rotate}')
        # OK FOR ANGLES > -pi and 0 < -pi < 0
        # We verify the optimal direction of the rotation here
        rotation_dir = -1
        if angle_to_rotate < 0:
            rotation_dir = 1
        
        # Prepare the cmd_vel message
        move_msg = Twist()
        move_msg.linear = Vector3(x=0.0, y=0.0, z=0.0)
        move_msg.angular = Vector3(x=0.0, y=0.0, z=ANGULAR_VELOCITY*rotation_dir) # rad/s


        # Publish the message until the correct rotation is reached (accounting for some eps error)
        # Note that here the eps also helps us stop the drone and not overshoot the target, as
        # the drone will keep moving for a while after it receives a stop message
        # Also note that rotating the drone too fast will make it loose altitude.
        # You can account for that by also giving some z linear speed to the rotation movement.
        while abs(angle_to_rotate) > eps:
            angle_to_rotate = target_angle - self.yaw
            self.cmd_vel_topic.publish(move_msg)
            # No sleep here. We don't want to miss the angle by sleeping too much. Even 0.1 seconds
            # could make us miss the given epsilon interval

        # When done, send a stop message to be sure that the drone doesn't
        # overshoot its target
        stop_msg = Twist()
        stop_msg.linear = Vector3(x=0.0, y=0.0, z=0.0)
        stop_msg.angular = Vector3(x=0.0, y=0.0, z=0.0)
        self.cmd_vel_topic.publish(stop_msg)


    # A target is considered visited in iot_project_manager/target_handler if the distance between the drone and the target is below 0.8
    def move_to_target(self, target: Point, eps: float = 0.5, angle_eps: float = 0.05):

        current_position: Coordinates = (self.position.x, self.position.y, self.position.z)
        objective_point: Coordinates = (target.x, target.y, target.z)

        while point_distance(current_position, objective_point) > eps:

            current_position = (self.position.x, self.position.y, self.position.z)
            direction_vector = move_vector(current_position, objective_point)

            mov = Twist()
            mov.linear = Vector3(x=direction_vector[0], y=0.0, z=direction_vector[1])
            mov.angular = Vector3(x=0.0, y=0.0, z=0.0)

            angle = angle_between_points(current_position, objective_point)
            current_angle = self.yaw

            if not (angle-angle_eps < current_angle < angle+angle_eps):
                angle_diff = (current_angle-angle)
                mov.angular = Vector3(x=0.0, y=0.0, z=math.sin(angle_diff))

            self.cmd_vel_topic.publish(mov)

        stop_msg = Twist()
        stop_msg.linear = Vector3(x=0.0, y=0.0, z=0.0)
        stop_msg.angular = Vector3(x=0.0, y=0.0, z=0.0)
        self.cmd_vel_topic.publish(stop_msg)


    def report_target_reached(self, goal_handle, target_count):
        feedback = PatrollingAction.Feedback()
        #self.get_logger().info("Target %d reached. Sending feedback." % target_count)
        feedback.progress = "Target %d reached" % target_count
        goal_handle.publish_feedback(feedback)


    # Function used to wait for the current task. After receiving the task, it submits
    # to all the drone topics
    def get_task_and_subscribe_to_drones(self):
        while not self.task_announcer.wait_for_service(timeout_sec = 1.0):
            time.sleep(0.5)
        assignment_future = self.task_announcer.call_async(TaskAssignment.Request())
        assignment_future.add_done_callback(self.initialize_wind)

    
    def initialize_wind(self, assignment_future):
        task: TaskAssignment.Response = assignment_future.result()
        self.wind = [task.wind_vector.x, task.wind_vector.y, task.wind_vector.z]


def main():

    rclpy.init()

    executor = MultiThreadedExecutor()
    drone_controller = DroneController()

    executor.add_node(drone_controller)
    drone_controller.get_task_and_subscribe_to_drones()
    executor.spin()

    executor.shutdown()
    drone_controller.destroy_node()

    rclpy.shutdown()