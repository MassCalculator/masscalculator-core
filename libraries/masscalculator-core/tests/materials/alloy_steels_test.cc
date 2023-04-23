/**
 * @file alloy_steels_test.cc
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Defines unit tests for the AlloySteels class.
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
#include "masscalculator/masscalculator-core/materials/alloy_steels.h" // for AlloySteels::Color

#include <gtest/gtest.h> // for ::testing::Test and TEST_F

#include <memory>  // for std::unique_ptr
#include <sstream> // for std::ostringstream
#include <string>  // for std::string
#include <utility> // for std::pair

#include "alloy_steels_test.h" // for AlloySteelsTest
#include "masscalculator/masscalculator-core/materials/constants/alloy_steels.h" // for alloysteel::k*
#include "masscalculator/masscalculator-core/materials/constants/color.h" // for color::k*
#include "masscalculator/third_party/units/units.h" // for units::*

namespace masscalculator_test::core_test::materials_test {
TEST_F(AlloySteelsTest, GetSpecificTypeTest) {
  EXPECT_EQ(masscalculator::core::materials::constants::alloysteel::k4135,
            as_4135->GetType());
  EXPECT_EQ(masscalculator::core::materials::constants::alloysteel::k4140,
            as_4140->GetType());
  EXPECT_EQ(masscalculator::core::materials::constants::alloysteel::k4340,
            as_4340->GetType());
}

TEST_F(AlloySteelsTest, GetSpecificColorTest) {
  EXPECT_EQ(masscalculator::core::materials::AlloySteels::Color::kMetallic,
            as_4135->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::AlloySteels::Color::kMetallic,
            as_4140->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::AlloySteels::Color::kMetallic,
            as_4340->GetSpecificColor());
}

TEST_F(AlloySteelsTest, GetSpecificDensityTest) {
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{10.0_kg_per_cu_m},
            as_4135->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{10.0_kg_per_cu_m},
            as_4140->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{10.0_kg_per_cu_m},
            as_4340->GetSpecificDensity());
}

TEST_F(AlloySteelsTest, GetSpecificMeltingPointTest) {
  EXPECT_EQ(units::temperature::kelvin_t{10.0_K},
            as_4135->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{10.0},
            as_4140->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{10.0},
            as_4340->GetSpecificMeltingPoint());
}

TEST_F(AlloySteelsTest, GetSpecificPoissonsRatioTest) {
  EXPECT_EQ(double{0.1}, as_4135->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.1}, as_4140->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.1}, as_4340->GetSpecificPoissonsRatio());
}

TEST_F(AlloySteelsTest, GetSpecificThermalConductivityTest) {
  EXPECT_EQ(units::power::watt_t{10.0_W},
            as_4135->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{10.0_W},
            as_4140->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{10.0_W},
            as_4340->GetSpecificThermalConductivity());
}

TEST_F(AlloySteelsTest, GetSpecificModOfElasticityTensionTest) {
  EXPECT_EQ(units::pressure::pascal_t{10.0_GPa},
            as_4135->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{10.0_GPa},
            as_4140->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{10.0_GPa},
            as_4340->GetSpecificModOfElasticityTension());
}

TEST_F(AlloySteelsTest, OstreamOperatorAlloySteelsColorTest) {
  std::vector<
      std::pair<std::unique_ptr<masscalculator::core::materials::Material<
                    masscalculator::core::materials::AlloySteels>>,
                std::string_view>>
      alloys;

  alloys.emplace_back(
      std::move(as_4135),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(as_4140),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(as_4340),
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
