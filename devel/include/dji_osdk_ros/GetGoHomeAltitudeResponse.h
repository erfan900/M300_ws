// Generated by gencpp from file dji_osdk_ros/GetGoHomeAltitudeResponse.msg
// DO NOT EDIT!


#ifndef DJI_OSDK_ROS_MESSAGE_GETGOHOMEALTITUDERESPONSE_H
#define DJI_OSDK_ROS_MESSAGE_GETGOHOMEALTITUDERESPONSE_H


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
struct GetGoHomeAltitudeResponse_
{
  typedef GetGoHomeAltitudeResponse_<ContainerAllocator> Type;

  GetGoHomeAltitudeResponse_()
    : result(false)
    , altitude(0)  {
    }
  GetGoHomeAltitudeResponse_(const ContainerAllocator& _alloc)
    : result(false)
    , altitude(0)  {
  (void)_alloc;
    }



   typedef uint8_t _result_type;
  _result_type result;

   typedef uint16_t _altitude_type;
  _altitude_type altitude;





  typedef boost::shared_ptr< ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetGoHomeAltitudeResponse_

typedef ::dji_osdk_ros::GetGoHomeAltitudeResponse_<std::allocator<void> > GetGoHomeAltitudeResponse;

typedef boost::shared_ptr< ::dji_osdk_ros::GetGoHomeAltitudeResponse > GetGoHomeAltitudeResponsePtr;
typedef boost::shared_ptr< ::dji_osdk_ros::GetGoHomeAltitudeResponse const> GetGoHomeAltitudeResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator1> & lhs, const ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator2> & rhs)
{
  return lhs.result == rhs.result &&
    lhs.altitude == rhs.altitude;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator1> & lhs, const ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dji_osdk_ros

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "481d1603c31c25eb38ff6abb0129e8bf";
  }

  static const char* value(const ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x481d1603c31c25ebULL;
  static const uint64_t static_value2 = 0x38ff6abb0129e8bfULL;
};

template<class ContainerAllocator>
struct DataType< ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dji_osdk_ros/GetGoHomeAltitudeResponse";
  }

  static const char* value(const ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#response\n"
"bool result\n"
"uint16 altitude\n"
;
  }

  static const char* value(const ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
      stream.next(m.altitude);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetGoHomeAltitudeResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dji_osdk_ros::GetGoHomeAltitudeResponse_<ContainerAllocator>& v)
  {
    s << indent << "result: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.result);
    s << indent << "altitude: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.altitude);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DJI_OSDK_ROS_MESSAGE_GETGOHOMEALTITUDERESPONSE_H