#include "brass_test.hpp"

namespace MassCalculatorTest::MaterialsTest
{
  /**
   * @brief Construct a new Brass object
   * 
   */
  TEST_F(BrassTest, TypeConstructorTest)
  {
    EXPECT_DOUBLE_EQ(5.0, 5.0);
  }

  /**
   * @brief Get Specific Type for specific material
   * 
   */
  TEST_F(BrassTest, GetSpecificTypeTest)
  {
    std::pair<std::string, MassCalculator::Materials::Brass::Type> 
      type{"B_240Low", MassCalculator::Materials::Brass::Type::B_240Low};

    EXPECT_EQ(type.first, material_B_240Low.getType().first);
    EXPECT_EQ(type.second, material_B_240Low.getType().second);

    type = {"B_260Cartridge", MassCalculator::Materials::Brass::Type::B_260Cartridge};
    EXPECT_EQ(type.first, material_B_260Cartridge.getType().first);
    EXPECT_EQ(type.second, material_B_260Cartridge.getType().second);

    type = {"B_353Leaded", MassCalculator::Materials::Brass::Type::B_353Leaded};
    EXPECT_EQ(type.first, material_B_353Leaded.getType().first);
    EXPECT_EQ(type.second, material_B_353Leaded.getType().second);

    type = {"B_360", MassCalculator::Materials::Brass::Type::B_360};
    EXPECT_EQ(type.first, material_B_360.getType().first);
    EXPECT_EQ(type.second, material_B_360.getType().second);

    type = {"B_365", MassCalculator::Materials::Brass::Type::B_365};
    EXPECT_EQ(type.first, material_B_365.getType().first);
    EXPECT_EQ(type.second, material_B_365.getType().second);

    type = {"B_380", MassCalculator::Materials::Brass::Type::B_380};
    EXPECT_EQ(type.first, material_B_380.getType().first);
    EXPECT_EQ(type.second, material_B_380.getType().second);

    type = {"B_385", MassCalculator::Materials::Brass::Type::B_385};
    EXPECT_EQ(type.first, material_B_385.getType().first);
    EXPECT_EQ(type.second, material_B_385.getType().second);

    type = {"B_464", MassCalculator::Materials::Brass::Type::B_464};
    EXPECT_EQ(type.first, material_B_464.getType().first);
    EXPECT_EQ(type.second, material_B_464.getType().second);
  }

  /**
   * @brief Get Specific Color for specific material
   * 
   */
  TEST_F(BrassTest, GetSpecificColorTest)
  {
    EXPECT_EQ(std::string{"Metallic"}, material_B_240Low.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_260Cartridge.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_353Leaded.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_360.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_365.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_380.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_385.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_464.getSpecificColor());
  }

  /**
   * @brief Get Specific Density for specific material
   * 
   */
  TEST_F(BrassTest, GetSpecificDensityTest)
  {
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_B_240Low.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_B_260Cartridge.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_B_353Leaded.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_B_360.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_B_365.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_B_380.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_B_385.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_B_464.getSpecificDensity());
  }

  /**
   * @brief Get Specific Gravity for specific material
   * 
   */
  TEST_F(BrassTest, GetSpecificGravityTest)
  {
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_B_240Low.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_B_260Cartridge.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_B_353Leaded.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_B_360.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_B_365.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_B_380.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_B_385.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_B_464.getSpecificGravity());
  }

  /**
   * @brief Get Specific Melting Point for specific material
   * 
   */
  TEST_F(BrassTest, GetSpecificMeltingPointTest)
  {
    EXPECT_EQ(kelvin_t{537.778_K}, material_B_240Low.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_B_260Cartridge.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_B_353Leaded.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_B_360.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_B_365.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_B_380.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_B_385.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_B_464.getSpecificMeltingPoint());
  }

  /**
   * @brief Get Specific Poissons Ratio for specific material
   * 
   */
  TEST_F(BrassTest, GetSpecificPoissonsRatioTest)
  {
    EXPECT_EQ(double{0.33}, material_B_240Low.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_260Cartridge.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_353Leaded.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_360.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_365.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_380.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_385.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_464.getSpecificPoissonsRatio());
  }

  /**
   * @brief Get Specific Thermal Conductivity for specific material
   * 
   */
  TEST_F(BrassTest, GetSpecificThermalConductivityTest)
  {
    EXPECT_EQ(watt_t{990.0_W}, material_B_240Low.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_B_260Cartridge.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_B_353Leaded.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_B_360.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_B_365.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_B_380.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_B_385.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_B_464.getSpecificThermalConductivity());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Tension for specific material
   * 
   */
  TEST_F(BrassTest, GetSpecificModOfElasticityTensionTest)
  {
    EXPECT_EQ(pascal_t{9.9_Pa}, material_B_240Low.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_B_260Cartridge.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_B_353Leaded.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_B_360.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_B_365.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_B_380.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_B_385.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_B_464.getSpecificModOfElasticityTension());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Torsion for specific material
   * 
   */
  TEST_F(BrassTest, GetSpecificModOfElasticityTorsionTest)
  {
    EXPECT_EQ(pascal_t{3.8_Pa}, material_B_240Low.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_B_260Cartridge.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_B_353Leaded.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_B_360.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_B_365.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_B_380.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_B_385.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_B_464.getSpecificModOfElasticityTorsion());
  }
}//end namespace MassCalculatorTest::MaterialsTest

/**
 * @brief Main function to run these tests
 * 
 */
int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}