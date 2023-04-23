# Tests for Shapes

include(GoogleTest)

## Cylinder test
add_executable(cylinder_test
  cylinder_test.cc
)

target_link_libraries(cylinder_test
  PUBLIC
    gtest::gtest
  PRIVATE
    ${PROJECT_NAME}
    masscalculator::masscalculator-base
    masscalculator::third_party::units
    pthread
)

gtest_add_tests(TARGET      cylinder_test
                TEST_SUFFIX .noArgs
                TEST_LIST   noArgsTests
)

## SquareBar test
# add_executable(
#   square_bar_test
#   square_bar_test.cpp
# )

# target_link_libraries(
#   square_bar_test
#   gtest::gtest
#   ${PROJECT_NAME}
# )

# add_test(
#   NAME SquareBarTest
#   COMMAND square_bar_test
# )

# #SquareTubing test
# add_executable(
#   square_tubing_test
#   square_tubing_test.cpp
# )

# target_link_libraries(
#   square_tubing_test
#   gtest::gtest
#   ${PROJECT_NAME}
# )

# add_test(
#   NAME SquareTubingTest
#   COMMAND square_tubing_test
# )
