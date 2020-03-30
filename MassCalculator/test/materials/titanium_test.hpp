/**
 * @file titanium_test.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Aluminium, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2020-03-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___TITANIUM_TEST_H___
#define ___TITANIUM_TEST_H___
#include "materials/titanium.hpp"
#include <gtest/gtest.h>

/**
 * @brief Default test namespace
 * 
 */
namespace MassCalculatorTest
{
  /**
   * @brief The test fixture for testing class Titanium.
   * 
   */
  class TitaniumTest : public ::testing::Test 
  {
    protected:
    /**
     * @brief Construct a new TitaniumTest object
     * 
     */
    TitaniumTest() 
    {
      material_T_6Al4V.setType(MassCalculator::Materials::Titanium::Type::T_6Al4V);
      material_T_Grade2.setType(MassCalculator::Materials::Titanium::Type::T_Grade2);
      material_T_Grade4.setType(MassCalculator::Materials::Titanium::Type::T_Grade4);
      material_T_Grade5.setType(MassCalculator::Materials::Titanium::Type::T_Grade5);
    }

    /**
     * @brief Destroy the TitaniumTest object
     * 
     */
    ~TitaniumTest() = default;

    /**
     * @brief Member objects for class Titanium for each Titanium type
     * 
     */
    MassCalculator::Materials::Titanium material_T_6Al4V,
                                        material_T_Grade2,
                                        material_T_Grade4,
                                        material_T_Grade5;
  };
}//end namespace MassCalculatorTest
#endif//___TITANIUM_TEST_H___