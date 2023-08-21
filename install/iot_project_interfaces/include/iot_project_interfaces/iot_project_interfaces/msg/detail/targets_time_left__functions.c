// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from iot_project_interfaces:msg/TargetsTimeLeft.idl
// generated code does not contain a copyright notice
#include "iot_project_interfaces/msg/detail/targets_time_left__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `times`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
iot_project_interfaces__msg__TargetsTimeLeft__init(iot_project_interfaces__msg__TargetsTimeLeft * msg)
{
  if (!msg) {
    return false;
  }
  // times
  if (!rosidl_runtime_c__double__Sequence__init(&msg->times, 0)) {
    iot_project_interfaces__msg__TargetsTimeLeft__fini(msg);
    return false;
  }
  return true;
}

void
iot_project_interfaces__msg__TargetsTimeLeft__fini(iot_project_interfaces__msg__TargetsTimeLeft * msg)
{
  if (!msg) {
    return;
  }
  // times
  rosidl_runtime_c__double__Sequence__fini(&msg->times);
}

bool
iot_project_interfaces__msg__TargetsTimeLeft__are_equal(const iot_project_interfaces__msg__TargetsTimeLeft * lhs, const iot_project_interfaces__msg__TargetsTimeLeft * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // times
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->times), &(rhs->times)))
  {
    return false;
  }
  return true;
}

bool
iot_project_interfaces__msg__TargetsTimeLeft__copy(
  const iot_project_interfaces__msg__TargetsTimeLeft * input,
  iot_project_interfaces__msg__TargetsTimeLeft * output)
{
  if (!input || !output) {
    return false;
  }
  // times
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->times), &(output->times)))
  {
    return false;
  }
  return true;
}

iot_project_interfaces__msg__TargetsTimeLeft *
iot_project_interfaces__msg__TargetsTimeLeft__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  iot_project_interfaces__msg__TargetsTimeLeft * msg = (iot_project_interfaces__msg__TargetsTimeLeft *)allocator.allocate(sizeof(iot_project_interfaces__msg__TargetsTimeLeft), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(iot_project_interfaces__msg__TargetsTimeLeft));
  bool success = iot_project_interfaces__msg__TargetsTimeLeft__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
iot_project_interfaces__msg__TargetsTimeLeft__destroy(iot_project_interfaces__msg__TargetsTimeLeft * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    iot_project_interfaces__msg__TargetsTimeLeft__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
iot_project_interfaces__msg__TargetsTimeLeft__Sequence__init(iot_project_interfaces__msg__TargetsTimeLeft__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  iot_project_interfaces__msg__TargetsTimeLeft * data = NULL;

  if (size) {
    data = (iot_project_interfaces__msg__TargetsTimeLeft *)allocator.zero_allocate(size, sizeof(iot_project_interfaces__msg__TargetsTimeLeft), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = iot_project_interfaces__msg__TargetsTimeLeft__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        iot_project_interfaces__msg__TargetsTimeLeft__fini(&data[i - 1]);
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
iot_project_interfaces__msg__TargetsTimeLeft__Sequence__fini(iot_project_interfaces__msg__TargetsTimeLeft__Sequence * array)
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
      iot_project_interfaces__msg__TargetsTimeLeft__fini(&array->data[i]);
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

iot_project_interfaces__msg__TargetsTimeLeft__Sequence *
iot_project_interfaces__msg__TargetsTimeLeft__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  iot_project_interfaces__msg__TargetsTimeLeft__Sequence * array = (iot_project_interfaces__msg__TargetsTimeLeft__Sequence *)allocator.allocate(sizeof(iot_project_interfaces__msg__TargetsTimeLeft__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = iot_project_interfaces__msg__TargetsTimeLeft__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
iot_project_interfaces__msg__TargetsTimeLeft__Sequence__destroy(iot_project_interfaces__msg__TargetsTimeLeft__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    iot_project_interfaces__msg__TargetsTimeLeft__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
iot_project_interfaces__msg__TargetsTimeLeft__Sequence__are_equal(const iot_project_interfaces__msg__TargetsTimeLeft__Sequence * lhs, const iot_project_interfaces__msg__TargetsTimeLeft__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!iot_project_interfaces__msg__TargetsTimeLeft__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
iot_project_interfaces__msg__TargetsTimeLeft__Sequence__copy(
  const iot_project_interfaces__msg__TargetsTimeLeft__Sequence * input,
  iot_project_interfaces__msg__TargetsTimeLeft__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(iot_project_interfaces__msg__TargetsTimeLeft);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    iot_project_interfaces__msg__TargetsTimeLeft * data =
      (iot_project_interfaces__msg__TargetsTimeLeft *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!iot_project_interfaces__msg__TargetsTimeLeft__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          iot_project_interfaces__msg__TargetsTimeLeft__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!iot_project_interfaces__msg__TargetsTimeLeft__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
