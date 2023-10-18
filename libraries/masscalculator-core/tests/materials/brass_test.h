/**
 * @file brass_test.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Defines unit tests for the Brass class.
 * @version 0.4
 * @date 2023-10-18
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
#ifndef MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_TESTS_MATERIALS_BRASS_TEST_H_
#define MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_TESTS_MATERIALS_BRASS_TEST_H_
#include <gtest/gtest.h> // for ::testing::Test and TEST_F

#include <memory> // for std::unique_ptr

#include "masscalculator/masscalculator-core/materials/brass.h" // for Brass
#include "masscalculator/masscalculator-core/materials/constants/brass.h" // for brass::k*

/**
 * @brief MassCalculator Test Core Test Materials Test namespace
 */
namespace masscalculator_test::core_test::materials_test {
/**
 * @brief The test fixture for testing class Brass.
 */
class BrassTest : public ::testing::Test {
 protected:
  void SetUp() override {
    b_240Low = std::make_unique<masscalculator::core::materials::Brass>(
        masscalculator::core::materials::constants::brass::k240Low);

    b_260Cartridge = std::make_unique<masscalculator::core::materials::Brass>(
        masscalculator::core::materials::constants::brass::k260Cartridge);

    b_353Leaded = std::make_unique<masscalculator::core::materials::Brass>(
        masscalculator::core::materials::constants::brass::k353Leaded);

    b_360 = std::make_unique<masscalculator::core::materials::Brass>(
        masscalculator::core::materials::constants::brass::k360);

    b_365 = std::make_unique<masscalculator::core::materials::Brass>(
        masscalculator::core::materials::constants::brass::k365);

    b_380 = std::make_unique<masscalculator::core::materials::Brass>(
        masscalculator::core::materials::constants::brass::k380);

    b_385 = std::make_unique<masscalculator::core::materials::Brass>(
        masscalculator::core::materials::constants::brass::k385);

    b_464 = std::make_unique<masscalculator::core::materials::Brass>(
        masscalculator::core::materials::constants::brass::k464);
  }

  void TearDown() override {
    b_240Low.reset();
    b_260Cartridge.reset();
    b_353Leaded.reset();
    b_360.reset();
    b_365.reset();
    b_380.reset();
    b_385.reset();
    b_464.reset();
  }

  /**
   * @brief Construct a new BrassTest object
   */
  BrassTest() = default;

  /**
   * @brief Destroy the BrassTest object
   */
  ~BrassTest() override = default;

  /**
   * @brief Member objects for class Brass for each Brass type
   */
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::Brass>>
      b_240Low;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::Brass>>
      b_260Cartridge;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::Brass>>
      b_353Leaded;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::Brass>>
      b_360;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::Brass>>
      b_365;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::Brass>>
      b_380;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::Brass>>
      b_385;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::Brass>>
      b_464;
};
} // namespace masscalculator_test::core_test::materials_test
#endif // MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_TESTS_MATERIALS_BRASS_TEST_H_
