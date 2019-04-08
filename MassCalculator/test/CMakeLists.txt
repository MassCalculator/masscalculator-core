# Found this on https://cmake.org/cmake/help/v3.0/module/FindGTest.html
# Test
add_executable(
  first_test
  cylinder_test.cpp
)

target_link_libraries(
  first_test
  ${GTEST_BOTH_LIBRARIES}
  ${PROJECT_NAME}
)

add_test(
  NAME FirstTest
  COMMAND first_test
)
