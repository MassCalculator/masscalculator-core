/**
 * @file nickel_test.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Nickel, it tests all the functions and the constructors of the class
 * @version 0.3
 * @date 2020-03-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___NICKEL_TEST_H___
#define ___NICKEL_TEST_H___
#include "materials/nickel.hpp"
#include <gtest/gtest.h>

/**
 * @brief Default test namespace
 * 
 */
namespace MassCalculatorTest
{
  /**
   * @brief The test fixture for testing class Nickel.
   * 
   */
  class NickelTest : public ::testing::Test 
  {
    protected:
    /**
     * @brief Construct a new NickelTest object
     * 
     */
    NickelTest() 
    {
      material_N_201.setType(MassCalculator::Materials::Nickel::Type::N_201);
      material_N_210.setType(MassCalculator::Materials::Nickel::Type::N_210);
      material_N_220.setType(MassCalculator::Materials::Nickel::Type::N_220);
      material_N_230.setType(MassCalculator::Materials::Nickel::Type::N_230);
      material_N_400.setType(MassCalculator::Materials::Nickel::Type::N_400);
    }

    /**
     * @brief Destroy the NickelTest object
     * 
     */
    ~NickelTest() = default;

    /**
     * @brief Member objects for class Nickel for each Nickel type
     * 
     */
    MassCalculator::Materials::Nickel material_N_201,
                                      material_N_210,
                                      material_N_220,
                                      material_N_230,
                                      material_N_400;
  };
}//end namespace MassCalculatorTest
#endif//___NICKEL_TEST_H___