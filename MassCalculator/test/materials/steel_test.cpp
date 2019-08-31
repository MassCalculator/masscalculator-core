/**
 * @file aluminium_test.cpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Aluminium, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2019-04-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "steel_test.hpp"

/**
 * @brief Construct a new TEST object
 * 
 */
TEST_F(SteelTest, TypeConstructorTest)
{
  EXPECT_DOUBLE_EQ( 5.0, 5.0);
}

TEST_F(SteelTest, GetSpecificTypeTest)
{
  std::pair<std::string, MassCalculator::Steel::Type> 
    type{"S_1010", MassCalculator::Steel::Type::S_1010};

  EXPECT_EQ( type.first, material_S_1010.getType().first);
  EXPECT_EQ( type.second, material_S_1010.getType().second);
}

TEST_F(SteelTest, GetSpecificColorTest)
{
  EXPECT_EQ( std::string{"Metallic"}, material_S_1010.getSpecificColor());
}

TEST_F(SteelTest, GetSpecificDensityTest)
{
  EXPECT_EQ( double{2.71}, material_S_1010.getSpecificDensity());
}

TEST_F(SteelTest, GetSpecificGravityTest)
{
  EXPECT_EQ( double{2.83}, material_S_1010.getSpecificGravity());
}

TEST_F(SteelTest, GetSpecificMeltingPointTest)
{
  EXPECT_EQ( double{537.778}, material_S_1010.getSpecificMeltingPoint());
}

TEST_F(SteelTest, GetSpecificPoissonsRatioTest)
{
  EXPECT_EQ( double{0.33}, material_S_1010.getSpecificPoissonsRatio());
}

TEST_F(SteelTest, GetSpecificThermalConductivityTest)
{
  EXPECT_EQ( double{990.0}, material_S_1010.getSpecificThermalConductivity());
}

TEST_F(SteelTest, GetSpecificModOfElasticityTensionTest)
{
  EXPECT_EQ( double{9.9}, material_S_1010.getSpecificModOfElasticityTension());
}

TEST_F(SteelTest, GetSpecificModOfElasticityTorsionTest)
{
  EXPECT_EQ( double{3.8}, material_S_1010.getSpecificModOfElasticityTorsion());
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}