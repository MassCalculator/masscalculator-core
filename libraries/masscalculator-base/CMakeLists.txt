cmake_minimum_required(VERSION 3.15)

project(masscalculator-base)

configure_file(config/software_version.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/include/masscalculator/${PROJECT_NAME}/software_version.h)

add_library(${PROJECT_NAME} SHARED 
  src/lua_handler.cc
)

add_library(masscalculator::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)

target_link_libraries(${PROJECT_NAME} 
  PUBLIC
    lua::lua
  PRIVATE
    masscalculator::masscalculator-base
)

if(${BUILD_TESTS})
  add_subdirectory(tests)
endif()
