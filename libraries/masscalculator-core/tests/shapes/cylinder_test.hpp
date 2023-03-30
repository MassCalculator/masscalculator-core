/**
 * @file cylinder_test.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Cylinder, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2020-04-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___CYLINDER_TEST_H___
#define ___CYLINDER_TEST_H___
#include "shapes/cylinder.hpp"
#include <gtest/gtest.h>

/**
 * @brief Default Shapes test namespace
 * 
 */
namespace MassCalculatorTest::ShapesTest
{
  /**
   * @brief The test fixture for testing class Cylinder.
   * 
   */
  class CylinderTest : public ::testing::Test 
  {
    protected:
    /**
     * @brief Construct a new CylinderTest object
     * 
     */
    CylinderTest() 
    {
      this->cylinder_.setSize(0.1_m, 1_m);
    }

    /**
     * @brief Destroy the Cylinder Test object
     * 
     */
    ~CylinderTest() = default;

    /**
     * @brief Member object for class Cylinder
     * 
     */
    MassCalculator::Shapes::Cylinder cylinder_;
  };
}//end namespace MassCalculatorTest::ShapesTest
#endif//___CYLINDER_TEST_H___