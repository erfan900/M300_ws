// Generated by gencpp from file dji_osdk_ros/DroneTaskControl.msg
// DO NOT EDIT!


#ifndef DJI_OSDK_ROS_MESSAGE_DRONETASKCONTROL_H
#define DJI_OSDK_ROS_MESSAGE_DRONETASKCONTROL_H

#include <ros/service_traits.h>


#include <dji_osdk_ros/DroneTaskControlRequest.h>
#include <dji_osdk_ros/DroneTaskControlResponse.h>


namespace dji_osdk_ros
{

struct DroneTaskControl
{

typedef DroneTaskControlRequest Request;
typedef DroneTaskControlResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct DroneTaskControl
} // namespace dji_osdk_ros


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::dji_osdk_ros::DroneTaskControl > {
  static const char* value()
  {
    return "ab91c4042653ca6868c5907bf22e4741";
  }

  static const char* value(const ::dji_osdk_ros::DroneTaskControl&) { return value(); }
};

template<>
struct DataType< ::dji_osdk_ros::DroneTaskControl > {
  static const char* value()
  {
    return "dji_osdk_ros/DroneTaskControl";
  }

  static const char* value(const ::dji_osdk_ros::DroneTaskControl&) { return value(); }
};


// service_traits::MD5Sum< ::dji_osdk_ros::DroneTaskControlRequest> should match
// service_traits::MD5Sum< ::dji_osdk_ros::DroneTaskControl >
template<>
struct MD5Sum< ::dji_osdk_ros::DroneTaskControlRequest>
{
  static const char* value()
  {
    return MD5Sum< ::dji_osdk_ros::DroneTaskControl >::value();
  }
  static const char* value(const ::dji_osdk_ros::DroneTaskControlRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::dji_osdk_ros::DroneTaskControlRequest> should match
// service_traits::DataType< ::dji_osdk_ros::DroneTaskControl >
template<>
struct DataType< ::dji_osdk_ros::DroneTaskControlRequest>
{
  static const char* value()
  {
    return DataType< ::dji_osdk_ros::DroneTaskControl >::value();
  }
  static const char* value(const ::dji_osdk_ros::DroneTaskControlRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::dji_osdk_ros::DroneTaskControlResponse> should match
// service_traits::MD5Sum< ::dji_osdk_ros::DroneTaskControl >
template<>
struct MD5Sum< ::dji_osdk_ros::DroneTaskControlResponse>
{
  static const char* value()
  {
    return MD5Sum< ::dji_osdk_ros::DroneTaskControl >::value();
  }
  static const char* value(const ::dji_osdk_ros::DroneTaskControlResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::dji_osdk_ros::DroneTaskControlResponse> should match
// service_traits::DataType< ::dji_osdk_ros::DroneTaskControl >
template<>
struct DataType< ::dji_osdk_ros::DroneTaskControlResponse>
{
  static const char* value()
  {
    return DataType< ::dji_osdk_ros::DroneTaskControl >::value();
  }
  static const char* value(const ::dji_osdk_ros::DroneTaskControlResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // DJI_OSDK_ROS_MESSAGE_DRONETASKCONTROL_H