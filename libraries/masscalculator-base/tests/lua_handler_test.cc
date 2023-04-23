/**
 * @file lua_handler_test.cc
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
#include "lua_handler_test.h" // for LuaHandlerTest

#include <gtest/gtest.h> // for ::testing::Test and TEST_F

namespace masscalculator_test::base_test {

namespace {
constexpr auto kFirstLevelKey{"FirstLevel"};
constexpr auto kMissingLevelKey{"Missing"};
constexpr auto kSecondLevelOneKey{"SecondLevelOne"};
constexpr auto kSecondLevelTwoKey{"SecondLevelTwo"};
constexpr auto kSecondLevelThreeKey{"SecondLevelThree"};
constexpr auto kSecondLevelFourKey{"SecondLevelFour"};
constexpr auto kBooleanValueKey{"kBooleanValue"};
constexpr auto kExpectedBooleanValueOne{true};
constexpr auto kExpectedBooleanValueTwo{false};
constexpr auto kStringValueKey{"kStringValue"};
constexpr auto kExpectedStringValueOne{"FromLuaOne"};
constexpr auto kExpectedStringValuetwo{"FromLuaTwo"};
constexpr auto kNumericValueKey{"kNumericValue"};
constexpr auto kExpectedNumericValueOne{1};
constexpr auto kExpectedNumericValueTwo{2.2};
} // namespace

TEST_F(LuaScriptHandlerTest, GetNonExistentKeyTest) {
  const auto string_value{lua_state->GetOrDefault<std::string>(
      std::string(kFirstLevelKey) + "." + std::string(kMissingLevelKey),
      "Default")};

  EXPECT_EQ(string_value, "Default");
}

TEST_F(LuaScriptHandlerTest, GetInvalidTypeTest) {
  const auto boolean_value{lua_state->GetOrDefault<bool>(
      std::string(kFirstLevelKey) + "." + std::string(kSecondLevelOneKey) +
          "." + std::string(kStringValueKey),
      true)};

  EXPECT_EQ(boolean_value, true);
}

TEST_F(LuaScriptHandlerTest, GetInvalidNumericTypeTest) {
  const auto numeric_value{lua_state->GetOrDefault<int>(
      std::string(kFirstLevelKey) + "." + std::string(kSecondLevelOneKey) +
          "." + std::string(kStringValueKey),
      0)};

  EXPECT_EQ(numeric_value, 0);
}

TEST_F(LuaScriptHandlerTest, GetBooleanValueOneTest) {
  const auto boolean_value{lua_state->GetOrDefault<bool>(
      std::string(kFirstLevelKey) + "." + std::string(kSecondLevelOneKey) +
          "." + std::string(kBooleanValueKey),
      false)};

  EXPECT_EQ(boolean_value, kExpectedBooleanValueOne);
}

TEST_F(LuaScriptHandlerTest, GetBooleanValueTwoTest) {
  const auto boolean_value{lua_state->GetOrDefault<bool>(
      std::string(kFirstLevelKey) + "." + std::string(kSecondLevelTwoKey) +
          "." + std::string(kBooleanValueKey),
      true)};

  EXPECT_EQ(boolean_value, kExpectedBooleanValueTwo);
}

TEST_F(LuaScriptHandlerTest, GetBooleanValueThreeTest) {
  const auto boolean_value{lua_state->GetOrDefault<bool>(
      std::string(kFirstLevelKey) + "." + std::string(kSecondLevelThreeKey) +
          "." + std::string(kBooleanValueKey),
      true)};

  EXPECT_EQ(boolean_value, true);
}

TEST_F(LuaScriptHandlerTest, GetBooleanValueFourTest) {
  const auto boolean_value{lua_state->GetOrDefault<bool>(
      std::string(kFirstLevelKey) + "." + std::string(kSecondLevelFourKey) +
          "." + std::string(kBooleanValueKey),
      true)};

  EXPECT_EQ(boolean_value, true);
}

TEST_F(LuaScriptHandlerTest, GetStringValueOneTest) {
  const auto string_value{lua_state->GetOrDefault<std::string>(
      std::string(kFirstLevelKey) + "." + std::string(kSecondLevelOneKey) +
          "." + std::string(kStringValueKey),
      "Default")};

  EXPECT_EQ(string_value, kExpectedStringValueOne);
}

TEST_F(LuaScriptHandlerTest, GetStringValueTwoTest) {
  const auto string_value{lua_state->GetOrDefault<std::string>(
      std::string(kFirstLevelKey) + "." + std::string(kSecondLevelTwoKey) +
          "." + std::string(kStringValueKey),
      "Default")};

  EXPECT_EQ(string_value, kExpectedStringValuetwo);
}

TEST_F(LuaScriptHandlerTest, GetStringValueThreeTest) {
  const auto string_value{lua_state->GetOrDefault<std::string>(
      std::string(kFirstLevelKey) + "." + std::string(kSecondLevelThreeKey) +
          "." + std::string(kStringValueKey),
      "Default")};

  EXPECT_EQ(string_value, "1");
}

TEST_F(LuaScriptHandlerTest, GetStringValueFourTest) {
  const auto string_value{lua_state->GetOrDefault<std::string>(
      std::string(kFirstLevelKey) + "." + std::string(kSecondLevelFourKey) +
          "." + std::string(kStringValueKey),
      "Default")};

  EXPECT_EQ(string_value, "Default");
}

TEST_F(LuaScriptHandlerTest, GetNumericValueOneTest) {
  const auto numeric_value{lua_state->GetOrDefault<int>(
      std::string(kFirstLevelKey) + "." + std::string(kSecondLevelOneKey) +
          "." + std::string(kNumericValueKey),
      0)};

  EXPECT_EQ(numeric_value, kExpectedNumericValueOne);
}

TEST_F(LuaScriptHandlerTest, GetNumericValueTwoTest) {
  const auto numeric_value{lua_state->GetOrDefault<double>(
      std::string(kFirstLevelKey) + "." + std::string(kSecondLevelTwoKey) +
          "." + std::string(kNumericValueKey),
      0.0)};

  EXPECT_EQ(numeric_value, kExpectedNumericValueTwo);
}

TEST_F(LuaScriptHandlerTest, GetNumericValueThreeTest) {
  const auto numeric_value{lua_state->GetOrDefault<int>(
      std::string(kFirstLevelKey) + "." + std::string(kSecondLevelThreeKey) +
          "." + std::string(kNumericValueKey),
      0)};

  EXPECT_EQ(numeric_value, 0);
}

TEST_F(LuaScriptHandlerTest, GetNumericValueFourTest) {
  const auto numeric_value{lua_state->GetOrDefault<double>(
      std::string(kFirstLevelKey) + "." + std::string(kSecondLevelFourKey) +
          "." + std::string(kNumericValueKey),
      0.0)};

  EXPECT_EQ(numeric_value, 0.0);
}

TEST_F(LuaScriptHandlerTest, LuaStateEmptyFilepath) {
  std::unique_ptr<masscalculator::base::LuaScriptHandler> lua_state_no_file =
      std::make_unique<masscalculator::base::LuaScriptHandler>("");

  ASSERT_NE(lua_state_no_file, nullptr);

  const auto numeric_value{lua_state_no_file->GetOrDefault<double>(
      std::string(kFirstLevelKey), 0.0)};
  EXPECT_EQ(numeric_value, 0.0);
}

} // namespace masscalculator_test::base_test

/**
 * @brief Main function to run these tests
 */
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
