# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/valerio/Desktop/IoT-Project/src/iot_project_solution_interfaces

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/valerio/Desktop/IoT-Project/build/iot_project_solution_interfaces

# Utility rule file for iot_project_solution_interfaces.

# Include any custom commands dependencies for this target.
include CMakeFiles/iot_project_solution_interfaces.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/iot_project_solution_interfaces.dir/progress.make

CMakeFiles/iot_project_solution_interfaces: /home/valerio/Desktop/IoT-Project/src/iot_project_solution_interfaces/action/PatrollingAction.action
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/Accel.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/AccelStamped.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/AccelWithCovariance.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/AccelWithCovarianceStamped.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/Inertia.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/InertiaStamped.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/Point.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/Point32.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/PointStamped.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/Polygon.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/PolygonStamped.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/Pose.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/Pose2D.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/PoseArray.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/PoseStamped.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/PoseWithCovariance.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/PoseWithCovarianceStamped.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/Quaternion.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/QuaternionStamped.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/Transform.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/TransformStamped.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/Twist.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/TwistStamped.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/TwistWithCovariance.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/TwistWithCovarianceStamped.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/Vector3.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/Vector3Stamped.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/Wrench.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/geometry_msgs/msg/WrenchStamped.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/action_msgs/msg/GoalInfo.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/action_msgs/msg/GoalStatus.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/action_msgs/msg/GoalStatusArray.idl
CMakeFiles/iot_project_solution_interfaces: /opt/ros/humble/share/action_msgs/srv/CancelGoal.idl

iot_project_solution_interfaces: CMakeFiles/iot_project_solution_interfaces
iot_project_solution_interfaces: CMakeFiles/iot_project_solution_interfaces.dir/build.make
.PHONY : iot_project_solution_interfaces

# Rule to build all files generated by this target.
CMakeFiles/iot_project_solution_interfaces.dir/build: iot_project_solution_interfaces
.PHONY : CMakeFiles/iot_project_solution_interfaces.dir/build

CMakeFiles/iot_project_solution_interfaces.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/iot_project_solution_interfaces.dir/cmake_clean.cmake
.PHONY : CMakeFiles/iot_project_solution_interfaces.dir/clean

CMakeFiles/iot_project_solution_interfaces.dir/depend:
	cd /home/valerio/Desktop/IoT-Project/build/iot_project_solution_interfaces && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/valerio/Desktop/IoT-Project/src/iot_project_solution_interfaces /home/valerio/Desktop/IoT-Project/src/iot_project_solution_interfaces /home/valerio/Desktop/IoT-Project/build/iot_project_solution_interfaces /home/valerio/Desktop/IoT-Project/build/iot_project_solution_interfaces /home/valerio/Desktop/IoT-Project/build/iot_project_solution_interfaces/CMakeFiles/iot_project_solution_interfaces.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/iot_project_solution_interfaces.dir/depend

