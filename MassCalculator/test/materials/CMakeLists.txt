# Found this on https://cmake.org/cmake/help/v3.0/module/FindGTest.html
# Tests for Materials

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