// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from iot_project_interfaces:srv/TaskAssignment.idl
// generated code does not contain a copyright notice

#ifndef IOT_PROJECT_INTERFACES__SRV__DETAIL__TASK_ASSIGNMENT__BUILDER_HPP_
#define IOT_PROJECT_INTERFACES__SRV__DETAIL__TASK_ASSIGNMENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "iot_project_interfaces/srv/detail/task_assignment__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace iot_project_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::iot_project_interfaces::srv::TaskAssignment_Request>()
{
  return ::iot_project_interfaces::srv::TaskAssignment_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace iot_project_interfaces


namespace iot_project_interfaces
{

namespace srv
{

namespace builder
{

class Init_TaskAssignment_Response_last_visits
{
public:
  explicit Init_TaskAssignment_Response_last_visits(::iot_project_interfaces::srv::TaskAssignment_Response & msg)
  : msg_(msg)
  {}
  ::iot_project_interfaces::srv::TaskAssignment_Response last_visits(::iot_project_interfaces::srv::TaskAssignment_Response::_last_visits_type arg)
  {
    msg_.last_visits = std::move(arg);
    return std::move(msg_);
  }

private:
  ::iot_project_interfaces::srv::TaskAssignment_Response msg_;
};

class Init_TaskAssignment_Response_wind_vector
{
public:
  explicit Init_TaskAssignment_Response_wind_vector(::iot_project_interfaces::srv::TaskAssignment_Response & msg)
  : msg_(msg)
  {}
  Init_TaskAssignment_Response_last_visits wind_vector(::iot_project_interfaces::srv::TaskAssignment_Response::_wind_vector_type arg)
  {
    msg_.wind_vector = std::move(arg);
    return Init_TaskAssignment_Response_last_visits(msg_);
  }

private:
  ::iot_project_interfaces::srv::TaskAssignment_Response msg_;
};

class Init_TaskAssignment_Response_simulation_time
{
public:
  explicit Init_TaskAssignment_Response_simulation_time(::iot_project_interfaces::srv::TaskAssignment_Response & msg)
  : msg_(msg)
  {}
  Init_TaskAssignment_Response_wind_vector simulation_time(::iot_project_interfaces::srv::TaskAssignment_Response::_simulation_time_type arg)
  {
    msg_.simulation_time = std::move(arg);
    return Init_TaskAssignment_Response_wind_vector(msg_);
  }

private:
  ::iot_project_interfaces::srv::TaskAssignment_Response msg_;
};

class Init_TaskAssignment_Response_fairness_weight
{
public:
  explicit Init_TaskAssignment_Response_fairness_weight(::iot_project_interfaces::srv::TaskAssignment_Response & msg)
  : msg_(msg)
  {}
  Init_TaskAssignment_Response_simulation_time fairness_weight(::iot_project_interfaces::srv::TaskAssignment_Response::_fairness_weight_type arg)
  {
    msg_.fairness_weight = std::move(arg);
    return Init_TaskAssignment_Response_simulation_time(msg_);
  }

private:
  ::iot_project_interfaces::srv::TaskAssignment_Response msg_;
};

class Init_TaskAssignment_Response_violation_weight
{
public:
  explicit Init_TaskAssignment_Response_violation_weight(::iot_project_interfaces::srv::TaskAssignment_Response & msg)
  : msg_(msg)
  {}
  Init_TaskAssignment_Response_fairness_weight violation_weight(::iot_project_interfaces::srv::TaskAssignment_Response::_violation_weight_type arg)
  {
    msg_.violation_weight = std::move(arg);
    return Init_TaskAssignment_Response_fairness_weight(msg_);
  }

private:
  ::iot_project_interfaces::srv::TaskAssignment_Response msg_;
};

class Init_TaskAssignment_Response_aoi_weight
{
public:
  explicit Init_TaskAssignment_Response_aoi_weight(::iot_project_interfaces::srv::TaskAssignment_Response & msg)
  : msg_(msg)
  {}
  Init_TaskAssignment_Response_violation_weight aoi_weight(::iot_project_interfaces::srv::TaskAssignment_Response::_aoi_weight_type arg)
  {
    msg_.aoi_weight = std::move(arg);
    return Init_TaskAssignment_Response_violation_weight(msg_);
  }

private:
  ::iot_project_interfaces::srv::TaskAssignment_Response msg_;
};

class Init_TaskAssignment_Response_target_thresholds
{
public:
  explicit Init_TaskAssignment_Response_target_thresholds(::iot_project_interfaces::srv::TaskAssignment_Response & msg)
  : msg_(msg)
  {}
  Init_TaskAssignment_Response_aoi_weight target_thresholds(::iot_project_interfaces::srv::TaskAssignment_Response::_target_thresholds_type arg)
  {
    msg_.target_thresholds = std::move(arg);
    return Init_TaskAssignment_Response_aoi_weight(msg_);
  }

private:
  ::iot_project_interfaces::srv::TaskAssignment_Response msg_;
};

class Init_TaskAssignment_Response_target_positions
{
public:
  explicit Init_TaskAssignment_Response_target_positions(::iot_project_interfaces::srv::TaskAssignment_Response & msg)
  : msg_(msg)
  {}
  Init_TaskAssignment_Response_target_thresholds target_positions(::iot_project_interfaces::srv::TaskAssignment_Response::_target_positions_type arg)
  {
    msg_.target_positions = std::move(arg);
    return Init_TaskAssignment_Response_target_thresholds(msg_);
  }

private:
  ::iot_project_interfaces::srv::TaskAssignment_Response msg_;
};

class Init_TaskAssignment_Response_no_drones
{
public:
  explicit Init_TaskAssignment_Response_no_drones(::iot_project_interfaces::srv::TaskAssignment_Response & msg)
  : msg_(msg)
  {}
  Init_TaskAssignment_Response_target_positions no_drones(::iot_project_interfaces::srv::TaskAssignment_Response::_no_drones_type arg)
  {
    msg_.no_drones = std::move(arg);
    return Init_TaskAssignment_Response_target_positions(msg_);
  }

private:
  ::iot_project_interfaces::srv::TaskAssignment_Response msg_;
};

class Init_TaskAssignment_Response_simulation_name
{
public:
  Init_TaskAssignment_Response_simulation_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskAssignment_Response_no_drones simulation_name(::iot_project_interfaces::srv::TaskAssignment_Response::_simulation_name_type arg)
  {
    msg_.simulation_name = std::move(arg);
    return Init_TaskAssignment_Response_no_drones(msg_);
  }

private:
  ::iot_project_interfaces::srv::TaskAssignment_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::iot_project_interfaces::srv::TaskAssignment_Response>()
{
  return iot_project_interfaces::srv::builder::Init_TaskAssignment_Response_simulation_name();
}

}  // namespace iot_project_interfaces

#endif  // IOT_PROJECT_INTERFACES__SRV__DETAIL__TASK_ASSIGNMENT__BUILDER_HPP_
