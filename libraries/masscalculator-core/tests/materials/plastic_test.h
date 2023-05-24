/**
 * @file plastic_test.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Plastic, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2020-03-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___PLASTIC_TEST_H___
#define ___PLASTIC_TEST_H___
#include "materials/plastic.hpp"
#include <gtest/gtest.h>

/**
 * @brief Default Materials test namespace
 * 
 */
namespace MassCalculatorTest
{
  /**
   * @brief The test fixture for testing class Plastic.
   * 
   */
  class PlasticTest : public ::testing::Test 
  {
    protected:
    /**
     * @brief Construct a new PlasticTest object
     * 
     */
    PlasticTest() 
    {
      material_P_ABS.setType(MassCalculator::Materials::Plastic::Type::P_ABS);
    }

    /**
     * @brief Destroy the PlasticTest object
     * 
     */
    ~PlasticTest() = default;

    /**
     * @brief Member objects for class Plastic for each Plastic type
     * 
     */
    MassCalculator::Materials::Plastic material_P_ABS;
  };
}//end namespace MassCalculatorTest::MaterialsTest
#endif//___PLASTIC_TEST_H___