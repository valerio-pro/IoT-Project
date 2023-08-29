import six
import sys
sys.modules['sklearn.externals.six'] = six
from sklearn.cluster import KMeans
from mlrose import TravellingSales, TSPOpt, genetic_alg

import numpy as np
from geometry_msgs.msg import Point
from math import inf, sqrt
from math_utils import point_distance, angle_between_points, move_vector

VIOLATION_SCORING_WEIGHT: float = 1.0
FAIRNESS_SCORING_WEIGHT: float = 0.5
C: float = 5.0

# Perform Clustering (K-means) on the given "targets" list. The number of clusters is equal to the number of drones (K = no_drones)
def clustering(no_drones: int, targets: list[Point], position: list[Point], n_init: int = 10) -> dict[int, list[Point]]:
    # "kmeans.labels_" contains the indexes of the cluster each sample/target belongs to
    # "kmeans.cluster_centers_" contains the coordinates of cluster centers
    centroids_targets_assignment: dict = {} # contains pairs cluster_centroid: list_of_targets_belonging_to_that_centroid
    kmeans = KMeans(init="random", n_clusters=no_drones, n_init=n_init)
    target_samples = np.array([[target.x, target.y, target.z] for target in targets])
    kmeans.fit(target_samples)
    centroid_idx: int = 0
    for centroid in kmeans.cluster_centers_:
        centroids_targets_assignment[tuple(centroid)] = [targets[label_idx] for label_idx, label in enumerate(kmeans.labels_) if label == centroid_idx]
        centroid_idx += 1
    return assign_drones_to_clusters(position=position, centroids_targets_assignment=centroids_targets_assignment, no_drones=no_drones)


# Solve TSP on each cluster
def tsp(drone_assignment: dict[int, list[Point]], no_drones: int, position: list[Point],
        mutation_prob: float = 0.1, max_attempts: int = 10, max_iters: int = 100) -> dict[int, list[Point]]:
    # "best_state" is the computed list of target indexes to be inspected
    for drone_id in range(no_drones):
        fitness_coords = TravellingSales(coords=[(drone_target.x, drone_target.y, drone_target.z) for drone_target in drone_assignment[drone_id]])
        problem_fit = TSPOpt(length=len(drone_assignment[drone_id]), fitness_fn=fitness_coords, maximize=False)
        best_state, _ = genetic_alg(problem_fit, mutation_prob=mutation_prob, max_attempts=max_attempts, max_iters=max_iters)
        old_assignment: list[Point] = drone_assignment[drone_id]
        drone_assignment[drone_id] = []
        for target in best_state:
            drone_assignment[drone_id].append(old_assignment[target])
        closest_target_idx, _ = compute_closest_target_to_drone(position[drone_id], drone_assignment[drone_id])
        drone_assignment[drone_id] = rotate(drone_assignment[drone_id], len(drone_assignment[drone_id])-closest_target_idx)
    return drone_assignment


# For each target it computes the closest drone to that target. Targets are considered in order.
# Executed when no_drones >= len(targets)
def trivial_case(position: list[Point], targets: list[Point], no_drones: int) -> dict[int, list[Point]]:
    available_drones: dict[int, Point] = {d: position[d] for d in range(no_drones)}
    drone_assignment: dict[int, list[Point]] = {}
    for target in targets:
        drone: int = compute_closest_drone_to_target(target, available_drones)
        available_drones.pop(drone) # removes occurrence of the given key/drone
        drone_assignment[drone] = [target]
    for remaining_drone in available_drones:
        drone_assignment[remaining_drone] = []
    return drone_assignment


# Used to compute the closest drone to each cluster center
def assign_drones_to_clusters(position: list, centroids_targets_assignment: dict, no_drones: int) -> dict[int, list[Point]]:
    available_drones: dict[int, Point] = {d: position[d] for d in range(no_drones)}
    drone_assignment: dict[int, list[Point]] = {}
    for centroid in centroids_targets_assignment: # the number of centroids is equal to the number of drones
        drone: int = compute_closest_drone_to_centroid(centroid, available_drones)
        available_drones.pop(drone) # removes occurrence of the given key/drone
        drone_assignment[drone] = centroids_targets_assignment[centroid]
    return drone_assignment


# Given a single target and a set of drones, computes and returns the closest drone to the given target.
# Used in the trivial_case function
def compute_closest_drone_to_target(target: Point, available_drones: dict[int, Point]) -> int:
    target_tuple: tuple[float, float, float] = (target.x, target.y, target.z)
    best_distance = inf
    best_drone = None
    for drone, drone_position in available_drones.items():
        drone_tuple: tuple[float, float, float] = (drone_position.x, drone_position.y, drone_position.z)
        curr_distance = point_distance(target_tuple, drone_tuple)
        if curr_distance < best_distance:
             best_distance = curr_distance
             best_drone = drone
    return best_drone


