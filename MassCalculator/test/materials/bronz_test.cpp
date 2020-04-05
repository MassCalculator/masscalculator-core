#include "bronz_test.hpp"

namespace MassCalculatorTest
{
  /**
   * @brief Construct a new Bronz object
   * 
   */
  TEST_F(BronzTest, TypeConstructorTest)
  {
    EXPECT_DOUBLE_EQ(5.0, 5.0);
  }

  /**
   * @brief Get Specific Type for specific material
   * 
   */
  TEST_F(BronzTest, GetSpecificTypeTest)
  {
    std::pair<std::string, MassCalculator::Materials::Bronz::Type> 
      type{"B_18Al", MassCalculator::Materials::Bronz::Type::B_18Al};

    EXPECT_EQ(type.first, material_B_18Al.getType().first);
    EXPECT_EQ(type.second, material_B_18Al.getType().second);

    type = {"B_21Al", MassCalculator::Materials::Bronz::Type::B_21Al};
    EXPECT_EQ(type.first, material_B_21Al.getType().first);
    EXPECT_EQ(type.second, material_B_21Al.getType().second);

    type = {"B_314Commercial", MassCalculator::Materials::Bronz::Type::B_314Commercial};
    EXPECT_EQ(type.first, material_B_314Commercial.getType().first);
    EXPECT_EQ(type.second, material_B_314Commercial.getType().second);

    type = {"B_485Naval", MassCalculator::Materials::Bronz::Type::B_485Naval};
    EXPECT_EQ(type.first, material_B_485Naval.getType().first);
    EXPECT_EQ(type.second, material_B_485Naval.getType().second);

    type = {"B_510Phos", MassCalculator::Materials::Bronz::Type::B_510Phos};
    EXPECT_EQ(type.first, material_B_510Phos.getType().first);
    EXPECT_EQ(type.second, material_B_510Phos.getType().second);

    type = {"B_524Phos", MassCalculator::Materials::Bronz::Type::B_524Phos};
    EXPECT_EQ(type.first, material_B_524Phos.getType().first);
    EXPECT_EQ(type.second, material_B_524Phos.getType().second);

    type = {"B_532Phos", MassCalculator::Materials::Bronz::Type::B_532Phos};
    EXPECT_EQ(type.first, material_B_532Phos.getType().first);
    EXPECT_EQ(type.second, material_B_532Phos.getType().second);

    type = {"B_534Phos", MassCalculator::Materials::Bronz::Type::B_534Phos};
    EXPECT_EQ(type.first, material_B_534Phos.getType().first);
    EXPECT_EQ(type.second, material_B_534Phos.getType().second);

    type = {"B_544Phos", MassCalculator::Materials::Bronz::Type::B_544Phos};
    EXPECT_EQ(type.first, material_B_544Phos.getType().first);
    EXPECT_EQ(type.second, material_B_544Phos.getType().second);

    type = {"B_613Al", MassCalculator::Materials::Bronz::Type::B_613Al};
    EXPECT_EQ(type.first, material_B_613Al.getType().first);
    EXPECT_EQ(type.second, material_B_613Al.getType().second);

    type = {"B_614Al", MassCalculator::Materials::Bronz::Type::B_614Al};
    EXPECT_EQ(type.first, material_B_614Al.getType().first);
    EXPECT_EQ(type.second, material_B_614Al.getType().second);

    type = {"B_623Al", MassCalculator::Materials::Bronz::Type::B_623Al};
    EXPECT_EQ(type.first, material_B_623Al.getType().first);
    EXPECT_EQ(type.second, material_B_623Al.getType().second);

    type = {"B_624Al", MassCalculator::Materials::Bronz::Type::B_624Al};
    EXPECT_EQ(type.first, material_B_624Al.getType().first);
    EXPECT_EQ(type.second, material_B_624Al.getType().second);

    type = {"B_625Al", MassCalculator::Materials::Bronz::Type::B_625Al};
    EXPECT_EQ(type.first, material_B_625Al.getType().first);
    EXPECT_EQ(type.second, material_B_625Al.getType().second);

    type = {"B_630NiAl", MassCalculator::Materials::Bronz::Type::B_630NiAl};
    EXPECT_EQ(type.first, material_B_630NiAl.getType().first);
    EXPECT_EQ(type.second, material_B_630NiAl.getType().second);

    type = {"B_642AlSi", MassCalculator::Materials::Bronz::Type::B_642AlSi};
    EXPECT_EQ(type.first, material_B_642AlSi.getType().first);
    EXPECT_EQ(type.second, material_B_642AlSi.getType().second);

    type = {"B_932Bearing", MassCalculator::Materials::Bronz::Type::B_932Bearing};
    EXPECT_EQ(type.first, material_B_932Bearing.getType().first);
    EXPECT_EQ(type.second, material_B_932Bearing.getType().second);

    type = {"B_954Al", MassCalculator::Materials::Bronz::Type::B_954Al};
    EXPECT_EQ(type.first, material_B_954Al.getType().first);
    EXPECT_EQ(type.second, material_B_954Al.getType().second);

    type = {"B_OilLite", MassCalculator::Materials::Bronz::Type::B_OilLite};
    EXPECT_EQ(type.first, material_B_OilLite.getType().first);
    EXPECT_EQ(type.second, material_B_OilLite.getType().second);
  }

