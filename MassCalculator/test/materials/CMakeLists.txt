# Found this on https://cmake.org/cmake/help/v3.0/module/FindGTest.html
# Tests for Materials

#AlloyCoppers test
add_executable(
  alloy_coppers_test
  alloy_coppers_test.cpp
)

target_link_libraries(
  alloy_coppers_test
  ${GTEST_BOTH_LIBRARIES}
  ${PROJECT_NAME}
)

add_test(
  NAME AlloyCoppers
  COMMAND alloy_coppers_test
)

#AlloySteels test
add_executable(
  alloy_steels_test
  alloy_steels_test.cpp
)

target_link_libraries(
  alloy_steels_test
  ${GTEST_BOTH_LIBRARIES}
  ${PROJECT_NAME}
)

add_test(
  NAME AlloySteelsTest
  COMMAND alloy_steels_test
)

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

#Brass test
add_executable(
  brass_test
  brass_test.cpp
)

target_link_libraries(
  brass_test
  ${GTEST_BOTH_LIBRARIES}
  ${PROJECT_NAME}
)

add_test(
  NAME BrassTest
  COMMAND brass_test
)

#Bronz test
add_executable(
  bronz_test
  bronz_test.cpp
)

target_link_libraries(
  bronz_test
  ${GTEST_BOTH_LIBRARIES}
  ${PROJECT_NAME}
)

add_test(
  NAME BronzTest
  COMMAND bronz_test
)

#Copper test
add_executable(
  copper_test
  copper_test.cpp
)

target_link_libraries(
  copper_test
  ${GTEST_BOTH_LIBRARIES}
  ${PROJECT_NAME}
)

add_test(
  NAME CopperTest
  COMMAND copper_test
)

#Magnesium test
add_executable(
  magnesium_test
  magnesium_test.cpp
)

target_link_libraries(
  magnesium_test
  ${GTEST_BOTH_LIBRARIES}
  ${PROJECT_NAME}
)

add_test(
  NAME MagnesiumTest
  COMMAND magnesium_test
)

#Nickel test
add_executable(
  nickel_test
  nickel_test.cpp
)

target_link_libraries(
  nickel_test
  ${GTEST_BOTH_LIBRARIES}
  ${PROJECT_NAME}
)

add_test(
  NAME NickelTest
  COMMAND nickel_test
)

#Plastic test
add_executable(
  plastic_test
  plastic_test.cpp
)

target_link_libraries(
  plastic_test
  ${GTEST_BOTH_LIBRARIES}
  ${PROJECT_NAME}
)

add_test(
  NAME PlasticTest
  COMMAND plastic_test
)

#StainlessSteel test
add_executable(
  stainless_steel_test
  stainless_steel_test.cpp
)

target_link_libraries(
  stainless_steel_test
  ${GTEST_BOTH_LIBRARIES}
  ${PROJECT_NAME}
)

add_test(
  NAME StainlessSteelTest
  COMMAND stainless_steel_test
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

#Titanium test
add_executable(
  titanium_test
  titanium_test.cpp
)

target_link_libraries(
  titanium_test
  ${GTEST_BOTH_LIBRARIES}
  ${PROJECT_NAME}
)

add_test(
  NAME TitaniumTest
  COMMAND titanium_test
)

#Zinc test
add_executable(
  zinc_test
  zinc_test.cpp
)

target_link_libraries(
  zinc_test
  ${GTEST_BOTH_LIBRARIES}
  ${PROJECT_NAME}
)

add_test(
  NAME ZincTest
  COMMAND zinc_test
)