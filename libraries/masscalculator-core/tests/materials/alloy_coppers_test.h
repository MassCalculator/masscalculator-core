/**
 * @file alloy_coppers_test.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Defines unit tests for the AlloyCoppers class.
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
#ifndef MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_TESTS_MATERIALS_ALLOY_COPPERS_TEST_H_
#define MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_TESTS_MATERIALS_ALLOY_COPPERS_TEST_H_
#include <gtest/gtest.h> // for ::testing::Test and TEST_F

#include <memory> // for std::unique_ptr

#include "masscalculator/masscalculator-core/materials/alloy_coppers.h" // for AlloyCoppers
#include "masscalculator/masscalculator-core/materials/constants/alloy_coppers.h" // for alloycopper::k*

/**
 * @brief Default Materials test namespace
 */
namespace masscalculator_test::materials_test {
/**
 * @brief The test fixture for testing class AlloyCoppers.
 */
class AlloyCoppersTest : public ::testing::Test {
 protected:
  void SetUp() override {
    ac_145_telluirum = std::make_unique<
        masscalculator::core::materials::AlloyCoppers>(
        masscalculator::core::materials::constants::alloycopper::k145Telluirum);

    ac_194_iron =
        std::make_unique<masscalculator::core::materials::AlloyCoppers>(
            masscalculator::core::materials::constants::alloycopper::k194Iron);

    ac_195_iron =
        std::make_unique<masscalculator::core::materials::AlloyCoppers>(
            masscalculator::core::materials::constants::alloycopper::k195Iron);

    ac_172_beryllium = std::make_unique<
        masscalculator::core::materials::AlloyCoppers>(
        masscalculator::core::materials::constants::alloycopper::k172Beryllium);

    ac_182_class2 = std::make_unique<
        masscalculator::core::materials::AlloyCoppers>(
        masscalculator::core::materials::constants::alloycopper::k182Class2);

    ac_655_silicon = std::make_unique<
        masscalculator::core::materials::AlloyCoppers>(
        masscalculator::core::materials::constants::alloycopper::k655Silicon);

    ac_706_nickel = std::make_unique<
        masscalculator::core::materials::AlloyCoppers>(
        masscalculator::core::materials::constants::alloycopper::k706Nickel);

    ac_715_nickel_silver =
        std::make_unique<masscalculator::core::materials::AlloyCoppers>(
            masscalculator::core::materials::constants::alloycopper::
                k715NickelSilver);

    ac_715_nickel_silver =
        std::make_unique<masscalculator::core::materials::AlloyCoppers>(
            masscalculator::core::materials::constants::alloycopper::
                k715NickelSilver);

    ac_725_nickel_silver =
        std::make_unique<masscalculator::core::materials::AlloyCoppers>(
            masscalculator::core::materials::constants::alloycopper::
                k725NickelSilver);

    ac_735_nickel_silver =
        std::make_unique<masscalculator::core::materials::AlloyCoppers>(
            masscalculator::core::materials::constants::alloycopper::
                k735NickelSilver);

    ac_752_nickel_silver =
        std::make_unique<masscalculator::core::materials::AlloyCoppers>(
            masscalculator::core::materials::constants::alloycopper::
                k752NickelSilver);

    ac_762_nickel_silver =
        std::make_unique<masscalculator::core::materials::AlloyCoppers>(
            masscalculator::core::materials::constants::alloycopper::
                k762NickelSilver);

    ac_770_nickel_silver =
        std::make_unique<masscalculator::core::materials::AlloyCoppers>(
            masscalculator::core::materials::constants::alloycopper::
                k770NickelSilver);

    ac_1751_class3 = std::make_unique<
        masscalculator::core::materials::AlloyCoppers>(
        masscalculator::core::materials::constants::alloycopper::k1751Class3);

    ac_1758_nickel = std::make_unique<
        masscalculator::core::materials::AlloyCoppers>(
        masscalculator::core::materials::constants::alloycopper::k1758Nickel);

    ac_moldmax_be_cu = std::make_unique<
        masscalculator::core::materials::AlloyCoppers>(
        masscalculator::core::materials::constants::alloycopper::kMoldmaxBeCu);

    ac_protherm_be_cu = std::make_unique<
        masscalculator::core::materials::AlloyCoppers>(
        masscalculator::core::materials::constants::alloycopper::kProthermBeCu);
  }

  void TearDown() override {
    ac_145_telluirum.reset();
    ac_194_iron.reset();
    ac_195_iron.reset();
    ac_172_beryllium.reset();
    ac_182_class2.reset();
    ac_655_silicon.reset();
    ac_706_nickel.reset();
    ac_715_nickel_silver.reset();
    ac_725_nickel_silver.reset();
    ac_735_nickel_silver.reset();
    ac_752_nickel_silver.reset();
    ac_762_nickel_silver.reset();
    ac_770_nickel_silver.reset();
    ac_1751_class3.reset();
    ac_1758_nickel.reset();
    ac_moldmax_be_cu.reset();
    ac_protherm_be_cu.reset();
  }

  /**
   * @brief Construct a new AlloyCoppersTest object
   */
  AlloyCoppersTest() = default;

  /**
   * @brief Destroy the AlloyCoppersTest object
   */
  ~AlloyCoppersTest() override = default;

  /**
   * @brief Member objects for class AlloyCopper for each AlloyCopper type
   */
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloyCoppers>>
      ac_145_telluirum;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloyCoppers>>
      ac_194_iron;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloyCoppers>>
      ac_195_iron;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloyCoppers>>
      ac_172_beryllium;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloyCoppers>>
      ac_182_class2;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloyCoppers>>
      ac_655_silicon;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloyCoppers>>
      ac_706_nickel;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloyCoppers>>
      ac_715_nickel_silver;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloyCoppers>>
      ac_725_nickel_silver;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloyCoppers>>
      ac_735_nickel_silver;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloyCoppers>>
      ac_752_nickel_silver;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloyCoppers>>
      ac_762_nickel_silver;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloyCoppers>>
      ac_770_nickel_silver;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloyCoppers>>
      ac_1751_class3;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloyCoppers>>
      ac_1758_nickel;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloyCoppers>>
      ac_moldmax_be_cu;
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloyCoppers>>
      ac_protherm_be_cu;
};
} // namespace masscalculator_test::materials_test
#endif // MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_TESTS_MATERIALS_ALLOY_COPPERS_TEST_H_
