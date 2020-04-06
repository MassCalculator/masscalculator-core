/**
 * @file steel_test.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Steel, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2020-03-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___STEEL_TEST_H___
#define ___STEEL_TEST_H___
#include "materials/steel.hpp"
#include <gtest/gtest.h>

/**
 * @brief Default Materials test namespace
 * 
 */
namespace MassCalculatorTest::MaterialsTest
{
  /**
   * @brief The test fixture for testing class Steel.
   * 
   */
  class SteelTest : public ::testing::Test 
  {
    protected:
    /**
     * @brief Construct a new SteelTest object
     * 
     */
    SteelTest() 
    {
      material_S_1010.setType(MassCalculator::Materials::Steel::Type::S_1010);
      material_S_1012.setType(MassCalculator::Materials::Steel::Type::S_1012);
      material_S_1015.setType(MassCalculator::Materials::Steel::Type::S_1015);
      material_S_1018.setType(MassCalculator::Materials::Steel::Type::S_1018);
      material_S_1541.setType(MassCalculator::Materials::Steel::Type::S_1541);
      material_S_4140.setType(MassCalculator::Materials::Steel::Type::S_4140);
      material_S_A36.setType(MassCalculator::Materials::Steel::Type::S_A36);
    }

    /**
     * @brief Destroy the SteelTest object
     * 
     */
    ~SteelTest() = default;

    /**
     * @brief Member objects for class Steel for each Steel type
     * 
     */
    MassCalculator::Materials::Steel material_S_1010,
                                     material_S_1012,
                                     material_S_1015,
                                     material_S_1018,
                                     material_S_1541,
                                     material_S_4140,
                                     material_S_A36;
  };
}//end namespace MassCalculatorTest::MaterialsTest
#endif//___STEEL_TEST_H___