/**
 * @file alloy_coppers_test.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class AlloyCoppers, it tests
 * all the functions and the constructors of the class
 * @version 0.3
 * @date 2020-03-26
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_TESTS_MATERIALS_ALLOY_COPPERS_TEST_H_
#define MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_TESTS_MATERIALS_ALLOY_COPPERS_TEST_H_
#include <gtest/gtest.h> // for ::testing::Test and TEST_F

#include "materials/alloy_coppers.h" // for AlloyCoppers

/**
 * @brief Default Materials test namespace
 *
 */
namespace masscalculator_test::materials_test {
/**
 * @brief The test fixture for testing class AlloyCoppers.
 *
 */
class AlloyCoppersTest : public ::testing::Test {
protected:
  /**
   * @brief Construct a new AlloyCoppersTest object
   *
   */
  AlloyCoppersTest() {
    ac_145_tellvirum.SetType(
        masscalculator::materials::AlloyCoppers::Type::AC_145Tellvirum);
    ac_194_iron.SetType(
        masscalculator::materials::AlloyCoppers::Type::AC_194Iron);
    ac_195_iron.SetType(
        masscalculator::materials::AlloyCoppers::Type::AC_195Iron);
    ac_182_class2.SetType(
        masscalculator::materials::AlloyCoppers::Type::AC_182Class2);
    ac_655_silicon.SetType(
        masscalculator::materials::AlloyCoppers::Type::AC_655Silicon);
    ac_706_nickel.SetType(
        masscalculator::materials::AlloyCoppers::Type::AC_706Nickel);
    ac_715_nickel_silver.SetType(
        masscalculator::materials::AlloyCoppers::Type::AC_715NickelSilver);
    ac_725_nickel_silver.SetType(
        masscalculator::materials::AlloyCoppers::Type::AC_725NickelSilver);
    ac_735_nickel_silver.SetType(
        masscalculator::materials::AlloyCoppers::Type::AC_735NickelSilver);
    ac_752_nickel_silver.SetType(
        masscalculator::materials::AlloyCoppers::Type::AC_752NickelSilver);
    ac_762_nickel_silver.SetType(
        masscalculator::materials::AlloyCoppers::Type::AC_762NickelSilver);
    ac_770_nickel_silver.SetType(
        masscalculator::materials::AlloyCoppers::Type::AC_770NickelSilver);
    ac_1751_class3.SetType(
        masscalculator::materials::AlloyCoppers::Type::AC_1751Class3);
    ac_1758_nickel.SetType(
        masscalculator::materials::AlloyCoppers::Type::AC_1758Nickel);
    ac_moldmax_be_cu.SetType(
        masscalculator::materials::AlloyCoppers::Type::AC_MoldmaxBeCu);
    ac_protherm_be_cu.SetType(
        masscalculator::materials::AlloyCoppers::Type::AC_ProthermBeCu);
  }

  /**
   * @brief Destroy the AlloyCoppersTest object
   */
  ~AlloyCoppersTest() override = default;

  /**
   * @brief Member objects for class AlloyCopper for each AlloyCopper type
   *
   */
  masscalculator::materials::AlloyCoppers ac_145_tellvirum, ac_194_iron,
      ac_195_iron, ac_182_class2, ac_655_silicon, ac_706_nickel,
      ac_715_nickel_silver, ac_725_nickel_silver, ac_735_nickel_silver,
      ac_752_nickel_silver, ac_762_nickel_silver, ac_770_nickel_silver,
      ac_1751_class3, ac_1758_nickel, ac_moldmax_be_cu, ac_protherm_be_cu;
};
} // namespace masscalculator_test::materials_test
#endif // MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_TESTS_MATERIALS_ALLOY_COPPERS_TEST_H_
