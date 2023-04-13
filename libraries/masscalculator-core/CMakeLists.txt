cmake_minimum_required(VERSION 3.15)

project(masscalculator-core)

set(MASSCALCULATOR_RESOURCES_PATH "${MASSCALCULATOR_HOME}/resources/")

configure_file(config/resources.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/include/masscalculator/${PROJECT_NAME}/resources.h)

file(
  COPY resources
  DESTINATION ${MASSCALCULATOR_HOME}
)

add_library(${PROJECT_NAME} SHARED 
  src/interface/object_interface.cc
  src/materials/alloy_coppers.cc
  src/materials/material.cc
  src/shapes/cylinder.cc
  src/shapes/shape.cc
)

target_include_directories(${PROJECT_NAME} PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)

target_link_libraries(${PROJECT_NAME} 
  PRIVATE
    MassCalculator::masscalculator-base
    MassCalculator::third_party::units
)

if(${BUILD_TESTS})
  add_subdirectory(tests)
endif()
