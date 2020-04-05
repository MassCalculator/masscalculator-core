# Found this on https://cmake.org/cmake/help/v3.0/module/FindGTest.html
# Tests for ObjectInterface
add_executable(
  object_interface_test
  object_interface_test.cpp
)

target_link_libraries(
  object_interface_test
  ${GTEST_BOTH_LIBRARIES}
  ${PROJECT_NAME}
)

add_test(
  NAME ObjectInterfaceTest
  COMMAND object_interface_test
)