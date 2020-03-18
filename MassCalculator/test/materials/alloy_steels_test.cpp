/**
 * @file alloy_steels_test.cpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class AlloySteels, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2019-08-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "alloy_steels_test.hpp"

/**
 * @brief Construct a new TEST object
 * 
 */
TEST_F(AlloySteelsTest, TypeConstructorTest)
{
  EXPECT_DOUBLE_EQ( 5.0, 5.0);
}

TEST_F(AlloySteelsTest, GetSpecificTypeTest)
{
  std::pair<std::string, MassCalculator::AlloySteels::Type> 
    type{"AS_4135", MassCalculator::AlloySteels::Type::AS_4135};

  EXPECT_EQ( type.first, material_AS_4135.getType().first);
  EXPECT_EQ( type.second, material_AS_4135.getType().second);
}

TEST_F(AlloySteelsTest, GetSpecificColorTest)
{
  EXPECT_EQ( std::string{"Metallic"}, material_AS_4135.getSpecificColor());
}

TEST_F(AlloySteelsTest, GetSpecificDensityTest)
{
  EXPECT_EQ( kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_AS_4135.getSpecificDensity());
}

TEST_F(AlloySteelsTest, GetSpecificGravityTest)
{
  EXPECT_EQ( meters_per_second_squared_t{2.83_mps_sq}, material_AS_4135.getSpecificGravity());
}

TEST_F(AlloySteelsTest, GetSpecificMeltingPointTest)
{
  EXPECT_EQ( kelvin_t{537.778_K}, material_AS_4135.getSpecificMeltingPoint());
}

TEST_F(AlloySteelsTest, GetSpecificPoissonsRatioTest)
{
  EXPECT_EQ( double{0.33}, material_AS_4135.getSpecificPoissonsRatio());
}

TEST_F(AlloySteelsTest, GetSpecificThermalConductivityTest)
{
  EXPECT_EQ( watt_t{990.0_W}, material_AS_4135.getSpecificThermalConductivity());
}

TEST_F(AlloySteelsTest, GetSpecificModOfElasticityTensionTest)
{
  EXPECT_EQ( pascal_t{9.9_Pa}, material_AS_4135.getSpecificModOfElasticityTension());
}

TEST_F(AlloySteelsTest, GetSpecificModOfElasticityTorsionTest)
{
  EXPECT_EQ( pascal_t{3.8_Pa}, material_AS_4135.getSpecificModOfElasticityTorsion());
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}