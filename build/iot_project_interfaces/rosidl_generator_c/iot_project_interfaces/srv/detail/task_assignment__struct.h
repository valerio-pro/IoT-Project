// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from iot_project_interfaces:srv/TaskAssignment.idl
// generated code does not contain a copyright notice

#ifndef IOT_PROJECT_INTERFACES__SRV__DETAIL__TASK_ASSIGNMENT__STRUCT_H_
#define IOT_PROJECT_INTERFACES__SRV__DETAIL__TASK_ASSIGNMENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/TaskAssignment in the package iot_project_interfaces.
typedef struct iot_project_interfaces__srv__TaskAssignment_Request
{
  uint8_t structure_needs_at_least_one_member;
} iot_project_interfaces__srv__TaskAssignment_Request;

// Struct for a sequence of iot_project_interfaces__srv__TaskAssignment_Request.
typedef struct iot_project_interfaces__srv__TaskAssignment_Request__Sequence
{
  iot_project_interfaces__srv__TaskAssignment_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} iot_project_interfaces__srv__TaskAssignment_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'simulation_name'
#include "rosidl_runtime_c/string.h"
// Member 'target_positions'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'target_thresholds'
// Member 'last_visits'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'wind_vector'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in srv/TaskAssignment in the package iot_project_interfaces.
typedef struct iot_project_interfaces__srv__TaskAssignment_Response
{
  rosidl_runtime_c__String simulation_name;
  int64_t no_drones;
  geometry_msgs__msg__Point__Sequence target_positions;
  rosidl_runtime_c__double__Sequence target_thresholds;
  double aoi_weight;
  double violation_weight;
  double fairness_weight;
  int64_t simulation_time;
  geometry_msgs__msg__Vector3 wind_vector;
  rosidl_runtime_c__double__Sequence last_visits;
} iot_project_interfaces__srv__TaskAssignment_Response;

// Struct for a sequence of iot_project_interfaces__srv__TaskAssignment_Response.
typedef struct iot_project_interfaces__srv__TaskAssignment_Response__Sequence
{
  iot_project_interfaces__srv__TaskAssignment_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} iot_project_interfaces__srv__TaskAssignment_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // IOT_PROJECT_INTERFACES__SRV__DETAIL__TASK_ASSIGNMENT__STRUCT_H_
