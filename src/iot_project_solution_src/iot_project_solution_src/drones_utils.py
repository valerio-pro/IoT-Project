import six
import sys
sys.modules['sklearn.externals.six'] = six
from sklearn.cluster import KMeans
from mlrose import TravellingSales, TSPOpt, genetic_alg

import numpy as np
from geometry_msgs.msg import Point
from math import inf
from math_utils import point_distance

# Perform Clustering on the given "targets" list. The number of clusters is equal to the number of drones
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
def tsp(drone_assignment: dict[int, list[Point]], no_drones: int, position: list[Point]) -> dict[int, list[Point]]:
    # "best_state" is the computed list of target indexes to be inspected
    for drone_id in range(no_drones):
        fitness_coords = TravellingSales(coords=[(drone_target.x, drone_target.y, drone_target.z) for drone_target in drone_assignment[drone_id]])
        problem_fit = TSPOpt(length=len(drone_assignment[drone_id]), fitness_fn=fitness_coords, maximize=False)
        best_state, _ = genetic_alg(problem_fit, mutation_prob=0.1, max_attempts=10, max_iters=100)
        old_assignment: list[Point] = drone_assignment[drone_id]
        drone_assignment[drone_id] = []
        for target in best_state:
            drone_assignment[drone_id].append(old_assignment[target])
        closest_target_idx, _ = compute_closest_target_to_drone(position[drone_id], drone_assignment[drone_id])
        drone_assignment[drone_id] = rotate(drone_assignment[drone_id], len(drone_assignment[drone_id])-closest_target_idx)
    return drone_assignment


# Executed when no_drones >= len(targets)
# For each target it computes the closest drone to that target. Targets are considered in order
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


# Used for trivial_case method
def compute_closest_drone_to_target(target: Point, available_drones: dict[int, Point]) -> int:
    target_tuple: tuple = (target.x, target.y, target.z)
    best_distance = inf
    best_drone = None
    for drone, drone_position in available_drones.items():
        drone_tuple: tuple = (drone_position.x, drone_position.y, drone_position.z)
        curr_distance = point_distance(target_tuple, drone_tuple)
        if curr_distance < best_distance:
             best_distance = curr_distance
             best_drone = drone
    return best_drone


def compute_closest_drone_to_centroid(centroid: tuple, available_drones: dict[int, Point]) -> int:
    best_distance = inf
    best_drone = None
    for drone, drone_position in available_drones.items():
        drone_tuple: tuple = (drone_position.x, drone_position.y, drone_position.z)
        curr_distance = point_distance(centroid, drone_tuple)
        if curr_distance < best_distance:
             best_distance = curr_distance
             best_drone = drone
    return best_drone


def compute_closest_target_to_drone(drone_position: Point, targets: list[Point]) -> tuple:
    best_distance = inf
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
        

def all_positions_initialized(position: list[Point]) -> bool:
    for pos in position:
        if not pos:
            return False
    return True


# Perform a "clockwise" rotation of the input list of "k" positions
def rotate(container: list, k: int) -> list:
    return container if 0 <= len(container) <= 1 else container[-k:] + container[:-k]