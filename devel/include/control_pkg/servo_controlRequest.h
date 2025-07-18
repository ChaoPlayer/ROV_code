// Generated by gencpp from file control_pkg/servo_controlRequest.msg
// DO NOT EDIT!


#ifndef CONTROL_PKG_MESSAGE_SERVO_CONTROLREQUEST_H
#define CONTROL_PKG_MESSAGE_SERVO_CONTROLREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace control_pkg
{
template <class ContainerAllocator>
struct servo_controlRequest_
{
  typedef servo_controlRequest_<ContainerAllocator> Type;

  servo_controlRequest_()
    : req()
    , servoID(0)  {
    }
  servo_controlRequest_(const ContainerAllocator& _alloc)
    : req(_alloc)
    , servoID(0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _req_type;
  _req_type req;

   typedef uint8_t _servoID_type;
  _servoID_type servoID;





  typedef boost::shared_ptr< ::control_pkg::servo_controlRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::control_pkg::servo_controlRequest_<ContainerAllocator> const> ConstPtr;

}; // struct servo_controlRequest_

typedef ::control_pkg::servo_controlRequest_<std::allocator<void> > servo_controlRequest;

typedef boost::shared_ptr< ::control_pkg::servo_controlRequest > servo_controlRequestPtr;
typedef boost::shared_ptr< ::control_pkg::servo_controlRequest const> servo_controlRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::control_pkg::servo_controlRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::control_pkg::servo_controlRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::control_pkg::servo_controlRequest_<ContainerAllocator1> & lhs, const ::control_pkg::servo_controlRequest_<ContainerAllocator2> & rhs)
{
  return lhs.req == rhs.req &&
    lhs.servoID == rhs.servoID;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::control_pkg::servo_controlRequest_<ContainerAllocator1> & lhs, const ::control_pkg::servo_controlRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace control_pkg

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::control_pkg::servo_controlRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::control_pkg::servo_controlRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::control_pkg::servo_controlRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::control_pkg::servo_controlRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::control_pkg::servo_controlRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::control_pkg::servo_controlRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::control_pkg::servo_controlRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f0eacf72d9549eb4f746bd299724faa1";
  }

  static const char* value(const ::control_pkg::servo_controlRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf0eacf72d9549eb4ULL;
  static const uint64_t static_value2 = 0xf746bd299724faa1ULL;
};

template<class ContainerAllocator>
struct DataType< ::control_pkg::servo_controlRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "control_pkg/servo_controlRequest";
  }

  static const char* value(const ::control_pkg::servo_controlRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::control_pkg::servo_controlRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string req\n"
"uint8 servoID\n"
;
  }

  static const char* value(const ::control_pkg::servo_controlRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::control_pkg::servo_controlRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.req);
      stream.next(m.servoID);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct servo_controlRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::control_pkg::servo_controlRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::control_pkg::servo_controlRequest_<ContainerAllocator>& v)
  {
    if (false || !indent.empty())
      s << std::endl;
    s << indent << "req: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.req);
    if (true || !indent.empty())
      s << std::endl;
    s << indent << "servoID: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.servoID);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CONTROL_PKG_MESSAGE_SERVO_CONTROLREQUEST_H
