/**
 * @file brass_test.cc
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Defines unit tests for the Brass class.
 * @version 0.2
 * @date 2023-10-18
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
#include "masscalculator/masscalculator-core/materials/brass.h" // for Brass::Color

#include <gtest/gtest.h> // for ::testing::Test and TEST_F

#include <memory>  // for std::unique_ptr
#include <sstream> // for std::ostringstream
#include <string>  // for std::string
#include <utility> // for std::pair

#include "brass_test.h" // for BrassTest
#include "masscalculator/masscalculator-core/materials/constants/brass.h" // for brass::k*
#include "masscalculator/masscalculator-core/materials/constants/color.h" // for color::k*
#include "masscalculator/third_party/units/units.h" // for units::*

namespace masscalculator_test::core_test::materials_test {
TEST_F(BrassTest, GetClassNameTest) {
  EXPECT_EQ(masscalculator::core::materials::constants::material::kBrass,
            b_240Low->GetClassName());
  EXPECT_EQ(masscalculator::core::materials::constants::material::kBrass,
            b_260Cartridge->GetClassName());
  EXPECT_EQ(masscalculator::core::materials::constants::material::kBrass,
            b_353Leaded->GetClassName());
}

TEST_F(BrassTest, GetGenericTypeTest) {
  EXPECT_EQ(masscalculator::core::materials::Brass::Type::kBrass,
            b_240Low->GetType());
  EXPECT_EQ(masscalculator::core::materials::Brass::Type::kBrass,
            b_260Cartridge->GetType());
  EXPECT_EQ(masscalculator::core::materials::Brass::Type::kBrass,
            b_353Leaded->GetType());
}

TEST_F(BrassTest, GetSpecificTypeTest) {
  EXPECT_EQ(masscalculator::core::materials::constants::brass::k240Low,
            b_240Low->GetSubType());
  EXPECT_EQ(masscalculator::core::materials::constants::brass::k260Cartridge,
            b_260Cartridge->GetSubType());
  EXPECT_EQ(masscalculator::core::materials::constants::brass::k353Leaded,
            b_353Leaded->GetSubType());
}

TEST_F(BrassTest, GetSpecificColorTest) {
  EXPECT_EQ(masscalculator::core::materials::Brass::Color::kMetallic,
            b_240Low->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::Brass::Color::kMetallic,
            b_260Cartridge->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::Brass::Color::kMetallic,
            b_353Leaded->GetSpecificColor());
}

TEST_F(BrassTest, GetSpecificDensityTest) {
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{10.0_kg_per_cu_m},
            b_240Low->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{10.0_kg_per_cu_m},
            b_260Cartridge->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{10.0_kg_per_cu_m},
            b_353Leaded->GetSpecificDensity());
}

TEST_F(BrassTest, GetSpecificMeltingPointTest) {
  EXPECT_EQ(units::temperature::kelvin_t{10.0_K},
            b_240Low->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{10.0},
            b_260Cartridge->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{10.0},
            b_353Leaded->GetSpecificMeltingPoint());
}

TEST_F(BrassTest, GetSpecificPoissonsRatioTest) {
  EXPECT_EQ(double{0.1}, b_240Low->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.1}, b_260Cartridge->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.1}, b_353Leaded->GetSpecificPoissonsRatio());
}

TEST_F(BrassTest, GetSpecificThermalConductivityTest) {
  EXPECT_EQ(units::power::watt_t{10.0_W},
            b_240Low->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{10.0_W},
            b_260Cartridge->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{10.0_W},
            b_353Leaded->GetSpecificThermalConductivity());
}

TEST_F(BrassTest, GetSpecificModOfElasticityTensionTest) {
  EXPECT_EQ(units::pressure::pascal_t{10.0_GPa},
            b_240Low->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{10.0_GPa},
            b_260Cartridge->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{10.0_GPa},
            b_353Leaded->GetSpecificModOfElasticityTension());
}

TEST_F(BrassTest, OstreamOperatorBrassColorTest) {
  std::vector<
      std::pair<std::unique_ptr<masscalculator::core::materials::Material<
                    masscalculator::core::materials::Brass>>,
                std::string_view>>
      alloys;

  alloys.emplace_back(
      std::move(b_240Low),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(b_260Cartridge),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(b_353Leaded),
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
