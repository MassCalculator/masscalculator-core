cmake_minimum_required(VERSION 3.13)
project(MassCalculatorApp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
                      /usr/local/share/cmake
                      /usr/share/cmake)

set(CMAKE_CXX_STANDARD 17)
#-Wextra
set(CMAKE_CXX_FLAGS "-Wall -O2 -pthread")

# System dependencies
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(glui REQUIRED)

#find_package(Eigen3 REQUIRED NO_MODULE)
find_package(GTest REQUIRED >= 1.8)

include_directories(
  ${OPENGL_INCLUDE_DIRS}
  ${GLUT_INCLUDE_DIRS}
  #${GLUI_INCLUDE_DIRS}

  MassCalculator/include/
  MassCalculatorGUI/include/
)

# Enable testing
enable_testing()

# to include static libraries in shared libraries, they need to be compiled with -fPIC
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Include subproject...

# TODO refactor cmake config to be "modern cmake":
# https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1

add_subdirectory(MassCalculator)
add_subdirectory(MassCalculatorGUI)

###############
## Packaging ##
###############
#

#install(
#  EXPORT ${PROJECT_NAME}-config
#  DESTINATION share/cmake/${PROJECT_NAME}
#)
