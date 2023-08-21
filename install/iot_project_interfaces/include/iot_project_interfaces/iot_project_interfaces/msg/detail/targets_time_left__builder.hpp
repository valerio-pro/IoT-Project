// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from iot_project_interfaces:msg/TargetsTimeLeft.idl
// generated code does not contain a copyright notice

#ifndef IOT_PROJECT_INTERFACES__MSG__DETAIL__TARGETS_TIME_LEFT__BUILDER_HPP_
#define IOT_PROJECT_INTERFACES__MSG__DETAIL__TARGETS_TIME_LEFT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "iot_project_interfaces/msg/detail/targets_time_left__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace iot_project_interfaces
{

namespace msg
{

namespace builder
{

class Init_TargetsTimeLeft_times
{
public:
  Init_TargetsTimeLeft_times()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::iot_project_interfaces::msg::TargetsTimeLeft times(::iot_project_interfaces::msg::TargetsTimeLeft::_times_type arg)
  {
    msg_.times = std::move(arg);
    return std::move(msg_);
  }

private:
  ::iot_project_interfaces::msg::TargetsTimeLeft msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::iot_project_interfaces::msg::TargetsTimeLeft>()
{
  return iot_project_interfaces::msg::builder::Init_TargetsTimeLeft_times();
}

}  // namespace iot_project_interfaces

#endif  // IOT_PROJECT_INTERFACES__MSG__DETAIL__TARGETS_TIME_LEFT__BUILDER_HPP_
