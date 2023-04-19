set(LUA_HANDLER_TEST_DATA_CONFIG "${CMAKE_CURRENT_SOURCE_DIR}/data/lua_handler_test_data.lua")
configure_file(config/lua_handler_data.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/include/masscalculator/${PROJECT_NAME}/lua_handler_data.h)

include(GoogleTest)

add_executable(lua_handler_test
lua_handler_test.cc
)

target_include_directories(lua_handler_test
  PRIVATE 
    ${CMAKE_CURRENT_BINARY_DIR}/include
)

target_link_libraries(lua_handler_test
  PUBLIC
    gtest::gtest
  PRIVATE
    ${PROJECT_NAME}
    masscalculator::masscalculator-base
    masscalculator::third_party::units
    pthread
)

gtest_add_tests(TARGET      lua_handler_test
                TEST_SUFFIX .noArgs
                TEST_LIST   noArgsTests
)

add_test(
  NAME LuaHandler
  COMMAND lua_handler_test
)
