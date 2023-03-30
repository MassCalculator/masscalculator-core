cmake_minimum_required(VERSION 3.15)

# Create an INTERFACE library for the header-only library
add_library(units INTERFACE)

# Add the include directory to the library's interface
target_include_directories(units 
  INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

# Set the output name of the library to third_party
set_target_properties(units PROPERTIES OUTPUT_NAME third_party)

# Export the library for use in other CMake projects
export(TARGETS units FILE ${CMAKE_CURRENT_BINARY_DIR}/UnitsTargets.cmake)