/**
 * @file aluminium_test.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Aluminium, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2020-03-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "materials/aluminium.hpp"
#include <gtest/gtest.h>

/**
 * @brief The test fixture for testing class AlloySteels.
 * 
 */
class AluminiumTest : public ::testing::Test 
{
  protected:
  /**
   * @brief Construct a new AluminiumTest object
   * 
   */
  AluminiumTest() 
  {
   // You can do set-up work for each test here.
   material_A_1100.setType(MassCalculator::Materials::Aluminium::Type::A_1100);
   material_A_2011.setType(MassCalculator::Materials::Aluminium::Type::A_2011);
   material_A_2014.setType(MassCalculator::Materials::Aluminium::Type::A_2014);
   material_A_2024.setType(MassCalculator::Materials::Aluminium::Type::A_2024);
   material_A_3003.setType(MassCalculator::Materials::Aluminium::Type::A_3003);
   material_A_5052.setType(MassCalculator::Materials::Aluminium::Type::A_5052);
   material_A_6061.setType(MassCalculator::Materials::Aluminium::Type::A_6061);
   material_A_6063.setType(MassCalculator::Materials::Aluminium::Type::A_6063);
   material_A_7075.setType(MassCalculator::Materials::Aluminium::Type::A_7075);
  }

  /**
   * @brief Destroy the AluminiumTest object
   * 
   */
  ~AluminiumTest() = default;

  /**
   * @brief Member objects for class Aluminium for each Aluminium type
   * 
   */
  MassCalculator::Materials::Aluminium material_A_1100,
                            material_A_2011,
                            material_A_2014,
                            material_A_2024,
                            material_A_3003,
                            material_A_5052,
                            material_A_6061,
                            material_A_6063,
                            material_A_7075;
};