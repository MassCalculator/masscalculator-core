/**
 * @file aluminium_test.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Defines unit tests for the Aluminium class.
 * @version 0.2
 * @date 2023-06-07
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
#ifndef MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_TESTS_MATERIALS_ALUMINIUM_TEST_H_
#define MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_TESTS_MATERIALS_ALUMINIUM_TEST_H_
#include <gtest/gtest.h> // for ::testing::Test and TEST_F

#include <memory> // for std::unique_ptr

#include "masscalculator/masscalculator-core/materials/aluminium.h" // for Aluminium
#include "masscalculator/masscalculator-core/materials/constants/aluminium.h" // for aluminium::k*

/**
 * @brief MassCalculator Test Core Test Materials Test namespace
 */
namespace masscalculator_test::core_test::materials_test {
/**
 * @brief The test fixture for testing class Aluminium.
 */
class AluminiumTest : public ::testing::Test {
 protected:
  void SetUp() override {
    a_1100 = std::make_unique<masscalculator::core::materials::Aluminium>(
        masscalculator::core::materials::constants::aluminium::k1100);

    a_2011 = std::make_unique<masscalculator::core::materials::Aluminium>(
        masscalculator::core::materials::constants::aluminium::k2011);

    a_2014 = std::make_unique<masscalculator::core::materials::Aluminium>(
        masscalculator::core::materials::constants::aluminium::k2014);

    a_2024 = std::make_unique<masscalculator::core::materials::Aluminium>(
        masscalculator::core::materials::constants::aluminium::k2024);

    a_3003 = std::make_unique<masscalculator::core::materials::Aluminium>(
        masscalculator::core::materials::constants::aluminium::k3003);

    a_5052 = std::make_unique<masscalculator::core::materials::Aluminium>(
        masscalculator::core::materials::constants::aluminium::k5052);

    a_6061 = std::make_unique<masscalculator::core::materials::Aluminium>(
        masscalculator::core::materials::constants::aluminium::k6061);

    a_6063 = std::make_unique<masscalculator::core::materials::Aluminium>(
        masscalculator::core::materials::constants::aluminium::k6063);

    a_7075 = std::make_unique<masscalculator::core::materials::Aluminium>(
        masscalculator::core::materials::constants::aluminium::k7075);
  }

  void TearDown() override {
    a_1100.reset();
    a_2011.reset();
    a_2014.reset();
    a_2024.reset();
    a_3003.reset();
    a_5052.reset();
    a_6061.reset();
    a_6063.reset();
    a_7075.reset();
  }

  /**
   * @brief Construct a new AluminiumTest object
   */
  AluminiumTest() = default;

  /**
   * @brief Destroy the AluminiumTest object
   */
  ~AluminiumTest() override = default;

  /**
   * @brief Member objects for class Aluminium for each Aluminium type
   */
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::Aluminium>>
      a_1100;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::Aluminium>>
      a_2011;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::Aluminium>>
      a_2014;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::Aluminium>>
      a_2024;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::Aluminium>>
      a_3003;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::Aluminium>>
      a_5052;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::Aluminium>>
      a_6061;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::Aluminium>>
      a_6063;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::Aluminium>>
      a_7075;
};
} // namespace masscalculator_test::core_test::materials_test
#endif // MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_TESTS_MATERIALS_ALUMINIUM_TEST_H_
