// Generated by gencpp from file control_pkg/servo_control.msg
// DO NOT EDIT!


#ifndef CONTROL_PKG_MESSAGE_SERVO_CONTROL_H
#define CONTROL_PKG_MESSAGE_SERVO_CONTROL_H

#include <ros/service_traits.h>


#include <control_pkg/servo_controlRequest.h>
#include <control_pkg/servo_controlResponse.h>


namespace control_pkg
{

struct servo_control
{

typedef servo_controlRequest Request;
typedef servo_controlResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct servo_control
} // namespace control_pkg


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::control_pkg::servo_control > {
  static const char* value()
  {
    return "e95109d072a249ed2c81c45a1a6b292a";
  }

  static const char* value(const ::control_pkg::servo_control&) { return value(); }
};

template<>
struct DataType< ::control_pkg::servo_control > {
  static const char* value()
  {
    return "control_pkg/servo_control";
  }

  static const char* value(const ::control_pkg::servo_control&) { return value(); }
};


// service_traits::MD5Sum< ::control_pkg::servo_controlRequest> should match
// service_traits::MD5Sum< ::control_pkg::servo_control >
template<>
struct MD5Sum< ::control_pkg::servo_controlRequest>
{
  static const char* value()
  {
    return MD5Sum< ::control_pkg::servo_control >::value();
  }
  static const char* value(const ::control_pkg::servo_controlRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::control_pkg::servo_controlRequest> should match
// service_traits::DataType< ::control_pkg::servo_control >
template<>
struct DataType< ::control_pkg::servo_controlRequest>
{
  static const char* value()
  {
    return DataType< ::control_pkg::servo_control >::value();
  }
  static const char* value(const ::control_pkg::servo_controlRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::control_pkg::servo_controlResponse> should match
// service_traits::MD5Sum< ::control_pkg::servo_control >
template<>
struct MD5Sum< ::control_pkg::servo_controlResponse>
{
  static const char* value()
  {
    return MD5Sum< ::control_pkg::servo_control >::value();
  }
  static const char* value(const ::control_pkg::servo_controlResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::control_pkg::servo_controlResponse> should match
// service_traits::DataType< ::control_pkg::servo_control >
template<>
struct DataType< ::control_pkg::servo_controlResponse>
{
  static const char* value()
  {
    return DataType< ::control_pkg::servo_control >::value();
  }
  static const char* value(const ::control_pkg::servo_controlResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // CONTROL_PKG_MESSAGE_SERVO_CONTROL_H
