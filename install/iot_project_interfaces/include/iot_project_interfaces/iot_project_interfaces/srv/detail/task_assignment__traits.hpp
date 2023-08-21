// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from iot_project_interfaces:srv/TaskAssignment.idl
// generated code does not contain a copyright notice

#ifndef IOT_PROJECT_INTERFACES__SRV__DETAIL__TASK_ASSIGNMENT__TRAITS_HPP_
#define IOT_PROJECT_INTERFACES__SRV__DETAIL__TASK_ASSIGNMENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "iot_project_interfaces/srv/detail/task_assignment__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace iot_project_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const TaskAssignment_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskAssignment_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskAssignment_Request & msg, bool use_flow_style = false)
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
  const iot_project_interfaces::srv::TaskAssignment_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  iot_project_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use iot_project_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const iot_project_interfaces::srv::TaskAssignment_Request & msg)
{
  return iot_project_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<iot_project_interfaces::srv::TaskAssignment_Request>()
{
  return "iot_project_interfaces::srv::TaskAssignment_Request";
}

template<>
inline const char * name<iot_project_interfaces::srv::TaskAssignment_Request>()
{
  return "iot_project_interfaces/srv/TaskAssignment_Request";
}

template<>
struct has_fixed_size<iot_project_interfaces::srv::TaskAssignment_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<iot_project_interfaces::srv::TaskAssignment_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<iot_project_interfaces::srv::TaskAssignment_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'target_positions'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'wind_vector'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace iot_project_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const TaskAssignment_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: simulation_name
  {
    out << "simulation_name: ";
    rosidl_generator_traits::value_to_yaml(msg.simulation_name, out);
    out << ", ";
  }

  // member: no_drones
  {
    out << "no_drones: ";
    rosidl_generator_traits::value_to_yaml(msg.no_drones, out);
    out << ", ";
  }

  // member: target_positions
  {
    if (msg.target_positions.size() == 0) {
      out << "target_positions: []";
    } else {
      out << "target_positions: [";
      size_t pending_items = msg.target_positions.size();
      for (auto item : msg.target_positions) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: target_thresholds
  {
    if (msg.target_thresholds.size() == 0) {
      out << "target_thresholds: []";
    } else {
      out << "target_thresholds: [";
      size_t pending_items = msg.target_thresholds.size();
      for (auto item : msg.target_thresholds) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: aoi_weight
  {
    out << "aoi_weight: ";
    rosidl_generator_traits::value_to_yaml(msg.aoi_weight, out);
    out << ", ";
  }

  // member: violation_weight
  {
    out << "violation_weight: ";
    rosidl_generator_traits::value_to_yaml(msg.violation_weight, out);
    out << ", ";
  }

  // member: fairness_weight
  {
    out << "fairness_weight: ";
    rosidl_generator_traits::value_to_yaml(msg.fairness_weight, out);
    out << ", ";
  }

  // member: simulation_time
  {
    out << "simulation_time: ";
    rosidl_generator_traits::value_to_yaml(msg.simulation_time, out);
    out << ", ";
  }

  // member: wind_vector
  {
    out << "wind_vector: ";
    to_flow_style_yaml(msg.wind_vector, out);
    out << ", ";
  }

  // member: last_visits
  {
    if (msg.last_visits.size() == 0) {
      out << "last_visits: []";
    } else {
      out << "last_visits: [";
      size_t pending_items = msg.last_visits.size();
      for (auto item : msg.last_visits) {
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
  const TaskAssignment_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: simulation_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "simulation_name: ";
    rosidl_generator_traits::value_to_yaml(msg.simulation_name, out);
    out << "\n";
  }

  // member: no_drones
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "no_drones: ";
    rosidl_generator_traits::value_to_yaml(msg.no_drones, out);
    out << "\n";
  }

  // member: target_positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.target_positions.size() == 0) {
      out << "target_positions: []\n";
    } else {
      out << "target_positions:\n";
      for (auto item : msg.target_positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: target_thresholds
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.target_thresholds.size() == 0) {
      out << "target_thresholds: []\n";
    } else {
      out << "target_thresholds:\n";
      for (auto item : msg.target_thresholds) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: aoi_weight
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "aoi_weight: ";
    rosidl_generator_traits::value_to_yaml(msg.aoi_weight, out);
    out << "\n";
  }

  // member: violation_weight
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "violation_weight: ";
    rosidl_generator_traits::value_to_yaml(msg.violation_weight, out);
    out << "\n";
  }

  // member: fairness_weight
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fairness_weight: ";
    rosidl_generator_traits::value_to_yaml(msg.fairness_weight, out);
    out << "\n";
  }

  // member: simulation_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "simulation_time: ";
    rosidl_generator_traits::value_to_yaml(msg.simulation_time, out);
    out << "\n";
  }

  // member: wind_vector
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wind_vector:\n";
    to_block_style_yaml(msg.wind_vector, out, indentation + 2);
  }

  // member: last_visits
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.last_visits.size() == 0) {
      out << "last_visits: []\n";
    } else {
      out << "last_visits:\n";
      for (auto item : msg.last_visits) {
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

inline std::string to_yaml(const TaskAssignment_Response & msg, bool use_flow_style = false)
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
  const iot_project_interfaces::srv::TaskAssignment_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  iot_project_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use iot_project_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const iot_project_interfaces::srv::TaskAssignment_Response & msg)
{
  return iot_project_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<iot_project_interfaces::srv::TaskAssignment_Response>()
{
  return "iot_project_interfaces::srv::TaskAssignment_Response";
}

template<>
inline const char * name<iot_project_interfaces::srv::TaskAssignment_Response>()
{
  return "iot_project_interfaces/srv/TaskAssignment_Response";
}

template<>
struct has_fixed_size<iot_project_interfaces::srv::TaskAssignment_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<iot_project_interfaces::srv::TaskAssignment_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<iot_project_interfaces::srv::TaskAssignment_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<iot_project_interfaces::srv::TaskAssignment>()
{
  return "iot_project_interfaces::srv::TaskAssignment";
}

template<>
inline const char * name<iot_project_interfaces::srv::TaskAssignment>()
{
  return "iot_project_interfaces/srv/TaskAssignment";
}

template<>
struct has_fixed_size<iot_project_interfaces::srv::TaskAssignment>
  : std::integral_constant<
    bool,
    has_fixed_size<iot_project_interfaces::srv::TaskAssignment_Request>::value &&
    has_fixed_size<iot_project_interfaces::srv::TaskAssignment_Response>::value
  >
{
};

template<>
struct has_bounded_size<iot_project_interfaces::srv::TaskAssignment>
  : std::integral_constant<
    bool,
    has_bounded_size<iot_project_interfaces::srv::TaskAssignment_Request>::value &&
    has_bounded_size<iot_project_interfaces::srv::TaskAssignment_Response>::value
  >
{
};

template<>
struct is_service<iot_project_interfaces::srv::TaskAssignment>
  : std::true_type
{
};

template<>
struct is_service_request<iot_project_interfaces::srv::TaskAssignment_Request>
  : std::true_type
{
};

template<>
struct is_service_response<iot_project_interfaces::srv::TaskAssignment_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // IOT_PROJECT_INTERFACES__SRV__DETAIL__TASK_ASSIGNMENT__TRAITS_HPP_
