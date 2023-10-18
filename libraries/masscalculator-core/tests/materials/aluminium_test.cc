/**
 * @file aluminium_test.cc
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Defines unit tests for the Aluminium class.
 * @version 0.3
 * @date 2023-06-07
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
#include "masscalculator/masscalculator-core/materials/aluminium.h" // for Aluminium::Color

#include <gtest/gtest.h> // for ::testing::Test and TEST_F

#include <memory>  // for std::unique_ptr
#include <sstream> // for std::ostringstream
#include <string>  // for std::string
#include <utility> // for std::pair

#include "aluminium_test.h" // for AluminiumTest
#include "masscalculator/masscalculator-core/materials/constants/aluminium.h" // for aluminium::k*
#include "masscalculator/masscalculator-core/materials/constants/color.h" // for color::k*
#include "masscalculator/third_party/units/units.h" // for units::*

namespace masscalculator_test::core_test::materials_test {
TEST_F(AluminiumTest, GetClassNameTest) {
  EXPECT_EQ(masscalculator::core::materials::constants::material::kAluminium,
            a_1100->GetClassName());
  EXPECT_EQ(masscalculator::core::materials::constants::material::kAluminium,
            a_2011->GetClassName());
  EXPECT_EQ(masscalculator::core::materials::constants::material::kAluminium,
            a_2014->GetClassName());
  EXPECT_EQ(masscalculator::core::materials::constants::material::kAluminium,
            a_2024->GetClassName());
  EXPECT_EQ(masscalculator::core::materials::constants::material::kAluminium,
            a_3003->GetClassName());
  EXPECT_EQ(masscalculator::core::materials::constants::material::kAluminium,
            a_5052->GetClassName());
  EXPECT_EQ(masscalculator::core::materials::constants::material::kAluminium,
            a_6061->GetClassName());
  EXPECT_EQ(masscalculator::core::materials::constants::material::kAluminium,
            a_6063->GetClassName());
  EXPECT_EQ(masscalculator::core::materials::constants::material::kAluminium,
            a_7075->GetClassName());
}

TEST_F(AluminiumTest, GetGenericTypeTest) {
  EXPECT_EQ(masscalculator::core::materials::Aluminium::Type::kAluminium,
            a_1100->GetType());
  EXPECT_EQ(masscalculator::core::materials::Aluminium::Type::kAluminium,
            a_2011->GetType());
  EXPECT_EQ(masscalculator::core::materials::Aluminium::Type::kAluminium,
            a_2014->GetType());
  EXPECT_EQ(masscalculator::core::materials::Aluminium::Type::kAluminium,
            a_2024->GetType());
  EXPECT_EQ(masscalculator::core::materials::Aluminium::Type::kAluminium,
            a_3003->GetType());
  EXPECT_EQ(masscalculator::core::materials::Aluminium::Type::kAluminium,
            a_5052->GetType());
  EXPECT_EQ(masscalculator::core::materials::Aluminium::Type::kAluminium,
            a_6061->GetType());
  EXPECT_EQ(masscalculator::core::materials::Aluminium::Type::kAluminium,
            a_6063->GetType());
  EXPECT_EQ(masscalculator::core::materials::Aluminium::Type::kAluminium,
            a_7075->GetType());
}

TEST_F(AluminiumTest, GetSpecificTypeTest) {
  EXPECT_EQ(masscalculator::core::materials::constants::aluminium::k1100,
            a_1100->GetSubType());
  EXPECT_EQ(masscalculator::core::materials::constants::aluminium::k2011,
            a_2011->GetSubType());
  EXPECT_EQ(masscalculator::core::materials::constants::aluminium::k2014,
            a_2014->GetSubType());
  EXPECT_EQ(masscalculator::core::materials::constants::aluminium::k2024,
            a_2024->GetSubType());
  EXPECT_EQ(masscalculator::core::materials::constants::aluminium::k3003,
            a_3003->GetSubType());
  EXPECT_EQ(masscalculator::core::materials::constants::aluminium::k5052,
            a_5052->GetSubType());
  EXPECT_EQ(masscalculator::core::materials::constants::aluminium::k6061,
            a_6061->GetSubType());
  EXPECT_EQ(masscalculator::core::materials::constants::aluminium::k6063,
            a_6063->GetSubType());
  EXPECT_EQ(masscalculator::core::materials::constants::aluminium::k7075,
            a_7075->GetSubType());
}

TEST_F(AluminiumTest, GetSpecificColorTest) {
  EXPECT_EQ(masscalculator::core::materials::Aluminium::Color::kMetallic,
            a_1100->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::Aluminium::Color::kMetallic,
            a_2011->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::Aluminium::Color::kMetallic,
            a_2014->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::Aluminium::Color::kMetallic,
            a_2024->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::Aluminium::Color::kMetallic,
            a_3003->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::Aluminium::Color::kMetallic,
            a_5052->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::Aluminium::Color::kMetallic,
            a_6061->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::Aluminium::Color::kMetallic,
            a_6063->GetSpecificColor());
  EXPECT_EQ(masscalculator::core::materials::Aluminium::Color::kMetallic,
            a_7075->GetSpecificColor());
}

TEST_F(AluminiumTest, GetSpecificDensityTest) {
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{10.0_kg_per_cu_m},
            a_1100->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{10.0_kg_per_cu_m},
            a_2011->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{10.0_kg_per_cu_m},
            a_2014->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{10.0_kg_per_cu_m},
            a_2024->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{10.0_kg_per_cu_m},
            a_3003->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{10.0_kg_per_cu_m},
            a_5052->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{10.0_kg_per_cu_m},
            a_6061->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{10.0_kg_per_cu_m},
            a_6063->GetSpecificDensity());
  EXPECT_EQ(units::density::kilograms_per_cubic_meter_t{10.0_kg_per_cu_m},
            a_7075->GetSpecificDensity());
}

TEST_F(AluminiumTest, GetSpecificMeltingPointTest) {
  EXPECT_EQ(units::temperature::kelvin_t{10.0_K},
            a_1100->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{10.0},
            a_2011->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{10.0},
            a_2014->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{10.0},
            a_2024->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{10.0},
            a_3003->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{10.0},
            a_5052->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{10.0},
            a_6061->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{10.0},
            a_6063->GetSpecificMeltingPoint());
  EXPECT_EQ(units::temperature::kelvin_t{10.0},
            a_7075->GetSpecificMeltingPoint());
}

TEST_F(AluminiumTest, GetSpecificPoissonsRatioTest) {
  EXPECT_EQ(double{0.1}, a_1100->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.1}, a_2011->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.1}, a_2014->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.1}, a_2024->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.1}, a_3003->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.1}, a_5052->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.1}, a_6061->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.1}, a_6063->GetSpecificPoissonsRatio());
  EXPECT_EQ(double{0.1}, a_7075->GetSpecificPoissonsRatio());
}

TEST_F(AluminiumTest, GetSpecificThermalConductivityTest) {
  EXPECT_EQ(units::power::watt_t{10.0_W},
            a_1100->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{10.0_W},
            a_2011->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{10.0_W},
            a_2014->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{10.0_W},
            a_2024->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{10.0_W},
            a_3003->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{10.0_W},
            a_5052->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{10.0_W},
            a_6061->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{10.0_W},
            a_6063->GetSpecificThermalConductivity());
  EXPECT_EQ(units::power::watt_t{10.0_W},
            a_7075->GetSpecificThermalConductivity());
}

TEST_F(AluminiumTest, GetSpecificModOfElasticityTensionTest) {
  EXPECT_EQ(units::pressure::pascal_t{10.0_GPa},
            a_1100->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{10.0_GPa},
            a_2011->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{10.0_GPa},
            a_2014->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{10.0_GPa},
            a_2024->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{10.0_GPa},
            a_3003->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{10.0_GPa},
            a_5052->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{10.0_GPa},
            a_6061->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{10.0_GPa},
            a_6063->GetSpecificModOfElasticityTension());
  EXPECT_EQ(units::pressure::pascal_t{10.0_GPa},
            a_7075->GetSpecificModOfElasticityTension());
}

TEST_F(AluminiumTest, OstreamOperatorAluminiumColorTest) {
  std::vector<
      std::pair<std::unique_ptr<masscalculator::core::materials::Material<
                    masscalculator::core::materials::Aluminium>>,
                std::string_view>>
      alloys;

  alloys.emplace_back(
      std::move(a_1100),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(a_2011),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(a_2014),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(a_2024),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(a_3003),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(a_5052),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(a_6061),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(a_6063),
      masscalculator::core::materials::constants::color::kMetallic);

  alloys.emplace_back(
      std::move(a_7075),
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
