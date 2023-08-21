// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from iot_project_interfaces:srv/TaskAssignment.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "iot_project_interfaces/srv/detail/task_assignment__rosidl_typesupport_introspection_c.h"
#include "iot_project_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "iot_project_interfaces/srv/detail/task_assignment__functions.h"
#include "iot_project_interfaces/srv/detail/task_assignment__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void iot_project_interfaces__srv__TaskAssignment_Request__rosidl_typesupport_introspection_c__TaskAssignment_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  iot_project_interfaces__srv__TaskAssignment_Request__init(message_memory);
}

void iot_project_interfaces__srv__TaskAssignment_Request__rosidl_typesupport_introspection_c__TaskAssignment_Request_fini_function(void * message_memory)
{
  iot_project_interfaces__srv__TaskAssignment_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember iot_project_interfaces__srv__TaskAssignment_Request__rosidl_typesupport_introspection_c__TaskAssignment_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(iot_project_interfaces__srv__TaskAssignment_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers iot_project_interfaces__srv__TaskAssignment_Request__rosidl_typesupport_introspection_c__TaskAssignment_Request_message_members = {
  "iot_project_interfaces__srv",  // message namespace
  "TaskAssignment_Request",  // message name
  1,  // number of fields
  sizeof(iot_project_interfaces__srv__TaskAssignment_Request),
  iot_project_interfaces__srv__TaskAssignment_Request__rosidl_typesupport_introspection_c__TaskAssignment_Request_message_member_array,  // message members
  iot_project_interfaces__srv__TaskAssignment_Request__rosidl_typesupport_introspection_c__TaskAssignment_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  iot_project_interfaces__srv__TaskAssignment_Request__rosidl_typesupport_introspection_c__TaskAssignment_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t iot_project_interfaces__srv__TaskAssignment_Request__rosidl_typesupport_introspection_c__TaskAssignment_Request_message_type_support_handle = {
  0,
  &iot_project_interfaces__srv__TaskAssignment_Request__rosidl_typesupport_introspection_c__TaskAssignment_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_iot_project_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, iot_project_interfaces, srv, TaskAssignment_Request)() {
  if (!iot_project_interfaces__srv__TaskAssignment_Request__rosidl_typesupport_introspection_c__TaskAssignment_Request_message_type_support_handle.typesupport_identifier) {
    iot_project_interfaces__srv__TaskAssignment_Request__rosidl_typesupport_introspection_c__TaskAssignment_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &iot_project_interfaces__srv__TaskAssignment_Request__rosidl_typesupport_introspection_c__TaskAssignment_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "iot_project_interfaces/srv/detail/task_assignment__rosidl_typesupport_introspection_c.h"
// already included above
// #include "iot_project_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "iot_project_interfaces/srv/detail/task_assignment__functions.h"
// already included above
// #include "iot_project_interfaces/srv/detail/task_assignment__struct.h"


// Include directives for member types
// Member `simulation_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `target_positions`
#include "geometry_msgs/msg/point.h"
// Member `target_positions`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `target_thresholds`
// Member `last_visits`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `wind_vector`
#include "geometry_msgs/msg/vector3.h"
// Member `wind_vector`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__TaskAssignment_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  iot_project_interfaces__srv__TaskAssignment_Response__init(message_memory);
}

void iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__TaskAssignment_Response_fini_function(void * message_memory)
{
  iot_project_interfaces__srv__TaskAssignment_Response__fini(message_memory);
}

size_t iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__size_function__TaskAssignment_Response__target_positions(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__get_const_function__TaskAssignment_Response__target_positions(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__get_function__TaskAssignment_Response__target_positions(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__fetch_function__TaskAssignment_Response__target_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__get_const_function__TaskAssignment_Response__target_positions(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__assign_function__TaskAssignment_Response__target_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__get_function__TaskAssignment_Response__target_positions(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__resize_function__TaskAssignment_Response__target_positions(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__size_function__TaskAssignment_Response__target_thresholds(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__get_const_function__TaskAssignment_Response__target_thresholds(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__get_function__TaskAssignment_Response__target_thresholds(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__fetch_function__TaskAssignment_Response__target_thresholds(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__get_const_function__TaskAssignment_Response__target_thresholds(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__assign_function__TaskAssignment_Response__target_thresholds(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__get_function__TaskAssignment_Response__target_thresholds(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__resize_function__TaskAssignment_Response__target_thresholds(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__size_function__TaskAssignment_Response__last_visits(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__get_const_function__TaskAssignment_Response__last_visits(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__get_function__TaskAssignment_Response__last_visits(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__fetch_function__TaskAssignment_Response__last_visits(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__get_const_function__TaskAssignment_Response__last_visits(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__assign_function__TaskAssignment_Response__last_visits(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__get_function__TaskAssignment_Response__last_visits(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__resize_function__TaskAssignment_Response__last_visits(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__TaskAssignment_Response_message_member_array[10] = {
  {
    "simulation_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(iot_project_interfaces__srv__TaskAssignment_Response, simulation_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "no_drones",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(iot_project_interfaces__srv__TaskAssignment_Response, no_drones),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(iot_project_interfaces__srv__TaskAssignment_Response, target_positions),  // bytes offset in struct
    NULL,  // default value
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__size_function__TaskAssignment_Response__target_positions,  // size() function pointer
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__get_const_function__TaskAssignment_Response__target_positions,  // get_const(index) function pointer
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__get_function__TaskAssignment_Response__target_positions,  // get(index) function pointer
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__fetch_function__TaskAssignment_Response__target_positions,  // fetch(index, &value) function pointer
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__assign_function__TaskAssignment_Response__target_positions,  // assign(index, value) function pointer
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__resize_function__TaskAssignment_Response__target_positions  // resize(index) function pointer
  },
  {
    "target_thresholds",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(iot_project_interfaces__srv__TaskAssignment_Response, target_thresholds),  // bytes offset in struct
    NULL,  // default value
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__size_function__TaskAssignment_Response__target_thresholds,  // size() function pointer
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__get_const_function__TaskAssignment_Response__target_thresholds,  // get_const(index) function pointer
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__get_function__TaskAssignment_Response__target_thresholds,  // get(index) function pointer
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__fetch_function__TaskAssignment_Response__target_thresholds,  // fetch(index, &value) function pointer
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__assign_function__TaskAssignment_Response__target_thresholds,  // assign(index, value) function pointer
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__resize_function__TaskAssignment_Response__target_thresholds  // resize(index) function pointer
  },
  {
    "aoi_weight",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(iot_project_interfaces__srv__TaskAssignment_Response, aoi_weight),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "violation_weight",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(iot_project_interfaces__srv__TaskAssignment_Response, violation_weight),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "fairness_weight",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(iot_project_interfaces__srv__TaskAssignment_Response, fairness_weight),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "simulation_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(iot_project_interfaces__srv__TaskAssignment_Response, simulation_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "wind_vector",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(iot_project_interfaces__srv__TaskAssignment_Response, wind_vector),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "last_visits",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(iot_project_interfaces__srv__TaskAssignment_Response, last_visits),  // bytes offset in struct
    NULL,  // default value
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__size_function__TaskAssignment_Response__last_visits,  // size() function pointer
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__get_const_function__TaskAssignment_Response__last_visits,  // get_const(index) function pointer
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__get_function__TaskAssignment_Response__last_visits,  // get(index) function pointer
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__fetch_function__TaskAssignment_Response__last_visits,  // fetch(index, &value) function pointer
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__assign_function__TaskAssignment_Response__last_visits,  // assign(index, value) function pointer
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__resize_function__TaskAssignment_Response__last_visits  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__TaskAssignment_Response_message_members = {
  "iot_project_interfaces__srv",  // message namespace
  "TaskAssignment_Response",  // message name
  10,  // number of fields
  sizeof(iot_project_interfaces__srv__TaskAssignment_Response),
  iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__TaskAssignment_Response_message_member_array,  // message members
  iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__TaskAssignment_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__TaskAssignment_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__TaskAssignment_Response_message_type_support_handle = {
  0,
  &iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__TaskAssignment_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_iot_project_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, iot_project_interfaces, srv, TaskAssignment_Response)() {
  iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__TaskAssignment_Response_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__TaskAssignment_Response_message_member_array[8].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  if (!iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__TaskAssignment_Response_message_type_support_handle.typesupport_identifier) {
    iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__TaskAssignment_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &iot_project_interfaces__srv__TaskAssignment_Response__rosidl_typesupport_introspection_c__TaskAssignment_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "iot_project_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "iot_project_interfaces/srv/detail/task_assignment__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers iot_project_interfaces__srv__detail__task_assignment__rosidl_typesupport_introspection_c__TaskAssignment_service_members = {
  "iot_project_interfaces__srv",  // service namespace
  "TaskAssignment",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // iot_project_interfaces__srv__detail__task_assignment__rosidl_typesupport_introspection_c__TaskAssignment_Request_message_type_support_handle,
  NULL  // response message
  // iot_project_interfaces__srv__detail__task_assignment__rosidl_typesupport_introspection_c__TaskAssignment_Response_message_type_support_handle
};

static rosidl_service_type_support_t iot_project_interfaces__srv__detail__task_assignment__rosidl_typesupport_introspection_c__TaskAssignment_service_type_support_handle = {
  0,
  &iot_project_interfaces__srv__detail__task_assignment__rosidl_typesupport_introspection_c__TaskAssignment_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, iot_project_interfaces, srv, TaskAssignment_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, iot_project_interfaces, srv, TaskAssignment_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_iot_project_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, iot_project_interfaces, srv, TaskAssignment)() {
  if (!iot_project_interfaces__srv__detail__task_assignment__rosidl_typesupport_introspection_c__TaskAssignment_service_type_support_handle.typesupport_identifier) {
    iot_project_interfaces__srv__detail__task_assignment__rosidl_typesupport_introspection_c__TaskAssignment_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)iot_project_interfaces__srv__detail__task_assignment__rosidl_typesupport_introspection_c__TaskAssignment_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, iot_project_interfaces, srv, TaskAssignment_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, iot_project_interfaces, srv, TaskAssignment_Response)()->data;
  }

  return &iot_project_interfaces__srv__detail__task_assignment__rosidl_typesupport_introspection_c__TaskAssignment_service_type_support_handle;
}
