#include "alloy_coppers_test.hpp" // for AlloyCoppersTest

#include "materials/constants/alloy_coppers.h" // for alloycopper::k*
#include "materials/constants/material.h"      // for color::k*
#include "units.h"                             // for units::*

namespace masscalculator_test::materials_test {
/**
 * @brief Construct a new AlloyCoppers object
 *
 */
TEST_F(AlloyCoppersTest, TypeConstructorTest) { EXPECT_DOUBLE_EQ(5.0, 5.0); }

/**
 * @brief Get Specific Type for specific material
 *
 */
TEST_F(AlloyCoppersTest, GetSpecificTypeTest) {
  std::pair<std::string, masscalculator::materials::AlloyCoppers::Type> type{
      masscalculator::materials::constants::alloycopper::k145Telluirum,
      masscalculator::materials::AlloyCoppers::Type::AC_145Tellvirum};

  EXPECT_EQ(type.first, ac_145_tellvirum.GetType().first);
  EXPECT_EQ(type.second, ac_145_tellvirum.GetType().second);

  type = {masscalculator::materials::constants::alloycopper::AC_194Iron,
          masscalculator::materials::AlloyCoppers::Type::AC_194Iron};
  EXPECT_EQ(type.first, ac_194_iron.GetType().first);
  EXPECT_EQ(type.second, ac_194_iron.GetType().second);

  type = {masscalculator::materials::constants::alloycopper::AC_195Iron,
          masscalculator::materials::AlloyCoppers::Type::AC_195Iron};
  EXPECT_EQ(type.first, ac_195_iron.GetType().first);
  EXPECT_EQ(type.second, ac_195_iron.GetType().second);

  type = {masscalculator::materials::constants::alloycopper::AC_182Class2,
          masscalculator::materials::AlloyCoppers::Type::AC_182Class2};
  EXPECT_EQ(type.first, ac_182_class2.GetType().first);
  EXPECT_EQ(type.second, ac_182_class2.GetType().second);

  type = {masscalculator::materials::constants::alloycopper::AC_655Silicon,
          masscalculator::materials::AlloyCoppers::Type::AC_655Silicon};
  EXPECT_EQ(type.first, ac_655_silicon.GetType().first);
  EXPECT_EQ(type.second, ac_655_silicon.GetType().second);

  type = {masscalculator::materials::constants::alloycopper::AC_706Nickel,
          masscalculator::materials::AlloyCoppers::Type::AC_706Nickel};
  EXPECT_EQ(type.first, ac_706_nickel.GetType().first);
  EXPECT_EQ(type.second, ac_706_nickel.GetType().second);

  type = {masscalculator::materials::constants::alloycopper::AC_715NickelSilver,
          masscalculator::materials::AlloyCoppers::Type::AC_715NickelSilver};
  EXPECT_EQ(type.first, ac_715_nickel_silver.GetType().first);
  EXPECT_EQ(type.second, ac_715_nickel_silver.GetType().second);

  type = {masscalculator::materials::constants::alloycopper::AC_725NickelSilver,
          masscalculator::materials::AlloyCoppers::Type::AC_725NickelSilver};
  EXPECT_EQ(type.first, ac_725_nickel_silver.GetType().first);
  EXPECT_EQ(type.second, ac_725_nickel_silver.GetType().second);

  type = {masscalculator::materials::constants::alloycopper::AC_735NickelSilver,
          masscalculator::materials::AlloyCoppers::Type::AC_735NickelSilver};
  EXPECT_EQ(type.first, ac_735_nickel_silver.GetType().first);
  EXPECT_EQ(type.second, ac_735_nickel_silver.GetType().second);

  type = {masscalculator::materials::constants::alloycopper::AC_752NickelSilver,
          masscalculator::materials::AlloyCoppers::Type::AC_752NickelSilver};
  EXPECT_EQ(type.first, ac_752_nickel_silver.GetType().first);
  EXPECT_EQ(type.second, ac_752_nickel_silver.GetType().second);

  type = {masscalculator::materials::constants::alloycopper::AC_762NickelSilver,
          masscalculator::materials::AlloyCoppers::Type::AC_762NickelSilver};
  EXPECT_EQ(type.first, ac_762_nickel_silver.GetType().first);
  EXPECT_EQ(type.second, ac_762_nickel_silver.GetType().second);

  type = {masscalculator::materials::constants::alloycopper::AC_770NickelSilver,
          masscalculator::materials::AlloyCoppers::Type::AC_770NickelSilver};
  EXPECT_EQ(type.first, ac_770_nickel_silver.GetType().first);
  EXPECT_EQ(type.second, ac_770_nickel_silver.GetType().second);

  type = {masscalculator::materials::constants::alloycopper::AC_1751Class3,
          masscalculator::materials::AlloyCoppers::Type::AC_1751Class3};
  EXPECT_EQ(type.first, ac_1751_class3.GetType().first);
  EXPECT_EQ(type.second, ac_1751_class3.GetType().second);

  type = {masscalculator::materials::constants::alloycopper::AC_1758Nickel,
          masscalculator::materials::AlloyCoppers::Type::AC_1758Nickel};
  EXPECT_EQ(type.first, ac_1758_nickel.GetType().first);
  EXPECT_EQ(type.second, ac_1758_nickel.GetType().second);

  type = {masscalculator::materials::constants::alloycopper::AC_MoldmaxBeCu,
          masscalculator::materials::AlloyCoppers::Type::AC_MoldmaxBeCu};
  EXPECT_EQ(type.first, ac_moldmax_be_cu.GetType().first);
  EXPECT_EQ(type.second, ac_moldmax_be_cu.GetType().second);

  type = {masscalculator::materials::constants::alloycopper::AC_ProthermBeCu,
          masscalculator::materials::AlloyCoppers::Type::AC_ProthermBeCu};
  EXPECT_EQ(type.first, ac_protherm_be_cu.GetType().first);
  EXPECT_EQ(type.second, ac_protherm_be_cu.GetType().second);
}

/**
 * @brief Get Specific Color for specific material
 *
 */
TEST_F(AlloyCoppersTest, GetSpecificColorTest) {
  EXPECT_EQ(std::string{masscalculator::materials::constants::color::kMetallic},
            ac_145_tellvirum.GetSpecificColor());
  EXPECT_EQ(std::string{masscalculator::materials::constants::color::kMetallic},
            ac_194_iron.GetSpecificColor());
  EXPECT_EQ(std::string{masscalculator::materials::constants::color::kMetallic},
            ac_195_iron.GetSpecificColor());
  EXPECT_EQ(std::string{masscalculator::materials::constants::color::kMetallic},
            ac_182_class2.GetSpecificColor());
  EXPECT_EQ(std::string{masscalculator::materials::constants::color::kMetallic},
            ac_655_silicon.GetSpecificColor());
  EXPECT_EQ(std::string{masscalculator::materials::constants::color::kMetallic},
            ac_706_nickel.GetSpecificColor());
  EXPECT_EQ(std::string{masscalculator::materials::constants::color::kMetallic},
            ac_715_nickel_silver.GetSpecificColor());
  EXPECT_EQ(std::string{masscalculator::materials::constants::color::kMetallic},
            ac_725_nickel_silver.GetSpecificColor());
  EXPECT_EQ(std::string{masscalculator::materials::constants::color::kMetallic},
            ac_735_nickel_silver.GetSpecificColor());
  EXPECT_EQ(std::string{masscalculator::materials::constants::color::kMetallic},
            ac_752_nickel_silver.GetSpecificColor());
  EXPECT_EQ(std::string{masscalculator::materials::constants::color::kMetallic},
            ac_762_nickel_silver.GetSpecificColor());
  EXPECT_EQ(std::string{masscalculator::materials::constants::color::kMetallic},
            ac_770_nickel_silver.GetSpecificColor());
  EXPECT_EQ(std::string{masscalculator::materials::constants::color::kMetallic},
            ac_1751_class3.GetSpecificColor());
  EXPECT_EQ(std::string{masscalculator::materials::constants::color::kMetallic},
            ac_1758_nickel.GetSpecificColor());
  EXPECT_EQ(std::string{masscalculator::materials::constants::color::kMetallic},
            ac_moldmax_be_cu.GetSpecificColor());
  EXPECT_EQ(std::string{masscalculator::materials::constants::color::kMetallic},
            ac_protherm_be_cu.GetSpecificColor());
}

/**
 * @brief Get Specific Density for specific material
 *
 */
TEST_F(AlloyCoppersTest, GetSpecificDensityTest) {
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{2.71_kg_per_cu_m},
            ac_145_tellvirum.GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{2.71_kg_per_cu_m},
            ac_194_iron.GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{2.71_kg_per_cu_m},
            ac_195_iron.GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{2.71_kg_per_cu_m},
            ac_182_class2.GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{2.71_kg_per_cu_m},
            ac_655_silicon.GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{2.71_kg_per_cu_m},
            ac_706_nickel.GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{2.71_kg_per_cu_m},
            ac_715_nickel_silver.GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{2.71_kg_per_cu_m},
            ac_725_nickel_silver.GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{2.71_kg_per_cu_m},
            ac_735_nickel_silver.GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{2.71_kg_per_cu_m},
            ac_752_nickel_silver.GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{2.71_kg_per_cu_m},
            ac_762_nickel_silver.GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{2.71_kg_per_cu_m},
            ac_770_nickel_silver.GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{2.71_kg_per_cu_m},
            ac_1751_class3.GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{2.71_kg_per_cu_m},
            ac_1758_nickel.GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{2.71_kg_per_cu_m},
            ac_moldmax_be_cu.GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{2.71_kg_per_cu_m},
            ac_protherm_be_cu.GetSpecificDensity());
}

