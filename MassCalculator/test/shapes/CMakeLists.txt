# Found this on https://cmake.org/cmake/help/v3.0/module/FindGTest.html
# Tests for Shapes

#Cylinder test
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

#SquareBar test
add_executable(
  square_bar_test
  square_bar_test.cpp
)

target_link_libraries(
  square_bar_test
  ${GTEST_BOTH_LIBRARIES}
  ${PROJECT_NAME}
)

add_test(
  NAME SquareBarTest
  COMMAND square_bar_test
)
