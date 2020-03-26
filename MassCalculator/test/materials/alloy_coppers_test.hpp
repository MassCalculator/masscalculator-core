/**
 * @file alloy_coppers_test.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class AlloyCoppers, it tests all the functions and the constructors of the class
 * @version 0.3
 * @date 2020-03-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "materials/alloy_coppers.hpp"
#include <gtest/gtest.h>

/**
 * @brief The test fixture for testing class AlloyCoppers.
 * 
 */
class AlloyCoppersTest : public ::testing::Test 
{
  protected:
  /**
   * @brief Construct a new Alloy Coppers Test object
   * 
   */
  AlloyCoppersTest() 
  {
    material_AC_145Tellvirum.setType(MassCalculator::AlloyCoppers::Type::AC_145Tellvirum);
    material_AC_194Iron.setType(MassCalculator::AlloyCoppers::Type::AC_194Iron);
    material_AC_195Iron.setType(MassCalculator::AlloyCoppers::Type::AC_195Iron);
    material_AC_182Class2.setType(MassCalculator::AlloyCoppers::Type::AC_182Class2);
    material_AC_655Silicon.setType(MassCalculator::AlloyCoppers::Type::AC_655Silicon);
    material_AC_706Nickel.setType(MassCalculator::AlloyCoppers::Type::AC_706Nickel);
    material_AC_715NickelSilver.setType(MassCalculator::AlloyCoppers::Type::AC_715NickelSilver);
    material_AC_725NickelSilver.setType(MassCalculator::AlloyCoppers::Type::AC_725NickelSilver);
    material_AC_735NickelSilver.setType(MassCalculator::AlloyCoppers::Type::AC_735NickelSilver);
    material_AC_752NickelSilver.setType(MassCalculator::AlloyCoppers::Type::AC_752NickelSilver);
    material_AC_762NickelSilver.setType(MassCalculator::AlloyCoppers::Type::AC_762NickelSilver);
    material_AC_770NickelSilver.setType(MassCalculator::AlloyCoppers::Type::AC_770NickelSilver);
    material_AC_1751Class3.setType(MassCalculator::AlloyCoppers::Type::AC_1751Class3);
    material_AC_1758Nickel.setType(MassCalculator::AlloyCoppers::Type::AC_1758Nickel);
    material_AC_MoldmaxBeCu.setType(MassCalculator::AlloyCoppers::Type::AC_MoldmaxBeCu);
    material_AC_ProthermBeCu.setType(MassCalculator::AlloyCoppers::Type::AC_ProthermBeCu);
  }

  /**
   * @brief Destroy the Alloy Coppers Test object
   * 
   */
  ~AlloyCoppersTest() = default;

  // Objects declared here can be used by all tests in the test case for AlloyCoppersTest.
  MassCalculator::AlloyCoppers material_AC_145Tellvirum,
                               material_AC_194Iron,
                               material_AC_195Iron,
                               material_AC_182Class2,
                               material_AC_655Silicon,
                               material_AC_706Nickel,
                               material_AC_715NickelSilver,
                               material_AC_725NickelSilver,
                               material_AC_735NickelSilver,
                               material_AC_752NickelSilver,
                               material_AC_762NickelSilver,
                               material_AC_770NickelSilver,
                               material_AC_1751Class3,
                               material_AC_1758Nickel,
                               material_AC_MoldmaxBeCu,
                               material_AC_ProthermBeCu;
};