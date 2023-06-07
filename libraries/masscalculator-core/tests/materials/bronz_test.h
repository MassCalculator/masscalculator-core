/**
 * @file Bronz_test.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Bronz, it tests all the functions and the constructors of the class
 * @version 0.3
 * @date 2020-03-28   
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___BRONZ_TEST_H___
#define ___BRONZ_TEST_H___
#include "materials/bronz.hpp"
#include <gtest/gtest.h>

/**
 * @brief Default Materials test namespace
 * 
 */
namespace MassCalculatorTest::MaterialsTest
{
  /**
   * @brief The test fixture for testing class Bronz.
   * 
   */
  class BronzTest : public ::testing::Test 
  {
    protected:
    /**
     * @brief Construct a new BronzTest object
     * 
     */
    BronzTest() 
    {
      material_B_18Al.setType(MassCalculator::Materials::Bronz::Type::B_18Al);
      material_B_21Al.setType(MassCalculator::Materials::Bronz::Type::B_21Al);
      material_B_314Commercial.setType(MassCalculator::Materials::Bronz::Type::B_314Commercial);
      material_B_485Naval.setType(MassCalculator::Materials::Bronz::Type::B_485Naval);
      material_B_510Phos.setType(MassCalculator::Materials::Bronz::Type::B_510Phos);
      material_B_524Phos.setType(MassCalculator::Materials::Bronz::Type::B_524Phos);
      material_B_532Phos.setType(MassCalculator::Materials::Bronz::Type::B_532Phos);
      material_B_534Phos.setType(MassCalculator::Materials::Bronz::Type::B_534Phos);
      material_B_544Phos.setType(MassCalculator::Materials::Bronz::Type::B_544Phos);
      material_B_613Al.setType(MassCalculator::Materials::Bronz::Type::B_613Al);
      material_B_614Al.setType(MassCalculator::Materials::Bronz::Type::B_614Al);
      material_B_623Al.setType(MassCalculator::Materials::Bronz::Type::B_623Al);
      material_B_624Al.setType(MassCalculator::Materials::Bronz::Type::B_624Al);
      material_B_625Al.setType(MassCalculator::Materials::Bronz::Type::B_625Al);
      material_B_630NiAl.setType(MassCalculator::Materials::Bronz::Type::B_630NiAl);
      material_B_642AlSi.setType(MassCalculator::Materials::Bronz::Type::B_642AlSi);
      material_B_932Bearing.setType(MassCalculator::Materials::Bronz::Type::B_932Bearing);
      material_B_954Al.setType(MassCalculator::Materials::Bronz::Type::B_954Al);
      material_B_OilLite.setType(MassCalculator::Materials::Bronz::Type::B_OilLite);
    }

    /**
     * @brief Destroy the BronzTest object
     * 
     */
    ~BronzTest() = default;

    /**
     * @brief Member objects for class Bronz for each Bronz type
     * 
     */
    MassCalculator::Materials::Bronz material_B_18Al,
                                     material_B_21Al,
                                     material_B_314Commercial,
                                     material_B_485Naval,
                                     material_B_510Phos,
                                     material_B_524Phos,
                                     material_B_532Phos,
                                     material_B_534Phos,
                                     material_B_544Phos,
                                     material_B_613Al,
                                     material_B_614Al,
                                     material_B_623Al,
                                     material_B_624Al,
                                     material_B_625Al,
                                     material_B_630NiAl,
                                     material_B_642AlSi,
                                     material_B_932Bearing,
                                     material_B_954Al,
                                     material_B_OilLite;
  };
}//end namespace MassCalculatorTest::MaterialsTest
#endif//___BRONZ_TEST_H___