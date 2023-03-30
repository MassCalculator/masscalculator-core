cmake_minimum_required(VERSION 3.15)

project(lua-handler)

find_package(GTest 1.8 REQUIRED)
find_package(Lua51 REQUIRED)

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
