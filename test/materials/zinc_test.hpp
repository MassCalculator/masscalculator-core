/**
 * @file zinc_test.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Zinc, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2020-03-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___ZINC_TEST_H___
#define ___ZINC_TEST_H___
#include "materials/zinc.hpp"
#include <gtest/gtest.h>

/**
 * @brief Default Materials test namespace
 * 
 */
namespace MassCalculatorTest::MaterialsTest
{
  /**
   * @brief The test fixture for testing class Zinc.
   * 
   */
  class ZincTest : public ::testing::Test 
  {
    protected:
    /**
     * @brief Construct a new ZincTest object
     * 
     */
    ZincTest() 
    {
      material_Z_190.setType(MassCalculator::Materials::Zinc::Type::Z_190);
      material_Z_310.setType(MassCalculator::Materials::Zinc::Type::Z_310);
      material_Z_320.setType(MassCalculator::Materials::Zinc::Type::Z_320);
      material_Z_500.setType(MassCalculator::Materials::Zinc::Type::Z_500);
      material_Z_700.setType(MassCalculator::Materials::Zinc::Type::Z_700);
      material_Z_720.setType(MassCalculator::Materials::Zinc::Type::Z_720);
      material_Z_750.setType(MassCalculator::Materials::Zinc::Type::Z_750);
    }

    /**
     * @brief Destroy the ZincTest object
     * 
     */
    ~ZincTest() = default;

    /**
     * @brief Member objects for class Titanium for each Titanium type
     * 
     */
    MassCalculator::Materials::Zinc material_Z_190,
                                    material_Z_310,
                                    material_Z_320,
                                    material_Z_500,
                                    material_Z_700,
                                    material_Z_720,
                                    material_Z_750;
  };
}//end namespace MassCalculatorTest::MaterialsTest
#endif//___ZINC_TEST_H___