/**
 * @brief Get Specific Gravity for specific material
 *
 */
TEST_F(AlloyCoppersTest, GetSpecificGravityTest) {
  EXPECT_EQ(units::acceleration::meters_per_second_squared_t{2.83_mps_sq},
            ac_145_tellvirum.GetSpecificGravity());
  EXPECT_EQ(units::acceleration::meters_per_second_squared_t{2.83_mps_sq},
            ac_194_iron.GetSpecificGravity());
  EXPECT_EQ(units::acceleration::meters_per_second_squared_t{2.83_mps_sq},
            ac_195_iron.GetSpecificGravity());
  EXPECT_EQ(units::acceleration::meters_per_second_squared_t{2.83_mps_sq},
            ac_182_class2.GetSpecificGravity());
  EXPECT_EQ(units::acceleration::meters_per_second_squared_t{2.83_mps_sq},
            ac_655_silicon.GetSpecificGravity());
  EXPECT_EQ(units::acceleration::meters_per_second_squared_t{2.83_mps_sq},
            ac_706_nickel.GetSpecificGravity());
  EXPECT_EQ(units::acceleration::meters_per_second_squared_t{2.83_mps_sq},
            ac_715_nickel_silver.GetSpecificGravity());
  EXPECT_EQ(units::acceleration::meters_per_second_squared_t{2.83_mps_sq},
            ac_725_nickel_silver.GetSpecificGravity());
  EXPECT_EQ(units::acceleration::meters_per_second_squared_t{2.83_mps_sq},
            ac_735_nickel_silver.GetSpecificGravity());
  EXPECT_EQ(units::acceleration::meters_per_second_squared_t{2.83_mps_sq},
            ac_752_nickel_silver.GetSpecificGravity());
  EXPECT_EQ(units::acceleration::meters_per_second_squared_t{2.83_mps_sq},
            ac_762_nickel_silver.GetSpecificGravity());
  EXPECT_EQ(units::acceleration::meters_per_second_squared_t{2.83_mps_sq},
            ac_770_nickel_silver.GetSpecificGravity());
  EXPECT_EQ(units::acceleration::meters_per_second_squared_t{2.83_mps_sq},
            ac_1751_class3.GetSpecificGravity());
  EXPECT_EQ(units::acceleration::meters_per_second_squared_t{2.83_mps_sq},
            ac_1758_nickel.GetSpecificGravity());
  EXPECT_EQ(units::acceleration::meters_per_second_squared_t{2.83_mps_sq},
            ac_moldmax_be_cu.GetSpecificGravity());
  EXPECT_EQ(units::acceleration::meters_per_second_squared_t{2.83_mps_sq},
            ac_protherm_be_cu.GetSpecificGravity());
}

