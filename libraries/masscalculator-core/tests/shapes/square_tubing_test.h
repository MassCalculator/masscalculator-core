/**
 * @file square_tubing_test.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class SquareTubing, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2020-04-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___SQUARE_TUBING_TEST_H___
#define ___SQUARE_TUBING_TEST_H___
#include "shapes/square_tubing.hpp"
#include <gtest/gtest.h>

/**
 * @brief Default Shapes test namespace
 * 
 */
namespace MassCalculatorTest::ShapesTest
{
  /**
   * @brief The test fixture for testing class SquareTubing.
   * 
   */
  class SquareTubingTest : public ::testing::Test 
  {
    protected:
    /**
     * @brief Construct a new SquareTubingTest object
     * 
     */
    SquareTubingTest() 
    {
      this->square_tubing_.setSize(0.1_m, 0.01_m, 1_m);
    }

    /**
     * @brief Destroy the SquareTubingTest object
     * 
     */
    ~SquareTubingTest() = default;

    /**
     * @brief Member object for class SquareTubing
     * 
     */
    MassCalculator::Shapes::SquareTubing square_tubing_;
  };
}//end namespace MassCalculatorTest::ShapesTest
#endif//___SQUARE_TUBING_TEST_H___