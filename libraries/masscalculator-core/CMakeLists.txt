cmake_minimum_required(VERSION 3.15)

project(masscalculator-core)

add_library(${PROJECT_NAME} SHARED 
  src/materials/alloy_coppers.cc
  src/materials/material.cc
)

target_include_directories(${PROJECT_NAME} PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)

target_link_libraries(${PROJECT_NAME} 
  PRIVATE
    MassCalculator::base
    lua-handler
    third_party::units
)

if(${BUILD_TESTS})
  add_subdirectory(tests)
endif()
