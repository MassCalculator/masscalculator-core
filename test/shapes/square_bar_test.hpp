/**
 * @file square_bar_test.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class SquareBar, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2020-04-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___SQUARE_BAR_TEST_H___
#define ___SQUARE_BAR_TEST_H___
#include "shapes/square_bar.hpp"
#include <gtest/gtest.h>

/**
 * @brief Default Shapes test namespace
 * 
 */
namespace MassCalculatorTest::ShapesTest
{
  /**
   * @brief The test fixture for testing class SquareBar.
   * 
   */
  class SquareBarTest : public ::testing::Test 
  {
    protected:
    /**
     * @brief Construct a new SquareBarTest object
     * 
     */
    SquareBarTest() 
    {
      this->square_bar_.setSize(0.1_m, 1_m);
    }

    /**
     * @brief Destroy the SquareBarTest object
     * 
     */
    ~SquareBarTest() = default;

    /**
     * @brief Member object for class SquareBar
     * 
     */
    MassCalculator::Shapes::SquareBar square_bar_;
  };
}//end namespace MassCalculatorTest::ShapesTest
#endif//___SQUARE_BAR_TEST_H___