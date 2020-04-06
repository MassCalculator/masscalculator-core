#include "nickel_test.hpp"

namespace MassCalculatorTest::MaterialsTest
{
  /**
   * @brief Construct a new Nickel object
   * 
   */
  TEST_F(NickelTest, TypeConstructorTest)
  {
    EXPECT_DOUBLE_EQ(5.0, 5.0);
  }

  /**
   * @brief Get Specific Type for specific material
   * 
   */
  TEST_F(NickelTest, GetSpecificTypeTest)
  {
    std::pair<std::string, MassCalculator::Materials::Nickel::Type> 
      type{"N_201", MassCalculator::Materials::Nickel::Type::N_201};

    EXPECT_EQ(type.first, material_N_201.getType().first);
    EXPECT_EQ(type.second, material_N_201.getType().second);

    type = {"N_210", MassCalculator::Materials::Nickel::Type::N_210};
    EXPECT_EQ(type.first, material_N_210.getType().first);
    EXPECT_EQ(type.second, material_N_210.getType().second);

    type = {"N_220", MassCalculator::Materials::Nickel::Type::N_220};
    EXPECT_EQ(type.first, material_N_220.getType().first);
    EXPECT_EQ(type.second, material_N_220.getType().second);

    type = {"N_230", MassCalculator::Materials::Nickel::Type::N_230};
    EXPECT_EQ(type.first, material_N_230.getType().first);
    EXPECT_EQ(type.second, material_N_230.getType().second);

    type = {"N_400", MassCalculator::Materials::Nickel::Type::N_400};
    EXPECT_EQ(type.first, material_N_400.getType().first);
    EXPECT_EQ(type.second, material_N_400.getType().second);
  }

  /**
   * @brief Get Specific Color for specific material
   * 
   */
  TEST_F(NickelTest, GetSpecificColorTest)
  {
    EXPECT_EQ(std::string{"Metallic"}, material_N_201.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_N_210.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_N_220.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_N_230.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_N_400.getSpecificColor());
  }

  /**
   * @brief Get Specific Density for specific material
   * 
   */
  TEST_F(NickelTest, GetSpecificDensityTest)
  {
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_N_201.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_N_210.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_N_220.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_N_230.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_N_400.getSpecificDensity());
  }

  /**
   * @brief Get Specific Gravity for specific material
   * 
   */
  TEST_F(NickelTest, GetSpecificGravityTest)
  {
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_N_201.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_N_210.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_N_220.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_N_230.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_N_400.getSpecificGravity());
  }

  /**
   * @brief Get Specific Melting Point for specific material
   * 
   */
  TEST_F(NickelTest, GetSpecificMeltingPointTest)
  {
    EXPECT_EQ(kelvin_t{537.778}, material_N_201.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_N_210.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_N_220.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_N_230.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_N_400.getSpecificMeltingPoint());
  }

  /**
   * @brief Get Specific Poissons Ratio for specific material
   * 
   */
  TEST_F(NickelTest, GetSpecificPoissonsRatioTest)
  {
    EXPECT_EQ(double{0.33}, material_N_201.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_N_210.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_N_220.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_N_230.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_N_400.getSpecificPoissonsRatio());
  }

  /**
   * @brief Get Specific Thermal Conductivity for specific material
   * 
   */
  TEST_F(NickelTest, GetSpecificThermalConductivityTest)
  {
    EXPECT_EQ(watt_t{990.0}, material_N_201.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_N_210.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_N_220.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_N_230.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_N_400.getSpecificThermalConductivity());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Tension for specific material
   * 
   */
  TEST_F(NickelTest, GetSpecificModOfElasticityTensionTest)
  {
    EXPECT_EQ(pascal_t{9.9}, material_N_201.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_N_210.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_N_220.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_N_230.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_N_400.getSpecificModOfElasticityTension());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Torsion for specific material
   * 
   */
  TEST_F(NickelTest, GetSpecificModOfElasticityTorsionTest)
  {
    EXPECT_EQ(pascal_t{3.8}, material_N_201.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_N_210.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_N_220.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_N_230.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_N_400.getSpecificModOfElasticityTorsion());
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