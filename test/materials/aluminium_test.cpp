#include "aluminium_test.hpp"

namespace MassCalculatorTest::MaterialsTest
{
  /**
   * @brief Construct a new AluminiumTest object
   * 
   */
  TEST_F(AluminiumTest, TypeConstructorTest)
  {
    EXPECT_DOUBLE_EQ(5.0, 5.0);
  }

  /**
   * @brief Get Specific Type for specific material
   * 
   */
  TEST_F(AluminiumTest, GetSpecificTypeTest)
  {
    std::pair<std::string, MassCalculator::Materials::Aluminium::Type> 
      type{MassCalculator::Materials::Constants::Aluminium::A_1100, MassCalculator::Materials::Aluminium::Type::A_1100};

    EXPECT_EQ(type.first, material_A_1100.getType().first);
    EXPECT_EQ(type.second, material_A_1100.getType().second);

    type = {MassCalculator::Materials::Constants::Aluminium::A_2011, MassCalculator::Materials::Aluminium::Type::A_2011};
    EXPECT_EQ(type.first, material_A_2011.getType().first);
    EXPECT_EQ(type.second, material_A_2011.getType().second);

    type = {MassCalculator::Materials::Constants::Aluminium::A_2014, MassCalculator::Materials::Aluminium::Type::A_2014};
    EXPECT_EQ(type.first, material_A_2014.getType().first);
    EXPECT_EQ(type.second, material_A_2014.getType().second);

    type = {MassCalculator::Materials::Constants::Aluminium::A_2024, MassCalculator::Materials::Aluminium::Type::A_2024};
    EXPECT_EQ(type.first, material_A_2024.getType().first);
    EXPECT_EQ(type.second, material_A_2024.getType().second);

    type = {MassCalculator::Materials::Constants::Aluminium::A_3003, MassCalculator::Materials::Aluminium::Type::A_3003};
    EXPECT_EQ(type.first, material_A_3003.getType().first);
    EXPECT_EQ(type.second, material_A_3003.getType().second);

    type = {MassCalculator::Materials::Constants::Aluminium::A_5052, MassCalculator::Materials::Aluminium::Type::A_5052};
    EXPECT_EQ(type.first, material_A_5052.getType().first);
    EXPECT_EQ(type.second, material_A_5052.getType().second);

    type = {MassCalculator::Materials::Constants::Aluminium::A_6061, MassCalculator::Materials::Aluminium::Type::A_6061};
    EXPECT_EQ(type.first, material_A_6061.getType().first);
    EXPECT_EQ(type.second, material_A_6061.getType().second);

    type = {MassCalculator::Materials::Constants::Aluminium::A_6063, MassCalculator::Materials::Aluminium::Type::A_6063};
    EXPECT_EQ(type.first, material_A_6063.getType().first);
    EXPECT_EQ(type.second, material_A_6063.getType().second);

    type = {MassCalculator::Materials::Constants::Aluminium::A_7075, MassCalculator::Materials::Aluminium::Type::A_7075};
    EXPECT_EQ(type.first, material_A_7075.getType().first);
    EXPECT_EQ(type.second, material_A_7075.getType().second);
  }

  /**
   * @brief Get Specific Color for specific material
   * 
   */
  TEST_F(AluminiumTest, GetSpecificColorTest)
  {
    EXPECT_EQ(std::string{MassCalculator::Materials::Constants::Color::Metallic}, material_A_1100.getSpecificColor());
    EXPECT_EQ(std::string{MassCalculator::Materials::Constants::Color::Metallic}, material_A_2011.getSpecificColor());
    EXPECT_EQ(std::string{MassCalculator::Materials::Constants::Color::Metallic}, material_A_2014.getSpecificColor());
    EXPECT_EQ(std::string{MassCalculator::Materials::Constants::Color::Metallic}, material_A_2024.getSpecificColor());
    EXPECT_EQ(std::string{MassCalculator::Materials::Constants::Color::Metallic}, material_A_3003.getSpecificColor());
    EXPECT_EQ(std::string{MassCalculator::Materials::Constants::Color::Metallic}, material_A_5052.getSpecificColor());
    EXPECT_EQ(std::string{MassCalculator::Materials::Constants::Color::Metallic}, material_A_6061.getSpecificColor());
    EXPECT_EQ(std::string{MassCalculator::Materials::Constants::Color::Metallic}, material_A_6063.getSpecificColor());
    EXPECT_EQ(std::string{MassCalculator::Materials::Constants::Color::Metallic}, material_A_7075.getSpecificColor());
  }

  /**
   * @brief Get Specific Density for specific material
   * 
   */
  TEST_F(AluminiumTest, GetSpecificDensityTest)
  {
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_A_1100.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.82}, material_A_2011.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_A_2014.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_A_2024.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_A_3003.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_A_5052.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_A_6061.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_A_6063.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_A_7075.getSpecificDensity());
  }

  /**
   * @brief Get Specific Gravity for specific material
   * 
   */
  TEST_F(AluminiumTest, GetSpecificGravityTest)
  {
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_A_1100.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_A_2011.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_A_2014.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_A_2024.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_A_3003.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_A_5052.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_A_6061.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_A_6063.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_A_7075.getSpecificGravity());
  }

  /**
   * @brief Get Specific Melting Point for specific material
   * 
   */
  TEST_F(AluminiumTest, GetSpecificMeltingPointTest)
  {
    EXPECT_EQ(kelvin_t{537.778}, material_A_1100.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{1000.00}, material_A_2011.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_A_2014.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_A_2024.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_A_3003.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_A_5052.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_A_6061.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_A_6063.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_A_7075.getSpecificMeltingPoint());
  }

  /**
   * @brief Get Specific Poissons Ratio for specific material
   * 
   */
  TEST_F(AluminiumTest, GetSpecificPoissonsRatioTest)
  {
    EXPECT_EQ(double{0.33}, material_A_1100.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_A_2011.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_A_2014.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_A_2024.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_A_3003.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_A_5052.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_A_6061.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_A_6063.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_A_7075.getSpecificPoissonsRatio());
  }

  /**
   * @brief Get Specific Thermal Conductivity for specific material
   * 
   */
  TEST_F(AluminiumTest, GetSpecificThermalConductivityTest)
  {
    EXPECT_EQ(watt_t{990.0}, material_A_1100.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_A_2011.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_A_2014.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_A_2024.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_A_3003.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_A_5052.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_A_6061.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_A_6063.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_A_7075.getSpecificThermalConductivity());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Tension for specific material
   * 
   */
  TEST_F(AluminiumTest, GetSpecificModOfElasticityTensionTest)
  {
    EXPECT_EQ(pascal_t{9.9}, material_A_1100.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{10.2}, material_A_2011.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_A_2014.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_A_2024.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_A_3003.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_A_5052.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_A_6061.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_A_6063.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_A_7075.getSpecificModOfElasticityTension());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Torsion for specific material
   * 
   */
  TEST_F(AluminiumTest, GetSpecificModOfElasticityTorsionTest)
  {
    EXPECT_EQ(pascal_t{3.8}, material_A_1100.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.85}, material_A_2011.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_A_2014.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_A_2024.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_A_3003.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_A_5052.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_A_6061.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_A_6063.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_A_7075.getSpecificModOfElasticityTorsion());
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