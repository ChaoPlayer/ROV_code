// Generated by gencpp from file rov_start_pkg/init_msg.msg
// DO NOT EDIT!


#ifndef ROV_START_PKG_MESSAGE_INIT_MSG_H
#define ROV_START_PKG_MESSAGE_INIT_MSG_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace rov_start_pkg
{
template <class ContainerAllocator>
struct init_msg_
{
  typedef init_msg_<ContainerAllocator> Type;

  init_msg_()
    : command(false)
    , success(false)
    , module_name()
    , check_status(false)  {
    }
  init_msg_(const ContainerAllocator& _alloc)
    : command(false)
    , success(false)
    , module_name(_alloc)
    , check_status(false)  {
  (void)_alloc;
    }



   typedef uint8_t _command_type;
  _command_type command;

   typedef uint8_t _success_type;
  _success_type success;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _module_name_type;
  _module_name_type module_name;

   typedef uint8_t _check_status_type;
  _check_status_type check_status;





  typedef boost::shared_ptr< ::rov_start_pkg::init_msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rov_start_pkg::init_msg_<ContainerAllocator> const> ConstPtr;

}; // struct init_msg_

typedef ::rov_start_pkg::init_msg_<std::allocator<void> > init_msg;

typedef boost::shared_ptr< ::rov_start_pkg::init_msg > init_msgPtr;
typedef boost::shared_ptr< ::rov_start_pkg::init_msg const> init_msgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rov_start_pkg::init_msg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rov_start_pkg::init_msg_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::rov_start_pkg::init_msg_<ContainerAllocator1> & lhs, const ::rov_start_pkg::init_msg_<ContainerAllocator2> & rhs)
{
  return lhs.command == rhs.command &&
    lhs.success == rhs.success &&
    lhs.module_name == rhs.module_name &&
    lhs.check_status == rhs.check_status;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::rov_start_pkg::init_msg_<ContainerAllocator1> & lhs, const ::rov_start_pkg::init_msg_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace rov_start_pkg

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::rov_start_pkg::init_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rov_start_pkg::init_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rov_start_pkg::init_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rov_start_pkg::init_msg_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rov_start_pkg::init_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rov_start_pkg::init_msg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rov_start_pkg::init_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d2995b634e846547e16a64fc61dda91c";
  }

  static const char* value(const ::rov_start_pkg::init_msg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd2995b634e846547ULL;
  static const uint64_t static_value2 = 0xe16a64fc61dda91cULL;
};

template<class ContainerAllocator>
struct DataType< ::rov_start_pkg::init_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rov_start_pkg/init_msg";
  }

  static const char* value(const ::rov_start_pkg::init_msg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rov_start_pkg::init_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool command\n"
"bool success\n"
"string module_name\n"
"bool check_status\n"
;
  }

  static const char* value(const ::rov_start_pkg::init_msg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rov_start_pkg::init_msg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.command);
      stream.next(m.success);
      stream.next(m.module_name);
      stream.next(m.check_status);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct init_msg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rov_start_pkg::init_msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rov_start_pkg::init_msg_<ContainerAllocator>& v)
  {
    if (false || !indent.empty())
      s << std::endl;
    s << indent << "command: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.command);
    if (true || !indent.empty())
      s << std::endl;
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
    if (true || !indent.empty())
      s << std::endl;
    s << indent << "module_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.module_name);
    if (true || !indent.empty())
      s << std::endl;
    s << indent << "check_status: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.check_status);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROV_START_PKG_MESSAGE_INIT_MSG_H