  /**
   * @brief Get Specific Color for specific material
   * 
   */
  TEST_F(BronzTest, GetSpecificColorTest)
  {
    EXPECT_EQ(std::string{"Metallic"}, material_B_18Al.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_21Al.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_314Commercial.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_485Naval.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_510Phos.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_524Phos.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_532Phos.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_534Phos.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_544Phos.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_613Al.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_614Al.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_623Al.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_624Al.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_625Al.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_630NiAl.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_642AlSi.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_932Bearing.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_954Al.getSpecificColor());
    EXPECT_EQ(std::string{"Metallic"}, material_B_OilLite.getSpecificColor());
  }

  /**
   * @brief Get Specific Density for specific material
   * 
   */
  TEST_F(BronzTest, GetSpecificDensityTest)
  {
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_B_18Al.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_B_21Al.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_B_314Commercial.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_B_485Naval.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_B_510Phos.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_B_524Phos.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_B_532Phos.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_B_534Phos.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_B_544Phos.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_B_613Al.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_B_614Al.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_B_623Al.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_B_624Al.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_B_625Al.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_B_630NiAl.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_B_642AlSi.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_B_932Bearing.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_B_954Al.getSpecificDensity());
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_B_OilLite.getSpecificDensity());
  }

  /**
   * @brief Get Specific Gravity for specific material
   * 
   */
  TEST_F(BronzTest, GetSpecificGravityTest)
  {
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_B_18Al.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_B_21Al.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_B_314Commercial.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_B_485Naval.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_B_510Phos.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_B_524Phos.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_B_532Phos.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_B_534Phos.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_B_544Phos.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_B_613Al.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_B_614Al.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_B_623Al.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_B_624Al.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_B_625Al.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_B_630NiAl.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_B_642AlSi.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_B_932Bearing.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_B_954Al.getSpecificGravity());
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_B_OilLite.getSpecificGravity());
  }

  /**
   * @brief Get Specific Melting Point for specific material
   * 
   */
  TEST_F(BronzTest, GetSpecificMeltingPointTest)
  {
    EXPECT_EQ(kelvin_t{537.778}, material_B_18Al.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_B_21Al.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_B_314Commercial.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_B_485Naval.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_B_510Phos.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_B_524Phos.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_B_532Phos.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_B_534Phos.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_B_544Phos.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_B_613Al.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_B_614Al.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_B_623Al.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_B_624Al.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_B_625Al.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_B_630NiAl.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_B_642AlSi.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_B_932Bearing.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_B_954Al.getSpecificMeltingPoint());
    EXPECT_EQ(kelvin_t{537.778}, material_B_OilLite.getSpecificMeltingPoint());
  }

  /**
   * @brief Get Specific Poissons Ratio for specific material
   * 
   */
  TEST_F(BronzTest, GetSpecificPoissonsRatioTest)
  {
    EXPECT_EQ(double{0.33}, material_B_18Al.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_21Al.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_314Commercial.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_485Naval.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_510Phos.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_524Phos.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_532Phos.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_534Phos.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_544Phos.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_613Al.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_614Al.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_623Al.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_624Al.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_625Al.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_630NiAl.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_642AlSi.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_932Bearing.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_954Al.getSpecificPoissonsRatio());
    EXPECT_EQ(double{0.33}, material_B_OilLite.getSpecificPoissonsRatio());
  }

  /**
   * @brief Get Specific Thermal Conductivity for specific material
   * 
   */
  TEST_F(BronzTest, GetSpecificThermalConductivityTest)
  {
    EXPECT_EQ(watt_t{990.0}, material_B_18Al.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_B_21Al.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_B_314Commercial.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_B_485Naval.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_B_510Phos.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_B_524Phos.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_B_532Phos.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_B_534Phos.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_B_544Phos.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_B_613Al.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_B_614Al.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_B_623Al.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_B_624Al.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_B_625Al.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_B_630NiAl.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_B_642AlSi.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_B_932Bearing.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_B_954Al.getSpecificThermalConductivity());
    EXPECT_EQ(watt_t{990.0}, material_B_OilLite.getSpecificThermalConductivity());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Tension for specific material
   * 
   */
  TEST_F(BronzTest, GetSpecificModOfElasticityTensionTest)
  {
    EXPECT_EQ(pascal_t{9.9}, material_B_18Al.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_B_21Al.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_B_314Commercial.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_B_485Naval.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_B_510Phos.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_B_524Phos.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_B_532Phos.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_B_534Phos.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_B_544Phos.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_B_613Al.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_B_614Al.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_B_623Al.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_B_624Al.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_B_625Al.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_B_630NiAl.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_B_642AlSi.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_B_932Bearing.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_B_954Al.getSpecificModOfElasticityTension());
    EXPECT_EQ(pascal_t{9.9}, material_B_OilLite.getSpecificModOfElasticityTension());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Torsion for specific material
   * 
   */
  TEST_F(BronzTest, GetSpecificModOfElasticityTorsionTest)
  {
    EXPECT_EQ(pascal_t{3.8}, material_B_18Al.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_B_21Al.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_B_314Commercial.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_B_485Naval.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_B_510Phos.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_B_524Phos.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_B_532Phos.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_B_534Phos.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_B_544Phos.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_B_613Al.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_B_614Al.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_B_623Al.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_B_624Al.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_B_625Al.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_B_630NiAl.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_B_642AlSi.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_B_932Bearing.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_B_954Al.getSpecificModOfElasticityTorsion());
    EXPECT_EQ(pascal_t{3.8}, material_B_OilLite.getSpecificModOfElasticityTorsion());
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