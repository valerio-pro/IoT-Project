// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from iot_project_interfaces:srv/ColorTarget.idl
// generated code does not contain a copyright notice

#ifndef IOT_PROJECT_INTERFACES__SRV__DETAIL__COLOR_TARGET__STRUCT_HPP_
#define IOT_PROJECT_INTERFACES__SRV__DETAIL__COLOR_TARGET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__iot_project_interfaces__srv__ColorTarget_Request __attribute__((deprecated))
#else
# define DEPRECATED__iot_project_interfaces__srv__ColorTarget_Request __declspec(deprecated)
#endif

namespace iot_project_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ColorTarget_Request_
{
  using Type = ColorTarget_Request_<ContainerAllocator>;

  explicit ColorTarget_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target = "";
      this->color_r = 0;
      this->color_g = 0;
      this->color_b = 0;
    }
  }

  explicit ColorTarget_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target = "";
      this->color_r = 0;
      this->color_g = 0;
      this->color_b = 0;
    }
  }

  // field types and members
  using _target_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _target_type target;
  using _color_r_type =
    int8_t;
  _color_r_type color_r;
  using _color_g_type =
    int8_t;
  _color_g_type color_g;
  using _color_b_type =
    int8_t;
  _color_b_type color_b;

  // setters for named parameter idiom
  Type & set__target(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->target = _arg;
    return *this;
  }
  Type & set__color_r(
    const int8_t & _arg)
  {
    this->color_r = _arg;
    return *this;
  }
  Type & set__color_g(
    const int8_t & _arg)
  {
    this->color_g = _arg;
    return *this;
  }
  Type & set__color_b(
    const int8_t & _arg)
  {
    this->color_b = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    iot_project_interfaces::srv::ColorTarget_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const iot_project_interfaces::srv::ColorTarget_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<iot_project_interfaces::srv::ColorTarget_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<iot_project_interfaces::srv::ColorTarget_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      iot_project_interfaces::srv::ColorTarget_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<iot_project_interfaces::srv::ColorTarget_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      iot_project_interfaces::srv::ColorTarget_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<iot_project_interfaces::srv::ColorTarget_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<iot_project_interfaces::srv::ColorTarget_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<iot_project_interfaces::srv::ColorTarget_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__iot_project_interfaces__srv__ColorTarget_Request
    std::shared_ptr<iot_project_interfaces::srv::ColorTarget_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__iot_project_interfaces__srv__ColorTarget_Request
    std::shared_ptr<iot_project_interfaces::srv::ColorTarget_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ColorTarget_Request_ & other) const
  {
    if (this->target != other.target) {
      return false;
    }
    if (this->color_r != other.color_r) {
      return false;
    }
    if (this->color_g != other.color_g) {
      return false;
    }
    if (this->color_b != other.color_b) {
      return false;
    }
    return true;
  }
  bool operator!=(const ColorTarget_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ColorTarget_Request_

// alias to use template instance with default allocator
using ColorTarget_Request =
  iot_project_interfaces::srv::ColorTarget_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace iot_project_interfaces


#ifndef _WIN32
# define DEPRECATED__iot_project_interfaces__srv__ColorTarget_Response __attribute__((deprecated))
#else
# define DEPRECATED__iot_project_interfaces__srv__ColorTarget_Response __declspec(deprecated)
#endif

namespace iot_project_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ColorTarget_Response_
{
  using Type = ColorTarget_Response_<ContainerAllocator>;

  explicit ColorTarget_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
    }
  }

  explicit ColorTarget_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
    }
  }

  // field types and members
  using _result_type =
    bool;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const bool & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    iot_project_interfaces::srv::ColorTarget_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const iot_project_interfaces::srv::ColorTarget_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<iot_project_interfaces::srv::ColorTarget_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<iot_project_interfaces::srv::ColorTarget_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      iot_project_interfaces::srv::ColorTarget_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<iot_project_interfaces::srv::ColorTarget_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      iot_project_interfaces::srv::ColorTarget_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<iot_project_interfaces::srv::ColorTarget_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<iot_project_interfaces::srv::ColorTarget_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<iot_project_interfaces::srv::ColorTarget_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__iot_project_interfaces__srv__ColorTarget_Response
    std::shared_ptr<iot_project_interfaces::srv::ColorTarget_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__iot_project_interfaces__srv__ColorTarget_Response
    std::shared_ptr<iot_project_interfaces::srv::ColorTarget_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ColorTarget_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const ColorTarget_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ColorTarget_Response_

// alias to use template instance with default allocator
using ColorTarget_Response =
  iot_project_interfaces::srv::ColorTarget_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace iot_project_interfaces

namespace iot_project_interfaces
{

namespace srv
{

struct ColorTarget
{
  using Request = iot_project_interfaces::srv::ColorTarget_Request;
  using Response = iot_project_interfaces::srv::ColorTarget_Response;
};

}  // namespace srv

}  // namespace iot_project_interfaces

#endif  // IOT_PROJECT_INTERFACES__SRV__DETAIL__COLOR_TARGET__STRUCT_HPP_
