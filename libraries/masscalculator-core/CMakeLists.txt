cmake_minimum_required(VERSION 3.15)

project(masscalculator-core)

add_library(${PROJECT_NAME} SHARED 
  src/materials/material.cc
  # src/materials/alloy_coppers.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../third_party/units>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
  #  ${CMAKE_CURRENT_SOURCE_DIR}/third_party/include
  #  ${CMAKE_CURRENT_SOURCE_DIR}/helper_classes
  #  ${CMAKE_CURRENT_SOURCE_DIR}/helper_functions
)

# message(${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} 
  # PUBLIC
    # third_party::Units
  # google-test
  # PRIVATE
  # core
)

if(${BUILD_TESTS})
  add_subdirectory(tests)
endif()