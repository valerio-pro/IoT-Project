import six
import sys
sys.modules['sklearn.externals.six'] = six
from sklearn.cluster import KMeans
from mlrose import TravellingSales, TSPOpt, genetic_alg

import numpy as np
from math import inf
from functools import reduce
from itertools import combinations

from geometry_msgs.msg import Point
from math_utils import point_distance

Coordinates = tuple[float, float, float]

H: int = 3

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
        mutation_prob: float = 0.2, max_attempts: int = 10, max_iters: int = 100) -> dict[int, list[Point]]:
    # "best_state" is the computed list of target indexes to be inspected
    for drone_id in range(no_drones):
        fitness_coords = TravellingSales(coords=[(drone_target.x, drone_target.y, drone_target.z) for drone_target in drone_assignment[drone_id]])
        problem_fit = TSPOpt(length=len(drone_assignment[drone_id]), fitness_fn=fitness_coords, maximize=False)
        best_state, _ = genetic_alg(problem=problem_fit, pop_size=100, mutation_prob=mutation_prob, max_attempts=max_attempts, max_iters=max_iters)
        old_assignment: list[Point] = drone_assignment[drone_id]
        drone_assignment[drone_id] = []
        for target in best_state:
            drone_assignment[drone_id].append(old_assignment[target])
        # Initially rotate the TSP path so that the first target is the closest one to the drone
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
def assign_drones_to_clusters(position: list[Point], centroids_targets_assignment: dict, no_drones: int) -> dict[int, list[Point]]:
    available_drones: dict[int, Point] = {drone_id: position[drone_id] for drone_id in range(no_drones)}
    drone_assignment: dict[int, list[Point]] = {}
    for centroid in centroids_targets_assignment: # the number of centroids is equal to the number of drones
        drone_id: int = compute_closest_drone_to_centroid(centroid, available_drones)
        available_drones.pop(drone_id) # removes occurrence of the given key/drone
        drone_assignment[drone_id] = centroids_targets_assignment[centroid]
    return drone_assignment


# Given a single target and a set of drones, computes and returns the closest drone to the given target.
# Used in the trivial_case function
def compute_closest_drone_to_target(target: Point, available_drones: dict[int, Point]) -> int:
    target_tuple: Coordinates = (target.x, target.y, target.z)
    best_distance = inf
    best_drone = None
    for drone, drone_position in available_drones.items():
        drone_tuple: Coordinates = (drone_position.x, drone_position.y, drone_position.z)
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
        drone_tuple: Coordinates = (drone_position.x, drone_position.y, drone_position.z)
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
    drone_position_tuple: Coordinates = (drone_position.x, drone_position.y, drone_position.z)
    for idx, target in enumerate(targets):
        target_tuple: Coordinates = (target.x, target.y, target.z)
        curr_distance = point_distance(drone_position_tuple, target_tuple)
        if curr_distance < best_distance:
            best_distance = curr_distance
            best_target = target
            best_idx = idx
    return  best_idx, best_target


# Perform a "clockwise" rotation of the input list of "k" positions
def rotate(container: list, k: int) -> list:
    return container if 0 <= len(container) <= 1 else container[-k:] + container[:-k]


# Retrieve from here when each target was last visited by some drone (in seconds).
# It works as it is even in case of violations
def get_time_since_last_visit_to_target(initial_targets_time: dict[Coordinates, float], targets_time_left: list[float],
                                        target_idx_assignment: dict[Coordinates, int], target: Point) -> float:
    return round(initial_targets_time[(target.x, target.y, target.z)] - targets_time_left[target_idx_assignment[(target.x, target.y, target.z)]], 3)


# Computes the average distance between a given target and all the remaining set of targets inside a cluster.
def compute_average_target_to_multitarget_distance(target: Point, all_targets: list[Point]) -> float:
    return 0.0 if len(all_targets) <= 1 else round(sum([point_distance((target.x, target.y, target.z), (other_target.x, other_target.y, other_target.z)) for other_target in all_targets])/(len(all_targets)-1), 3)


# Computes the average distance between pairs of targets
def compute_average_distance_between_targets(targets: list[Point]) -> float:
    targets_tuples: list[Coordinates] = [(target.x, target.y, target.z) for target in targets]
    distances: list[float] = [point_distance(p1, p2) for p1, p2 in combinations(targets_tuples, 2)]
    return 0.0 if not targets else round(sum(distances)/len(distances), 3)


# Scoring function used to evaluate targets inside a cluster to perform a shift in the TSP schedule in order to meet
# time and fairness constraints
def scoring_function(target: Point, all_targets: list[Point], initial_targets_time: dict[Coordinates, float], targets_time_left: list[float],
                    target_idx_assignment: dict[Coordinates, int], violation_weight: float, fairness_weight: float) -> float:
    t_left: float = targets_time_left[target_idx_assignment[(target.x, target.y, target.z)]]
    t_last_visit: float = get_time_since_last_visit_to_target(initial_targets_time, targets_time_left, target_idx_assignment, target)
    max_threshold: float = max(initial_targets_time.values())
    average_target_to_multitarget_distance: float = compute_average_target_to_multitarget_distance(target, all_targets)
    return round(violation_weight * ((H*max_threshold)/(t_left + 0.1)) + fairness_weight * (t_last_visit + average_target_to_multitarget_distance), 3)


