/**
 * @file alloy_coppers_test.cc
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Defines unit tests for the AlloyCoppers class.
 * @version 0.2
 * @date 2023-04-03
 *
 * @copyright Copyright (c) 2023, MassCalculator, Org., All rights reserved.
 * @license This project is released under the  MIT license (MIT).
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "alloy_coppers_test.h" // for AlloyCoppersTest

#include <gtest/gtest.h> // for ::testing::Test and TEST_F

#include <memory>  // for std::unique_ptr
#include <sstream> // for std::ostringstream
#include <string>  // for std::string
#include <utility> // for std::pair

#include "masscalculator/masscalculator-core/materials/alloy_coppers.h" // for AlloyCoppers::Color
#include "masscalculator/masscalculator-core/materials/constants/alloy_coppers.h" // for alloycopper::k*
#include "masscalculator/masscalculator-core/materials/constants/color.h" // for color::k*
#include "masscalculator/third_party/units/units.h" // for units::*

namespace masscalculator_test::core_test::materials_test {
TEST_F(AlloyCoppersTest, GetSpecificTypeTest) {
  EXPECT_EQ(
      masscalculator::core::materials::constants::alloycopper::k145Telluirum,
      ac_145_telluirum->GetType());
  EXPECT_EQ(masscalculator::core::materials::constants::alloycopper::k194Iron,
            ac_194_iron->GetType());
  EXPECT_EQ(masscalculator::core::materials::constants::alloycopper::k195Iron,
            ac_195_iron->GetType());
  EXPECT_EQ(
      masscalculator::core::materials::constants::alloycopper::k172Beryllium,
      ac_172_beryllium->GetType());
  EXPECT_EQ(masscalculator::core::materials::constants::alloycopper::k182Class2,
            ac_182_class2->GetType());
  EXPECT_EQ(
      masscalculator::core::materials::constants::alloycopper::k655Silicon,
      ac_655_silicon->GetType());
  EXPECT_EQ(masscalculator::core::materials::constants::alloycopper::k706Nickel,
            ac_706_nickel->GetType());
  EXPECT_EQ(
      masscalculator::core::materials::constants::alloycopper::k715NickelSilver,
      ac_715_nickel_silver->GetType());
  EXPECT_EQ(
      masscalculator::core::materials::constants::alloycopper::k725NickelSilver,
      ac_725_nickel_silver->GetType());
  EXPECT_EQ(
      masscalculator::core::materials::constants::alloycopper::k735NickelSilver,
      ac_735_nickel_silver->GetType());
  EXPECT_EQ(
      masscalculator::core::materials::constants::alloycopper::k752NickelSilver,
      ac_752_nickel_silver->GetType());
  EXPECT_EQ(
      masscalculator::core::materials::constants::alloycopper::k762NickelSilver,
      ac_762_nickel_silver->GetType());
  EXPECT_EQ(
      masscalculator::core::materials::constants::alloycopper::k770NickelSilver,
      ac_770_nickel_silver->GetType());
  EXPECT_EQ(
      masscalculator::core::materials::constants::alloycopper::k1751Class3,
      ac_1751_class3->GetType());
  EXPECT_EQ(
      masscalculator::core::materials::constants::alloycopper::k1758Nickel,
      ac_1758_nickel->GetType());
  EXPECT_EQ(
      masscalculator::core::materials::constants::alloycopper::kMoldmaxBeCu,
      ac_moldmax_be_cu->GetType());
  EXPECT_EQ(
      masscalculator::core::materials::constants::alloycopper::kProthermBeCu,
      ac_protherm_be_cu->GetType());
}

TEST_F(AlloyCoppersTest, GetSpecificColorTest) {
  EXPECT_EQ(masscalculator::core::materials::AlloyCoppers::Color::kMetallic,
            ac_145_telluirum->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::AlloyCoppers::Color::kMetallic,
            ac_194_iron->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::AlloyCoppers::Color::kMetallic,
            ac_195_iron->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::AlloyCoppers::Color::kMetallic,
            ac_182_class2->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::AlloyCoppers::Color::kMetallic,
            ac_172_beryllium->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::AlloyCoppers::Color::kMetallic,
            ac_655_silicon->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::AlloyCoppers::Color::kMetallic,
            ac_706_nickel->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::AlloyCoppers::Color::kMetallic,
            ac_715_nickel_silver->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::AlloyCoppers::Color::kMetallic,
            ac_725_nickel_silver->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::AlloyCoppers::Color::kMetallic,
            ac_735_nickel_silver->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::AlloyCoppers::Color::kMetallic,
            ac_752_nickel_silver->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::AlloyCoppers::Color::kMetallic,
            ac_762_nickel_silver->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::AlloyCoppers::Color::kMetallic,
            ac_770_nickel_silver->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::AlloyCoppers::Color::kMetallic,
            ac_1751_class3->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::AlloyCoppers::Color::kMetallic,
            ac_1758_nickel->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::AlloyCoppers::Color::kMetallic,
            ac_moldmax_be_cu->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::AlloyCoppers::Color::kMetallic,
            ac_protherm_be_cu->GetSpecificColor());
}

TEST_F(AlloyCoppersTest, GetSpecificDensityTest) {
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{8940_kg_per_cu_m},
            ac_145_telluirum->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{7874_kg_per_cu_m},
            ac_194_iron->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{7874_kg_per_cu_m},
            ac_195_iron->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{8300_kg_per_cu_m},
            ac_172_beryllium->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{8300_kg_per_cu_m},
            ac_182_class2->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{2330_kg_per_cu_m},
            ac_655_silicon->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{8908_kg_per_cu_m},
            ac_706_nickel->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{8400_kg_per_cu_m},
            ac_715_nickel_silver->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{8450_kg_per_cu_m},
            ac_725_nickel_silver->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{8500_kg_per_cu_m},
            ac_735_nickel_silver->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{8600_kg_per_cu_m},
            ac_752_nickel_silver->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{8650_kg_per_cu_m},
            ac_762_nickel_silver->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{8700_kg_per_cu_m},
            ac_770_nickel_silver->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{8920_kg_per_cu_m},
            ac_1751_class3->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{8908_kg_per_cu_m},
            ac_1758_nickel->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{8250_kg_per_cu_m},
            ac_moldmax_be_cu->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{8250_kg_per_cu_m},
            ac_protherm_be_cu->GetSpecificDensity());
}

TEST_F(AlloyCoppersTest, GetSpecificMeltingPointTest) {
  EXPECT_EQ(units::temperature::kelvin_t{1323.15_K},
            ac_145_telluirum->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{1811.15_K},
            ac_194_iron->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{1811.15_K},
            ac_195_iron->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{1356.15_K},
            ac_172_beryllium->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{1356.15_K},
            ac_182_class2->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{1687_K},
            ac_655_silicon->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{1728_K},
            ac_706_nickel->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{1373_K},
            ac_715_nickel_silver->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{1373_K},
            ac_725_nickel_silver->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{1373_K},
            ac_735_nickel_silver->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{1373_K},
            ac_752_nickel_silver->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{1373_K},
            ac_762_nickel_silver->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{1373_K},
            ac_770_nickel_silver->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{1400_K},
            ac_1751_class3->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{1728_K},
            ac_1758_nickel->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{1356.15_K},
            ac_moldmax_be_cu->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{1356.15_K},
            ac_protherm_be_cu->GetSpecificMeltingPoint());
}

TEST_F(AlloyCoppersTest, GetSpecificPoissonsRatioTest) {
  EXPECT_EQ(double{0.34}, ac_145_telluirum->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.29}, ac_194_iron->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.29}, ac_195_iron->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.30}, ac_172_beryllium->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.30}, ac_182_class2->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.22}, ac_655_silicon->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.31}, ac_706_nickel->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.37}, ac_715_nickel_silver->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.37}, ac_725_nickel_silver->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.37}, ac_735_nickel_silver->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.37}, ac_752_nickel_silver->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.37}, ac_762_nickel_silver->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.37}, ac_770_nickel_silver->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.31}, ac_1751_class3->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.31}, ac_1758_nickel->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.30}, ac_moldmax_be_cu->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.30}, ac_protherm_be_cu->GetSpecificPoissonsRatio());
}

TEST_F(AlloyCoppersTest, GetSpecificThermalConductivityTest) {
  EXPECT_EQ(units::power::watt_t{315.0_W},
            ac_145_telluirum->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{80.4_W},
            ac_194_iron->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{80.4_W},
            ac_195_iron->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{209_W},
            ac_172_beryllium->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{209_W},
            ac_182_class2->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{149_W},
            ac_655_silicon->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{91_W},
            ac_706_nickel->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{94_W},
            ac_715_nickel_silver->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{93_W},
            ac_725_nickel_silver->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{92_W},
            ac_735_nickel_silver->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{90_W},
            ac_752_nickel_silver->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{89_W},
            ac_762_nickel_silver->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{88_W},
            ac_770_nickel_silver->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{42_W},
            ac_1751_class3->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{91_W},
            ac_1758_nickel->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{209_W},
            ac_moldmax_be_cu->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{209_W},
            ac_protherm_be_cu->GetSpecificThermalConductivity());
}

TEST_F(AlloyCoppersTest, GetSpecificModOfElasticityTensionTest) {
  EXPECT_EQ(units::pressure::pascal_t{128_GPa},
            ac_145_telluirum->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{211_GPa},
            ac_194_iron->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{211_GPa},
            ac_195_iron->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{140_GPa},
            ac_172_beryllium->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{140_GPa},
            ac_182_class2->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{50_GPa},
            ac_655_silicon->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{207_GPa},
            ac_706_nickel->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{130_GPa},
            ac_715_nickel_silver->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{130_GPa},
            ac_725_nickel_silver->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{130_GPa},
            ac_735_nickel_silver->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{130_GPa},
            ac_752_nickel_silver->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{130_GPa},
            ac_762_nickel_silver->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{130_GPa},
            ac_770_nickel_silver->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{110_GPa},
            ac_1751_class3->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{207_GPa},
            ac_1758_nickel->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{140_GPa},
            ac_moldmax_be_cu->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{140_GPa},
            ac_protherm_be_cu->GetSpecificModOfElasticityTension());
}

TEST_F(AlloyCoppersTest, OstreamOperatorAlloyCoppersColorTest) {
  std::vector<
      std::pair<std::unique_ptr<masscalculator::core::materials::Material<
                    masscalculator::core::materials::AlloyCoppers>>,
                std::string_view>>
      alloys;

  alloys.emplace_back(
      std::move(ac_145_telluirum),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(ac_194_iron),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(ac_195_iron),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(ac_172_beryllium),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(ac_655_silicon),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(ac_706_nickel),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(ac_715_nickel_silver),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(ac_725_nickel_silver),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(ac_735_nickel_silver),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(ac_752_nickel_silver),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(ac_762_nickel_silver),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(ac_770_nickel_silver),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(ac_1751_class3),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(ac_1758_nickel),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(ac_moldmax_be_cu),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(ac_protherm_be_cu),
      masscalculator::core::materials::constants::color::kMetallic);

  for (const auto& [alloy, expected] : alloys) {
    std::ostringstream type;
    type << alloy->GetSpecificColor();
    EXPECT_EQ(expected, type.str());
  }
}
} // namespace masscalculator_test::core_test::materials_test

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
