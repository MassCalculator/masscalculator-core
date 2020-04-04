/**
 * @file stainless_steel_test.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class StainlessSteel, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2020-03-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___STAINLESS_STEEL_TEST_H___
#define ___STAINLESS_STEEL_TEST_H___
#include "materials/stainless_steel.hpp"
#include <gtest/gtest.h>

/**
 * @brief Default test namespace
 * 
 */
namespace MassCalculatorTest
{
  /**
   * @brief The test fixture for testing class StainlessSteel.
   * 
   */
  class StainlessSteelTest : public ::testing::Test 
  {
    protected:
    /**
     * @brief Construct a new StainlessSteelTest object
     * 
     */
    StainlessSteelTest() 
    {
      material_SS_301.setType(MassCalculator::Materials::StainlessSteel::Type::SS_301);
      material_SS_302.setType(MassCalculator::Materials::StainlessSteel::Type::SS_302);
      material_SS_303.setType(MassCalculator::Materials::StainlessSteel::Type::SS_303);
      material_SS_304.setType(MassCalculator::Materials::StainlessSteel::Type::SS_304);
      material_SS_305.setType(MassCalculator::Materials::StainlessSteel::Type::SS_305);
      material_SS_316.setType(MassCalculator::Materials::StainlessSteel::Type::SS_316);
      material_SS_321.setType(MassCalculator::Materials::StainlessSteel::Type::SS_321);
      material_SS_409.setType(MassCalculator::Materials::StainlessSteel::Type::SS_409);
      material_SS_410.setType(MassCalculator::Materials::StainlessSteel::Type::SS_410);
      material_SS_420.setType(MassCalculator::Materials::StainlessSteel::Type::SS_420);
      material_SS_430.setType(MassCalculator::Materials::StainlessSteel::Type::SS_430);
      material_SS_15_5.setType(MassCalculator::Materials::StainlessSteel::Type::SS_15_5);
      material_SS_17_4.setType(MassCalculator::Materials::StainlessSteel::Type::SS_17_4);
    }

    /**
     * @brief Destroy the StainlessSteelTest object
     * 
     */
    ~StainlessSteelTest() = default;

    /**
     * @brief Member objects for class Stainless Steel for each Stainless Steel type
     * 
     */
    MassCalculator::Materials::StainlessSteel material_SS_301,
                                              material_SS_302,
                                              material_SS_303,
                                              material_SS_304,
                                              material_SS_305,
                                              material_SS_316,
                                              material_SS_321,
                                              material_SS_409,
                                              material_SS_410,
                                              material_SS_420,
                                              material_SS_430,
                                              material_SS_15_5,
                                              material_SS_17_4;
  };
}//end namespace MassCalculatorTest
#endif//___STAINLESS_STEEL_TEST_H___