/** @file advanced_sensing_node.cpp
 *  @version 4.0
 *  @date May 2020
 *
 *  @brief sample node of flight control.
 *
 *  @Copyright (c) 2020 DJI
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

//INCLUDE
#include <ros/ros.h>
#include <dji_osdk_ros/common_type.h>

#include <dji_osdk_ros/FlightTaskControl.h>
#include <dji_osdk_ros/SetGoHomeAltitude.h>
#include <dji_osdk_ros/GetGoHomeAltitude.h>
#include <dji_osdk_ros/SetCurrentAircraftLocAsHomePoint.h>
#include <dji_osdk_ros/SetAvoidEnable.h>
#include <dji_osdk_ros/ObtainControlAuthority.h>
#include <dji_osdk_ros/EmergencyBrake.h>
#include <dji_osdk_ros/GetAvoidEnable.h>

#include<dji_osdk_ros/SetJoystickMode.h>
#include<dji_osdk_ros/JoystickAction.h>

#include <dji_osdk_ros/common_type.h>
#include <dji_osdk_ros/GimbalAction.h>
#include <dji_osdk_ros/CameraEV.h>
#include <dji_osdk_ros/CameraShutterSpeed.h>
#include <dji_osdk_ros/CameraAperture.h>
#include <dji_osdk_ros/CameraISO.h>
#include <dji_osdk_ros/CameraFocusPoint.h>
#include <dji_osdk_ros/CameraTapZoomPoint.h>
#include <dji_osdk_ros/CameraSetZoomPara.h>
#include <dji_osdk_ros/CameraZoomCtrl.h>
#include <dji_osdk_ros/CameraStartShootBurstPhoto.h>
#include <dji_osdk_ros/CameraStartShootAEBPhoto.h>
#include <dji_osdk_ros/CameraStartShootSinglePhoto.h>
#include <dji_osdk_ros/CameraStartShootIntervalPhoto.h>
#include <dji_osdk_ros/CameraStopShootPhoto.h>
#include <dji_osdk_ros/CameraRecordVideoAction.h>

// #include <app/single_fire_point_task/SingleFirePointTaskManager.hpp>
#include <sensor_msgs/NavSatFix.h>

#include <geometry_msgs/PointStamped.h>

#include <geometry_msgs/QuaternionStamped.h>


#include <tools/MathLib.hpp>

// #include <dji_sdk_ros/SetLocalPosRef.h>

//CODE
using namespace dji_osdk_ros;

/*
FFDS::APP::SingleFirePointTaskManager::SingleFirePointTaskManager() {



    task_control_client =
            nh.serviceClient<dji_osdk_ros::FlightTaskControl>("/flight_task_control");


    gpsPositionSub =
            nh.subscribe("dji_osdk_ros/gps_position", 10,
                         &SingleFirePointTaskManager::gpsPositionSubCallback, this);
    attitudeSub =
            nh.subscribe("dji_osdk_ros/attitude", 10,
                         &SingleFirePointTaskManager::attitudeSubCallback, this);*/



   // gimbal_control_client = nh.serviceClient<dji_osdk_ros::GimbalAction>("gimbal_task_control");





    // obtain the authorization when really needed... Now :)
   /* obtainCtrlAuthority.request.enable_obtain = true;
    obtain_ctrl_authority_client.call(obtainCtrlAuthority);
    if (obtainCtrlAuthority.response.result) {
        PRINT_INFO("get control authority!");
    } else {
        PRINT_ERROR("can NOT get control authority!");
        return;
    }

    ros::Duration(3.0).sleep();
    //PRINT_INFO("initializing Done");
}
*/

/*FFDS::APP::SingleFirePointTaskManager::~SingleFirePointTaskManager() {
   /* obtainCtrlAuthority.request.enable_obtain = false;
    obtain_ctrl_authority_client.call(obtainCtrlAuthority);
    if (obtainCtrlAuthority.response.result) {
        PRINT_INFO("release control authority!");
    } else {
        PRINT_ERROR("can NOT release control authority!");
    }*/
//}

ros::ServiceClient task_control_client;
ros::ServiceClient set_joystick_mode_client;
ros::ServiceClient joystick_action_client;

bool moveByPosOffset(FlightTaskControl& task,const JoystickCommand &offsetDesired,
                     float posThresholdInM ,
                     float yawThresholdInDeg);

void velocityAndYawRateCtrl(const JoystickCommand &offsetDesired, uint32_t timeMs);

