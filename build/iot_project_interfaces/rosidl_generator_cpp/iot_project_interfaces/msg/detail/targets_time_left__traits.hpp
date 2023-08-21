// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from iot_project_interfaces:msg/TargetsTimeLeft.idl
// generated code does not contain a copyright notice

#ifndef IOT_PROJECT_INTERFACES__MSG__DETAIL__TARGETS_TIME_LEFT__TRAITS_HPP_
#define IOT_PROJECT_INTERFACES__MSG__DETAIL__TARGETS_TIME_LEFT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "iot_project_interfaces/msg/detail/targets_time_left__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace iot_project_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TargetsTimeLeft & msg,
  std::ostream & out)
{
  out << "{";
  // member: times
  {
    if (msg.times.size() == 0) {
      out << "times: []";
    } else {
      out << "times: [";
      size_t pending_items = msg.times.size();
      for (auto item : msg.times) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TargetsTimeLeft & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: times
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.times.size() == 0) {
      out << "times: []\n";
    } else {
      out << "times:\n";
      for (auto item : msg.times) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TargetsTimeLeft & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace iot_project_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use iot_project_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const iot_project_interfaces::msg::TargetsTimeLeft & msg,
  std::ostream & out, size_t indentation = 0)
{
  iot_project_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use iot_project_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const iot_project_interfaces::msg::TargetsTimeLeft & msg)
{
  return iot_project_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<iot_project_interfaces::msg::TargetsTimeLeft>()
{
  return "iot_project_interfaces::msg::TargetsTimeLeft";
}

template<>
inline const char * name<iot_project_interfaces::msg::TargetsTimeLeft>()
{
  return "iot_project_interfaces/msg/TargetsTimeLeft";
}

template<>
struct has_fixed_size<iot_project_interfaces::msg::TargetsTimeLeft>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<iot_project_interfaces::msg::TargetsTimeLeft>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<iot_project_interfaces::msg::TargetsTimeLeft>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // IOT_PROJECT_INTERFACES__MSG__DETAIL__TARGETS_TIME_LEFT__TRAITS_HPP_
