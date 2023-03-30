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

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(third_party)
add_subdirectory(libraries)
