/**
 * @file titanium_test.cpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Aluminium, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2019-04-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "titanium_test.hpp"

/**
 * @brief Construct a new TEST object
 * 
 */
TEST_F(TitaniumTest, TypeConstructorTest)
{
  EXPECT_DOUBLE_EQ( 5.0, 5.0);
}

TEST_F(TitaniumTest, GetSpecificTypeTest)
{
  std::pair<std::string, MassCalculator::Titanium::Type> 
    type{"T_6Al4V", MassCalculator::Titanium::Type::T_6Al4V};

  EXPECT_EQ( type.first, material_T_6Al4V.getType().first);
  EXPECT_EQ( type.second, material_T_6Al4V.getType().second);
}

TEST_F(TitaniumTest, GetSpecificColorTest)
{
  EXPECT_EQ( std::string{"Metallic"}, material_T_6Al4V.getSpecificColor());
}

TEST_F(TitaniumTest, GetSpecificDensityTest)
{
  EXPECT_EQ( double{2.71}, material_T_6Al4V.getSpecificDensity());
}

TEST_F(TitaniumTest, GetSpecificGravityTest)
{
  EXPECT_EQ( double{2.83}, material_T_6Al4V.getSpecificGravity());
}

TEST_F(TitaniumTest, GetSpecificMeltingPointTest)
{
  EXPECT_EQ( double{537.778}, material_T_6Al4V.getSpecificMeltingPoint());
}

TEST_F(TitaniumTest, GetSpecificPoissonsRatioTest)
{
  EXPECT_EQ( double{0.33}, material_T_6Al4V.getSpecificPoissonsRatio());
}

TEST_F(TitaniumTest, GetSpecificThermalConductivityTest)
{
  EXPECT_EQ( double{990.0}, material_T_6Al4V.getSpecificThermalConductivity());
}

TEST_F(TitaniumTest, GetSpecificModOfElasticityTensionTest)
{
  EXPECT_EQ( double{9.9}, material_T_6Al4V.getSpecificModOfElasticityTension());
}

TEST_F(TitaniumTest, GetSpecificModOfElasticityTorsionTest)
{
  EXPECT_EQ( double{3.8}, material_T_6Al4V.getSpecificModOfElasticityTorsion());
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}