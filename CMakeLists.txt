cmake_minimum_required(VERSION 3.15)

################################################################################
#
# Project definition
#
################################################################################

# Define the project
project(masscalculator-core
        VERSION 0.2.0
        HOMEPAGE_URL "https://github.com/MassCalculator/masscalculator-core"
        DESCRIPTION "masscalculator-core library"
        LANGUAGES CXX
)

# Set C and C++ standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(BUILD_TESTS ON)
  set(BUILD_EXAMPLES ON)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
  set(BUILD_TESTS ON)
  # set(BUILD_RELEASE ON)
endif()

# Set the project version.
set(MASSCALCULATOR_CORE_NAME ${PROJECT_NAME})
set(MASSCALCULATOR_CORE_VERSION ${PROJECT_VERSION})
set(MASSCALCULATOR_CORE_MAJOR ${PROJECT_VERSION_MAJOR})
set(MASSCALCULATOR_CORE_MINOR ${PROJECT_VERSION_MINOR})
set(MASSCALCULATOR_CORE_PATCH ${PROJECT_VERSION_PATCH})

# Set the MassCalculator core source directory.
set(MASSCALCULATOR_SOURCE ${PROJECT_SOURCE_DIR})

# Set the MassCalculator core home directory.
set(MASSCALCULATOR_HOME "$ENV{HOME}/.masscalculator")

################################################################################
#
# Additional CMake functionalities
#
################################################################################

# Additional CMake modules are added here to allow finding libraries not
# natively supported by CMake and to be able to include CMake files
# uder third_party/ redirectly.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
  "${CMAKE_SOURCE_DIR}/cmake"
  "${CMAKE_SOURCE_DIR}/cmake/modules"
  "${CMAKE_SOURCE_DIR}/third_party"
)

# Initialize the package manager.
include(conan)

# Search for all third party dependencies
include(third_party)

# This adds the packaging steps.
include(test-ctest)

################################################################################
#
# CMake targets definition
#
################################################################################

if(${BUILD_DOCS})
  # This adds the doxygen documentation.
  add_subdirectory(docs)
endif()

# This adds the libraries.
add_subdirectory(libraries)

if (${BUILD_EXAMPLES})
  # This adds the examples executables.
  add_subdirectory(examples)
endif()

# This adds the compile flags.
target_compile_options(${PROJECT_NAME} PRIVATE -O2 -Wall -Wextra -Werror)

# This adds the linker flags.
target_link_options(${PROJECT_NAME} PRIVATE -flto)

################################################################################
#
# Installation and Deployment
#
################################################################################

include(install)

# This adds the packaging steps.
# @todo(jimmyhalimi): Commented out for now, until time comes to fix this.
# include(pack-cpack)

if(${BUILD_RELEASE})
  # @todo(jimmyhalimi): Commented out for now, until time comes to fix this.
  # This adds the deployment steps.
  # include(deploy)
endif()
