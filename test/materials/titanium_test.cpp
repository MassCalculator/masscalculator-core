#include "titanium_test.hpp"

namespace MassCalculatorTest::MaterialsTest
{
  /**
   * @brief Construct a new Titanium object
   * 
   */
  TEST_F(TitaniumTest, TypeConstructorTest)
  {
    EXPECT_DOUBLE_EQ(5.0, 5.0);
  }

  /**
   * @brief Get Specific Color for specific material
   * 
   */
  TEST_F(TitaniumTest, GetSpecificTypeTest)
  {
    std::pair<std::string, MassCalculator::Materials::Titanium::Type> 
      type{MassCalculator::Materials::Constants::Titanium::T_6Al4V, MassCalculator::Materials::Titanium::Type::T_6Al4V};

    EXPECT_EQ(type.first, material_T_6Al4V.getType().first);
    EXPECT_EQ(type.second, material_T_6Al4V.getType().second);

    type = {MassCalculator::Materials::Constants::Titanium::T_Grade2, MassCalculator::Materials::Titanium::Type::T_Grade2};
    EXPECT_EQ(type.first, material_T_Grade2.getType().first);
    EXPECT_EQ(type.second, material_T_Grade2.getType().second);

    type = {MassCalculator::Materials::Constants::Titanium::T_Grade4, MassCalculator::Materials::Titanium::Type::T_Grade4};
    EXPECT_EQ(type.first, material_T_Grade4.getType().first);
    EXPECT_EQ(type.second, material_T_Grade4.getType().second);

    type = {MassCalculator::Materials::Constants::Titanium::T_Grade5, MassCalculator::Materials::Titanium::Type::T_Grade5};
    EXPECT_EQ(type.first, material_T_Grade5.getType().first);
    EXPECT_EQ(type.second, material_T_Grade5.getType().second);
  }

  /**
   * @brief Get Specific Color for specific material
   * 
   */
  TEST_F(TitaniumTest, GetSpecificColorTest)
  {
    EXPECT_EQ(std::string{MassCalculator::Materials::Constants::Color::Metallic}, material_T_6Al4V.getSpecificColor());
    EXPECT_EQ(std::string{MassCalculator::Materials::Constants::Color::Metallic}, material_T_Grade2.getSpecificColor());
    EXPECT_EQ(std::string{MassCalculator::Materials::Constants::Color::Metallic}, material_T_Grade4.getSpecificColor());
    EXPECT_EQ(std::string{MassCalculator::Materials::Constants::Color::Metallic}, material_T_Grade5.getSpecificColor());
  }

  /**
   * @brief Get Specific Density for specific material
   * 
   */
  TEST_F(TitaniumTest, GetSpecificDensityTest)
  {
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_T_6Al4V.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_T_Grade2.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_T_Grade4.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_T_Grade5.getSpecificDensity());
  }

  /**
   * @brief Get Specific Gravity for specific material
   * 
   */
  TEST_F(TitaniumTest, GetSpecificGravityTest)
  {
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_T_6Al4V.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_T_Grade2.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_T_Grade4.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_T_Grade5.getSpecificGravity());
  }

  /**
   * @brief Get Specific Melting Point for specific material
   * 
   */
  TEST_F(TitaniumTest, GetSpecificMeltingPointTest)
  {
    EXPECT_EQ(kelvin_t{537.778}, material_T_6Al4V.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_T_Grade2.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_T_Grade4.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_T_Grade5.getSpecificMeltingPoint());
  }

  /**
   * @brief Get Specific Poissons Ratio for specific material
   * 
   */
  TEST_F(TitaniumTest, GetSpecificPoissonsRatioTest)
  {
    EXPECT_EQ(double{0.33}, material_T_6Al4V.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_T_Grade2.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_T_Grade4.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_T_Grade5.getSpecificPoissonsRatio());
  }

  /**
   * @brief Get Specific Thermal Conductivity for specific material
   * 
   */
  TEST_F(TitaniumTest, GetSpecificThermalConductivityTest)
  {
    EXPECT_EQ(watt_t{990.0}, material_T_6Al4V.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_T_Grade2.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_T_Grade4.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_T_Grade5.getSpecificThermalConductivity());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Tension for specific material
   * 
   */
  TEST_F(TitaniumTest, GetSpecificModOfElasticityTensionTest)
  {
    EXPECT_EQ(pascal_t{9.9}, material_T_6Al4V.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_T_Grade2.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_T_Grade4.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_T_Grade5.getSpecificModOfElasticityTension());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Torsion for specific material
   * 
   */
  TEST_F(TitaniumTest, GetSpecificModOfElasticityTorsionTest)
  {
    EXPECT_EQ(pascal_t{3.8}, material_T_6Al4V.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_T_Grade2.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_T_Grade4.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_T_Grade5.getSpecificModOfElasticityTorsion());
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