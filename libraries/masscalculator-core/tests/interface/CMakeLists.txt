# Test for ObjectInterface

add_executable(object_interface_test
  object_interface_test.cc
)

target_link_libraries(object_interface_test
  PUBLIC
    ${GTEST_BOTH_LIBRARIES}
  PRIVATE
    ${PROJECT_NAME}
    MassCalculator::masscalculator-base
    MassCalculator::third_party::units
    pthread
)

gtest_add_tests(TARGET      object_interface_test
                TEST_SUFFIX .noArgs
                TEST_LIST   noArgsTests
)
