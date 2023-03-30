cmake_minimum_required(VERSION 3.15)

################################################################################
#
# Project definition
#
################################################################################

# Define the project
project(masscalculator-core
        VERSION 0.1.0
        HOMEPAGE_URL "https://github.com/MassCalculator/masscalculator-core"
        DESCRIPTION "masscalculator-core library"
        LANGUAGES CXX
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(BUILD_TESTS ON)
# set(BUILD_DOCS ON)
# set(BUILD_EXAMPLES ON)
# set(BUILD_RELEASE ON)

# Set the project version.
add_compile_definitions(LIBMASSCALCULATOR_NAME=${PROJECT_NAME})
add_compile_definitions(LIBMASSCALCULATOR_MAJOR_VERSION=${PROJECT_VERSION_MAJOR})
add_compile_definitions(LIBMASSCALCULATOR_MINOR_VERSION=${PROJECT_VERSION_MINOR})
add_compile_definitions(LIBMASSCALCULATOR_PATCH_VERSION=${PROJECT_VERSION_PATCH})
add_compile_definitions(LIBMASSCALCULATOR_VERSION=${PROJECT_VERSION})
add_compile_definitions(ROOT_PATH=${CMAKE_CURRENT_SOURCE_DIR})

################################################################################
#
# Additional CMake functionalities
#
################################################################################

# Additional CMake modules are added here to allow finding libraries not
# natively supported by CMake and to be able to include CMake files
# uder third_party/ redirectly.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
  "${CMAKE_SOURCE_DIR}/cmake/"
  "${CMAKE_SOURCE_DIR}/cmake/modules/"
  "${CMAKE_SOURCE_DIR}/third_party/cmake"
)

# Initialize the package manager.
# @todo(jimmyhalimi): Commented out for now, until time comes to fix this.
# include(conan)
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
  add_subdirectory(docs)
endif()

add_subdirectory(libraries)

# @todo(jimmyhalimi): Check if this can be removed, maybe move units in base.
add_subdirectory(third_party)

if (${BUILD_EXAMPLES})
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

# @todo(jimmyhalimi): Commented out for now, until time comes to fix this.
# include(install)

# This adds the packaging steps.
# @todo(jimmyhalimi): Commented out for now, until time comes to fix this.
# include(pack-cpack)

if(${BUILD_RELEASE})
  include(deploy)
endif()