/**
 * @brief Get Specific Melting Point for specific material
 *
 */
TEST_F(AlloyCoppersTest, GetSpecificMeltingPointTest) {
  EXPECT_EQ(units::temperature::kelvin_t{537.778_K},
            ac_145_tellvirum.GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{537.778_K},
            ac_194_iron.GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{537.778_K},
            ac_195_iron.GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{537.778_K},
            ac_182_class2.GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{537.778_K},
            ac_655_silicon.GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{537.778_K},
            ac_706_nickel.GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{537.778_K},
            ac_715_nickel_silver.GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{537.778_K},
            ac_725_nickel_silver.GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{537.778_K},
            ac_735_nickel_silver.GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{537.778_K},
            ac_752_nickel_silver.GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{537.778_K},
            ac_762_nickel_silver.GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{537.778_K},
            ac_770_nickel_silver.GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{537.778_K},
            ac_1751_class3.GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{537.778_K},
            ac_1758_nickel.GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{537.778_K},
            ac_moldmax_be_cu.GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{537.778_K},
            ac_protherm_be_cu.GetSpecificMeltingPoint());
}

/**
 * @brief Get Specific Poissons Ratio for specific material
 *
 */
TEST_F(AlloyCoppersTest, GetSpecificPoissonsRatioTest) {
  EXPECT_EQ(double{0.33}, ac_145_tellvirum.GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.33}, ac_194_iron.GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.33}, ac_195_iron.GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.33}, ac_182_class2.GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.33}, ac_655_silicon.GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.33}, ac_706_nickel.GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.33}, ac_715_nickel_silver.GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.33}, ac_725_nickel_silver.GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.33}, ac_735_nickel_silver.GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.33}, ac_752_nickel_silver.GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.33}, ac_762_nickel_silver.GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.33}, ac_770_nickel_silver.GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.33}, ac_1751_class3.GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.33}, ac_1758_nickel.GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.33}, ac_moldmax_be_cu.GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.33}, ac_protherm_be_cu.GetSpecificPoissonsRatio());
}