sensor_msgs::NavSatFix gps_position_;

geometry_msgs::PointStamped local_position_;

float euler[3];

void gpsPositionSubCallback2(
        const sensor_msgs::NavSatFix::ConstPtr &gpsPosition) {
    gps_position_ = *gpsPosition;
    ROS_INFO("latitude is [%f]",gps_position_.latitude);
    ROS_INFO("longitude is [%f]",gps_position_.longitude);

}

void QuaternionSubCallback(const geometry_msgs::QuaternionStamped msg)
{


    float quat[4];
    quat[0]= msg.quaternion.x;
    quat[1]= msg.quaternion.y;
    quat[2]= msg.quaternion.z;
    quat[3]= msg.quaternion.w;

    euler[0] = atan2(2.0 * (quat[3] * quat[2] + quat[0] * quat[1]),
                             1.0 - 2.0 * (quat[1] * quat[1] + quat[2] * quat[2]));
    euler[1] = asin(2.0 * (quat[2] * quat[0] - quat[3] * quat[1]));
    euler[2] = atan2(2.0 * (quat[3] * quat[0] + quat[1] * quat[2]),
                     -1.0 + 2.0 * (quat[0] * quat[0] + quat[1] * quat[1]));
euler[0] = euler[0]* 180 / M_PI; // radian to degree
    euler[1] = euler[1]* 180 / M_PI; // radian to degree
    euler[2] = euler[2]* 180 / M_PI; // radian to degree

    // calibration. making frames equal. when drone pointing north, yaw be 0.
    // beware of changes between NED  and ENU
    euler[0] = 90 - euler[0];


    // euler[0] is yaw
}

void LocalPositionSubCallback(
        const geometry_msgs::PointStamped::ConstPtr &LocalPosition) {
    local_position_ = *LocalPosition;

}


/*sensor_msgs::NavSatFix
FFDS::APP::SingleFirePointTaskManager::getHomeGPosAverage(int times) {
    FFDS::TOOLS::PositionHelper posHelper;
    return posHelper.getAverageGPS(times);
}*/

sensor_msgs::NavSatFix getAverageGPS(const int);


float cosd(float angleDegrees) {
    double angleRadians = angleDegrees * (M_PI / 180.0);
    return cos(angleRadians);
}

float sind(float angleDegrees) {
    double angleRadians = angleDegrees * (M_PI / 180.0);
    return sin(angleRadians);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "flight_control_node");
  ros::NodeHandle nh;
  task_control_client = nh.serviceClient<FlightTaskControl>("/flight_task_control");
  auto set_go_home_altitude_client = nh.serviceClient<SetGoHomeAltitude>("/set_go_home_altitude");
  auto get_go_home_altitude_client = nh.serviceClient<GetGoHomeAltitude>("get_go_home_altitude");
  auto set_current_point_as_home_client = nh.serviceClient<SetCurrentAircraftLocAsHomePoint>("/set_current_aircraft_point_as_home");
  auto enable_horizon_avoid_client  = nh.serviceClient<SetAvoidEnable>("/set_horizon_avoid_enable");
  auto enable_upward_avoid_client   = nh.serviceClient<SetAvoidEnable>("/set_upwards_avoid_enable");
  auto get_avoid_enable_client      = nh.serviceClient<GetAvoidEnable>("get_avoid_enable_status");
  auto obtain_ctrl_authority_client = nh.serviceClient<dji_osdk_ros::ObtainControlAuthority>("obtain_release_control_authority");
  auto emergency_brake_client       = nh.serviceClient<dji_osdk_ros::EmergencyBrake>("emergency_brake");

  set_joystick_mode_client = nh.serviceClient<SetJoystickMode>("set_joystick_mode");
  joystick_action_client   = nh.serviceClient<JoystickAction>("joystick_action");

    // Here, you can add the code to set the home position using the /dji_sdk/set_local_pos_ref service
     /*ros::ServiceClient client = nh.serviceClient<dji_osdk_ros::SetLocalPosRef>("/set_local_pos_reference");

    // Wait for the service to become available
    if (!setLocalPosRefClient.waitForExistence(ros::Duration(5.0)))
    {
        ROS_ERROR("Service '/dji_sdk/set_local_pos_ref' not available.");
        return 1;
    }

    // Create the service request
    dji_sdk::SetLocalPosRef srv;

    // Call the service to set the home position
    if (setLocalPosRefClient.call(srv))
    {
        if (srv.response.result)
        {
            ROS_INFO("Home position set successfully.");
        }
        else
        {
            ROS_ERROR("Failed to set home position.");
        }
    }
    else
    {
        ROS_ERROR("Service call failed.");
        return 1;
    }

*/



    auto gimbal_control_client = nh.serviceClient<GimbalAction>("gimbal_task_control");
  auto camera_set_EV_client = nh.serviceClient<CameraEV>("camera_task_set_EV");
  auto camera_set_shutter_speed_client = nh.serviceClient<CameraShutterSpeed>("camera_task_set_shutter_speed");
  auto camera_set_aperture_client = nh.serviceClient<CameraAperture>("camera_task_set_aperture");
  auto camera_set_iso_client = nh.serviceClient<CameraISO>("camera_task_set_ISO");
  auto camera_set_focus_point_client = nh.serviceClient<CameraFocusPoint>("camera_task_set_focus_point");
  auto camera_set_tap_zoom_point_client = nh.serviceClient<CameraTapZoomPoint>("camera_task_tap_zoom_point");
  auto camera_set_zoom_para_client = nh.serviceClient<CameraSetZoomPara>("camera_task_set_zoom_para");
  auto camera_task_zoom_ctrl_client = nh.serviceClient<CameraZoomCtrl>("camera_task_zoom_ctrl");
  auto camera_start_shoot_single_photo_client = nh.serviceClient<CameraStartShootSinglePhoto>(
      "camera_start_shoot_single_photo");
  auto camera_start_shoot_aeb_photo_client = nh.serviceClient<CameraStartShootAEBPhoto>("camera_start_shoot_aeb_photo");
  auto camera_start_shoot_burst_photo_client = nh.serviceClient<CameraStartShootBurstPhoto>(
      "camera_start_shoot_burst_photo");
  auto camera_start_shoot_interval_photo_client = nh.serviceClient<CameraStartShootIntervalPhoto>(
      "camera_start_shoot_interval_photo");
  auto camera_stop_shoot_photo_client = nh.serviceClient<CameraStopShootPhoto>("camera_stop_shoot_photo");
  auto camera_record_video_action_client = nh.serviceClient<CameraRecordVideoAction>("camera_record_video_action");


  
