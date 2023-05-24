/**
 * @file cylinder_test.cc
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Defines unit tests for the Cylinder class.
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
#include "cylinder_test.h" // for AlloyCoppersTest

#include <gtest/gtest.h> // for ::testing::Test and TEST_F

#include "masscalculator/masscalculator-core/shapes/cylinder.h" // for Cylinder::Type
#include "masscalculator/third_party/units/units.h"             // for units::*

namespace masscalculator_test::core_test::shapes_test {
TEST_F(CylinderTest, GetTypeTest) {
  EXPECT_EQ(masscalculator::core::shapes::Cylinder::Type::kCylinder,
            cylinder->GetType());
}

TEST_F(CylinderTest, GetSurfaceAreaTest) {
  EXPECT_EQ(units::area::square_meter_t{0_sq_m}, cylinder->GetSurfaceArea());
}

TEST_F(CylinderTest, GetSurfaceAreaAfterSetSizeTest) {
  EXPECT_EQ(units::area::square_meter_t{0_sq_m}, cylinder->GetSurfaceArea());
}

TEST_F(CylinderTest, GetVolumeTest) {
  EXPECT_TRUE(cylinder->SetSize(0.1_m, 0.2_m));
  EXPECT_NEAR(units::volume::cubic_meter_t{0.0062831_cu_m}.to<double>(),
              cylinder->GetVolume().to<double>(), 0.001);
}

TEST_F(CylinderTest, GetVolumeAfterSetSizeTest) {
  EXPECT_TRUE(cylinder->SetSize(0.2_m, 0.3_m));
  EXPECT_NEAR(units::volume::cubic_meter_t{0.0376991_cu_m}.to<double>(),
              cylinder->GetVolume().to<double>(), 0.001);
}

TEST_F(CylinderTest, SetSizeTest) {
  EXPECT_TRUE(cylinder->SetSize(0.1_m, 0.1_m));
}
} // namespace masscalculator_test::core_test::shapes_test

/**
 * @brief Main function to run these tests
 *
 */
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
