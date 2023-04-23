/**
 * @file example_1.cc
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains an example for using the Object Interface class.
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
#include <memory>  // for std::make_unique
#include <sstream> // for std::ostringstream

#include "masscalculator/masscalculator-base/macro_logger.h" // for LOG_*
#include "masscalculator/masscalculator-core/interface/object_interface.h" // for Object<T, U>
#include "masscalculator/masscalculator-core/materials/constants/alloy_coppers.h" // for alloycopper::k*
#include "masscalculator/masscalculator-core/materials/materials.hh" // for Materials*
#include "masscalculator/masscalculator-core/shapes/shapes.hh" // for Shapes*
#include "masscalculator/third_party/units/units.h"            // for units::*

// NOLINTNEXTLINE(google-global-names-in-headers,google-build-using-namespace)
using namespace units::literals;

int main(/*int argc, char** argv*/) {
  /**
   * @brief Create a unique_ptr for the shape, giving it the properties of the
   * shape. E.g.: A cylinder with properties: Radius 0 and Length 0.
   */
  std::unique_ptr<masscalculator::core::shapes::Shape<
      masscalculator::core::shapes::Cylinder>>
      shape = std::make_unique<masscalculator::core::shapes::Cylinder>(0.0_m,
                                                                       0.0_m);

  /**
   * @brief Create a unique_ptr for the material, giving it the properties of
   * the material. E.g.: An Alloy Copper with properties: Type 194Iron.
   */
  std::unique_ptr<masscalculator::core::materials::Material<
      masscalculator::core::materials::AlloyCoppers>>
      material = std::make_unique<
          masscalculator::core::materials::AlloyCoppers>(
          masscalculator::core::materials::constants::alloycopper::k194Iron);

  /**
   * @brief Create a unique_ptr for the object, giving it the properties of
   * the object. E.g.: The shape and material constructed earlier.
   */
  std::unique_ptr<masscalculator::core::interface::Object<
      masscalculator::core::shapes::Shape<
          masscalculator::core::shapes::Cylinder>,
      masscalculator::core::materials::Material<
          masscalculator::core::materials::AlloyCoppers>>>
      object = std::make_unique<masscalculator::core::interface::Object<
          masscalculator::core::shapes::Shape<
              masscalculator::core::shapes::Cylinder>,
          masscalculator::core::materials::Material<
              masscalculator::core::materials::AlloyCoppers>>>(shape, material);

  /**
   * @brief Declare an osstream so we capture ostream overloaded items.
   */
  std::ostringstream oss;

  /**
   * @brief Printout the properties for Shape, Material and Object.
   */
  oss.str("");
  oss << shape->ThisTShapeType();
  LOG_INFO("\n%s", oss.str().c_str());
  oss.str("");
  oss << material->ThisTMaterialType();
  LOG_INFO("\n%s", oss.str().c_str());
  oss.str("");
  oss << object->ThisObjectType();
  LOG_INFO("\n%s", oss.str().c_str());

  /**
   * @brief Change the size of the shape.
   */
  shape->SetSize(0.1_m, 0.1_m);

  /**
   * @brief Printout using logger and oss.
   */
  oss.str("");
  oss << shape->GetType();
  LOG_INFO("%s object properties:", oss.str().c_str());
  LOG_INFO("  - Type        : %s", oss.str().c_str());
  LOG_INFO("  - Volume      : %s",
           units::volume::to_string(shape->GetVolume()).c_str());
  LOG_INFO("  - Surface area: %s",
           units::area::to_string(shape->GetSurfaceArea()).c_str());

  /**
   * @brief Change the type of the material.
   */
  material->SetType(
      masscalculator::core::materials::constants::alloycopper::kMoldmaxBeCu);

  /**
   * @brief Printout using logger and oss.
   */
  LOG_INFO("%s object properties:", material->GetType().data());
  LOG_INFO("  - Type                         : %s", material->GetType().data());
  oss.str("");
  oss << material->GetSpecificColor();
  LOG_INFO("  - Color                        : %s", oss.str().c_str());
  LOG_INFO("  - Density                      : %s",
           units::density::to_string(material->GetSpecificDensity()).c_str());
  LOG_INFO("  - Melting point                : %s",
           units::temperature::to_string(material->GetSpecificMeltingPoint())
               .c_str());
  LOG_INFO("  - Poisons ratio                : %f",
           material->GetSpecificPoissonsRatio());
  LOG_INFO("  - Thermal conductivity         : %s",
           units::power::to_string(material->GetSpecificThermalConductivity())
               .c_str());
  LOG_INFO(
      "  - Modulus of elasticity tension: %s",
      units::pressure::to_string(material->GetSpecificModOfElasticityTension())
          .c_str());

  /**
   * @brief Change the shape and material of the object.
   */
  object->SetProperties(shape, material);

  /**
   * @brief Printout using logger and oss.
   */
  LOG_INFO("Object properties:");
  LOG_INFO("  - Mass: %s", units::mass::to_string(object->GetMass()).c_str());

  return 0;
}
