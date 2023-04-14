/**
 * @file object_interface_test.h
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
#ifndef MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_TESTS_INTERFACE_OBJECT_INTERFACE_TEST_H_
#define MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_TESTS_INTERFACE_OBJECT_INTERFACE_TEST_H_
#include <gtest/gtest.h> // for ::testing::Test and TEST_F

#include "masscalculator/masscalculator-core/interface/object_interface.h" // for Object<T, U>
#include "masscalculator/masscalculator-core/materials/constants/alloy_coppers.h" // for alloycopper::k*
#include "masscalculator/masscalculator-core/materials/materials.hh" // for Materials*
#include "masscalculator/masscalculator-core/shapes/shapes.hh" // for Shapes*

/**
 * @brief Default Object Interface test namespace
 */
namespace masscalculator_test::core_test::interface_test {
/**
 * @brief The test fixture for testing class ObjectInterface.
 *
 */
class ObjectInterfaceTest : public ::testing::Test {
 protected:
  void SetUp() override {
    shape =
        std::make_unique<masscalculator::core::shapes::Cylinder>(0.0_m, 0.0_m);

    material = std::make_unique<masscalculator::core::materials::AlloyCoppers>(
        masscalculator::core::materials::constants::alloycopper::k145Telluirum);

    object_cylinder_alloycopper =
        std::make_unique<masscalculator::core::interface::Object<
            masscalculator::core::shapes::Shape<
                masscalculator::core::shapes::Cylinder>,
            masscalculator::core::materials::Material<
                masscalculator::core::materials::AlloyCoppers>>>(shape,
                                                                 material);
  }

  void TearDown() override {
    shape.reset();
    material.reset();
    object_cylinder_alloycopper.reset();
  }

  /**
   * @brief Construct a new ObjectInterfaceTest object
   */
  ObjectInterfaceTest() = default;

  /**
   * @brief Destroy the ObjectInterfaceTest object
   */
  ~ObjectInterfaceTest() override = default;

  /**
   * @brief Member objects for class Shape
   */
  std::unique_ptr<masscalculator::core::shapes::Shape<
      masscalculator::core::shapes::Cylinder>>
      shape;

  /**
   * @brief Member objects for class Material
   */
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloyCoppers>>
      material;

  /**
   * @brief Member objects for class Object
   */
  std::unique_ptr<masscalculator::core::interface::Object<
      masscalculator::core::shapes::Shape<
          masscalculator::core::shapes::Cylinder>,
      masscalculator::core::materials::Material<
          masscalculator::core::materials::AlloyCoppers>>>
      object_cylinder_alloycopper;
};
} // namespace masscalculator_test::core_test::interface_test
#endif // MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_TESTS_INTERFACE_OBJECT_INTERFACE_TEST_H_
