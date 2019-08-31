# Found this on https://cmake.org/cmake/help/v3.0/module/FindGTest.html
# Tests for Materials

#Aluminium test
add_executable(
  aluminium_test
  aluminium_test.cpp
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

#Steel test
add_executable(
  steel_test
  steel_test.cpp
)

target_link_libraries(
  steel_test
  ${GTEST_BOTH_LIBRARIES}
  ${PROJECT_NAME}
)

add_test(
  NAME SteelTest
  COMMAND steel_test
)