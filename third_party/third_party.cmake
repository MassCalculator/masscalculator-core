cmake_minimum_required(VERSION 3.15)

# FetchContent is used to clone and configure third_party libraries.
include(FetchContent)

# Third-party dependencies available
if(${BUILD_DOCS})
  include(doxygen)
endif()

if(${BUILD_TESTS})
  include(googletest)
endif()

include(lua51)
