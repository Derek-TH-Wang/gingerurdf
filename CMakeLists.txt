cmake_minimum_required(VERSION 2.8.3)

project(gingerurdf)

find_package(catkin REQUIRED roscpp rospy std_msgs  geometry_msgs message_generation)

add_message_files(
   FILES
   HandMsgs.msg
   HeadMsgs.msg
   ArmMsgs.msg
   BodyMsgs.msg
   WheelMsg.msg
)

add_service_files(FILES
  SetZero.srv
)

generate_messages(DEPENDENCIES
  roscpp
  std_msgs
  geometry_msgs
)

catkin_package(
    #INCLUDE_DIRS include
    CATKIN_DEPENDS roscpp rospy std_msgs geometry_msgs message_runtime)

find_package(roslaunch)

foreach(dir config launch meshes urdf)
	install(DIRECTORY ${dir}/
		DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir)


find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
)

include_directories(
  include ${catkin_INCLUDE_DIRS}
)

add_executable(js_filter
  include/gingerurdf/joint_state.h
  src/js_filter.cpp
)
add_dependencies(js_filter ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(js_filter
  ${catkin_LIBRARIES}
)

install(FILES 
    urdf.rviz
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
install(DIRECTORY launch DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
install(DIRECTORY config DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
install(DIRECTORY include DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})
install(DIRECTORY meshes DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
install(DIRECTORY srv DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
install(DIRECTORY urdf DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(TARGETS js_filter
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
