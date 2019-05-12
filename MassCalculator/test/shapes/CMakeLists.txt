# Found this on https://cmake.org/cmake/help/v3.0/module/FindGTest.html
# Tests for Shapes
add_executable(
  cylinder_test
  cylinder_test.cpp
)

target_link_libraries(
  cylinder_test
  ${GTEST_BOTH_LIBRARIES}
  ${PROJECT_NAME}
)

add_test(
  NAME CylinderTest
  COMMAND cylinder_test
)
