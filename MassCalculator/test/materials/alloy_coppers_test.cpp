#include "alloy_coppers_test.hpp"

namespace MassCalculatorTest
{
  /**
   * @brief Construct a new AlloyCoppers object
   * 
   */
  TEST_F(AlloyCoppersTest, TypeConstructorTest)
  {
    EXPECT_DOUBLE_EQ(5.0, 5.0);
  }

  /**
   * @brief Get Specific Type for specific material
   * 
   */
  TEST_F(AlloyCoppersTest, GetSpecificTypeTest)
  {
    std::pair<std::string, MassCalculator::Materials::AlloyCoppers::Type> 
      type{"AC_145Tellvirum", MassCalculator::Materials::AlloyCoppers::Type::AC_145Tellvirum};

    EXPECT_EQ(type.first, material_AC_145Tellvirum.getType().first);
    EXPECT_EQ(type.second, material_AC_145Tellvirum.getType().second);

    type = {"AC_194Iron", MassCalculator::Materials::AlloyCoppers::Type::AC_194Iron};
    EXPECT_EQ(type.first, material_AC_194Iron.getType().first);
    EXPECT_EQ(type.second, material_AC_194Iron.getType().second);

    type = {"AC_195Iron", MassCalculator::Materials::AlloyCoppers::Type::AC_195Iron};
    EXPECT_EQ(type.first, material_AC_195Iron.getType().first);
    EXPECT_EQ(type.second, material_AC_195Iron.getType().second);

    type = {"AC_182Class2", MassCalculator::Materials::AlloyCoppers::Type::AC_182Class2};
    EXPECT_EQ(type.first, material_AC_182Class2.getType().first);
    EXPECT_EQ(type.second, material_AC_182Class2.getType().second);

    type = {"AC_655Silicon", MassCalculator::Materials::AlloyCoppers::Type::AC_655Silicon};
    EXPECT_EQ(type.first, material_AC_655Silicon.getType().first);
    EXPECT_EQ(type.second, material_AC_655Silicon.getType().second);

    type = {"AC_706Nickel", MassCalculator::Materials::AlloyCoppers::Type::AC_706Nickel};
    EXPECT_EQ(type.first, material_AC_706Nickel.getType().first);
    EXPECT_EQ(type.second, material_AC_706Nickel.getType().second);

    type = {"AC_715NickelSilver", MassCalculator::Materials::AlloyCoppers::Type::AC_715NickelSilver};
    EXPECT_EQ(type.first, material_AC_715NickelSilver.getType().first);
    EXPECT_EQ(type.second, material_AC_715NickelSilver.getType().second);

    type = {"AC_725NickelSilver", MassCalculator::Materials::AlloyCoppers::Type::AC_725NickelSilver};
    EXPECT_EQ(type.first, material_AC_725NickelSilver.getType().first);
    EXPECT_EQ(type.second, material_AC_725NickelSilver.getType().second);

    type = {"AC_735NickelSilver", MassCalculator::Materials::AlloyCoppers::Type::AC_735NickelSilver};
    EXPECT_EQ(type.first, material_AC_735NickelSilver.getType().first);
    EXPECT_EQ(type.second, material_AC_735NickelSilver.getType().second);

    type = {"AC_752NickelSilver", MassCalculator::Materials::AlloyCoppers::Type::AC_752NickelSilver};
    EXPECT_EQ(type.first, material_AC_752NickelSilver.getType().first);
    EXPECT_EQ(type.second, material_AC_752NickelSilver.getType().second);

    type = {"AC_762NickelSilver", MassCalculator::Materials::AlloyCoppers::Type::AC_762NickelSilver};
    EXPECT_EQ(type.first, material_AC_762NickelSilver.getType().first);
    EXPECT_EQ(type.second, material_AC_762NickelSilver.getType().second);

    type = {"AC_770NickelSilver", MassCalculator::Materials::AlloyCoppers::Type::AC_770NickelSilver};
    EXPECT_EQ(type.first, material_AC_770NickelSilver.getType().first);
    EXPECT_EQ(type.second, material_AC_770NickelSilver.getType().second);

    type = {"AC_1751Class3", MassCalculator::Materials::AlloyCoppers::Type::AC_1751Class3};
    EXPECT_EQ(type.first, material_AC_1751Class3.getType().first);
    EXPECT_EQ(type.second, material_AC_1751Class3.getType().second);

    type = {"AC_1758Nickel", MassCalculator::Materials::AlloyCoppers::Type::AC_1758Nickel};
    EXPECT_EQ(type.first, material_AC_1758Nickel.getType().first);
    EXPECT_EQ(type.second, material_AC_1758Nickel.getType().second);

    type = {"AC_MoldmaxBeCu", MassCalculator::Materials::AlloyCoppers::Type::AC_MoldmaxBeCu};
    EXPECT_EQ(type.first, material_AC_MoldmaxBeCu.getType().first);
    EXPECT_EQ(type.second, material_AC_MoldmaxBeCu.getType().second);

    type = {"AC_ProthermBeCu", MassCalculator::Materials::AlloyCoppers::Type::AC_ProthermBeCu};
    EXPECT_EQ(type.first, material_AC_ProthermBeCu.getType().first);
    EXPECT_EQ(type.second, material_AC_ProthermBeCu.getType().second);
  }

