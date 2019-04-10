# Found this on https://cmake.org/cmake/help/v3.0/module/FindGTest.html
# Test
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
