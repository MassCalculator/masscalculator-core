cmake_minimum_required(VERSION 3.17)

# Include Conan CMake script
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/release/0.18/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake"
                TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

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
