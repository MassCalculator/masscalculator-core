/**
 * @file alloy_coppers_test.cpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Aluminium, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2019-09-03
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "alloy_coppers_test.hpp"

/**
 * @brief Construct a new TEST object
 * 
 */
TEST_F(AlloyCoppersTest, TypeConstructorTest)
{
  EXPECT_DOUBLE_EQ( 5.0, 5.0);
}

TEST_F(AlloyCoppersTest, GetSpecificTypeTest)
{
  std::pair<std::string, MassCalculator::AlloyCoppers::Type> 
    type{"AC_145Tellvirum", MassCalculator::AlloyCoppers::Type::AC_145Tellvirum};

  EXPECT_EQ( type.first, material_AC_145Tellvirum.getType().first);
  EXPECT_EQ( type.second, material_AC_145Tellvirum.getType().second);
}

TEST_F(AlloyCoppersTest, GetSpecificColorTest)
{
  EXPECT_EQ( std::string{"Metallic"}, material_AC_145Tellvirum.getSpecificColor());
}

TEST_F(AlloyCoppersTest, GetSpecificDensityTest)
{
  EXPECT_EQ( double{2.71}, material_AC_145Tellvirum.getSpecificDensity());
}

TEST_F(AlloyCoppersTest, GetSpecificGravityTest)
{
  EXPECT_EQ( double{2.83}, material_AC_145Tellvirum.getSpecificGravity());
}

TEST_F(AlloyCoppersTest, GetSpecificMeltingPointTest)
{
  EXPECT_EQ( double{537.778}, material_AC_145Tellvirum.getSpecificMeltingPoint());
}

TEST_F(AlloyCoppersTest, GetSpecificPoissonsRatioTest)
{
  EXPECT_EQ( double{0.33}, material_AC_145Tellvirum.getSpecificPoissonsRatio());
}

TEST_F(AlloyCoppersTest, GetSpecificThermalConductivityTest)
{
  EXPECT_EQ( double{990.0}, material_AC_145Tellvirum.getSpecificThermalConductivity());
}

TEST_F(AlloyCoppersTest, GetSpecificModOfElasticityTensionTest)
{
  EXPECT_EQ( double{9.9}, material_AC_145Tellvirum.getSpecificModOfElasticityTension());
}

TEST_F(AlloyCoppersTest, GetSpecificModOfElasticityTorsionTest)
{
  EXPECT_EQ( double{3.8}, material_AC_145Tellvirum.getSpecificModOfElasticityTorsion());
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}