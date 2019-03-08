cmake_minimum_required(VERSION 2.8.3)
project(ros_test)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS roscpp geometry_msgs)

catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(hello hello.cpp)
target_link_libraries(hello ${catkin_LIBRARIES})


add_executable(pubvel pubvel.cpp)
target_link_libraries(pubvel ${catkin_LIBRARIES})