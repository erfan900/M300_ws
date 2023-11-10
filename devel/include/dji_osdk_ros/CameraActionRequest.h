// Generated by gencpp from file dji_osdk_ros/CameraActionRequest.msg
// DO NOT EDIT!


#ifndef DJI_OSDK_ROS_MESSAGE_CAMERAACTIONREQUEST_H
#define DJI_OSDK_ROS_MESSAGE_CAMERAACTIONREQUEST_H


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
struct CameraActionRequest_
{
  typedef CameraActionRequest_<ContainerAllocator> Type;

  CameraActionRequest_()
    : camera_action(0)  {
    }
  CameraActionRequest_(const ContainerAllocator& _alloc)
    : camera_action(0)  {
  (void)_alloc;
    }



   typedef uint8_t _camera_action_type;
  _camera_action_type camera_action;



// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(CAMERA_ACTION_TAKE_PICTURE)
  #undef CAMERA_ACTION_TAKE_PICTURE
#endif
#if defined(_WIN32) && defined(CAMERA_ACTION_START_RECORD)
  #undef CAMERA_ACTION_START_RECORD
#endif
#if defined(_WIN32) && defined(CAMERA_ACTION_STOP_RECORD)
  #undef CAMERA_ACTION_STOP_RECORD
#endif

  enum {
    CAMERA_ACTION_TAKE_PICTURE = 0u,
    CAMERA_ACTION_START_RECORD = 1u,
    CAMERA_ACTION_STOP_RECORD = 2u,
  };


  typedef boost::shared_ptr< ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator> const> ConstPtr;

}; // struct CameraActionRequest_

typedef ::dji_osdk_ros::CameraActionRequest_<std::allocator<void> > CameraActionRequest;

typedef boost::shared_ptr< ::dji_osdk_ros::CameraActionRequest > CameraActionRequestPtr;
typedef boost::shared_ptr< ::dji_osdk_ros::CameraActionRequest const> CameraActionRequestConstPtr;

// constants requiring out of line definition

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator1> & lhs, const ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator2> & rhs)
{
  return lhs.camera_action == rhs.camera_action;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator1> & lhs, const ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dji_osdk_ros

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7211ed45eec22a2555341dbae4c3b3af";
  }

  static const char* value(const ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7211ed45eec22a25ULL;
  static const uint64_t static_value2 = 0x55341dbae4c3b3afULL;
};

template<class ContainerAllocator>
struct DataType< ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dji_osdk_ros/CameraActionRequest";
  }

  static const char* value(const ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#constant for camera_action\n"
"uint8 CAMERA_ACTION_TAKE_PICTURE = 0\n"
"uint8 CAMERA_ACTION_START_RECORD = 1\n"
"uint8 CAMERA_ACTION_STOP_RECORD  = 2\n"
"\n"
"#request\n"
"uint8 camera_action     # see constants above for possible camera_actions\n"
;
  }

  static const char* value(const ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.camera_action);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CameraActionRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dji_osdk_ros::CameraActionRequest_<ContainerAllocator>& v)
  {
    s << indent << "camera_action: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.camera_action);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DJI_OSDK_ROS_MESSAGE_CAMERAACTIONREQUEST_H