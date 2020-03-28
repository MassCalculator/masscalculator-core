/**
 * @file stainless_steel_test.cpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class StainlessSteelTest, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2019-09-03
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "stainless_steel_test.hpp"

/**
 * @brief Construct a new TEST object
 * 
 */
TEST_F(StainlessSteelTest, TypeConstructorTest)
{
  EXPECT_DOUBLE_EQ( 5.0, 5.0);
}

TEST_F(StainlessSteelTest, GetSpecificTypeTest)
{
  std::pair<std::string, MassCalculator::Materials::StainlessSteel::Type> 
    type{"SS_301", MassCalculator::Materials::StainlessSteel::Type::SS_301};

  EXPECT_EQ( type.first, material_SS_301.getType().first);
  EXPECT_EQ( type.second, material_SS_301.getType().second);
}

TEST_F(StainlessSteelTest, GetSpecificColorTest)
{
  EXPECT_EQ( std::string{"Metallic"}, material_SS_301.getSpecificColor());
}

TEST_F(StainlessSteelTest, GetSpecificDensityTest)
{
  EXPECT_EQ( double{2.71}, material_SS_301.getSpecificDensity());
}

TEST_F(StainlessSteelTest, GetSpecificGravityTest)
{
  EXPECT_EQ( double{2.83}, material_SS_301.getSpecificGravity());
}

TEST_F(StainlessSteelTest, GetSpecificMeltingPointTest)
{
  EXPECT_EQ( double{537.778}, material_SS_301.getSpecificMeltingPoint());
}

TEST_F(StainlessSteelTest, GetSpecificPoissonsRatioTest)
{
  EXPECT_EQ( double{0.33}, material_SS_301.getSpecificPoissonsRatio());
}

TEST_F(StainlessSteelTest, GetSpecificThermalConductivityTest)
{
  EXPECT_EQ( double{990.0}, material_SS_301.getSpecificThermalConductivity());
}

TEST_F(StainlessSteelTest, GetSpecificModOfElasticityTensionTest)
{
  EXPECT_EQ( double{9.9}, material_SS_301.getSpecificModOfElasticityTension());
}

TEST_F(StainlessSteelTest, GetSpecificModOfElasticityTorsionTest)
{
  EXPECT_EQ( double{3.8}, material_SS_301.getSpecificModOfElasticityTorsion());
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}