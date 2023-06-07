/**
 * @file alloy_steels_test.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Defines unit tests for the AlloySteels class.
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
#ifndef MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_TESTS_MATERIALS_ALLOY_STEELS_TEST_H_
#define MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_TESTS_MATERIALS_ALLOY_STEELS_TEST_H_
#include <gtest/gtest.h> // for ::testing::Test and TEST_F

#include <memory> // for std::unique_ptr

#include "masscalculator/masscalculator-core/materials/alloy_steels.h" // for AlloySteels
#include "masscalculator/masscalculator-core/materials/constants/alloy_steels.h" // for alloysteel::k*

/**
 * @brief MassCalculator Test Core Test Materials Test namespace
 */
namespace masscalculator_test::core_test::materials_test {
/**
 * @brief The test fixture for testing class AlloySteels.
 */
class AlloySteelsTest : public ::testing::Test {
 protected:
  void SetUp() override {
    as_4135 = std::make_unique<masscalculator::core::materials::AlloySteels>(
        masscalculator::core::materials::constants::alloysteel::k4135);

    as_4140 = std::make_unique<masscalculator::core::materials::AlloySteels>(
        masscalculator::core::materials::constants::alloysteel::k4140);

    as_4340 = std::make_unique<masscalculator::core::materials::AlloySteels>(
        masscalculator::core::materials::constants::alloysteel::k4340);
  }

  void TearDown() override {
    as_4135.reset();
    as_4140.reset();
    as_4340.reset();
  }

  /**
   * @brief Construct a new AlloySteelsTest object
   */
  AlloySteelsTest() = default;

  /**
   * @brief Destroy the AlloySteelsTest object
   */
  ~AlloySteelsTest() override = default;

  /**
   * @brief Member objects for class AlloySteels for each AlloySteels type
   */
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloySteels>>
      as_4135;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloySteels>>
      as_4140;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloySteels>>
      as_4340;
};
} // namespace masscalculator_test::core_test::materials_test
#endif // MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_TESTS_MATERIALS_ALLOY_STEELS_TEST_H_
