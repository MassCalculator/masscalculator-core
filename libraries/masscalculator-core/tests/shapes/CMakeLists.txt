# Tests for Shapes

#Cylinder test
add_executable(cylinder_test
  cylinder_test.cc
)

target_link_libraries(cylinder_test
  PUBLIC
    ${GTEST_BOTH_LIBRARIES}
  PRIVATE
    ${PROJECT_NAME}
    MassCalculator::masscalculator-base
    MassCalculator::third_party::units
    pthread
)

gtest_add_tests(TARGET      cylinder_test
                TEST_SUFFIX .noArgs
                TEST_LIST   noArgsTests
)

# #SquareBar test
# add_executable(
#   square_bar_test
#   square_bar_test.cpp
# )

# target_link_libraries(
#   square_bar_test
#   ${GTEST_BOTH_LIBRARIES}
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
#   ${GTEST_BOTH_LIBRARIES}
#   ${PROJECT_NAME}
# )

# add_test(
#   NAME SquareTubingTest
#   COMMAND square_tubing_test
# )
