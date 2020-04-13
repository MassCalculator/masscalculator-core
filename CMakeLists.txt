cmake_minimum_required(VERSION 3.10...3.15)
project(MassCalculator
        VERSION 0.1
        DESCRIPTION "MassCalculator base library"
        LANGUAGES CXX
)

###########
## Build ##
###########

find_package(GTest REQUIRED >= 1.8)
find_package(Lua51 REQUIRED)
find_package(DXFLib PATHS cmake_modules)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS 
  "-O2 \
  -pthread \
  -pedantic \
  -Wall \
  -Wextra \
  -Wcast-align \
  -Wcast-qual \
  -Wctor-dtor-privacy \
  -Wdisabled-optimization \
  -Wformat=2 \
  -Winit-self \
  -Wlogical-op \
  -Wmissing-declarations \
  -Wnoexcept \
  -Wold-style-cast \
  -Woverloaded-virtual \
  -Wredundant-decls \
  -Wshadow \
  -Wsign-conversion \
  -Wsign-promo \
  -Wstrict-null-sentinel \
  -Wstrict-overflow=5 \
  -Wswitch-default \
  -Wundef \
  -Werror \
  -Wno-unused"
)

include_directories(
  include/
  3rdParty/include/
  helper_classes/
  helper_functions/
  ${LUA_INCLUDE_DIR}
  ${DXFLib_INCLUDE_DIRS}
)

# Sources
set( material_src
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

set( shape_src
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

set( interface_src
  src/interface/object_interface.cpp
)

set ( helper_classes_src
  helper_classes/lua_handler.cpp
)

set ( helper_functions_src
  helper_functions/helper_functions.cpp
)

set( SRC
  ${shape_src}
  ${material_src}
  ${interface_src}
  ${helper_classes_src}
  ${helper_functions_src}
)

# set libto build itself
add_library(
  ${PROJECT_NAME} STATIC
  ${SRC}
)

target_include_directories( ${PROJECT_NAME}
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/MassCalculator/>
         $<INSTALL_INTERFACE:include/MassCalculator/>
)

# target_include_directories( ${PROJECT_NAME}
#   SYSTEM
#   PUBLIC ${EIGEN3_INCLUDE_DIR}
# )

target_link_libraries( ${PROJECT_NAME}
  ${LUA_LIBRARIES}
  ${DXFLib_LIBRARIES}
)

#############
## TESTING ##
#############

add_subdirectory(test)

#############
## Install ##
#############

# to be discussed, we want to expose data types only!
install(
  TARGETS ${PROJECT_NAME} EXPORT MassCalculator-config
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  INCLUDES DESTINATION include
)

## install headers
install(
  DIRECTORY include/
  DESTINATION include/MassCalculator/libmasscalculator
  PATTERN "CMakeLists.txt" EXCLUDE
)

###############
## Packaging ##
###############
#

install(
 EXPORT ${PROJECT_NAME}-config
 DESTINATION share/cmake/${PROJECT_NAME}
)

# todo: copy resources to .MassCalculator/resources/*