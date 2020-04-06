#include "stainless_steel_test.hpp"

namespace MassCalculatorTest::MaterialsTest
{
  /**
   * @brief Construct a new StainlessSteel object
   * 
   */
  TEST_F(StainlessSteelTest, TypeConstructorTest)
  {
    EXPECT_DOUBLE_EQ(5.0, 5.0);
  }

  /**
   * @brief Get Specific Color for specific material
   * 
   */
  TEST_F(StainlessSteelTest, GetSpecificTypeTest)
  {
    std::pair<std::string, MassCalculator::Materials::StainlessSteel::Type> 
      type{"SS_301", MassCalculator::Materials::StainlessSteel::Type::SS_301};

    EXPECT_EQ(type.first, material_SS_301.getType().first);
    EXPECT_EQ(type.second, material_SS_301.getType().second);

    type = {"SS_302", MassCalculator::Materials::StainlessSteel::Type::SS_302};
    EXPECT_EQ(type.first, material_SS_302.getType().first);
    EXPECT_EQ(type.second, material_SS_302.getType().second);

    type = {"SS_303", MassCalculator::Materials::StainlessSteel::Type::SS_303};
    EXPECT_EQ(type.first, material_SS_303.getType().first);
    EXPECT_EQ(type.second, material_SS_303.getType().second);

    type = {"SS_304", MassCalculator::Materials::StainlessSteel::Type::SS_304};
    EXPECT_EQ(type.first, material_SS_304.getType().first);
    EXPECT_EQ(type.second, material_SS_304.getType().second);

    type = {"SS_305", MassCalculator::Materials::StainlessSteel::Type::SS_305};
    EXPECT_EQ(type.first, material_SS_305.getType().first);
    EXPECT_EQ(type.second, material_SS_305.getType().second);

    type = {"SS_316", MassCalculator::Materials::StainlessSteel::Type::SS_316};
    EXPECT_EQ(type.first, material_SS_316.getType().first);
    EXPECT_EQ(type.second, material_SS_316.getType().second);

    type = {"SS_321", MassCalculator::Materials::StainlessSteel::Type::SS_321};
    EXPECT_EQ(type.first, material_SS_321.getType().first);
    EXPECT_EQ(type.second, material_SS_321.getType().second);

    type = {"SS_409", MassCalculator::Materials::StainlessSteel::Type::SS_409};
    EXPECT_EQ(type.first, material_SS_409.getType().first);
    EXPECT_EQ(type.second, material_SS_409.getType().second);

    type = {"SS_410", MassCalculator::Materials::StainlessSteel::Type::SS_410};
    EXPECT_EQ(type.first, material_SS_410.getType().first);
    EXPECT_EQ(type.second, material_SS_410.getType().second);

    type = {"SS_420", MassCalculator::Materials::StainlessSteel::Type::SS_420};
    EXPECT_EQ(type.first, material_SS_420.getType().first);
    EXPECT_EQ(type.second, material_SS_420.getType().second);

    type = {"SS_430", MassCalculator::Materials::StainlessSteel::Type::SS_430};
    EXPECT_EQ(type.first, material_SS_430.getType().first);
    EXPECT_EQ(type.second, material_SS_430.getType().second);

    type = {"SS_15_5", MassCalculator::Materials::StainlessSteel::Type::SS_15_5};
    EXPECT_EQ(type.first, material_SS_15_5.getType().first);
    EXPECT_EQ(type.second, material_SS_15_5.getType().second);

    type = {"SS_17_4", MassCalculator::Materials::StainlessSteel::Type::SS_17_4};
    EXPECT_EQ(type.first, material_SS_17_4.getType().first);
    EXPECT_EQ(type.second, material_SS_17_4.getType().second);
  }

