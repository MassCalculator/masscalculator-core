/**
 * @file copper_test.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Copper, it tests all the functions and the constructors of the class
 * @version 0.3
 * @date 2020-03-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___COPPER_TEST_H___
#define ___COPPER_TEST_H___
#include "materials/copper.hpp"
#include <gtest/gtest.h>

/**
 * @brief Default Materials test namespace
 * 
 */
namespace MassCalculatorTest::MaterialsTest
{
    /**
   * @brief The test fixture for testing class Copper.
   * 
   */
  class CopperTest : public ::testing::Test 
  {
    protected:
    /**
     * @brief Construct a new CopperTest object
     * 
     */
    CopperTest() 
    {
      material_C_101.setType(MassCalculator::Materials::Copper::Type::C_101);
      material_C_102.setType(MassCalculator::Materials::Copper::Type::C_102);
      material_C_103.setType(MassCalculator::Materials::Copper::Type::C_103);
      material_C_110.setType(MassCalculator::Materials::Copper::Type::C_110);
      material_C_122.setType(MassCalculator::Materials::Copper::Type::C_122);
    }

    /**
     * @brief Destroy the CopperTest object
     * 
     */
    ~CopperTest() = default;

    /**
     * @brief Member objects for class Copper for each Copper type
     * 
     */
    MassCalculator::Materials::Copper material_C_101,
                                      material_C_102,
                                      material_C_103,
                                      material_C_110,
                                      material_C_122;
  };
}//end namespace MassCalculatorTest::MaterialsTest
#endif//___COPPER_TEST_H___