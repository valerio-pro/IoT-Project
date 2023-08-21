// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from iot_project_interfaces:msg/TargetsTimeLeft.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "iot_project_interfaces/msg/detail/targets_time_left__rosidl_typesupport_introspection_c.h"
#include "iot_project_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "iot_project_interfaces/msg/detail/targets_time_left__functions.h"
#include "iot_project_interfaces/msg/detail/targets_time_left__struct.h"


// Include directives for member types
// Member `times`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__TargetsTimeLeft_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  iot_project_interfaces__msg__TargetsTimeLeft__init(message_memory);
}

void iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__TargetsTimeLeft_fini_function(void * message_memory)
{
  iot_project_interfaces__msg__TargetsTimeLeft__fini(message_memory);
}

size_t iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__size_function__TargetsTimeLeft__times(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__get_const_function__TargetsTimeLeft__times(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__get_function__TargetsTimeLeft__times(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__fetch_function__TargetsTimeLeft__times(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__get_const_function__TargetsTimeLeft__times(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__assign_function__TargetsTimeLeft__times(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__get_function__TargetsTimeLeft__times(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__resize_function__TargetsTimeLeft__times(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__TargetsTimeLeft_message_member_array[1] = {
  {
    "times",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(iot_project_interfaces__msg__TargetsTimeLeft, times),  // bytes offset in struct
    NULL,  // default value
    iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__size_function__TargetsTimeLeft__times,  // size() function pointer
    iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__get_const_function__TargetsTimeLeft__times,  // get_const(index) function pointer
    iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__get_function__TargetsTimeLeft__times,  // get(index) function pointer
    iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__fetch_function__TargetsTimeLeft__times,  // fetch(index, &value) function pointer
    iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__assign_function__TargetsTimeLeft__times,  // assign(index, value) function pointer
    iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__resize_function__TargetsTimeLeft__times  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__TargetsTimeLeft_message_members = {
  "iot_project_interfaces__msg",  // message namespace
  "TargetsTimeLeft",  // message name
  1,  // number of fields
  sizeof(iot_project_interfaces__msg__TargetsTimeLeft),
  iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__TargetsTimeLeft_message_member_array,  // message members
  iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__TargetsTimeLeft_init_function,  // function to initialize message memory (memory has to be allocated)
  iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__TargetsTimeLeft_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__TargetsTimeLeft_message_type_support_handle = {
  0,
  &iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__TargetsTimeLeft_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_iot_project_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, iot_project_interfaces, msg, TargetsTimeLeft)() {
  if (!iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__TargetsTimeLeft_message_type_support_handle.typesupport_identifier) {
    iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__TargetsTimeLeft_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &iot_project_interfaces__msg__TargetsTimeLeft__rosidl_typesupport_introspection_c__TargetsTimeLeft_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
