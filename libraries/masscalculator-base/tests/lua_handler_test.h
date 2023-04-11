/**
 * @file lua_handler_test.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Defines unit tests for the LuaScriptHandler class.
 * @version 0.2
 * @date 2023-04-03
 *
 * @copyright Copyright (c) 2023, MassCalculator, Org., All rights reserved.
 * @license This project is released under the  MIT license (MIT).
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_BASE_TESTS_LUA_HANDLER_TEST_H_
#define MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_BASE_TESTS_LUA_HANDLER_TEST_H_
#include <gtest/gtest.h> // for ::testing::Test and TEST_F

#include <memory> // for std::unique_ptr

#include "masscalculator/masscalculator-base/lua_handler.h" // for LuaScriptHandler
#include "masscalculator/masscalculator-base/lua_handler_data.h" // for kTestDataConfigPath

namespace masscalculator::base {

class LuaScriptHandlerTest : public ::testing::Test {
 protected:
  void SetUp() override {
    lua_state = std::make_unique<LuaScriptHandler>(kTestDataConfigPath);
  }

  void TearDown() override { lua_state.reset(); }

  /**
   * @brief Construct a new AlloyCoppersTest object
   */
  LuaScriptHandlerTest() = default;

  /**
   * @brief Destroy the AlloyCoppersTest object
   */
  ~LuaScriptHandlerTest() override = default;

  /**
   * @brief Member objects for class AlloyCopper for each AlloyCopper type
   */
  std::unique_ptr<LuaScriptHandler> lua_state;
};
} // namespace masscalculator::base
#endif // MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_BASE_TESTS_LUA_HANDLER_TEST_H_
