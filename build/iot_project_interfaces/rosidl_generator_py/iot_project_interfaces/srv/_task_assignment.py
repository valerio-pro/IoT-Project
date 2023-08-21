# generated from rosidl_generator_py/resource/_idl.py.em
# with input from iot_project_interfaces:srv/TaskAssignment.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TaskAssignment_Request(type):
    """Metaclass of message 'TaskAssignment_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('iot_project_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'iot_project_interfaces.srv.TaskAssignment_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__task_assignment__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__task_assignment__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__task_assignment__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__task_assignment__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__task_assignment__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TaskAssignment_Request(metaclass=Metaclass_TaskAssignment_Request):
    """Message class 'TaskAssignment_Request'."""

    __slots__ = [
    ]

    _fields_and_field_types = {
    }

    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


# Import statements for member types

# Member 'target_thresholds'
# Member 'last_visits'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_TaskAssignment_Response(type):
    """Metaclass of message 'TaskAssignment_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('iot_project_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'iot_project_interfaces.srv.TaskAssignment_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__task_assignment__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__task_assignment__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__task_assignment__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__task_assignment__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__task_assignment__response

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

            from geometry_msgs.msg import Vector3
            if Vector3.__class__._TYPE_SUPPORT is None:
                Vector3.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TaskAssignment_Response(metaclass=Metaclass_TaskAssignment_Response):
    """Message class 'TaskAssignment_Response'."""

    __slots__ = [
        '_simulation_name',
        '_no_drones',
        '_target_positions',
        '_target_thresholds',
        '_aoi_weight',
        '_violation_weight',
        '_fairness_weight',
        '_simulation_time',
        '_wind_vector',
        '_last_visits',
    ]

    _fields_and_field_types = {
        'simulation_name': 'string',
        'no_drones': 'int64',
        'target_positions': 'sequence<geometry_msgs/Point>',
        'target_thresholds': 'sequence<double>',
        'aoi_weight': 'double',
        'violation_weight': 'double',
        'fairness_weight': 'double',
        'simulation_time': 'int64',
        'wind_vector': 'geometry_msgs/Vector3',
        'last_visits': 'sequence<double>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.simulation_name = kwargs.get('simulation_name', str())
        self.no_drones = kwargs.get('no_drones', int())
        self.target_positions = kwargs.get('target_positions', [])
        self.target_thresholds = array.array('d', kwargs.get('target_thresholds', []))
        self.aoi_weight = kwargs.get('aoi_weight', float())
        self.violation_weight = kwargs.get('violation_weight', float())
        self.fairness_weight = kwargs.get('fairness_weight', float())
        self.simulation_time = kwargs.get('simulation_time', int())
        from geometry_msgs.msg import Vector3
        self.wind_vector = kwargs.get('wind_vector', Vector3())
        self.last_visits = array.array('d', kwargs.get('last_visits', []))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.simulation_name != other.simulation_name:
            return False
        if self.no_drones != other.no_drones:
            return False
        if self.target_positions != other.target_positions:
            return False
        if self.target_thresholds != other.target_thresholds:
            return False
        if self.aoi_weight != other.aoi_weight:
            return False
        if self.violation_weight != other.violation_weight:
            return False
        if self.fairness_weight != other.fairness_weight:
            return False
        if self.simulation_time != other.simulation_time:
            return False
        if self.wind_vector != other.wind_vector:
            return False
        if self.last_visits != other.last_visits:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def simulation_name(self):
        """Message field 'simulation_name'."""
        return self._simulation_name

    @simulation_name.setter
    def simulation_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'simulation_name' field must be of type 'str'"
        self._simulation_name = value

    @builtins.property
    def no_drones(self):
        """Message field 'no_drones'."""
        return self._no_drones

    @no_drones.setter
    def no_drones(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'no_drones' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'no_drones' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._no_drones = value

    @builtins.property
    def target_positions(self):
        """Message field 'target_positions'."""
        return self._target_positions

    @target_positions.setter
    def target_positions(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'target_positions' field must be a set or sequence and each value of type 'Point'"
        self._target_positions = value

    @builtins.property
    def target_thresholds(self):
        """Message field 'target_thresholds'."""
        return self._target_thresholds

    @target_thresholds.setter
    def target_thresholds(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'target_thresholds' array.array() must have the type code of 'd'"
            self._target_thresholds = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'target_thresholds' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._target_thresholds = array.array('d', value)

    @builtins.property
    def aoi_weight(self):
        """Message field 'aoi_weight'."""
        return self._aoi_weight

    @aoi_weight.setter
    def aoi_weight(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'aoi_weight' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'aoi_weight' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._aoi_weight = value

    @builtins.property
    def violation_weight(self):
        """Message field 'violation_weight'."""
        return self._violation_weight

    @violation_weight.setter
    def violation_weight(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'violation_weight' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'violation_weight' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._violation_weight = value

    @builtins.property
    def fairness_weight(self):
        """Message field 'fairness_weight'."""
        return self._fairness_weight

    @fairness_weight.setter
    def fairness_weight(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'fairness_weight' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'fairness_weight' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._fairness_weight = value

    @builtins.property
    def simulation_time(self):
        """Message field 'simulation_time'."""
        return self._simulation_time

    @simulation_time.setter
    def simulation_time(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'simulation_time' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'simulation_time' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._simulation_time = value

    @builtins.property
    def wind_vector(self):
        """Message field 'wind_vector'."""
        return self._wind_vector

    @wind_vector.setter
    def wind_vector(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'wind_vector' field must be a sub message of type 'Vector3'"
        self._wind_vector = value

    @builtins.property
    def last_visits(self):
        """Message field 'last_visits'."""
        return self._last_visits

    @last_visits.setter
    def last_visits(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'last_visits' array.array() must have the type code of 'd'"
            self._last_visits = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'last_visits' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._last_visits = array.array('d', value)


class Metaclass_TaskAssignment(type):
    """Metaclass of service 'TaskAssignment'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('iot_project_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'iot_project_interfaces.srv.TaskAssignment')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__task_assignment

            from iot_project_interfaces.srv import _task_assignment
            if _task_assignment.Metaclass_TaskAssignment_Request._TYPE_SUPPORT is None:
                _task_assignment.Metaclass_TaskAssignment_Request.__import_type_support__()
            if _task_assignment.Metaclass_TaskAssignment_Response._TYPE_SUPPORT is None:
                _task_assignment.Metaclass_TaskAssignment_Response.__import_type_support__()


class TaskAssignment(metaclass=Metaclass_TaskAssignment):
    from iot_project_interfaces.srv._task_assignment import TaskAssignment_Request as Request
    from iot_project_interfaces.srv._task_assignment import TaskAssignment_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
