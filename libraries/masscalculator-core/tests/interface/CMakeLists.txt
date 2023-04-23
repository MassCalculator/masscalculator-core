# Test for ObjectInterface

include(GoogleTest)

add_executable(object_interface_test
  object_interface_test.cc
)

target_link_libraries(object_interface_test
  PUBLIC
    gtest::gtest
  PRIVATE
    ${PROJECT_NAME}
    masscalculator::masscalculator-base
    masscalculator::third_party::units
    pthread
)

gtest_add_tests(TARGET      object_interface_test
                TEST_SUFFIX .noArgs
                TEST_LIST   noArgsTests
)
