#include "copper_test.hpp"

namespace MassCalculatorTest::MaterialsTest
{
  /**
   * @brief Construct a new Copper object
   * 
   */
  TEST_F(CopperTest, TypeConstructorTest)
  {
    EXPECT_DOUBLE_EQ(5.0, 5.0);
  }

  /**
   * @brief Get Specific Type for specific material
   * 
   */
  TEST_F(CopperTest, GetSpecificTypeTest)
  {
    std::pair<std::string, MassCalculator::Materials::Copper::Type> 
      type{MassCalculator::Materials::Constants::Copper::C_101, MassCalculator::Materials::Copper::Type::C_101};

    EXPECT_EQ(type.first, material_C_101.getType().first);
    EXPECT_EQ(type.second, material_C_101.getType().second);

    type = {MassCalculator::Materials::Constants::Copper::C_102, MassCalculator::Materials::Copper::Type::C_102};
    EXPECT_EQ(type.first, material_C_102.getType().first);
    EXPECT_EQ(type.second, material_C_102.getType().second);

    type = {MassCalculator::Materials::Constants::Copper::C_103, MassCalculator::Materials::Copper::Type::C_103};
    EXPECT_EQ(type.first, material_C_103.getType().first);
    EXPECT_EQ(type.second, material_C_103.getType().second);

    type = {MassCalculator::Materials::Constants::Copper::C_110, MassCalculator::Materials::Copper::Type::C_110};
    EXPECT_EQ(type.first, material_C_110.getType().first);
    EXPECT_EQ(type.second, material_C_110.getType().second);

    type = {MassCalculator::Materials::Constants::Copper::C_122, MassCalculator::Materials::Copper::Type::C_122};
    EXPECT_EQ(type.first, material_C_122.getType().first);
    EXPECT_EQ(type.second, material_C_122.getType().second);
  }

  /**
   * @brief Get Specific Color for specific material
   * 
   */
  TEST_F(CopperTest, GetSpecificColorTest)
  {
    EXPECT_EQ(std::string{MassCalculator::Materials::Constants::Color::Metallic}, material_C_101.getSpecificColor());
    EXPECT_EQ(std::string{MassCalculator::Materials::Constants::Color::Metallic}, material_C_102.getSpecificColor());
    EXPECT_EQ(std::string{MassCalculator::Materials::Constants::Color::Metallic}, material_C_103.getSpecificColor());
    EXPECT_EQ(std::string{MassCalculator::Materials::Constants::Color::Metallic}, material_C_110.getSpecificColor());
    EXPECT_EQ(std::string{MassCalculator::Materials::Constants::Color::Metallic}, material_C_122.getSpecificColor());
  }

  /**
   * @brief Get Specific Density for specific material
   * 
   */
  TEST_F(CopperTest, GetSpecificDensityTest)
  {
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_C_101.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_C_102.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_C_103.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_C_110.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_C_122.getSpecificDensity());
  }

  /**
   * @brief Get Specific Gravity for specific material
   * 
   */
  TEST_F(CopperTest, GetSpecificGravityTest)
  {
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_C_101.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_C_102.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_C_103.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_C_110.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_C_122.getSpecificGravity());
  }

  /**
   * @brief Get Specific Melting Point for specific material
   * 
   */
  TEST_F(CopperTest, GetSpecificMeltingPointTest)
  {
    EXPECT_EQ(kelvin_t{537.778}, material_C_101.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_C_102.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_C_103.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_C_110.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_C_122.getSpecificMeltingPoint());
  }

  /**
   * @brief Get Specific Poissons Ratio for specific material
   * 
   */
  TEST_F(CopperTest, GetSpecificPoissonsRatioTest)
  {
    EXPECT_EQ(double{0.33}, material_C_101.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_C_102.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_C_103.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_C_110.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_C_122.getSpecificPoissonsRatio());
  }

  /**
   * @brief Get Specific Thermal Conductivity for specific material
   * 
   */
  TEST_F(CopperTest, GetSpecificThermalConductivityTest)
  {
    EXPECT_EQ(watt_t{990.0}, material_C_101.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_C_102.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_C_103.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_C_110.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_C_122.getSpecificThermalConductivity());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Tension for specific material
   * 
   */
  TEST_F(CopperTest, GetSpecificModOfElasticityTensionTest)
  {
    EXPECT_EQ(pascal_t{9.9}, material_C_101.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_C_102.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_C_103.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_C_110.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_C_122.getSpecificModOfElasticityTension());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Torsion for specific material
   * 
   */
  TEST_F(CopperTest, GetSpecificModOfElasticityTorsionTest)
  {
    EXPECT_EQ(pascal_t{3.8}, material_C_101.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_C_102.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_C_103.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_C_110.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_C_122.getSpecificModOfElasticityTorsion());
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