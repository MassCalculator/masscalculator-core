/**
 * @file nickel_test.cpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Nickel, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2019-09-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "nickel_test.hpp"

/**
 * @brief Construct a new TEST object
 * 
 */
TEST_F(NickelTest, TypeConstructorTest)
{
  EXPECT_DOUBLE_EQ( 5.0, 5.0);
}

TEST_F(NickelTest, GetSpecificTypeTest)
{
  std::pair<std::string, MassCalculator::Nickel::Type> 
    type{"N_201", MassCalculator::Nickel::Type::N_201};

  EXPECT_EQ( type.first, material_N_201.getType().first);
  EXPECT_EQ( type.second, material_N_201.getType().second);
}

TEST_F(NickelTest, GetSpecificColorTest)
{
  EXPECT_EQ( std::string{"Metallic"}, material_N_201.getSpecificColor());
}

TEST_F(NickelTest, GetSpecificDensityTest)
{
  EXPECT_EQ( double{2.71}, material_N_201.getSpecificDensity());
}

TEST_F(NickelTest, GetSpecificGravityTest)
{
  EXPECT_EQ( double{2.83}, material_N_201.getSpecificGravity());
}

TEST_F(NickelTest, GetSpecificMeltingPointTest)
{
  EXPECT_EQ( double{537.778}, material_N_201.getSpecificMeltingPoint());
}

TEST_F(NickelTest, GetSpecificPoissonsRatioTest)
{
  EXPECT_EQ( double{0.33}, material_N_201.getSpecificPoissonsRatio());
}

TEST_F(NickelTest, GetSpecificThermalConductivityTest)
{
  EXPECT_EQ( double{990.0}, material_N_201.getSpecificThermalConductivity());
}

TEST_F(NickelTest, GetSpecificModOfElasticityTensionTest)
{
  EXPECT_EQ( double{9.9}, material_N_201.getSpecificModOfElasticityTension());
}

TEST_F(NickelTest, GetSpecificModOfElasticityTorsionTest)
{
  EXPECT_EQ( double{3.8}, material_N_201.getSpecificModOfElasticityTorsion());
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}