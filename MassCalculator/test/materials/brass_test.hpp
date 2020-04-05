/**
 * @file brass_test.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Brass, it tests all the functions and the constructors of the class
 * @version 0.3
 * @date 2020-03-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___BRASS_TEST_H___
#define ___BRASS_TEST_H___
#include "materials/brass.hpp"
#include <gtest/gtest.h>

/**
 * @brief Default test namespace
 * 
 */
namespace MassCalculatorTest
{
    /**
   * @brief The test fixture for testing class Brass.
   * 
   */
  class BrassTest : public ::testing::Test 
  {
    protected:
    /**
     * @brief Construct a new BrassTest object
     * 
     */
    BrassTest() 
    {
      material_B_240Low.setType(MassCalculator::Materials::Brass::Type::B_240Low);
      material_B_260Cartridge.setType(MassCalculator::Materials::Brass::Type::B_260Cartridge);
      material_B_353Leaded.setType(MassCalculator::Materials::Brass::Type::B_353Leaded);
      material_B_360.setType(MassCalculator::Materials::Brass::Type::B_360);
      material_B_365.setType(MassCalculator::Materials::Brass::Type::B_365);
      material_B_380.setType(MassCalculator::Materials::Brass::Type::B_380);
      material_B_385.setType(MassCalculator::Materials::Brass::Type::B_385);
      material_B_464.setType(MassCalculator::Materials::Brass::Type::B_464);
    }

    /**
     * @brief Destroy the BrassTest object
     * 
     */
    ~BrassTest() = default;

    /**
     * @brief Member objects for class Brass for each Brass type
     * 
     */
    MassCalculator::Materials::Brass material_B_240Low,
                                     material_B_260Cartridge,
                                     material_B_353Leaded,
                                     material_B_360,
                                     material_B_365,
                                     material_B_380,
                                     material_B_385,
                                     material_B_464;
  };
}//end namespace MassCalculatorTest
#endif//___BRASS_TEST_H___