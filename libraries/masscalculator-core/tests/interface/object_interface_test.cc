/**
 * @file object_interface_test.cc
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Defines unit tests for the Object class.
 * @version 0.2
 * @date 2023-04-14
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
#include "object_interface_test.h" // for Object<T, U>

#include "masscalculator/masscalculator-core/materials/constants/alloy_coppers.h"
#include "units.h"

namespace masscalculator_test::core_test::interface_test {

namespace {
constexpr auto kControlRadius{0.05_m};
constexpr auto kControlLength{0.10_m};
constexpr auto kControlType{
    masscalculator::core::materials::constants::alloycopper::k715NickelSilver};
constexpr auto kExpectedMass{6.5973445725385664_kg};
} // namespace

TEST_F(ObjectInterfaceTest, GetMassTest) {
  EXPECT_NEAR(units::mass::kilogram_t{0.0_kg}.to<double>(),
              object_cylinder_alloycopper->GetMass().to<double>(), 0.001);
}

TEST_F(ObjectInterfaceTest, GetMassAfterSetTest) {
  shape->SetSize(kControlRadius, kControlLength);
  material->SetType(kControlType);

  object_cylinder_alloycopper->SetProperties(shape, material);

  EXPECT_NEAR(kExpectedMass.to<double>(),
              object_cylinder_alloycopper->GetMass().to<double>(), 0.001);
}
} // namespace masscalculator_test::core_test::interface_test

/**
 * @brief Main function to run these tests
 */
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
