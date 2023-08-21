// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from iot_project_interfaces:srv/TaskAssignment.idl
// generated code does not contain a copyright notice
#include "iot_project_interfaces/srv/detail/task_assignment__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
iot_project_interfaces__srv__TaskAssignment_Request__init(iot_project_interfaces__srv__TaskAssignment_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
iot_project_interfaces__srv__TaskAssignment_Request__fini(iot_project_interfaces__srv__TaskAssignment_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
iot_project_interfaces__srv__TaskAssignment_Request__are_equal(const iot_project_interfaces__srv__TaskAssignment_Request * lhs, const iot_project_interfaces__srv__TaskAssignment_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
iot_project_interfaces__srv__TaskAssignment_Request__copy(
  const iot_project_interfaces__srv__TaskAssignment_Request * input,
  iot_project_interfaces__srv__TaskAssignment_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

iot_project_interfaces__srv__TaskAssignment_Request *
iot_project_interfaces__srv__TaskAssignment_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  iot_project_interfaces__srv__TaskAssignment_Request * msg = (iot_project_interfaces__srv__TaskAssignment_Request *)allocator.allocate(sizeof(iot_project_interfaces__srv__TaskAssignment_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(iot_project_interfaces__srv__TaskAssignment_Request));
  bool success = iot_project_interfaces__srv__TaskAssignment_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
iot_project_interfaces__srv__TaskAssignment_Request__destroy(iot_project_interfaces__srv__TaskAssignment_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    iot_project_interfaces__srv__TaskAssignment_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
iot_project_interfaces__srv__TaskAssignment_Request__Sequence__init(iot_project_interfaces__srv__TaskAssignment_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  iot_project_interfaces__srv__TaskAssignment_Request * data = NULL;

  if (size) {
    data = (iot_project_interfaces__srv__TaskAssignment_Request *)allocator.zero_allocate(size, sizeof(iot_project_interfaces__srv__TaskAssignment_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = iot_project_interfaces__srv__TaskAssignment_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        iot_project_interfaces__srv__TaskAssignment_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
iot_project_interfaces__srv__TaskAssignment_Request__Sequence__fini(iot_project_interfaces__srv__TaskAssignment_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      iot_project_interfaces__srv__TaskAssignment_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

iot_project_interfaces__srv__TaskAssignment_Request__Sequence *
iot_project_interfaces__srv__TaskAssignment_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  iot_project_interfaces__srv__TaskAssignment_Request__Sequence * array = (iot_project_interfaces__srv__TaskAssignment_Request__Sequence *)allocator.allocate(sizeof(iot_project_interfaces__srv__TaskAssignment_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = iot_project_interfaces__srv__TaskAssignment_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
iot_project_interfaces__srv__TaskAssignment_Request__Sequence__destroy(iot_project_interfaces__srv__TaskAssignment_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    iot_project_interfaces__srv__TaskAssignment_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
iot_project_interfaces__srv__TaskAssignment_Request__Sequence__are_equal(const iot_project_interfaces__srv__TaskAssignment_Request__Sequence * lhs, const iot_project_interfaces__srv__TaskAssignment_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!iot_project_interfaces__srv__TaskAssignment_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
iot_project_interfaces__srv__TaskAssignment_Request__Sequence__copy(
  const iot_project_interfaces__srv__TaskAssignment_Request__Sequence * input,
  iot_project_interfaces__srv__TaskAssignment_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(iot_project_interfaces__srv__TaskAssignment_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    iot_project_interfaces__srv__TaskAssignment_Request * data =
      (iot_project_interfaces__srv__TaskAssignment_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!iot_project_interfaces__srv__TaskAssignment_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          iot_project_interfaces__srv__TaskAssignment_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!iot_project_interfaces__srv__TaskAssignment_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `simulation_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `target_positions`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `target_thresholds`
// Member `last_visits`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `wind_vector`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
iot_project_interfaces__srv__TaskAssignment_Response__init(iot_project_interfaces__srv__TaskAssignment_Response * msg)
{
  if (!msg) {
    return false;
  }
  // simulation_name
  if (!rosidl_runtime_c__String__init(&msg->simulation_name)) {
    iot_project_interfaces__srv__TaskAssignment_Response__fini(msg);
    return false;
  }
  // no_drones
  // target_positions
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->target_positions, 0)) {
    iot_project_interfaces__srv__TaskAssignment_Response__fini(msg);
    return false;
  }
  // target_thresholds
  if (!rosidl_runtime_c__double__Sequence__init(&msg->target_thresholds, 0)) {
    iot_project_interfaces__srv__TaskAssignment_Response__fini(msg);
    return false;
  }
  // aoi_weight
  // violation_weight
  // fairness_weight
  // simulation_time
  // wind_vector
  if (!geometry_msgs__msg__Vector3__init(&msg->wind_vector)) {
    iot_project_interfaces__srv__TaskAssignment_Response__fini(msg);
    return false;
  }
  // last_visits
  if (!rosidl_runtime_c__double__Sequence__init(&msg->last_visits, 0)) {
    iot_project_interfaces__srv__TaskAssignment_Response__fini(msg);
    return false;
  }
  return true;
}

void
iot_project_interfaces__srv__TaskAssignment_Response__fini(iot_project_interfaces__srv__TaskAssignment_Response * msg)
{
  if (!msg) {
    return;
  }
  // simulation_name
  rosidl_runtime_c__String__fini(&msg->simulation_name);
  // no_drones
  // target_positions
  geometry_msgs__msg__Point__Sequence__fini(&msg->target_positions);
  // target_thresholds
  rosidl_runtime_c__double__Sequence__fini(&msg->target_thresholds);
  // aoi_weight
  // violation_weight
  // fairness_weight
  // simulation_time
  // wind_vector
  geometry_msgs__msg__Vector3__fini(&msg->wind_vector);
  // last_visits
  rosidl_runtime_c__double__Sequence__fini(&msg->last_visits);
}

bool
iot_project_interfaces__srv__TaskAssignment_Response__are_equal(const iot_project_interfaces__srv__TaskAssignment_Response * lhs, const iot_project_interfaces__srv__TaskAssignment_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // simulation_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->simulation_name), &(rhs->simulation_name)))
  {
    return false;
  }
  // no_drones
  if (lhs->no_drones != rhs->no_drones) {
    return false;
  }
  // target_positions
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->target_positions), &(rhs->target_positions)))
  {
    return false;
  }
  // target_thresholds
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->target_thresholds), &(rhs->target_thresholds)))
  {
    return false;
  }
  // aoi_weight
  if (lhs->aoi_weight != rhs->aoi_weight) {
    return false;
  }
  // violation_weight
  if (lhs->violation_weight != rhs->violation_weight) {
    return false;
  }
  // fairness_weight
  if (lhs->fairness_weight != rhs->fairness_weight) {
    return false;
  }
  // simulation_time
  if (lhs->simulation_time != rhs->simulation_time) {
    return false;
  }
  // wind_vector
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->wind_vector), &(rhs->wind_vector)))
  {
    return false;
  }
  // last_visits
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->last_visits), &(rhs->last_visits)))
  {
    return false;
  }
  return true;
}

bool
iot_project_interfaces__srv__TaskAssignment_Response__copy(
  const iot_project_interfaces__srv__TaskAssignment_Response * input,
  iot_project_interfaces__srv__TaskAssignment_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // simulation_name
  if (!rosidl_runtime_c__String__copy(
      &(input->simulation_name), &(output->simulation_name)))
  {
    return false;
  }
  // no_drones
  output->no_drones = input->no_drones;
  // target_positions
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->target_positions), &(output->target_positions)))
  {
    return false;
  }
  // target_thresholds
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->target_thresholds), &(output->target_thresholds)))
  {
    return false;
  }
  // aoi_weight
  output->aoi_weight = input->aoi_weight;
  // violation_weight
  output->violation_weight = input->violation_weight;
  // fairness_weight
  output->fairness_weight = input->fairness_weight;
  // simulation_time
  output->simulation_time = input->simulation_time;
  // wind_vector
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->wind_vector), &(output->wind_vector)))
  {
    return false;
  }
  // last_visits
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->last_visits), &(output->last_visits)))
  {
    return false;
  }
  return true;
}

iot_project_interfaces__srv__TaskAssignment_Response *
iot_project_interfaces__srv__TaskAssignment_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  iot_project_interfaces__srv__TaskAssignment_Response * msg = (iot_project_interfaces__srv__TaskAssignment_Response *)allocator.allocate(sizeof(iot_project_interfaces__srv__TaskAssignment_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(iot_project_interfaces__srv__TaskAssignment_Response));
  bool success = iot_project_interfaces__srv__TaskAssignment_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
iot_project_interfaces__srv__TaskAssignment_Response__destroy(iot_project_interfaces__srv__TaskAssignment_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    iot_project_interfaces__srv__TaskAssignment_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
iot_project_interfaces__srv__TaskAssignment_Response__Sequence__init(iot_project_interfaces__srv__TaskAssignment_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  iot_project_interfaces__srv__TaskAssignment_Response * data = NULL;

  if (size) {
    data = (iot_project_interfaces__srv__TaskAssignment_Response *)allocator.zero_allocate(size, sizeof(iot_project_interfaces__srv__TaskAssignment_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = iot_project_interfaces__srv__TaskAssignment_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        iot_project_interfaces__srv__TaskAssignment_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
iot_project_interfaces__srv__TaskAssignment_Response__Sequence__fini(iot_project_interfaces__srv__TaskAssignment_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      iot_project_interfaces__srv__TaskAssignment_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

iot_project_interfaces__srv__TaskAssignment_Response__Sequence *
iot_project_interfaces__srv__TaskAssignment_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  iot_project_interfaces__srv__TaskAssignment_Response__Sequence * array = (iot_project_interfaces__srv__TaskAssignment_Response__Sequence *)allocator.allocate(sizeof(iot_project_interfaces__srv__TaskAssignment_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = iot_project_interfaces__srv__TaskAssignment_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
iot_project_interfaces__srv__TaskAssignment_Response__Sequence__destroy(iot_project_interfaces__srv__TaskAssignment_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    iot_project_interfaces__srv__TaskAssignment_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
iot_project_interfaces__srv__TaskAssignment_Response__Sequence__are_equal(const iot_project_interfaces__srv__TaskAssignment_Response__Sequence * lhs, const iot_project_interfaces__srv__TaskAssignment_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!iot_project_interfaces__srv__TaskAssignment_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
iot_project_interfaces__srv__TaskAssignment_Response__Sequence__copy(
  const iot_project_interfaces__srv__TaskAssignment_Response__Sequence * input,
  iot_project_interfaces__srv__TaskAssignment_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(iot_project_interfaces__srv__TaskAssignment_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    iot_project_interfaces__srv__TaskAssignment_Response * data =
      (iot_project_interfaces__srv__TaskAssignment_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!iot_project_interfaces__srv__TaskAssignment_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          iot_project_interfaces__srv__TaskAssignment_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!iot_project_interfaces__srv__TaskAssignment_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
