#It needs to use VERSION 3.13, but due to new laptop used it was not installed
#Also check the minimum version of cmake that allows the project to compile without errors
cmake_minimum_required(VERSION 3.10)
project(MassCalculatorApp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
                      /usr/local/share/cmake
                      /usr/share/cmake)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

#-Wextra -pedantic 
set(CMAKE_CXX_FLAGS "-Wall -O2 -pthread")

#find_package(Eigen3 REQUIRED NO_MODULE)
find_package(GTest REQUIRED >= 1.8)

message(STATUS ${GTEST_INCLUDE_DIRS})
message(STATUS ${GTEST_BOTH_LIBRARIES})

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

# install(
#  EXPORT ${PROJECT_NAME}-config
#  DESTINATION share/cmake/${PROJECT_NAME}
# )
