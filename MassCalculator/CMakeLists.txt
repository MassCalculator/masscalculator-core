project(MassCalculator)

###########
## Build ##
###########

message(STATUS ${GTEST_INCLUDE_DIRS})
message(STATUS ${GTEST_BOTH_LIBRARIES})

include_directories(
  3rdParty/include/
  include/
)

# Sources
set(SRC
  src/shapes/shape.cpp
  src/shapes/cylinder.cpp

  src/materials/material.cpp
  src/materials/aluminium.cpp
  
  src/interface/object.cpp
)

# set libto build itself
add_library(
  ${PROJECT_NAME} STATIC
  ${SRC}
)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include/MassCalculator/>
)

target_include_directories(
  ${PROJECT_NAME}
  SYSTEM
  PUBLIC ${EIGEN3_INCLUDE_DIR}
)

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
  DIRECTORY include/MassCalculator
  DESTINATION include/MassCalculator/
  PATTERN "CMakeLists.txt" EXCLUDE
)
