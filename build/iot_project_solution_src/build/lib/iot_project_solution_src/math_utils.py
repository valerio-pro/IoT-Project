import math
from geometry_msgs.msg import Point

# Used for trivial_case method
def compute_closest_drone_to_target(target: Point, available_drones: dict[int, Point]) -> int:
    target_tuple: tuple = (target.x, target.y, target.z)
    best_distance = math.inf
    best_drone = None
    for drone, drone_position in available_drones.items():
        drone_tuple: tuple = (drone_position.x, drone_position.y, drone_position.z)
        curr_distance = point_distance(target_tuple, drone_tuple)
        if curr_distance < best_distance:
             best_distance = curr_distance
             best_drone = drone
    return best_drone


def compute_closest_drone_to_centroid(centroid: tuple, available_drones: dict[int, Point]) -> int:
    best_distance = math.inf
    best_drone = None
    for drone, drone_position in available_drones.items():
        drone_tuple: tuple = (drone_position.x, drone_position.y, drone_position.z)
        curr_distance = point_distance(centroid, drone_tuple)
        if curr_distance < best_distance:
             best_distance = curr_distance
             best_drone = drone
    return best_drone


def compute_closest_target_to_drone(drone_position: Point, targets: list[Point]) -> tuple:
    best_distance = math.inf
    best_target = None
    best_idx = None
    drone_position_tuple: tuple = (drone_position.x, drone_position.y, drone_position.z)
    for idx, target in enumerate(targets):
        target_tuple: tuple = (target.x, target.y, target.z)
        curr_distance = point_distance(drone_position_tuple, target_tuple)
        if curr_distance < best_distance:
            best_distance = curr_distance
            best_target = target
            best_idx = idx
    return  best_idx, best_target

 
# Perform a "clockwise" rotation of the input list of "k" positions
def rotate(container: list, k: int) -> list:
    return container if 0 <= len(container) <= 1 else container[-k:] + container[:-k]


def unit_vector_between_points(p0: tuple, p1: tuple):

    '''
    Computes the unit vector between the two given points.
    Direction of the vector is from p0 to p1.
    p0: the coordinates of the first point (x0, y0, z0)
    p1: the coordinates of the second point (x1, y1, z0)
    '''

    vb = (p1[0] - p0[0], p1[1] - p0[1], p1[2] - p0[2])
    norm = math.sqrt(vb[0]**2 + vb[1]**2 + vb[2]**2)

    return (vb[0] / norm, vb[1] / norm, vb[2] / norm)


def move_vector(p0: tuple, p1: tuple):

	'''
    Computes the unit vector between the two given points on a 2d plane.
    The vector is calculated on a 2d plane perpendicular to the ground_plane
    and passing between p0 and p1.
    The x and y components are merged into a single, forward, component.
    Direction of the vector is from p0 to p1.
    p0: the coordinates of the first point (x0, y0, z0)
    p1: the coordinates of the second point (x1, y1, z1)
    '''
	vb = (math.sqrt( (p1[0] - p0[0])**2 + (p1[1] - p0[1])**2), p1[2] - p0[2])
	norm = math.sqrt(vb[0]**2 + vb[1]**2)

	return (vb[0] / norm, vb[1] / norm)


def angle_between_points(p0: tuple, p1: tuple):

    '''
    Computes the angle between the two given points, in radiants.
    p0: the coordinates of the first point (x0, y0, z0)
    p1: the coordinates of the second point (x1, y1, z0)
    '''

    vb = (p1[0] - p0[0], p1[1] - p0[1])
    norm = math.sqrt(vb[0]**2 + vb[1]**2)
    direction = (vb[0] / norm, vb[1] / norm)

    return math.atan2(direction[0], direction[1])


def point_distance(p0: tuple, p1: tuple):

    '''
    Computes the distance between the two given points.
    p0: the coordinates of the first point (x0, y0)
    p1: the coordinates of the second point (x1, y1)
    '''

    vb = (p1[0] - p0[0], p1[1] - p0[1], p1[2] - p0[2])
    return math.sqrt(vb[0]**2 + vb[1]**2 + vb[2]**2)


def euler_from_quaternion(x, y, z, w):

    """
    Convert a quaternion into euler angles (roll, pitch, yaw)
    roll is rotation around x in radians (counterclockwise)
    pitch is rotation around y in radians (counterclockwise)
    yaw is rotation around z in radians (counterclockwise)
    """

    t0 = +2.0 * (w * x + y * z)
    t1 = +1.0 - 2.0 * (x * x + y * y)
    roll_x = math.atan2(t0, t1)

    t2 = +2.0 * (w * y - z * x)
    t2 = +1.0 if t2 > +1.0 else t2
    t2 = -1.0 if t2 < -1.0 else t2
    pitch_y = math.asin(t2)

    t3 = +1.0 - 2.0 * (y * y + z * z)
    t4 = +2.0 * (w * z + x * y)
    yaw_z = math.atan2(t3, t4)

    return roll_x, pitch_y, yaw_z # in radians


def get_yaw(x, y, z, w):

    '''
    Transform the given quaternion orientation to angles
    and simply returns the yaw angle.
    orientation: orientation of the quaternion (assumed to have four values x,y,z,w)
    '''

    return euler_from_quaternion(x,y,z,w)[2]