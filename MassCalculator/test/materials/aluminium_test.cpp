/**
 * @file aluminium_test.cpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief TODO
 * @version 0.1
 * @date 2019-04-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <gtest/gtest.h>

#include "materials/aluminium.h"

/**
 * @brief Construct a new TEST object
 * 
 */
TEST(Aluminium, TypeConstructorTest)
{
  std::unique_ptr<MassCalculator::Material<MassCalculator::Aluminium>>
    material(new MassCalculator::Aluminium(MassCalculator::Aluminium::Type::A_1100));

  EXPECT_DOUBLE_EQ( 5.0, 5.0);
}

TEST(Aluminium, SpecificMassTest)
{
  std::unique_ptr<MassCalculator::Material<MassCalculator::Aluminium>>
    material(new MassCalculator::Aluminium(MassCalculator::Aluminium::Type::A_1100));

  EXPECT_DOUBLE_EQ( 5.0, 5.0);
}
