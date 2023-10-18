cmake_minimum_required(VERSION 3.15)

project(masscalculator-core)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(MASSCALCULATOR_RESOURCES_PATH "${MASSCALCULATOR_HOME}/resources/")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
  set(MASSCALCULATOR_RESOURCES_PATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/masscalculator/resources/")
endif()

configure_file(config/resources.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/include/masscalculator/${PROJECT_NAME}/resources.h)

file(
  COPY resources
  DESTINATION ${MASSCALCULATOR_HOME}
)

add_library(${PROJECT_NAME} SHARED
  src/interface/object_interface.cc
  src/materials/alloy_coppers.cc
  src/materials/alloy_steels.cc
  src/materials/aluminium.cc
  src/materials/brass.cc
  src/materials/material.cc
  src/shapes/cylinder.cc
  src/shapes/shape.cc
)

add_library(masscalculator::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(${PROJECT_NAME} 
  PUBLIC
    masscalculator::masscalculator-base
    masscalculator::third_party::units
)

if(${BUILD_TESTS})
  add_subdirectory(tests)
endif()