/*

  std::cout << "Please select the estimated orientation of the fire: ";

    std::cout
            << "| Available commands:                                            |"
            << std::endl;
    std::cout
            << "| [a] North                                |"
            << std::endl;
    std::cout
            << "| [b] North-west             |"
            << std::endl;
    std::cout << "| [c] West  |"
              << std::endl;
    std::cout << "| [d] South-West |"
              << std::endl;
    std::cout << "| [e] South |"
              << std::endl;
    std::cout << "| [f] South-East |"
              << std::endl;
    std::cout << "| [g] East |"
              << std::endl;
    std::cout << "| [h] North-East |"
              << std::endl;
*/

float yaw_const;
std::cout<< " plasse enter initial yaw angle in degree-Z axes downward"<<std::endl;
std::cin>>yaw_const;

/*
    char inputChar;
    std::cin >> inputChar;

    switch (inputChar) {
        case 'a':
        {
            break;
        }

        
    }
  */

  EmergencyBrake emergency_brake;
  FlightTaskControl control_task;
  ObtainControlAuthority obtainCtrlAuthority;
  
  obtainCtrlAuthority.request.enable_obtain = true;
  obtain_ctrl_authority_client.call(obtainCtrlAuthority);

    ros::Subscriber gpsPositionSub;
    gpsPositionSub =
            nh.subscribe("dji_osdk_ros/gps_position", 10,
                         gpsPositionSubCallback2);


    ros::Subscriber LocalPositionSub;
    LocalPositionSub =
            nh.subscribe("dji_osdk_ros/local_position", 10,
                         LocalPositionSubCallback);

    ros::Subscriber QuaternionSub;
    QuaternionSub =
            nh.subscribe("dji_osdk_ros/attitude", 10,
                         QuaternionSubCallback);







          sensor_msgs::NavSatFix homeGPos = getAverageGPS(100);
          float homeGPS_posArray[2];
          homeGPS_posArray[0] = homeGPos.latitude;
          homeGPS_posArray[1] = homeGPos.longitude;
          homeGPS_posArray[2] = homeGPos.altitude;

          // FFDS::TOOLS::T a_pos[2];




          control_task.request.task = FlightTaskControl::Request::TASK_TAKEOFF;
          ROS_INFO_STREAM("Takeoff request sending ...");
          task_control_client.call(control_task);
          if(control_task.response.result == false)
          {
              ROS_ERROR_STREAM("Takeoff task failed");
          }

          if(control_task.response.result == true)
          {
              ROS_INFO_STREAM("Takeoff task successful");
              ros::Duration(2.0).sleep();
              moveByPosOffset(control_task, {0, 0, 0, yaw_const}, 1, 3);

              ros::spinOnce();
              ROS_INFO("euler1 is [%f]",euler[0]);
              ROS_INFO("euler2 is [%f]",euler[1]);
              ROS_INFO("euler3 is [%f]",euler[2]);

              ROS_INFO("yaw_const is [%f]",yaw_const);


              GimbalAction gimbalAction;
              gimbalAction.request.is_reset = false;
              gimbalAction.request.payload_index = static_cast<uint8_t>(dji_osdk_ros::PayloadIndex::PAYLOAD_INDEX_0);
              gimbalAction.request.rotationMode = 0;
              gimbalAction.request.pitch = 25.0f;
              gimbalAction.request.roll = 0.0f;
              gimbalAction.request.yaw = 90.0f;
              gimbalAction.request.time = 0.5;
              gimbal_control_client.call(gimbalAction);

              float zz_l = 8;  //zigzag_width
              float zz_w = 4;   //zigzag_length


              ROS_INFO_STREAM("Move by position offset request sending ...");
              moveByPosOffset(control_task, {0, 0, 10, yaw_const}, 1, 3);

              ros::spinOnce();

ROS_INFO("destination y is [%f] and x is [%f]: ",zz_l*sind(yaw_const), zz_l*cosd(yaw_const));

              moveByPosOffset(control_task, {-zz_l*sind(yaw_const), zz_l*cosd(yaw_const), 0, yaw_const}, 1, 3);


              float m[2];

              float current_GPS_posArray[2];
              current_GPS_posArray[0] = gps_position_.latitude;
              current_GPS_posArray[1] = gps_position_.longitude;
              current_GPS_posArray[2] = gps_position_.altitude;

              FFDS::TOOLS::LatLong2Meter(homeGPS_posArray, current_GPS_posArray,m);

              ROS_INFO("x is [%f]",m[0]);
              ROS_INFO("y is [%f]",m[1]);



              /* ROS_INFO("x is [%f]",local_position_.point.x);
               ROS_INFO("y is [%f]",local_position_.point.y);
               ROS_INFO("z is [%f]",local_position_.point.z);*/
              //ROS_INFO("latitude is [%f]",gps_position_.latitude);
              //ROS_INFO("longitude is [%f]",gps_position_.longitude);
              //ros::spin(); //here is good?
              ROS_INFO_STREAM("Step 1 over!");


                      moveByPosOffset(control_task, {zz_w*cosd(yaw_const), zz_w*sind(yaw_const), 0, yaw_const}, 1, 3);
              ros::spinOnce();




              current_GPS_posArray[0] = gps_position_.latitude;
              current_GPS_posArray[1] = gps_position_.longitude;
              current_GPS_posArray[2] = gps_position_.altitude;

              FFDS::TOOLS::LatLong2Meter(homeGPS_posArray, current_GPS_posArray,m);

              ROS_INFO("x is [%f]",m[0]);
              ROS_INFO("y is [%f]",m[1]);

              ROS_INFO_STREAM("Step 2 over!");
                      moveByPosOffset(control_task, {zz_l*sind(yaw_const), -zz_l*cosd(yaw_const), 0.0, yaw_const}, 0.8, 3);
                      ROS_INFO_STREAM("Step 3 over!");
              moveByPosOffset(control_task, {zz_w*cosd(yaw_const), zz_w*sind(yaw_const), 0.0, yaw_const}, 1, 3);
              moveByPosOffset(control_task, {-zz_l*sind(yaw_const), zz_l*cosd(yaw_const), 0.0, yaw_const}, 1, 3);
              moveByPosOffset(control_task, {zz_w*cosd(yaw_const), zz_w*sind(yaw_const), 0.0, yaw_const}, 1, 3);
              moveByPosOffset(control_task, {-3*sind(yaw_const), static_cast<DJI::OSDK::float32_t>(-6.5*cosd(yaw_const)), 0.0, yaw_const}, 1, 3);

// the more generous you are in threshold, the more agile your drone would be       

float abs_vel = 5; // absolute velocity that needs to be projected


              velocityAndYawRateCtrl( {abs_vel*cosd(yaw_const), abs_vel*sind(yaw_const), 0, 0}, 3000);
                      ROS_INFO_STREAM("Step 1 over!EmergencyBrake for 2s\n");
                      emergency_brake_client.call(emergency_brake);
                      ros::Duration(2).sleep();



              PRINT_INFO("going home now");
              control_task.request.task =
                      dji_osdk_ros::FlightTaskControl::Request::TASK_GOHOME;
              task_control_client.call(control_task);
              if (control_task.response.result == true) {
                  PRINT_INFO("go home successful");
              } else {
                  PRINT_WARN("go home failed.");
              }

              control_task.request.task =
                      dji_osdk_ros::FlightTaskControl::Request::TASK_LAND;
              PRINT_INFO(
                      "Landing request sending ... need your confirmation on the remoter!");
              task_control_client.call(control_task);
              if (control_task.response.result == true) {
                  PRINT_INFO("land task successful");
              } else {
                  PRINT_ERROR("land task failed.");
              }



          }









  ROS_INFO_STREAM("Finished. Press CTRL-C to terminate the node");

  ros::spin();
  return 0;
}



