// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from iot_project_interfaces:srv/ColorTarget.idl
// generated code does not contain a copyright notice

#ifndef IOT_PROJECT_INTERFACES__SRV__DETAIL__COLOR_TARGET__TRAITS_HPP_
#define IOT_PROJECT_INTERFACES__SRV__DETAIL__COLOR_TARGET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "iot_project_interfaces/srv/detail/color_target__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace iot_project_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ColorTarget_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: target
  {
    out << "target: ";
    rosidl_generator_traits::value_to_yaml(msg.target, out);
    out << ", ";
  }

  // member: r
  {
    out << "r: ";
    rosidl_generator_traits::value_to_yaml(msg.r, out);
    out << ", ";
  }

  // member: g
  {
    out << "g: ";
    rosidl_generator_traits::value_to_yaml(msg.g, out);
    out << ", ";
  }

  // member: b
  {
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << ", ";
  }

  // member: a
  {
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ColorTarget_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target: ";
    rosidl_generator_traits::value_to_yaml(msg.target, out);
    out << "\n";
  }

  // member: r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r: ";
    rosidl_generator_traits::value_to_yaml(msg.r, out);
    out << "\n";
  }

  // member: g
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "g: ";
    rosidl_generator_traits::value_to_yaml(msg.g, out);
    out << "\n";
  }

  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << "\n";
  }

  // member: a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ColorTarget_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace iot_project_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use iot_project_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const iot_project_interfaces::srv::ColorTarget_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  iot_project_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use iot_project_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const iot_project_interfaces::srv::ColorTarget_Request & msg)
{
  return iot_project_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<iot_project_interfaces::srv::ColorTarget_Request>()
{
  return "iot_project_interfaces::srv::ColorTarget_Request";
}

template<>
inline const char * name<iot_project_interfaces::srv::ColorTarget_Request>()
{
  return "iot_project_interfaces/srv/ColorTarget_Request";
}

template<>
struct has_fixed_size<iot_project_interfaces::srv::ColorTarget_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<iot_project_interfaces::srv::ColorTarget_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<iot_project_interfaces::srv::ColorTarget_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace iot_project_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ColorTarget_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ColorTarget_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ColorTarget_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace iot_project_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use iot_project_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const iot_project_interfaces::srv::ColorTarget_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  iot_project_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use iot_project_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const iot_project_interfaces::srv::ColorTarget_Response & msg)
{
  return iot_project_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<iot_project_interfaces::srv::ColorTarget_Response>()
{
  return "iot_project_interfaces::srv::ColorTarget_Response";
}

template<>
inline const char * name<iot_project_interfaces::srv::ColorTarget_Response>()
{
  return "iot_project_interfaces/srv/ColorTarget_Response";
}

template<>
struct has_fixed_size<iot_project_interfaces::srv::ColorTarget_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<iot_project_interfaces::srv::ColorTarget_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<iot_project_interfaces::srv::ColorTarget_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<iot_project_interfaces::srv::ColorTarget>()
{
  return "iot_project_interfaces::srv::ColorTarget";
}

template<>
inline const char * name<iot_project_interfaces::srv::ColorTarget>()
{
  return "iot_project_interfaces/srv/ColorTarget";
}

template<>
struct has_fixed_size<iot_project_interfaces::srv::ColorTarget>
  : std::integral_constant<
    bool,
    has_fixed_size<iot_project_interfaces::srv::ColorTarget_Request>::value &&
    has_fixed_size<iot_project_interfaces::srv::ColorTarget_Response>::value
  >
{
};

template<>
struct has_bounded_size<iot_project_interfaces::srv::ColorTarget>
  : std::integral_constant<
    bool,
    has_bounded_size<iot_project_interfaces::srv::ColorTarget_Request>::value &&
    has_bounded_size<iot_project_interfaces::srv::ColorTarget_Response>::value
  >
{
};

template<>
struct is_service<iot_project_interfaces::srv::ColorTarget>
  : std::true_type
{
};

template<>
struct is_service_request<iot_project_interfaces::srv::ColorTarget_Request>
  : std::true_type
{
};

template<>
struct is_service_response<iot_project_interfaces::srv::ColorTarget_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // IOT_PROJECT_INTERFACES__SRV__DETAIL__COLOR_TARGET__TRAITS_HPP_