/**
 * @brief Get Specific Thermal Conductivity for specific material
 *
 */
TEST_F(AlloyCoppersTest, GetSpecificThermalConductivityTest) {
  EXPECT_EQ(units::power::watt_t{990.0_W},
            ac_145_tellvirum.GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{990.0_W},
            ac_194_iron.GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{990.0_W},
            ac_195_iron.GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{990.0_W},
            ac_182_class2.GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{990.0_W},
            ac_655_silicon.GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{990.0_W},
            ac_706_nickel.GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{990.0_W},
            ac_715_nickel_silver.GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{990.0_W},
            ac_725_nickel_silver.GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{990.0_W},
            ac_735_nickel_silver.GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{990.0_W},
            ac_752_nickel_silver.GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{990.0_W},
            ac_762_nickel_silver.GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{990.0_W},
            ac_770_nickel_silver.GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{990.0_W},
            ac_1751_class3.GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{990.0_W},
            ac_1758_nickel.GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{990.0_W},
            ac_moldmax_be_cu.GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{990.0_W},
            ac_protherm_be_cu.GetSpecificThermalConductivity());
}

/**
 * @brief Get Specific Modulus of Elasticity Tension for specific material
 *
 */
TEST_F(AlloyCoppersTest, GetSpecificModOfElasticityTensionTest) {
  EXPECT_EQ(units::pressure::pascal_t{9.9_Pa},
            ac_145_tellvirum.GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{9.9_Pa},
            ac_194_iron.GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{9.9_Pa},
            ac_195_iron.GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{9.9_Pa},
            ac_182_class2.GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{9.9_Pa},
            ac_655_silicon.GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{9.9_Pa},
            ac_706_nickel.GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{9.9_Pa},
            ac_715_nickel_silver.GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{9.9_Pa},
            ac_725_nickel_silver.GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{9.9_Pa},
            ac_735_nickel_silver.GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{9.9_Pa},
            ac_752_nickel_silver.GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{9.9_Pa},
            ac_762_nickel_silver.GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{9.9_Pa},
            ac_770_nickel_silver.GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{9.9_Pa},
            ac_1751_class3.GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{9.9_Pa},
            ac_1758_nickel.GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{9.9_Pa},
            ac_moldmax_be_cu.GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{9.9_Pa},
            ac_protherm_be_cu.GetSpecificModOfElasticityTension());
}
} // namespace masscalculator_test::materials_test

/**
 * @brief Main function to run these tests
 *
 */
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
