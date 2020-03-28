/**
 * @file plastic_test.cpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Plastic, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2019-09-05
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "plastic_test.hpp"

/**
 * @brief Construct a new TEST object
 * 
 */
TEST_F(PlasticTest, TypeConstructorTest)
{
  EXPECT_DOUBLE_EQ( 5.0, 5.0);
}

TEST_F(PlasticTest, GetSpecificTypeTest)
{
  std::pair<std::string, MassCalculator::Materials::Plastic::Type> 
    type{"P_ABS", MassCalculator::Materials::Plastic::Type::P_ABS};

  EXPECT_EQ( type.first, material_P_ABS.getType().first);
  EXPECT_EQ( type.second, material_P_ABS.getType().second);
}

TEST_F(PlasticTest, GetSpecificColorTest)
{
  EXPECT_EQ( std::string{"Metallic"}, material_P_ABS.getSpecificColor());
}

TEST_F(PlasticTest, GetSpecificDensityTest)
{
  EXPECT_EQ( double{2.71}, material_P_ABS.getSpecificDensity());
}

TEST_F(PlasticTest, GetSpecificGravityTest)
{
  EXPECT_EQ( double{2.83}, material_P_ABS.getSpecificGravity());
}

TEST_F(PlasticTest, GetSpecificMeltingPointTest)
{
  EXPECT_EQ( double{537.778}, material_P_ABS.getSpecificMeltingPoint());
}

TEST_F(PlasticTest, GetSpecificPoissonsRatioTest)
{
  EXPECT_EQ( double{0.33}, material_P_ABS.getSpecificPoissonsRatio());
}

TEST_F(PlasticTest, GetSpecificThermalConductivityTest)
{
  EXPECT_EQ( double{990.0}, material_P_ABS.getSpecificThermalConductivity());
}

TEST_F(PlasticTest, GetSpecificModOfElasticityTensionTest)
{
  EXPECT_EQ( double{9.9}, material_P_ABS.getSpecificModOfElasticityTension());
}

TEST_F(PlasticTest, GetSpecificModOfElasticityTorsionTest)
{
  EXPECT_EQ( double{3.8}, material_P_ABS.getSpecificModOfElasticityTorsion());
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}