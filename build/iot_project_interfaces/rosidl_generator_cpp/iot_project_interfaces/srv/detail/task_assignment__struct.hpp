// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from iot_project_interfaces:srv/TaskAssignment.idl
// generated code does not contain a copyright notice

#ifndef IOT_PROJECT_INTERFACES__SRV__DETAIL__TASK_ASSIGNMENT__STRUCT_HPP_
#define IOT_PROJECT_INTERFACES__SRV__DETAIL__TASK_ASSIGNMENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__iot_project_interfaces__srv__TaskAssignment_Request __attribute__((deprecated))
#else
# define DEPRECATED__iot_project_interfaces__srv__TaskAssignment_Request __declspec(deprecated)
#endif

namespace iot_project_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TaskAssignment_Request_
{
  using Type = TaskAssignment_Request_<ContainerAllocator>;

  explicit TaskAssignment_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit TaskAssignment_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    iot_project_interfaces::srv::TaskAssignment_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const iot_project_interfaces::srv::TaskAssignment_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<iot_project_interfaces::srv::TaskAssignment_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<iot_project_interfaces::srv::TaskAssignment_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      iot_project_interfaces::srv::TaskAssignment_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<iot_project_interfaces::srv::TaskAssignment_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      iot_project_interfaces::srv::TaskAssignment_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<iot_project_interfaces::srv::TaskAssignment_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<iot_project_interfaces::srv::TaskAssignment_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<iot_project_interfaces::srv::TaskAssignment_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__iot_project_interfaces__srv__TaskAssignment_Request
    std::shared_ptr<iot_project_interfaces::srv::TaskAssignment_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__iot_project_interfaces__srv__TaskAssignment_Request
    std::shared_ptr<iot_project_interfaces::srv::TaskAssignment_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskAssignment_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskAssignment_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskAssignment_Request_

// alias to use template instance with default allocator
using TaskAssignment_Request =
  iot_project_interfaces::srv::TaskAssignment_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace iot_project_interfaces


// Include directives for member types
// Member 'target_positions'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'wind_vector'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__iot_project_interfaces__srv__TaskAssignment_Response __attribute__((deprecated))
#else
# define DEPRECATED__iot_project_interfaces__srv__TaskAssignment_Response __declspec(deprecated)
#endif

namespace iot_project_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TaskAssignment_Response_
{
  using Type = TaskAssignment_Response_<ContainerAllocator>;

  explicit TaskAssignment_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : wind_vector(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->simulation_name = "";
      this->no_drones = 0ll;
      this->aoi_weight = 0.0;
      this->violation_weight = 0.0;
      this->fairness_weight = 0.0;
      this->simulation_time = 0ll;
    }
  }

  explicit TaskAssignment_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : simulation_name(_alloc),
    wind_vector(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->simulation_name = "";
      this->no_drones = 0ll;
      this->aoi_weight = 0.0;
      this->violation_weight = 0.0;
      this->fairness_weight = 0.0;
      this->simulation_time = 0ll;
    }
  }

  // field types and members
  using _simulation_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _simulation_name_type simulation_name;
  using _no_drones_type =
    int64_t;
  _no_drones_type no_drones;
  using _target_positions_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _target_positions_type target_positions;
  using _target_thresholds_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _target_thresholds_type target_thresholds;
  using _aoi_weight_type =
    double;
  _aoi_weight_type aoi_weight;
  using _violation_weight_type =
    double;
  _violation_weight_type violation_weight;
  using _fairness_weight_type =
    double;
  _fairness_weight_type fairness_weight;
  using _simulation_time_type =
    int64_t;
  _simulation_time_type simulation_time;
  using _wind_vector_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _wind_vector_type wind_vector;
  using _last_visits_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _last_visits_type last_visits;

  // setters for named parameter idiom
  Type & set__simulation_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->simulation_name = _arg;
    return *this;
  }
  Type & set__no_drones(
    const int64_t & _arg)
  {
    this->no_drones = _arg;
    return *this;
  }
  Type & set__target_positions(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->target_positions = _arg;
    return *this;
  }
  Type & set__target_thresholds(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->target_thresholds = _arg;
    return *this;
  }
  Type & set__aoi_weight(
    const double & _arg)
  {
    this->aoi_weight = _arg;
    return *this;
  }
  Type & set__violation_weight(
    const double & _arg)
  {
    this->violation_weight = _arg;
    return *this;
  }
  Type & set__fairness_weight(
    const double & _arg)
  {
    this->fairness_weight = _arg;
    return *this;
  }
  Type & set__simulation_time(
    const int64_t & _arg)
  {
    this->simulation_time = _arg;
    return *this;
  }
  Type & set__wind_vector(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->wind_vector = _arg;
    return *this;
  }
  Type & set__last_visits(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->last_visits = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    iot_project_interfaces::srv::TaskAssignment_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const iot_project_interfaces::srv::TaskAssignment_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<iot_project_interfaces::srv::TaskAssignment_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<iot_project_interfaces::srv::TaskAssignment_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      iot_project_interfaces::srv::TaskAssignment_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<iot_project_interfaces::srv::TaskAssignment_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      iot_project_interfaces::srv::TaskAssignment_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<iot_project_interfaces::srv::TaskAssignment_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<iot_project_interfaces::srv::TaskAssignment_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<iot_project_interfaces::srv::TaskAssignment_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__iot_project_interfaces__srv__TaskAssignment_Response
    std::shared_ptr<iot_project_interfaces::srv::TaskAssignment_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__iot_project_interfaces__srv__TaskAssignment_Response
    std::shared_ptr<iot_project_interfaces::srv::TaskAssignment_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskAssignment_Response_ & other) const
  {
    if (this->simulation_name != other.simulation_name) {
      return false;
    }
    if (this->no_drones != other.no_drones) {
      return false;
    }
    if (this->target_positions != other.target_positions) {
      return false;
    }
    if (this->target_thresholds != other.target_thresholds) {
      return false;
    }
    if (this->aoi_weight != other.aoi_weight) {
      return false;
    }
    if (this->violation_weight != other.violation_weight) {
      return false;
    }
    if (this->fairness_weight != other.fairness_weight) {
      return false;
    }
    if (this->simulation_time != other.simulation_time) {
      return false;
    }
    if (this->wind_vector != other.wind_vector) {
      return false;
    }
    if (this->last_visits != other.last_visits) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskAssignment_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskAssignment_Response_

// alias to use template instance with default allocator
using TaskAssignment_Response =
  iot_project_interfaces::srv::TaskAssignment_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace iot_project_interfaces

namespace iot_project_interfaces
{

namespace srv
{

struct TaskAssignment
{
  using Request = iot_project_interfaces::srv::TaskAssignment_Request;
  using Response = iot_project_interfaces::srv::TaskAssignment_Response;
};

}  // namespace srv

}  // namespace iot_project_interfaces

#endif  // IOT_PROJECT_INTERFACES__SRV__DETAIL__TASK_ASSIGNMENT__STRUCT_HPP_