  /**
   * @brief Get Specific Color for specific material
   * 
   */
  TEST_F(StainlessSteelTest, GetSpecificColorTest)
  {
    EXPECT_EQ( std::string{"Metallic"}, material_SS_301.getSpecificColor());
    EXPECT_EQ( std::string{"Metallic"}, material_SS_302.getSpecificColor());
    EXPECT_EQ( std::string{"Metallic"}, material_SS_303.getSpecificColor());
    EXPECT_EQ( std::string{"Metallic"}, material_SS_304.getSpecificColor());
    EXPECT_EQ( std::string{"Metallic"}, material_SS_305.getSpecificColor());
    EXPECT_EQ( std::string{"Metallic"}, material_SS_316.getSpecificColor());
    EXPECT_EQ( std::string{"Metallic"}, material_SS_321.getSpecificColor());
    EXPECT_EQ( std::string{"Metallic"}, material_SS_409.getSpecificColor());
    EXPECT_EQ( std::string{"Metallic"}, material_SS_410.getSpecificColor());
    EXPECT_EQ( std::string{"Metallic"}, material_SS_420.getSpecificColor());
    EXPECT_EQ( std::string{"Metallic"}, material_SS_430.getSpecificColor());
    EXPECT_EQ( std::string{"Metallic"}, material_SS_15_5.getSpecificColor());
    EXPECT_EQ( std::string{"Metallic"}, material_SS_17_4.getSpecificColor());
  }

  /**
   * @brief Get Specific Density for specific material
   * 
   */
  TEST_F(StainlessSteelTest, GetSpecificDensityTest)
  {
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_SS_301.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_SS_302.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_SS_303.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_SS_304.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_SS_305.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_SS_316.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_SS_321.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_SS_409.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_SS_410.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_SS_420.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_SS_430.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_SS_15_5.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_SS_17_4.getSpecificDensity());
  }

  /**
   * @brief Get Specific Gravity for specific material
   * 
   */
  TEST_F(StainlessSteelTest, GetSpecificGravityTest)
  {
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_SS_301.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_SS_302.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_SS_303.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_SS_304.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_SS_305.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_SS_316.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_SS_321.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_SS_409.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_SS_410.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_SS_420.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_SS_430.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_SS_15_5.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_SS_17_4.getSpecificGravity());
  }

  /**
   * @brief Get Specific Melting Point for specific material
   * 
   */
  TEST_F(StainlessSteelTest, GetSpecificMeltingPointTest)
  {
    EXPECT_EQ(kelvin_t{537.778}, material_SS_301.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_SS_302.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_SS_303.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_SS_304.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_SS_305.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_SS_316.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_SS_321.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_SS_409.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_SS_410.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_SS_420.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_SS_430.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_SS_15_5.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_SS_17_4.getSpecificMeltingPoint());
  }

  /**
   * @brief Get Specific Poissons Ratio for specific material
   * 
   */
  TEST_F(StainlessSteelTest, GetSpecificPoissonsRatioTest)
  {
    EXPECT_EQ(double{0.33}, material_SS_301.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_SS_302.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_SS_303.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_SS_304.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_SS_305.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_SS_316.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_SS_321.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_SS_409.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_SS_410.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_SS_420.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_SS_430.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_SS_15_5.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_SS_17_4.getSpecificPoissonsRatio());
  }

  /**
   * @brief Get Specific Thermal Conductivity for specific material
   * 
   */
  TEST_F(StainlessSteelTest, GetSpecificThermalConductivityTest)
  {
    EXPECT_EQ(watt_t{990.0}, material_SS_301.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_SS_302.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_SS_303.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_SS_304.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_SS_305.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_SS_316.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_SS_321.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_SS_409.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_SS_410.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_SS_420.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_SS_430.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_SS_15_5.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_SS_17_4.getSpecificThermalConductivity());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Tension for specific material
   * 
   */
  TEST_F(StainlessSteelTest, GetSpecificModOfElasticityTensionTest)
  {
    EXPECT_EQ(pascal_t{9.9}, material_SS_301.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_SS_302.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_SS_303.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_SS_304.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_SS_305.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_SS_316.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_SS_321.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_SS_409.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_SS_410.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_SS_420.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_SS_430.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_SS_15_5.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_SS_17_4.getSpecificModOfElasticityTension());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Torsion for specific material
   * 
   */
  TEST_F(StainlessSteelTest, GetSpecificModOfElasticityTorsionTest)
  {
    EXPECT_EQ(pascal_t{3.8}, material_SS_301.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_SS_302.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_SS_303.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_SS_304.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_SS_305.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_SS_316.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_SS_321.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_SS_409.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_SS_410.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_SS_420.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_SS_430.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_SS_15_5.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_SS_17_4.getSpecificModOfElasticityTorsion());
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