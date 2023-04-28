# Tests for Materials

include(GoogleTest)

## AlloyCoppers test
add_executable(alloy_coppers_test
  alloy_coppers_test.cc
)

target_link_libraries(alloy_coppers_test
  PUBLIC
    gtest::gtest
  PRIVATE
    masscalculator::masscalculator-base
    masscalculator::${PROJECT_NAME}
    masscalculator::third_party::units
    pthread
)

gtest_add_tests(TARGET      alloy_coppers_test
                TEST_SUFFIX .noArgs
                TEST_LIST   noArgsTests
)

## AlloySteels test
add_executable(alloy_steels_test
  alloy_steels_test.cc
)

target_link_libraries(alloy_steels_test
  PUBLIC
    gtest::gtest
  PRIVATE
    masscalculator::masscalculator-base
    masscalculator::${PROJECT_NAME}
    masscalculator::third_party::units
    pthread
)

gtest_add_tests(TARGET      alloy_steels_test
                TEST_SUFFIX .noArgs
                TEST_LIST   noArgsTests
)

## Aluminium test
# add_executable(aluminium_test
#   aluminium_test.cc
# )

# target_link_libraries(aluminium_test
#   PUBLIC
#     gtest::gtest
#   PRIVATE
#     masscalculator::masscalculator-base
#     masscalculator::${PROJECT_NAME}
#     masscalculator::third_party::units
#     pthread
# )

# gtest_add_tests(TARGET      aluminium_test
#                 TEST_SUFFIX .noArgs
#                 TEST_LIST   noArgsTests
# )

## Brass test
# add_executable(brass_test
#   brass_test.cc
# )

# target_link_libraries(brass_test
#   PUBLIC
#     gtest::gtest
#   PRIVATE
#     masscalculator::masscalculator-base
#     masscalculator::${PROJECT_NAME}
#     masscalculator::third_party::units
#     pthread
# )

# gtest_add_tests(TARGET      brass_test
#                 TEST_SUFFIX .noArgs
#                 TEST_LIST   noArgsTests
# )

## Bronz test
# add_executable(bronz_test
#   bronz_test.cc
# )

# target_link_libraries(bronz_test
#   PUBLIC
#     gtest::gtest
#   PRIVATE
#     masscalculator::masscalculator-base
#     masscalculator::${PROJECT_NAME}
#     masscalculator::third_party::units
#     pthread
# )

# gtest_add_tests(TARGET      bronz_test
#                 TEST_SUFFIX .noArgs
#                 TEST_LIST   noArgsTests
# )

## Copper test
# add_executable(copper_test
#   copper_test.cc
# )

# target_link_libraries(copper_test
#   PUBLIC
#     gtest::gtest
#   PRIVATE
#     masscalculator::masscalculator-base
#     masscalculator::${PROJECT_NAME}
#     masscalculator::third_party::units
#     pthread
# )

# gtest_add_tests(TARGET      copper_test
#                 TEST_SUFFIX .noArgs
#                 TEST_LIST   noArgsTests
# )

## Magnesium test
# add_executable(magnesium_test
#   magnesium_test.cc
# )

# target_link_libraries(magnesium_test
#   PUBLIC
#     gtest::gtest
#   PRIVATE
#     masscalculator::masscalculator-base
#     masscalculator::${PROJECT_NAME}
#     masscalculator::third_party::units
#     pthread
# )

# gtest_add_tests(TARGET      magnesium_test
#                 TEST_SUFFIX .noArgs
#                 TEST_LIST   noArgsTests
# )

## Nickel test
# add_executable(nickel_test
#   nickel_test.cc
# )

# target_link_libraries(nickel_test
#   PUBLIC
#     gtest::gtest
#   PRIVATE
#     masscalculator::masscalculator-base
#     masscalculator::${PROJECT_NAME}
#     masscalculator::third_party::units
#     pthread
# )

# gtest_add_tests(TARGET      nickel_test
#                 TEST_SUFFIX .noArgs
#                 TEST_LIST   noArgsTests
# )

## Plastic test
# add_executable(plastic_test
#   plastic_test.cc
# )

# target_link_libraries(plastic_test
#   PUBLIC
#     gtest::gtest
#   PRIVATE
#     masscalculator::masscalculator-base
#     masscalculator::${PROJECT_NAME}
#     masscalculator::third_party::units
#     pthread
# )

# gtest_add_tests(TARGET      plastic_test
#                 TEST_SUFFIX .noArgs
#                 TEST_LIST   noArgsTests
# )

## StainlessSteel test
# add_executable(stainless_steel_test
#   stainless_steel_test.cc
# )

# target_link_libraries(stainless_steel_test
#   PUBLIC
#     gtest::gtest
#   PRIVATE
#     masscalculator::masscalculator-base
#     masscalculator::${PROJECT_NAME}
#     masscalculator::third_party::units
#     pthread
# )

# gtest_add_tests(TARGET      stainless_steel_test
#                 TEST_SUFFIX .noArgs
#                 TEST_LIST   noArgsTests
# )

## Steel test
# add_executable(steel_test
#   steel_test.cc
# )

# target_link_libraries(steel_test
#   PUBLIC
#     gtest::gtest
#   PRIVATE
#     masscalculator::masscalculator-base
#     masscalculator::${PROJECT_NAME}
#     masscalculator::third_party::units
#     pthread
# )

# gtest_add_tests(TARGET      steel_test
#                 TEST_SUFFIX .noArgs
#                 TEST_LIST   noArgsTests
# )

## Titanium test
# add_executable(titanium_test
#   titanium_test.cc
# )

# target_link_libraries(titanium_test
#   PUBLIC
#     gtest::gtest
#   PRIVATE
#     masscalculator::masscalculator-base
#     masscalculator::${PROJECT_NAME}
#     masscalculator::third_party::units
#     pthread
# )

# gtest_add_tests(TARGET      titanium_test
#                 TEST_SUFFIX .noArgs
#                 TEST_LIST   noArgsTests
# )

## Zinc test
# add_executable(zinc_test
#   zinc_test.cc
# )

# target_link_libraries(zinc_test
#   PUBLIC
#     gtest::gtest
#   PRIVATE
#     masscalculator::masscalculator-base
#     masscalculator::${PROJECT_NAME}
#     masscalculator::third_party::units
#     pthread
# )

# gtest_add_tests(TARGET      zinc_test
#                 TEST_SUFFIX .noArgs
#                 TEST_LIST   noArgsTests
# )

set_tests_properties(${noArgsTests}   PROPERTIES TIMEOUT 10)
set_tests_properties(${withArgsTests} PROPERTIES TIMEOUT 20)
