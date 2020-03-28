/**
 * @file magnesium_test.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Magnesium, it tests all the functions and the constructors of the class
 * @version 0.3
 * @date 2020-03-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___MAGNESIUM_TEST_H___
#define ___MAGNESIUM_TEST_H___
#include "materials/magnesium.hpp"
#include <gtest/gtest.h>

/**
 * @brief Default test namespace
 * 
 */
namespace MassCalculatorTest
{
  /**
   * @brief The test fixture for testing class Magnesium.
   * 
   */
  class MagnesiumTest : public ::testing::Test 
  {
    protected:
    /**
     * @brief Construct a new MagnesiumTest object
     * 
     */
    MagnesiumTest() 
    {
      material_M_AZ31B.setType(MassCalculator::Materials::Magnesium::Type::M_AZ31B);
    }

    /**
     * @brief Destroy the MagnesiumTest object
     * 
     */
    ~MagnesiumTest() = default;

    /**
     * @brief Member objects for class AlloyCoppers for each AlloyCopper type
     * 
     */
    MassCalculator::Materials::Magnesium material_M_AZ31B;
  };
}//end namespace MassCalculatorTest
#endif//___MAGNESIUM_TEST_H___