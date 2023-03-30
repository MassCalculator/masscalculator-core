cmake_minimum_required(VERSION 3.15)

project(lua-handler)

add_library(${PROJECT_NAME} SHARED 
  src/lua_handler.cc
)

target_include_directories(${PROJECT_NAME} PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${LUA_INCLUDE_DIR}>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)

target_link_libraries(${PROJECT_NAME} 
  PUBLIC
    ${LUA_LIBRARIES}
  PRIVATE
    MassCalculator::base
)

if(${BUILD_TESTS})
  add_subdirectory(tests)
endif()
