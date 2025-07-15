cmake_minimum_required(VERSION 3.0.2)
project(rov_start_pkg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)
find_package(serial REQUIRED)
find_package(OpenCV REQUIRED)
set(Opencv_INCLUDE_DIRS "usr/include/opencv4")

add_message_files(FILES init_msg.msg)
generate_messages(DEPENDENCIES std_msgs)

catkin_package(
  INCLUDE_DIRS include 
  LIBRARIES rov_start_pkg
  CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
  DEPENDS serial
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  /usr/include/opencv4
)

add_executable(rov_init_node src/rov_init_node.cpp)
add_executable(servo_init_node src/servo_init_node.cpp)
add_executable(camera_init_node src/camera_init_node.cpp)

target_link_libraries(rov_init_node ${catkin_LIBRARIES})
target_link_libraries(servo_init_node ${catkin_LIBRARIES} serial)
target_link_libraries(camera_init_node ${catkin_LIBRARIES} ${OpenCV_LIBS})