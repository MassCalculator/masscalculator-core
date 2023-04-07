cmake_minimum_required(VERSION 3.15)

project(masscalculator-base)

configure_file(config/software_version.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/include/masscalculator/${PROJECT_NAME}/software_version.h)

add_library(${PROJECT_NAME} INTERFACE)

add_library(MassCalculator::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} INTERFACE 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)

if(${BUILD_TESTS})
  add_subdirectory(tests)
endif()
