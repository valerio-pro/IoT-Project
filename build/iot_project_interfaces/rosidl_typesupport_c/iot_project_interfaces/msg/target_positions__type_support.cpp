// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from iot_project_interfaces:msg/TargetPositions.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "iot_project_interfaces/msg/detail/target_positions__struct.h"
#include "iot_project_interfaces/msg/detail/target_positions__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace iot_project_interfaces
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _TargetPositions_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TargetPositions_type_support_ids_t;

static const _TargetPositions_type_support_ids_t _TargetPositions_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _TargetPositions_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TargetPositions_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TargetPositions_type_support_symbol_names_t _TargetPositions_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, iot_project_interfaces, msg, TargetPositions)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, iot_project_interfaces, msg, TargetPositions)),
  }
};

typedef struct _TargetPositions_type_support_data_t
{
  void * data[2];
} _TargetPositions_type_support_data_t;

static _TargetPositions_type_support_data_t _TargetPositions_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TargetPositions_message_typesupport_map = {
  2,
  "iot_project_interfaces",
  &_TargetPositions_message_typesupport_ids.typesupport_identifier[0],
  &_TargetPositions_message_typesupport_symbol_names.symbol_name[0],
  &_TargetPositions_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TargetPositions_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TargetPositions_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace iot_project_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, iot_project_interfaces, msg, TargetPositions)() {
  return &::iot_project_interfaces::msg::rosidl_typesupport_c::TargetPositions_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
