// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from iot_project_interfaces:msg/TargetsTimeLeft.idl
// generated code does not contain a copyright notice

#ifndef IOT_PROJECT_INTERFACES__MSG__DETAIL__TARGETS_TIME_LEFT__STRUCT_H_
#define IOT_PROJECT_INTERFACES__MSG__DETAIL__TARGETS_TIME_LEFT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'times'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/TargetsTimeLeft in the package iot_project_interfaces.
typedef struct iot_project_interfaces__msg__TargetsTimeLeft
{
  rosidl_runtime_c__double__Sequence times;
} iot_project_interfaces__msg__TargetsTimeLeft;

// Struct for a sequence of iot_project_interfaces__msg__TargetsTimeLeft.
typedef struct iot_project_interfaces__msg__TargetsTimeLeft__Sequence
{
  iot_project_interfaces__msg__TargetsTimeLeft * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} iot_project_interfaces__msg__TargetsTimeLeft__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // IOT_PROJECT_INTERFACES__MSG__DETAIL__TARGETS_TIME_LEFT__STRUCT_H_
