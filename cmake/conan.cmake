cmake_minimum_required(VERSION 3.17)

# Include Conan CMake script
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/release/0.18/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake"
                TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

find_program(CONAN conan)
if(CONAN)
  execute_process(
    COMMAND ${CONAN} profile list
    OUTPUT_VARIABLE CONAN_PROFILE_LIST
  )

  if("${CONAN_PROFILE_LIST}" MATCHES "default")
    message(STATUS "Using existing default Conan profile")
  else()
    message(STATUS "Creating default Conan profile")
    execute_process(
      COMMAND ${CONAN} profile detect
    )
  endif()
else()
    message(WARNING "Conan not found, skipping profile creation")
endif()

# Set libcxx and compiler settings
conan_cmake_autodetect(settings)
conan_cmake_configure(
  SETTINGS ${settings}
  BUILD missing
)

conan_cmake_install(
  PATH_OR_REFERENCE ${CMAKE_CURRENT_SOURCE_DIR}/conan/conanfile.txt
  SETTINGS ${settings}
  BUILD missing
  OUTPUT_FOLDER ${CMAKE_BINARY_DIR}
)

# Include Conan-generated build information
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)
