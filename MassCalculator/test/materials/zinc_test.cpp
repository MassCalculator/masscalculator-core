#include "zinc_test.hpp"

namespace MassCalculatorTest
{
  /**
   * @brief Construct a new Zinc object
   * 
   */
  TEST_F(ZincTest, TypeConstructorTest)
  {
    EXPECT_DOUBLE_EQ(5.0, 5.0);
  }

  /**
   * @brief Get Specific Color for specific material
   * 
   */
  TEST_F(ZincTest, GetSpecificTypeTest)
  {
    std::pair<std::string, MassCalculator::Materials::Zinc::Type> 
      type{"Z_190", MassCalculator::Materials::Zinc::Type::Z_190};

    EXPECT_EQ(type.first, material_Z_190.getType().first);
    EXPECT_EQ(type.second, material_Z_190.getType().second);

    type = {"Z_310", MassCalculator::Materials::Zinc::Type::Z_310};
    EXPECT_EQ(type.first, material_Z_310.getType().first);
    EXPECT_EQ(type.second, material_Z_310.getType().second);

    type = {"Z_320", MassCalculator::Materials::Zinc::Type::Z_320};
    EXPECT_EQ(type.first, material_Z_320.getType().first);
    EXPECT_EQ(type.second, material_Z_320.getType().second);

    type = {"Z_500", MassCalculator::Materials::Zinc::Type::Z_500};
    EXPECT_EQ(type.first, material_Z_500.getType().first);
    EXPECT_EQ(type.second, material_Z_500.getType().second);

    type = {"Z_700", MassCalculator::Materials::Zinc::Type::Z_700};
    EXPECT_EQ(type.first, material_Z_700.getType().first);
    EXPECT_EQ(type.second, material_Z_700.getType().second);

    type = {"Z_720", MassCalculator::Materials::Zinc::Type::Z_720};
    EXPECT_EQ(type.first, material_Z_720.getType().first);
    EXPECT_EQ(type.second, material_Z_720.getType().second);

    type = {"Z_750", MassCalculator::Materials::Zinc::Type::Z_750};
    EXPECT_EQ(type.first, material_Z_750.getType().first);
    EXPECT_EQ(type.second, material_Z_750.getType().second);
  }

  /**
   * @brief Get Specific Color for specific material
   * 
   */
  TEST_F(ZincTest, GetSpecificColorTest)
  {
    EXPECT_EQ(std::string{"Metallic"}, material_Z_190.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_Z_310.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_Z_320.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_Z_500.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_Z_700.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_Z_720.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_Z_750.getSpecificColor());
  }

  /**
   * @brief Get Specific Density for specific material
   * 
   */
  TEST_F(ZincTest, GetSpecificDensityTest)
  {
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_Z_190.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_Z_310.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_Z_320.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_Z_500.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_Z_700.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_Z_720.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_Z_750.getSpecificDensity());
  }

  /**
   * @brief Get Specific Gravity for specific material
   * 
   */
  TEST_F(ZincTest, GetSpecificGravityTest)
  {
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_Z_190.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_Z_310.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_Z_320.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_Z_500.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_Z_700.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_Z_720.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_Z_750.getSpecificGravity());
  }

  /**
   * @brief Get Specific Melting Point for specific material
   * 
   */
  TEST_F(ZincTest, GetSpecificMeltingPointTest)
  {
    EXPECT_EQ(kelvin_t{537.778}, material_Z_190.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_Z_310.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_Z_320.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_Z_500.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_Z_700.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_Z_720.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_Z_750.getSpecificMeltingPoint());
  }

  /**
   * @brief Get Specific Poissons Ratio for specific material
   * 
   */
  TEST_F(ZincTest, GetSpecificPoissonsRatioTest)
  {
    EXPECT_EQ(double{0.33}, material_Z_190.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_Z_310.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_Z_320.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_Z_500.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_Z_700.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_Z_720.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_Z_750.getSpecificPoissonsRatio());
  }

  /**
   * @brief Get Specific Thermal Conductivity for specific material
   * 
   */
  TEST_F(ZincTest, GetSpecificThermalConductivityTest)
  {
    EXPECT_EQ(watt_t{990.0}, material_Z_190.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_Z_310.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_Z_320.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_Z_500.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_Z_700.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_Z_720.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_Z_750.getSpecificThermalConductivity());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Tension for specific material
   * 
   */
  TEST_F(ZincTest, GetSpecificModOfElasticityTensionTest)
  {
    EXPECT_EQ(pascal_t{9.9}, material_Z_190.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_Z_310.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_Z_320.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_Z_500.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_Z_700.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_Z_720.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_Z_750.getSpecificModOfElasticityTension());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Torsion for specific material
   * 
   */
  TEST_F(ZincTest, GetSpecificModOfElasticityTorsionTest)
  {
    EXPECT_EQ(pascal_t{3.8}, material_Z_190.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_Z_310.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_Z_320.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_Z_500.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_Z_700.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_Z_720.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_Z_750.getSpecificModOfElasticityTorsion());
  }
}//end namespace MassCalculatorTest

/**
 * @brief Main function to run these tests
 * 
 */
int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}