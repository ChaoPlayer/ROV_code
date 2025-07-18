# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "rov_start_pkg: 1 messages, 0 services")

set(MSG_I_FLAGS "-Irov_start_pkg:/home/chao/ROV_code/src/rov_start_pkg/msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(rov_start_pkg_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/chao/ROV_code/src/rov_start_pkg/msg/init_msg.msg" NAME_WE)
add_custom_target(_rov_start_pkg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rov_start_pkg" "/home/chao/ROV_code/src/rov_start_pkg/msg/init_msg.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(rov_start_pkg
  "/home/chao/ROV_code/src/rov_start_pkg/msg/init_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rov_start_pkg
)

### Generating Services

### Generating Module File
_generate_module_cpp(rov_start_pkg
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rov_start_pkg
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(rov_start_pkg_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(rov_start_pkg_generate_messages rov_start_pkg_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chao/ROV_code/src/rov_start_pkg/msg/init_msg.msg" NAME_WE)
add_dependencies(rov_start_pkg_generate_messages_cpp _rov_start_pkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rov_start_pkg_gencpp)
add_dependencies(rov_start_pkg_gencpp rov_start_pkg_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rov_start_pkg_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(rov_start_pkg
  "/home/chao/ROV_code/src/rov_start_pkg/msg/init_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rov_start_pkg
)

### Generating Services

### Generating Module File
_generate_module_eus(rov_start_pkg
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rov_start_pkg
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(rov_start_pkg_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(rov_start_pkg_generate_messages rov_start_pkg_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chao/ROV_code/src/rov_start_pkg/msg/init_msg.msg" NAME_WE)
add_dependencies(rov_start_pkg_generate_messages_eus _rov_start_pkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rov_start_pkg_geneus)
add_dependencies(rov_start_pkg_geneus rov_start_pkg_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rov_start_pkg_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(rov_start_pkg
  "/home/chao/ROV_code/src/rov_start_pkg/msg/init_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rov_start_pkg
)

### Generating Services

### Generating Module File
_generate_module_lisp(rov_start_pkg
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rov_start_pkg
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(rov_start_pkg_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(rov_start_pkg_generate_messages rov_start_pkg_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chao/ROV_code/src/rov_start_pkg/msg/init_msg.msg" NAME_WE)
add_dependencies(rov_start_pkg_generate_messages_lisp _rov_start_pkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rov_start_pkg_genlisp)
add_dependencies(rov_start_pkg_genlisp rov_start_pkg_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rov_start_pkg_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(rov_start_pkg
  "/home/chao/ROV_code/src/rov_start_pkg/msg/init_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rov_start_pkg
)

### Generating Services

### Generating Module File
_generate_module_nodejs(rov_start_pkg
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rov_start_pkg
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(rov_start_pkg_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(rov_start_pkg_generate_messages rov_start_pkg_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chao/ROV_code/src/rov_start_pkg/msg/init_msg.msg" NAME_WE)
add_dependencies(rov_start_pkg_generate_messages_nodejs _rov_start_pkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rov_start_pkg_gennodejs)
add_dependencies(rov_start_pkg_gennodejs rov_start_pkg_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rov_start_pkg_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(rov_start_pkg
  "/home/chao/ROV_code/src/rov_start_pkg/msg/init_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rov_start_pkg
)

### Generating Services

### Generating Module File
_generate_module_py(rov_start_pkg
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rov_start_pkg
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(rov_start_pkg_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(rov_start_pkg_generate_messages rov_start_pkg_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chao/ROV_code/src/rov_start_pkg/msg/init_msg.msg" NAME_WE)
add_dependencies(rov_start_pkg_generate_messages_py _rov_start_pkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rov_start_pkg_genpy)
add_dependencies(rov_start_pkg_genpy rov_start_pkg_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rov_start_pkg_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rov_start_pkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rov_start_pkg
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(rov_start_pkg_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rov_start_pkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rov_start_pkg
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(rov_start_pkg_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rov_start_pkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rov_start_pkg
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(rov_start_pkg_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rov_start_pkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rov_start_pkg
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(rov_start_pkg_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rov_start_pkg)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rov_start_pkg\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rov_start_pkg
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(rov_start_pkg_generate_messages_py std_msgs_generate_messages_py)
endif()
