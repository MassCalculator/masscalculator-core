project(MassCalculator)

###########
## Build ##
###########

find_package(Lua51 REQUIRED)
find_package(DXFLib PATHS 3rdParty/CMakeModules/)

include_directories(
  include/
  3rdParty/include/
  helper_classes
  ${LUA51_INCLUDE_DIR}
  ${DXFLib_INCLUDE_DIRS}
)

# Sources
set( SRC
  src/shapes/shape.cpp
  src/shapes/dxf_shape.cpp
  src/shapes/cylinder.cpp

  src/materials/material.cpp
  src/materials/aluminium.cpp
  
  src/interface/object_interface.cpp

  helper_classes/lua_handler.cpp
)

# set libto build itself
add_library(
  ${PROJECT_NAME} STATIC
  ${SRC}
)

target_include_directories( ${PROJECT_NAME}
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/MassCalculator/>
         $<INSTALL_INTERFACE:include/MassCalculator/>
)

target_include_directories( ${PROJECT_NAME}
  SYSTEM
  PUBLIC ${EIGEN3_INCLUDE_DIR}
)

target_link_libraries( ${PROJECT_NAME}
  ${LUA51_LIBRARIES}
  ${DXFLib_LIBRARIES}
)

##############
## EXAMPLES ##
##############

add_subdirectory(examples)

#############
## TESTING ##
#############

add_subdirectory(test)

#############
## Install ##
#############

# to be discussed, we want to expose data types only!
install(
  TARGETS ${PROJECT_NAME} EXPORT MassCalculator-config
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  INCLUDES DESTINATION include
)

## install headers
install(
  DIRECTORY include/
  DESTINATION include/MassCalculator/
  PATTERN "CMakeLists.txt" EXCLUDE
)

###############
## Packaging ##
###############
#

install(
 EXPORT ${PROJECT_NAME}-config
 DESTINATION share/cmake/${PROJECT_NAME}
)
