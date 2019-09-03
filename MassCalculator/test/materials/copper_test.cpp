/**
 * @file copper_test.cpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Copper, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2019-09-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "copper_test.hpp"

/**
 * @brief Construct a new TEST object
 * 
 */
TEST_F(CopperTest, TypeConstructorTest)
{
  EXPECT_DOUBLE_EQ( 5.0, 5.0);
}

TEST_F(CopperTest, GetSpecificTypeTest)
{
  std::pair<std::string, MassCalculator::Copper::Type> 
    type{"C_101", MassCalculator::Copper::Type::C_101};

  EXPECT_EQ( type.first, material_C_101.getType().first);
  EXPECT_EQ( type.second, material_C_101.getType().second);
}

TEST_F(CopperTest, GetSpecificColorTest)
{
  EXPECT_EQ( std::string{"Metallic"}, material_C_101.getSpecificColor());
}

TEST_F(CopperTest, GetSpecificDensityTest)
{
  EXPECT_EQ( double{2.71}, material_C_101.getSpecificDensity());
}

TEST_F(CopperTest, GetSpecificGravityTest)
{
  EXPECT_EQ( double{2.83}, material_C_101.getSpecificGravity());
}

TEST_F(CopperTest, GetSpecificMeltingPointTest)
{
  EXPECT_EQ( double{537.778}, material_C_101.getSpecificMeltingPoint());
}

TEST_F(CopperTest, GetSpecificPoissonsRatioTest)
{
  EXPECT_EQ( double{0.33}, material_C_101.getSpecificPoissonsRatio());
}

TEST_F(CopperTest, GetSpecificThermalConductivityTest)
{
  EXPECT_EQ( double{990.0}, material_C_101.getSpecificThermalConductivity());
}

TEST_F(CopperTest, GetSpecificModOfElasticityTensionTest)
{
  EXPECT_EQ( double{9.9}, material_C_101.getSpecificModOfElasticityTension());
}

TEST_F(CopperTest, GetSpecificModOfElasticityTorsionTest)
{
  EXPECT_EQ( double{3.8}, material_C_101.getSpecificModOfElasticityTorsion());
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}