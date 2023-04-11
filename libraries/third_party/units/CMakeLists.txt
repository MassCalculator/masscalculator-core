cmake_minimum_required(VERSION 3.15)

project(units)

add_library(${PROJECT_NAME} INTERFACE)

add_library(MassCalculator::third_party::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} INTERFACE 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)
