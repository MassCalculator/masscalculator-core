# Found this on https://cmake.org/cmake/help/v3.0/module/FindGTest.html
# Tests for Materials
add_executable(
  aluminium_test
  materials/aluminium_test.cpp
)

target_link_libraries(
  aluminium_test
  ${GTEST_BOTH_LIBRARIES}
  ${PROJECT_NAME}
)

add_test(
  NAME AluminiumTest
  COMMAND aluminium_test
)

# Tests for Shapes
add_executable(
  cylinder_test
  shapes/cylinder_test.cpp
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
