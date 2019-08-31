/**
 * @file brass_test.cpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Brass, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2019-08-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "brass_test.hpp"

/**
 * @brief Construct a new TEST object
 * 
 */
TEST_F(BrassTest, TypeConstructorTest)
{
  EXPECT_DOUBLE_EQ( 5.0, 5.0);
}

TEST_F(BrassTest, GetSpecificTypeTest)
{
  std::pair<std::string, MassCalculator::Brass::Type> 
    type{"A_1100", MassCalculator::Brass::Type::B_240Low};

  EXPECT_EQ( type.first, material_B_240LowBrass.getType().first);
  EXPECT_EQ( type.second, material_B_240LowBrass.getType().second);
}

TEST_F(BrassTest, GetSpecificColorTest)
{
  EXPECT_EQ( std::string{"Metallic"}, material_B_240LowBrass.getSpecificColor());
}

TEST_F(BrassTest, GetSpecificDensityTest)
{
  EXPECT_EQ( double{2.71}, material_B_240LowBrass.getSpecificDensity());
}

TEST_F(BrassTest, GetSpecificGravityTest)
{
  EXPECT_EQ( double{2.83}, material_B_240LowBrass.getSpecificGravity());
}

TEST_F(BrassTest, GetSpecificMeltingPointTest)
{
  EXPECT_EQ( double{537.778}, material_B_240LowBrass.getSpecificMeltingPoint());
}

TEST_F(BrassTest, GetSpecificPoissonsRatioTest)
{
  EXPECT_EQ( double{0.33}, material_B_240LowBrass.getSpecificPoissonsRatio());
}

TEST_F(BrassTest, GetSpecificThermalConductivityTest)
{
  EXPECT_EQ( double{990.0}, material_B_240LowBrass.getSpecificThermalConductivity());
}

TEST_F(BrassTest, GetSpecificModOfElasticityTensionTest)
{
  EXPECT_EQ( double{9.9}, material_B_240LowBrass.getSpecificModOfElasticityTension());
}

TEST_F(BrassTest, GetSpecificModOfElasticityTorsionTest)
{
  EXPECT_EQ( double{3.8}, material_B_240LowBrass.getSpecificModOfElasticityTorsion());
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}