# Given a cluster centroid and a set of drones, computes and returns the closest drone to the given centroid.
# Used in the assign_drones_to_clusters function
def compute_closest_drone_to_centroid(centroid: tuple, available_drones: dict[int, Point]) -> int:
    best_distance = inf
    best_drone = None
    for drone, drone_position in available_drones.items():
        drone_tuple: tuple[float, float, float] = (drone_position.x, drone_position.y, drone_position.z)
        curr_distance = point_distance(centroid, drone_tuple)
        if curr_distance < best_distance:
             best_distance = curr_distance
             best_drone = drone
    return best_drone


# Given a set of targets and the position of a drone, computes and returns the closest target to the given drone position.
# Used in the tsp function
def compute_closest_target_to_drone(drone_position: Point, targets: list[Point]) -> tuple[int, Point]:
    best_distance = inf
    best_target = None
    best_idx = None
    drone_position_tuple: tuple[float, float, float] = (drone_position.x, drone_position.y, drone_position.z)
    for idx, target in enumerate(targets):
        target_tuple: tuple[float, float, float] = (target.x, target.y, target.z)
        curr_distance = point_distance(drone_position_tuple, target_tuple)
        if curr_distance < best_distance:
            best_distance = curr_distance
            best_target = target
            best_idx = idx
    return  best_idx, best_target
        

# Returns True if all drones' positions are initialized (not None)
def all_positions_initialized(position: list[Point]) -> bool:
    for pos in position:
        if not pos:
            return False
    return True


# Perform a "clockwise" rotation of the input list of "k" positions
def rotate(container: list, k: int) -> list:
    return container if 0 <= len(container) <= 1 else container[-k:] + container[:-k]


# Retrieve from here when each target was last visited by some drone (in seconds).
# It works as it is even in case of violations
def get_time_since_last_visit_to_target(initial_targets_time: dict[tuple[float, float, float], float], targets_time_left: list[float],
                                        target_idx_assignment: dict[tuple[float, float, float], int], target: Point) -> float:
    return round(initial_targets_time[(target.x, target.y, target.z)] - targets_time_left[target_idx_assignment[(target.x, target.y, target.z)]], 3)


# Computes an estimate of the time it takes a given drone to rotate and move towards a given target
def compute_drone_travel_estimate(drone_position: Point, drone_yaw: float, drone_angular_velocity: float, target: Point) -> float:
    
    drone_position_tuple: tuple[float, float, float] = (drone_position.x, drone_position.y, drone_position.z)
    target_tuple: tuple[float, float, float] = (target.x, target.y, target.z)

    target_angle: float = angle_between_points(drone_position_tuple, target_tuple)
    angle_to_rotate: float = target_angle - drone_yaw
    t_rotation: float = angle_to_rotate/drone_angular_velocity

    drone_linear_velocity_x, drone_linear_velocity_z = move_vector(drone_position_tuple, target_tuple)
    velocity_magnitude: float = sqrt(drone_linear_velocity_x**2 + drone_linear_velocity_z**2)
    if velocity_magnitude == 0.0:
            return 0.0
    
    t_flight: float = point_distance(drone_position_tuple, target_tuple)/velocity_magnitude
    return t_flight + t_rotation


# Computes the average distance between a given target and all the remaining set of targets inside a cluster
def compute_average_target_to_multitarget_distance(target: Point, all_targets: list[Point]) -> float:
    return 0.0 if not all_targets else sum([point_distance((target.x, target.y, target.z), (other_target.x, other_target.y, other_target.z)) for other_target in all_targets])/len(all_targets)


# Scoring function used to evaluate targets inside a cluster to perform a shift in the TSP schedule in order to meet 
# time and fairness constraints
def scoring_function(drone_position: Point, target: Point, all_targets_in_cluster: list[Point], drone_yaw: float, drone_angular_velocity: float,
                    initial_targets_time: dict[tuple[float, float, float], float], targets_time_left: list[float],
                    target_idx_assignment: dict[tuple[float, float, float], int]) -> float:

    drone_travel_estimate: float = compute_drone_travel_estimate(drone_position, drone_yaw, drone_angular_velocity, target)
    
    t_left: float = targets_time_left[target_idx_assignment[(target.x, target.y, target.z)]]
    t_last_visit: float = get_time_since_last_visit_to_target(initial_targets_time, targets_time_left, target_idx_assignment, target)
    average_target_to_multitarget_distance: float = compute_average_target_to_multitarget_distance(target=target, all_targets=all_targets_in_cluster)

    return VIOLATION_SCORING_WEIGHT * ((drone_travel_estimate + C)/(t_left + 0.1)) + FAIRNESS_SCORING_WEIGHT * (t_last_visit + average_target_to_multitarget_distance)