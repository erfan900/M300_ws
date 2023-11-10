// Generated by gencpp from file dji_osdk_ros/GetAvoidEnableResponse.msg
// DO NOT EDIT!


#ifndef DJI_OSDK_ROS_MESSAGE_GETAVOIDENABLERESPONSE_H
#define DJI_OSDK_ROS_MESSAGE_GETAVOIDENABLERESPONSE_H


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
struct GetAvoidEnableResponse_
{
  typedef GetAvoidEnableResponse_<ContainerAllocator> Type;

  GetAvoidEnableResponse_()
    : result(false)
    , horizon_avoid_enable_status(0)
    , upwards_avoid_enable_status(0)  {
    }
  GetAvoidEnableResponse_(const ContainerAllocator& _alloc)
    : result(false)
    , horizon_avoid_enable_status(0)
    , upwards_avoid_enable_status(0)  {
  (void)_alloc;
    }



   typedef uint8_t _result_type;
  _result_type result;

   typedef uint8_t _horizon_avoid_enable_status_type;
  _horizon_avoid_enable_status_type horizon_avoid_enable_status;

   typedef uint8_t _upwards_avoid_enable_status_type;
  _upwards_avoid_enable_status_type upwards_avoid_enable_status;





  typedef boost::shared_ptr< ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetAvoidEnableResponse_

typedef ::dji_osdk_ros::GetAvoidEnableResponse_<std::allocator<void> > GetAvoidEnableResponse;

typedef boost::shared_ptr< ::dji_osdk_ros::GetAvoidEnableResponse > GetAvoidEnableResponsePtr;
typedef boost::shared_ptr< ::dji_osdk_ros::GetAvoidEnableResponse const> GetAvoidEnableResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator1> & lhs, const ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator2> & rhs)
{
  return lhs.result == rhs.result &&
    lhs.horizon_avoid_enable_status == rhs.horizon_avoid_enable_status &&
    lhs.upwards_avoid_enable_status == rhs.upwards_avoid_enable_status;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator1> & lhs, const ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dji_osdk_ros

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "12c68a1a9e8bfbd739c56cc5d4af2738";
  }

  static const char* value(const ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x12c68a1a9e8bfbd7ULL;
  static const uint64_t static_value2 = 0x39c56cc5d4af2738ULL;
};

template<class ContainerAllocator>
struct DataType< ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dji_osdk_ros/GetAvoidEnableResponse";
  }

  static const char* value(const ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#response\n"
"bool result\n"
"uint8 horizon_avoid_enable_status #0:disable 1:enable 0xF:invalid\n"
"uint8 upwards_avoid_enable_status\n"
;
  }

  static const char* value(const ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
      stream.next(m.horizon_avoid_enable_status);
      stream.next(m.upwards_avoid_enable_status);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetAvoidEnableResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dji_osdk_ros::GetAvoidEnableResponse_<ContainerAllocator>& v)
  {
    s << indent << "result: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.result);
    s << indent << "horizon_avoid_enable_status: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.horizon_avoid_enable_status);
    s << indent << "upwards_avoid_enable_status: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.upwards_avoid_enable_status);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DJI_OSDK_ROS_MESSAGE_GETAVOIDENABLERESPONSE_H