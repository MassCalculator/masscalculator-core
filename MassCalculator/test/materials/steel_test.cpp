#include "steel_test.hpp"

namespace MassCalculatorTest
{
  /**
   * @brief Construct a new Steel object
   * 
   */
  TEST_F(SteelTest, TypeConstructorTest)
  {
    EXPECT_DOUBLE_EQ(5.0, 5.0);
  }

  /**
   * @brief Get Specific Color for specific material
   * 
   */
  TEST_F(SteelTest, GetSpecificTypeTest)
  {
    std::pair<std::string, MassCalculator::Materials::Steel::Type> 
      type{"S_1010", MassCalculator::Materials::Steel::Type::S_1010};

    EXPECT_EQ( type.first, material_S_1010.getType().first);
    EXPECT_EQ( type.second, material_S_1010.getType().second);

    type = {"S_1012", MassCalculator::Materials::Steel::Type::S_1012};
    EXPECT_EQ(type.first, material_S_1012.getType().first);
    EXPECT_EQ(type.second, material_S_1012.getType().second);

    type = {"S_1015", MassCalculator::Materials::Steel::Type::S_1015};
    EXPECT_EQ(type.first, material_S_1015.getType().first);
    EXPECT_EQ(type.second, material_S_1015.getType().second);

    type = {"S_1018", MassCalculator::Materials::Steel::Type::S_1018};
    EXPECT_EQ(type.first, material_S_1018.getType().first);
    EXPECT_EQ(type.second, material_S_1018.getType().second);

    type = {"S_1541", MassCalculator::Materials::Steel::Type::S_1541};
    EXPECT_EQ(type.first, material_S_1541.getType().first);
    EXPECT_EQ(type.second, material_S_1541.getType().second);

    type = {"S_4140", MassCalculator::Materials::Steel::Type::S_4140};
    EXPECT_EQ(type.first, material_S_4140.getType().first);
    EXPECT_EQ(type.second, material_S_4140.getType().second);

    type = {"S_A36", MassCalculator::Materials::Steel::Type::S_A36};
    EXPECT_EQ(type.first, material_S_A36.getType().first);
    EXPECT_EQ(type.second, material_S_A36.getType().second);
  }

  /**
   * @brief Get Specific Color for specific material
   * 
   */
  TEST_F(SteelTest, GetSpecificColorTest)
  {
    EXPECT_EQ(std::string{"Metallic"}, material_S_1010.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_S_1012.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_S_1015.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_S_1018.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_S_1541.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_S_4140.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_S_A36.getSpecificColor());
  }

  /**
   * @brief Get Specific Density for specific material
   * 
   */
  TEST_F(SteelTest, GetSpecificDensityTest)
  {
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_S_1010.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_S_1012.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_S_1015.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_S_1018.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_S_1541.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_S_4140.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_S_A36.getSpecificDensity());
  }

  /**
   * @brief Get Specific Gravity for specific material
   * 
   */
  TEST_F(SteelTest, GetSpecificGravityTest)
  {
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_S_1010.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_S_1012.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_S_1015.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_S_1018.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_S_1541.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_S_4140.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_S_A36.getSpecificGravity());
  }

  /**
   * @brief Get Specific Melting Point for specific material
   * 
   */
  TEST_F(SteelTest, GetSpecificMeltingPointTest)
  {
    EXPECT_EQ(kelvin_t{537.778}, material_S_1010.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_S_1012.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_S_1015.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_S_1018.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_S_1541.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_S_4140.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_S_A36.getSpecificMeltingPoint());
  }

  /**
   * @brief Get Specific Poissons Ratio for specific material
   * 
   */
  TEST_F(SteelTest, GetSpecificPoissonsRatioTest)
  {
    EXPECT_EQ(double{0.33}, material_S_1010.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_S_1012.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_S_1015.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_S_1018.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_S_1541.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_S_4140.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_S_A36.getSpecificPoissonsRatio());
  }

  /**
   * @brief Get Specific Thermal Conductivity for specific material
   * 
   */
  TEST_F(SteelTest, GetSpecificThermalConductivityTest)
  {
    EXPECT_EQ(watt_t{990.0}, material_S_1010.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_S_1012.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_S_1015.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_S_1018.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_S_1541.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_S_4140.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_S_A36.getSpecificThermalConductivity());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Tension for specific material
   * 
   */
  TEST_F(SteelTest, GetSpecificModOfElasticityTensionTest)
  {
    EXPECT_EQ(pascal_t{9.9}, material_S_1010.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_S_1012.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_S_1015.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_S_1018.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_S_1541.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_S_4140.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_S_A36.getSpecificModOfElasticityTension());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Torsion for specific material
   * 
   */
  TEST_F(SteelTest, GetSpecificModOfElasticityTorsionTest)
  {
    EXPECT_EQ(pascal_t{3.8}, material_S_1010.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_S_1012.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_S_1015.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_S_1018.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_S_1541.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_S_4140.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_S_A36.getSpecificModOfElasticityTorsion());
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