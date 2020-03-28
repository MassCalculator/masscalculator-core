/**
 * @file Zinc_test.cpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Zinc, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2019-09-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "zinc_test.hpp"

/**
 * @brief Construct a new TEST object
 * 
 */
TEST_F(ZincTest, TypeConstructorTest)
{
  EXPECT_DOUBLE_EQ( 5.0, 5.0);
}

TEST_F(ZincTest, GetSpecificTypeTest)
{
  std::pair<std::string, MassCalculator::Materials::Zinc::Type> 
    type{"Z_190", MassCalculator::Materials::Zinc::Type::Z_190};

  EXPECT_EQ( type.first, material_Z_190.getType().first);
  EXPECT_EQ( type.second, material_Z_190.getType().second);
}

TEST_F(ZincTest, GetSpecificColorTest)
{
  EXPECT_EQ( std::string{"Metallic"}, material_Z_190.getSpecificColor());
}

TEST_F(ZincTest, GetSpecificDensityTest)
{
  EXPECT_EQ( double{2.71}, material_Z_190.getSpecificDensity());
}

TEST_F(ZincTest, GetSpecificGravityTest)
{
  EXPECT_EQ( double{2.83}, material_Z_190.getSpecificGravity());
}

TEST_F(ZincTest, GetSpecificMeltingPointTest)
{
  EXPECT_EQ( double{537.778}, material_Z_190.getSpecificMeltingPoint());
}

TEST_F(ZincTest, GetSpecificPoissonsRatioTest)
{
  EXPECT_EQ( double{0.33}, material_Z_190.getSpecificPoissonsRatio());
}

TEST_F(ZincTest, GetSpecificThermalConductivityTest)
{
  EXPECT_EQ( double{990.0}, material_Z_190.getSpecificThermalConductivity());
}

TEST_F(ZincTest, GetSpecificModOfElasticityTensionTest)
{
  EXPECT_EQ( double{9.9}, material_Z_190.getSpecificModOfElasticityTension());
}

TEST_F(ZincTest, GetSpecificModOfElasticityTorsionTest)
{
  EXPECT_EQ( double{3.8}, material_Z_190.getSpecificModOfElasticityTorsion());
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}