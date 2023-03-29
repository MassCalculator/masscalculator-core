cmake_minimum_required(VERSION 3.15)

project(masscalculator-core
        VERSION 0.1.0
        DESCRIPTION "masscalculator-core library"
        LANGUAGES CXX
)

#################
## Definitions ##
#################

add_compile_definitions(LIBMASSCALCULATOR_NAME=${PROJECT_NAME})
add_compile_definitions(LIBMASSCALCULATOR_MAJOR_VERSION=${PROJECT_VERSION_MAJOR})
add_compile_definitions(LIBMASSCALCULATOR_MINOR_VERSION=${PROJECT_VERSION_MINOR})
add_compile_definitions(LIBMASSCALCULATOR_PATCH_VERSION=${PROJECT_VERSION_PATCH})
add_compile_definitions(LIBMASSCALCULATOR_VERSION=${PROJECT_VERSION})
add_compile_definitions(ROOT_PATH=${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules/)

###########
## Build ##
###########

find_package(GTest 1.8 REQUIRED)
find_package(Lua51 REQUIRED)
find_package(DXFLib)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-pthread") 

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(
  include/
  3rdParty/include/
  helper_classes/
  helper_functions/
  ${LUA_INCLUDE_DIR}
  ${DXFLib_INCLUDE_DIRS}
)

set(material_src
  src/materials/material.cpp
  src/materials/alloy_coppers.cpp
  src/materials/alloy_steels.cpp
  src/materials/aluminium.cpp
  src/materials/brass.cpp
  src/materials/bronz.cpp
  src/materials/copper.cpp
  src/materials/magnesium.cpp
  src/materials/nickel.cpp
  src/materials/plastic.cpp
  src/materials/stainless_steel.cpp
  src/materials/steel.cpp
  src/materials/titanium.cpp
  src/materials/zinc.cpp
)

set(shape_src
  src/shapes/shape.cpp
  src/shapes/angle.cpp
  src/shapes/bar.cpp
  src/shapes/beam.cpp
  src/shapes/channel.cpp
  src/shapes/cylinder.cpp
  src/shapes/dxf_shape.cpp
  src/shapes/elipse.cpp
  src/shapes/hexagon_bar.cpp
  src/shapes/octagon_bar.cpp
  src/shapes/pipe.cpp
  src/shapes/sheet.cpp
  src/shapes/square_bar.cpp
  src/shapes/square_tubing.cpp
  src/shapes/stl_shape.cpp
  src/shapes/t_bar.cpp
)

set(interface_src
  src/interface/object_interface.cpp
)

set(helper_classes_src
  helper_classes/lua_handler.cpp
)

set(helper_functions_src
  helper_functions/helper_functions.cpp
)

set(SRC
  ${shape_src}
  ${material_src}
  ${interface_src}
  ${helper_classes_src}
  ${helper_functions_src}
)

add_library(
  ${PROJECT_NAME} STATIC
  ${SRC}
)

target_compile_options(${PROJECT_NAME}
  PRIVATE -O2 -pedantic -Wall -Wextra -Wcast-align -Wcast-qual
          -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2
          -Winit-self -Wlogical-op -Wmissing-declarations -Wnoexcept
          -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow
          -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel
          -Wstrict-overflow=5 -Wswitch-default -Wundef -Wunused -Werror
          -Wno-variadic-macros
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}>
    $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    ${LUA_LIBRARIES}
    ${DXFLib_LIBRARIES}
  PRIVATE 
    ${CONAN_LIBS}
)

#############
## TESTING ##
#############

enable_testing()

include(CTest)

add_subdirectory(test)

#############
## Install ##
#############

install(
  TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}-config
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  INCLUDES DESTINATION include
)

install(
  DIRECTORY include/
  DESTINATION include/${PROJECT_NAME}/libmasscalculator
  PATTERN "CMakeLists.txt" EXCLUDE
)

install(
 EXPORT ${PROJECT_NAME}-config
 DESTINATION share/cmake/${PROJECT_NAME}
)

install(
  FILES ${CMAKE_SOURCE_DIR}/docs/man/libmasscalculator.1.gz
  DESTINATION share/man/man1 COMPONENT docs
)

install(
  DIRECTORY ${CMAKE_SOURCE_DIR}/resources
  DESTINATION share/masscalculator
)

###############
## Packaging ##
###############

include(CPack)

###############
## Uninstall ##
###############

if(NOT TARGET uninstall)
  configure_file(
      "${CMAKE_MODULE_PATH}/templates/cmake_uninstall.cmake.in"
      "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
      IMMEDIATE @ONLY)

  add_custom_target(uninstall 
    COMMAND ${CMAKE_COMMAND} 
    -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake
  )
endif()
