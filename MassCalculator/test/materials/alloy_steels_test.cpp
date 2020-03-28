#include "alloy_steels_test.hpp"

/**
 * @brief Construct a new AlloySteels object
 * 
 */
TEST_F(AlloySteelsTest, TypeConstructorTest)
{
  EXPECT_DOUBLE_EQ(5.0, 5.0);
}

/**
 * @brief Get Specific Type for specific material
 * 
 */
TEST_F(AlloySteelsTest, GetSpecificTypeTest)
{
  std::pair<std::string, MassCalculator::AlloySteels::Type> 
    type{"AS_4135", MassCalculator::AlloySteels::Type::AS_4135};

  EXPECT_EQ(type.first, material_AS_4135.getType().first);
  EXPECT_EQ(type.second, material_AS_4135.getType().second);

  type = {"AS_4140", MassCalculator::AlloySteels::Type::AS_4140};
  EXPECT_EQ(type.first, material_AS_4140.getType().first);
  EXPECT_EQ(type.second, material_AS_4140.getType().second);

  type = {"AS_4340", MassCalculator::AlloySteels::Type::AS_4340};
  EXPECT_EQ(type.first, material_AS_4340.getType().first);
  EXPECT_EQ(type.second, material_AS_4340.getType().second);
}

/**
 * @brief Get Specific Color for specific material
 * 
 */
TEST_F(AlloySteelsTest, GetSpecificColorTest)
{
  EXPECT_EQ(std::string{"Metallic"}, material_AS_4135.getSpecificColor());
  EXPECT_EQ(std::string{"Metallic"}, material_AS_4140.getSpecificColor());
  EXPECT_EQ(std::string{"Metallic"}, material_AS_4340.getSpecificColor());
}

/**
 * @brief Get Specific Density for specific material
 * 
 */
TEST_F(AlloySteelsTest, GetSpecificDensityTest)
{
  EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_AS_4135.getSpecificDensity());
  EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_AS_4140.getSpecificDensity());
  EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_AS_4340.getSpecificDensity());
}

/**
 * @brief Get Specific Gravity for specific material
 * 
 */
TEST_F(AlloySteelsTest, GetSpecificGravityTest)
{
  EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_AS_4135.getSpecificGravity());
  EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_AS_4140.getSpecificGravity());
  EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_AS_4340.getSpecificGravity());
}

/**
 * @brief Get Specific Melting Point for specific material
 * 
 */
TEST_F(AlloySteelsTest, GetSpecificMeltingPointTest)
{
  EXPECT_EQ(kelvin_t{537.778_K}, material_AS_4135.getSpecificMeltingPoint());
  EXPECT_EQ(kelvin_t{537.778_K}, material_AS_4140.getSpecificMeltingPoint());
  EXPECT_EQ(kelvin_t{537.778_K}, material_AS_4340.getSpecificMeltingPoint());
}

/**
 * @brief Get Specific Poissons Ratio for specific material
 * 
 */
TEST_F(AlloySteelsTest, GetSpecificPoissonsRatioTest)
{
  EXPECT_EQ(double{0.33}, material_AS_4135.getSpecificPoissonsRatio());
  EXPECT_EQ(double{0.33}, material_AS_4140.getSpecificPoissonsRatio());
  EXPECT_EQ(double{0.33}, material_AS_4340.getSpecificPoissonsRatio());
}

/**
 * @brief Get Specific Thermal Conductivity for specific material
 * 
 */
TEST_F(AlloySteelsTest, GetSpecificThermalConductivityTest)
{
  EXPECT_EQ(watt_t{990.0_W}, material_AS_4135.getSpecificThermalConductivity());
  EXPECT_EQ(watt_t{990.0_W}, material_AS_4140.getSpecificThermalConductivity());
  EXPECT_EQ(watt_t{990.0_W}, material_AS_4340.getSpecificThermalConductivity());
}

/**
 * @brief Get Specific Modulus of Elasticity Tension for specific material
 * 
 */
TEST_F(AlloySteelsTest, GetSpecificModOfElasticityTensionTest)
{
  EXPECT_EQ(pascal_t{9.9_Pa}, material_AS_4135.getSpecificModOfElasticityTension());
  EXPECT_EQ(pascal_t{9.9_Pa}, material_AS_4140.getSpecificModOfElasticityTension());
  EXPECT_EQ(pascal_t{9.9_Pa}, material_AS_4340.getSpecificModOfElasticityTension());
}

/**
 * @brief Get Specific Modulus of Elasticity Torsion for specific material
 * 
 */
TEST_F(AlloySteelsTest, GetSpecificModOfElasticityTorsionTest)
{
  EXPECT_EQ(pascal_t{3.8_Pa}, material_AS_4135.getSpecificModOfElasticityTorsion());
  EXPECT_EQ(pascal_t{3.8_Pa}, material_AS_4140.getSpecificModOfElasticityTorsion());
  EXPECT_EQ(pascal_t{3.8_Pa}, material_AS_4340.getSpecificModOfElasticityTorsion());
}

/**
 * @brief Main function to run these tests
 * 
 */
int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}