/**
 * @file Bronz_test.cpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Bronz, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2019-08-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "bronz_test.hpp"

/**
 * @brief Construct a new TEST object
 * 
 */
TEST_F(BronzTest, TypeConstructorTest)
{
  EXPECT_DOUBLE_EQ( 5.0, 5.0);
}

TEST_F(BronzTest, GetSpecificTypeTest)
{
  std::pair<std::string, MassCalculator::Bronz::Type> 
    type{"B_18Al", MassCalculator::Bronz::Type::B_18Al};

  EXPECT_EQ( type.first, material_B_18Al.getType().first);
  EXPECT_EQ( type.second, material_B_18Al.getType().second);
}

TEST_F(BronzTest, GetSpecificColorTest)
{
  EXPECT_EQ( std::string{"Metallic"}, material_B_18Al.getSpecificColor());
}

TEST_F(BronzTest, GetSpecificDensityTest)
{
  EXPECT_EQ( double{2.71}, material_B_18Al.getSpecificDensity());
}

TEST_F(BronzTest, GetSpecificGravityTest)
{
  EXPECT_EQ( double{2.83}, material_B_18Al.getSpecificGravity());
}

TEST_F(BronzTest, GetSpecificMeltingPointTest)
{
  EXPECT_EQ( double{537.778}, material_B_18Al.getSpecificMeltingPoint());
}

TEST_F(BronzTest, GetSpecificPoissonsRatioTest)
{
  EXPECT_EQ( double{0.33}, material_B_18Al.getSpecificPoissonsRatio());
}

TEST_F(BronzTest, GetSpecificThermalConductivityTest)
{
  EXPECT_EQ( double{990.0}, material_B_18Al.getSpecificThermalConductivity());
}

TEST_F(BronzTest, GetSpecificModOfElasticityTensionTest)
{
  EXPECT_EQ( double{9.9}, material_B_18Al.getSpecificModOfElasticityTension());
}

TEST_F(BronzTest, GetSpecificModOfElasticityTorsionTest)
{
  EXPECT_EQ( double{3.8}, material_B_18Al.getSpecificModOfElasticityTorsion());
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}