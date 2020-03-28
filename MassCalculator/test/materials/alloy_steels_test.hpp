/**
 * @file alloy_steels_test.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class AlloySteels, it tests all the functions and the constructors of the class
 * @version 0.3
 * @date 2020-03-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "materials/alloy_steels.hpp"
#include <gtest/gtest.h>

/**
 * @brief The test fixture for testing class AlloySteels.
 * 
 */
class AlloySteelsTest : public ::testing::Test 
{
  protected:
  /**
   * @brief Construct a new AlloySteelsTest object
   * 
   */
  AlloySteelsTest() 
  {
    material_AS_4135.setType(MassCalculator::Materials::AlloySteels::Type::AS_4135);
    material_AS_4140.setType(MassCalculator::Materials::AlloySteels::Type::AS_4140);
    material_AS_4340.setType(MassCalculator::Materials::AlloySteels::Type::AS_4340);
  }

  /**
   * @brief Destroy the AlloySteelsTest object
   * 
   */
  ~AlloySteelsTest() = default;

  /**
   * @brief Member objects for class AlloyCoppers for each AlloyCopper type
   * 
   */
  MassCalculator::Materials::AlloySteels material_AS_4135,
                              material_AS_4140,
                              material_AS_4340;
};