# Checks mission requirements (i.e., fairness) and eventually prunes greedily one target from each cluster
def check_mission_requirements(drone_assignment: dict[int, list[Point]], fairness_weight: float, fairness_threshold: float) -> dict[int, list [Point]]:
    if fairness_weight < fairness_threshold:
        for drone_id, drone_targets in drone_assignment.items():
            if len(drone_targets) >= 3: # prune only if there are more than 3 targets in the cluster
                pruned_targets: list[Point] = prune_targets(targets=drone_targets)
                drone_assignment[drone_id] = pruned_targets
    return drone_assignment


# Given a set of targets, prunes one target that makes the average distance between targets worse w.r.t. a given threshold.
# Used when the mission requires a fairly low (or null) fairness
def prune_targets(targets: list[Point], threshold: float = 0.75) -> list[Point]:
    original_average_distance: float = compute_average_distance_between_targets(targets=targets)
    if original_average_distance <= 8.0: # requires targets to be a little bit spaced, no sense in pruning well grouped targets
        return targets
    distances: list[tuple[Point, float]] = []
    for idx, target in enumerate(targets):
        curr_targets: list[Point] = targets[:]
        curr_targets.pop(idx)
        new_average_distance: float = compute_average_distance_between_targets(targets=curr_targets)
        distances.append((target, new_average_distance))
    if distances:
        distances.sort(key=lambda x: x[1], reverse=False)
        if distances[0][1] < threshold * original_average_distance:
            targets.remove(distances[0][0])
    return targets


# Given a TSP tour/schedule, performs a 3-rotation (clockwise) of the schedule by evaluating each target with a scoring function.
# Triplets will be ordered in the new schedule starting with the triplet with highest score. The actual order of the near-optimal TSP schedule is
# of course still preserved (it is just shifted)
def rotate_tsp_tour(path_targets: list[Point], initial_targets_time: dict[Coordinates, float], targets_time_left: list[float],
                    target_idx_assignment: dict[Coordinates, int], violation_weight: float, fairness_weight: float) -> list[Point]:
    
    path_targets_tuple: list[Coordinates] = [(target.x, target.y, target.z) for target in path_targets]

    # Assign to each target a score using the scoring function
    target_score_assignment: dict[Coordinates, float] = {(target.x, target.y, target.z): scoring_function(target, path_targets, initial_targets_time,
                                                                                targets_time_left, target_idx_assignment, violation_weight, fairness_weight)
                                                                                for target in path_targets}

    # Compute the score for triplets of targets
    remainder: int = len(path_targets_tuple) % 3
    triplets_scores: dict[tuple[Coordinates, Coordinates, Coordinates], float] = {(path_targets_tuple[t], path_targets_tuple[t+1], path_targets_tuple[t+2]):
                                                                                    round((target_score_assignment[path_targets_tuple[t]]+target_score_assignment[path_targets_tuple[t+1]]+target_score_assignment[path_targets_tuple[t+2]])/3, 3)
                                                                                    for t in range(0, len(path_targets_tuple)-remainder, 3)}
    
    # Compute the score for the remaining targets
    if remainder != 0:
        remaining_targets: tuple = tuple(path_targets_tuple[len(path_targets_tuple)-remainder:])
        triplets_scores[remaining_targets] = round(sum([target_score_assignment[target] for target in remaining_targets])/remainder, 3)

    # Compute the highest scoring triplet and find the index of the first target in such triplet inside the initial TSP path
    highest_scoring_triplet: tuple[Coordinates, Coordinates, Coordinates] = reduce(lambda x,y: x if x[1] >= y[1] else y, triplets_scores.items())[0]
    idx_first_target_in_highest_scoring_triplet: int = path_targets_tuple.index(highest_scoring_triplet[0])

    # Rotate the initial TSP path so that the highest scoring triplet of targets is the one that will be visited first
    return rotate(path_targets, len(path_targets)-idx_first_target_in_highest_scoring_triplet)


# Given a complete schedule/tour for each drone, rotates it so that the 3 most critical targets are visited first.
# Not currently in use
def rotate_all_tsp_tours(drone_assignment: dict[int, list[Point]], initial_targets_time: dict[Coordinates, float], targets_time_left: list[float],
                        target_idx_assignment: dict[Coordinates, int], violation_weight: float, fairness_weight: float) -> dict[int, list [Point]]:
    for drone_id, drone_tour in drone_assignment.items():
        drone_assignment[drone_id] = rotate_tsp_tour(drone_tour, initial_targets_time, targets_time_left, target_idx_assignment, violation_weight, fairness_weight)
    return drone_assignment