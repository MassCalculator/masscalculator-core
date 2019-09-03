/**
 * @file magnesium_test.cpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Magnesium, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2019-04-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "magnesium_test.hpp"

/**
 * @brief Construct a new TEST object
 * 
 */
TEST_F(MagnesiumTest, TypeConstructorTest)
{
  EXPECT_DOUBLE_EQ( 5.0, 5.0);
}

TEST_F(MagnesiumTest, GetSpecificTypeTest)
{
  std::pair<std::string, MassCalculator::Magnesium::Type> 
    type{"M_AZ31B", MassCalculator::Magnesium::Type::M_AZ31B};

  EXPECT_EQ( type.first, material_M_AZ31B.getType().first);
  EXPECT_EQ( type.second, material_M_AZ31B.getType().second);
}

TEST_F(MagnesiumTest, GetSpecificColorTest)
{
  EXPECT_EQ( std::string{"Metallic"}, material_M_AZ31B.getSpecificColor());
}

TEST_F(MagnesiumTest, GetSpecificDensityTest)
{
  EXPECT_EQ( double{2.71}, material_M_AZ31B.getSpecificDensity());
}

TEST_F(MagnesiumTest, GetSpecificGravityTest)
{
  EXPECT_EQ( double{2.83}, material_M_AZ31B.getSpecificGravity());
}

TEST_F(MagnesiumTest, GetSpecificMeltingPointTest)
{
  EXPECT_EQ( double{537.778}, material_M_AZ31B.getSpecificMeltingPoint());
}

TEST_F(MagnesiumTest, GetSpecificPoissonsRatioTest)
{
  EXPECT_EQ( double{0.33}, material_M_AZ31B.getSpecificPoissonsRatio());
}

TEST_F(MagnesiumTest, GetSpecificThermalConductivityTest)
{
  EXPECT_EQ( double{990.0}, material_M_AZ31B.getSpecificThermalConductivity());
}

TEST_F(MagnesiumTest, GetSpecificModOfElasticityTensionTest)
{
  EXPECT_EQ( double{9.9}, material_M_AZ31B.getSpecificModOfElasticityTension());
}

TEST_F(MagnesiumTest, GetSpecificModOfElasticityTorsionTest)
{
  EXPECT_EQ( double{3.8}, material_M_AZ31B.getSpecificModOfElasticityTorsion());
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}