  /**
   * @brief Get Specific Color for specific material
   * 
   */
  TEST_F(AlloyCoppersTest, GetSpecificColorTest)
  {
    EXPECT_EQ(std::string{"Metallic"}, material_AC_145Tellvirum.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_AC_194Iron.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_AC_195Iron.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_AC_182Class2.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_AC_655Silicon.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_AC_706Nickel.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_AC_715NickelSilver.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_AC_725NickelSilver.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_AC_735NickelSilver.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_AC_752NickelSilver.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_AC_762NickelSilver.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_AC_770NickelSilver.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_AC_1751Class3.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_AC_1758Nickel.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_AC_MoldmaxBeCu.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_AC_ProthermBeCu.getSpecificColor());
  }

  /**
   * @brief Get Specific Density for specific material
   * 
   */
  TEST_F(AlloyCoppersTest, GetSpecificDensityTest)
  {
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_AC_145Tellvirum.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_AC_194Iron.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_AC_195Iron.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_AC_182Class2.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_AC_655Silicon.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_AC_706Nickel.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_AC_715NickelSilver.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_AC_725NickelSilver.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_AC_735NickelSilver.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_AC_752NickelSilver.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_AC_762NickelSilver.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_AC_770NickelSilver.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_AC_1751Class3.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_AC_1758Nickel.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_AC_MoldmaxBeCu.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_AC_ProthermBeCu.getSpecificDensity());
  }

  /**
   * @brief Get Specific Gravity for specific material
   * 
   */
  TEST_F(AlloyCoppersTest, GetSpecificGravityTest)
  {
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_AC_145Tellvirum.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_AC_194Iron.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_AC_195Iron.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_AC_182Class2.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_AC_655Silicon.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_AC_706Nickel.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_AC_715NickelSilver.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_AC_725NickelSilver.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_AC_735NickelSilver.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_AC_752NickelSilver.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_AC_762NickelSilver.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_AC_770NickelSilver.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_AC_1751Class3.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_AC_1758Nickel.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_AC_MoldmaxBeCu.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_AC_ProthermBeCu.getSpecificGravity());
  }

  /**
   * @brief Get Specific Melting Point for specific material
   * 
   */
  TEST_F(AlloyCoppersTest, GetSpecificMeltingPointTest)
  {
    EXPECT_EQ(kelvin_t{537.778_K}, material_AC_145Tellvirum.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_AC_194Iron.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_AC_195Iron.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_AC_182Class2.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_AC_655Silicon.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_AC_706Nickel.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_AC_715NickelSilver.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_AC_725NickelSilver.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_AC_735NickelSilver.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_AC_752NickelSilver.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_AC_762NickelSilver.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_AC_770NickelSilver.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_AC_1751Class3.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_AC_1758Nickel.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_AC_MoldmaxBeCu.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778_K}, material_AC_ProthermBeCu.getSpecificMeltingPoint());
  }

  /**
   * @brief Get Specific Poissons Ratio for specific material
   * 
   */
  TEST_F(AlloyCoppersTest, GetSpecificPoissonsRatioTest)
  {
    EXPECT_EQ(double{0.33}, material_AC_145Tellvirum.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_AC_194Iron.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_AC_195Iron.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_AC_182Class2.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_AC_655Silicon.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_AC_706Nickel.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_AC_715NickelSilver.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_AC_725NickelSilver.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_AC_735NickelSilver.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_AC_752NickelSilver.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_AC_762NickelSilver.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_AC_770NickelSilver.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_AC_1751Class3.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_AC_1758Nickel.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_AC_MoldmaxBeCu.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_AC_ProthermBeCu.getSpecificPoissonsRatio());
  }

  /**
   * @brief Get Specific Thermal Conductivity for specific material
   * 
   */
  TEST_F(AlloyCoppersTest, GetSpecificThermalConductivityTest)
  {
    EXPECT_EQ(watt_t{990.0_W}, material_AC_145Tellvirum.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_AC_194Iron.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_AC_195Iron.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_AC_182Class2.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_AC_655Silicon.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_AC_706Nickel.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_AC_715NickelSilver.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_AC_725NickelSilver.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_AC_735NickelSilver.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_AC_752NickelSilver.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_AC_762NickelSilver.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_AC_770NickelSilver.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_AC_1751Class3.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_AC_1758Nickel.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_AC_MoldmaxBeCu.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0_W}, material_AC_ProthermBeCu.getSpecificThermalConductivity());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Tension for specific material
   * 
   */
  TEST_F(AlloyCoppersTest, GetSpecificModOfElasticityTensionTest)
  {
    EXPECT_EQ(pascal_t{9.9_Pa}, material_AC_145Tellvirum.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_AC_194Iron.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_AC_195Iron.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_AC_182Class2.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_AC_655Silicon.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_AC_706Nickel.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_AC_715NickelSilver.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_AC_725NickelSilver.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_AC_735NickelSilver.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_AC_752NickelSilver.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_AC_762NickelSilver.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_AC_770NickelSilver.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_AC_1751Class3.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_AC_1758Nickel.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_AC_MoldmaxBeCu.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9_Pa}, material_AC_ProthermBeCu.getSpecificModOfElasticityTension());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Torsion for specific material
   * 
   */
  TEST_F(AlloyCoppersTest, GetSpecificModOfElasticityTorsionTest)
  {
    EXPECT_EQ(pascal_t{3.8_Pa}, material_AC_145Tellvirum.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_AC_194Iron.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_AC_195Iron.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_AC_182Class2.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_AC_655Silicon.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_AC_706Nickel.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_AC_715NickelSilver.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_AC_725NickelSilver.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_AC_735NickelSilver.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_AC_752NickelSilver.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_AC_762NickelSilver.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_AC_770NickelSilver.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_AC_1751Class3.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_AC_1758Nickel.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_AC_MoldmaxBeCu.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8_Pa}, material_AC_ProthermBeCu.getSpecificModOfElasticityTorsion());
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