bool moveByPosOffset(FlightTaskControl& task,const JoystickCommand &offsetDesired,
                    float posThresholdInM,
                    float yawThresholdInDeg)
{
  task.request.task = FlightTaskControl::Request::TASK_POSITION_AND_YAW_CONTROL;
  task.request.joystickCommand.x = offsetDesired.x;
  task.request.joystickCommand.y = offsetDesired.y;
  task.request.joystickCommand.z = offsetDesired.z;
  task.request.joystickCommand.yaw = offsetDesired.yaw;
  task.request.posThresholdInM   = posThresholdInM;
  task.request.yawThresholdInDeg = yawThresholdInDeg;

  task_control_client.call(task);
  return task.response.result;
}

void velocityAndYawRateCtrl(const JoystickCommand &offsetDesired, uint32_t timeMs)
{
  double originTime  = 0;
  double currentTime = 0;
  uint64_t elapsedTimeInMs = 0;
  
  SetJoystickMode joystickMode;
  JoystickAction joystickAction;

  joystickMode.request.horizontal_mode = joystickMode.request.HORIZONTAL_VELOCITY;
  joystickMode.request.vertical_mode = joystickMode.request.VERTICAL_VELOCITY;
  joystickMode.request.yaw_mode = joystickMode.request.YAW_RATE;
  joystickMode.request.horizontal_coordinate = joystickMode.request.HORIZONTAL_GROUND;
  joystickMode.request.stable_mode = joystickMode.request.STABLE_ENABLE;
  set_joystick_mode_client.call(joystickMode);

  joystickAction.request.joystickCommand.x = offsetDesired.x;
  joystickAction.request.joystickCommand.y = offsetDesired.y;
  joystickAction.request.joystickCommand.z = offsetDesired.z;
  joystickAction.request.joystickCommand.yaw = offsetDesired.yaw;

  originTime  = ros::Time::now().toSec();
  currentTime = originTime;
  elapsedTimeInMs = (currentTime - originTime)*1000;

  while(elapsedTimeInMs <= timeMs)
  {
    currentTime = ros::Time::now().toSec();
    elapsedTimeInMs = (currentTime - originTime) * 1000;
    joystick_action_client.call(joystickAction);
  }
}

static bool isEqual(const double a, const double b) {
    return (fabs(a - b) <= 1e-15);
}

sensor_msgs::NavSatFix getAverageGPS(
        const int average_times) {
    sensor_msgs::NavSatFix homeGPos;

    for (int i = 0; (i < average_times) && ros::ok(); i++) {
        ros::spinOnce();
        if (isEqual(0.0, gps_position_.latitude) ||
            isEqual(0.0, gps_position_.longitude) ||
            isEqual(0.0, gps_position_.altitude)) {
            PRINT_WARN("zero in gps_position, waiting for normal gps position!");
            i = 0;
            continue;
        }
        homeGPos.latitude += gps_position_.latitude;
        homeGPos.longitude += gps_position_.longitude;
        homeGPos.altitude += gps_position_.altitude;

        ros::Rate(10).sleep();
    }
    homeGPos.latitude = homeGPos.latitude / average_times;
    homeGPos.longitude = homeGPos.longitude / average_times;
    homeGPos.altitude = homeGPos.altitude / average_times;

    return homeGPos;
}

