// Generated by gencpp from file dji_osdk_ros/MissionWpGetSpeedResponse.msg
// DO NOT EDIT!


#ifndef DJI_OSDK_ROS_MESSAGE_MISSIONWPGETSPEEDRESPONSE_H
#define DJI_OSDK_ROS_MESSAGE_MISSIONWPGETSPEEDRESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace dji_osdk_ros
{
template <class ContainerAllocator>
struct MissionWpGetSpeedResponse_
{
  typedef MissionWpGetSpeedResponse_<ContainerAllocator> Type;

  MissionWpGetSpeedResponse_()
    : speed(0.0)
    , cmd_set(0)
    , cmd_id(0)
    , ack_data(0)  {
    }
  MissionWpGetSpeedResponse_(const ContainerAllocator& _alloc)
    : speed(0.0)
    , cmd_set(0)
    , cmd_id(0)
    , ack_data(0)  {
  (void)_alloc;
    }



   typedef float _speed_type;
  _speed_type speed;

   typedef uint8_t _cmd_set_type;
  _cmd_set_type cmd_set;

   typedef uint8_t _cmd_id_type;
  _cmd_id_type cmd_id;

   typedef uint32_t _ack_data_type;
  _ack_data_type ack_data;





  typedef boost::shared_ptr< ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator> const> ConstPtr;

}; // struct MissionWpGetSpeedResponse_

typedef ::dji_osdk_ros::MissionWpGetSpeedResponse_<std::allocator<void> > MissionWpGetSpeedResponse;

typedef boost::shared_ptr< ::dji_osdk_ros::MissionWpGetSpeedResponse > MissionWpGetSpeedResponsePtr;
typedef boost::shared_ptr< ::dji_osdk_ros::MissionWpGetSpeedResponse const> MissionWpGetSpeedResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator1> & lhs, const ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator2> & rhs)
{
  return lhs.speed == rhs.speed &&
    lhs.cmd_set == rhs.cmd_set &&
    lhs.cmd_id == rhs.cmd_id &&
    lhs.ack_data == rhs.ack_data;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator1> & lhs, const ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dji_osdk_ros

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "24b8cc8834f9763e3d1c641b02dfffb4";
  }

  static const char* value(const ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x24b8cc8834f9763eULL;
  static const uint64_t static_value2 = 0x3d1c641b02dfffb4ULL;
};

template<class ContainerAllocator>
struct DataType< ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dji_osdk_ros/MissionWpGetSpeedResponse";
  }

  static const char* value(const ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 speed\n"
"# for debugging usage\n"
"uint8 cmd_set\n"
"uint8 cmd_id\n"
"uint32 ack_data\n"
;
  }

  static const char* value(const ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.speed);
      stream.next(m.cmd_set);
      stream.next(m.cmd_id);
      stream.next(m.ack_data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MissionWpGetSpeedResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dji_osdk_ros::MissionWpGetSpeedResponse_<ContainerAllocator>& v)
  {
    s << indent << "speed: ";
    Printer<float>::stream(s, indent + "  ", v.speed);
    s << indent << "cmd_set: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.cmd_set);
    s << indent << "cmd_id: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.cmd_id);
    s << indent << "ack_data: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.ack_data);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DJI_OSDK_ROS_MESSAGE_MISSIONWPGETSPEEDRESPONSE_H