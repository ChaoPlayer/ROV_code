#include<ros/ros.h>
#include<std_msgs/String.h>
#include<std_msgs/Bool.h>
#include<std_msgs/Float32.h>
#include<std_msgs/Int32.h>

#include<mavros_msgs/State.h>
#include<mavros_msgs/SetMode.h>
#include<mavros_msgs/ManualControl.h>
#include<mavros_msgs/OverrideRCIn.h>
#include<mavros_msgs/RCIn.h>
#include<mavros_msgs/RCOut.h>
#include<mavros_msgs/BatteryStatus.h>
#include<mavros_msgs/Altitude.h>

#include<sensor_msgs/Imu.h>
#include<sensor_msgs/NavSatFix.h>
#include<geometry_msgs/TwistStamped.h>
#include<geometry_msgs/PoseStamped.h>
#include<nav_msgs/Odometry.h>

#include<sensor_msgs/Joy.h>

#include<libserial/SerialPort.h>
#include<libserial/SerialStream.h>

#include<map>
#include<string>
#include<thread>
#include<termios.h>
#include<unistd.h>
#include<fcntl.h>
