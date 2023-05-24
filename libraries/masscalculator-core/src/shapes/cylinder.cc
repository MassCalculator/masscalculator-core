/**
 * @file cylinder.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains the implementation for the cylinder class.
 * The cylinder class holds all the specific properties for the cylinder shape.
 * It inherits from the base class Shape and provides the getters and setters
 * for the cylinder properties.
 * @version 0.2
 * @date 2023-04-13
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
#include "masscalculator/masscalculator-core/shapes/cylinder.h" // for Cylinder

#include <memory>    // for std::make_unique
#include <ostream>   // fot std::ostream
#include <stdexcept> // for std::runtime_error
#include <string>    // for std::string

#include "masscalculator/masscalculator-base/macro_logger.h" // for LOG_*
#include "masscalculator/masscalculator-core/shapes/constants/shape.h" // for shape::k*
#include "masscalculator/masscalculator-core/shapes/shape.h" // for Shape<T>
#include "masscalculator/third_party/units/units.h"          // for units::*

namespace masscalculator::core::shapes {
Cylinder::Cylinder(units::length::meter_t radius, units::length::meter_t length)
    : properties_(std::make_unique<Properties>()) {
  if (properties_ == nullptr) {
    throw std::runtime_error{"Cylinder failed to initialize..."};
  }

  if (const auto success = SetSize(radius, length); !success) {
    LOG_ERROR("Construction of the object failed. %s", __PRETTY_FUNCTION__);
    throw std::runtime_error{"Cylinder failed to initialize..."};
  }
}

bool Cylinder::SetSize(units::length::meter_t radius,
                       units::length::meter_t length) {
  properties_->radius = radius;
  properties_->length = length;

  if (properties_->radius != radius && properties_->length != length) {
    LOG_ERROR("Could not set the size of cylinder. %s", __PRETTY_FUNCTION__);
    return false;
  }

  return SetGenericProperties();
}

[[nodiscard]] units::volume::cubic_meter_t Cylinder::GetVolume() const {
  return {M_PI * units::math::pow<2>(GetRadius()) * GetLength()};
}

[[nodiscard]] units::area::square_meter_t Cylinder::GetSurfaceArea() const {
  return {2 * M_PI * GetRadius() * (GetRadius() + GetLength())};
}

[[nodiscard]] Cylinder::Type Cylinder::GetType() const {
  return properties_->type;
}

bool Cylinder::SetGenericProperties() {
  properties_->type = Type::kCylinder;
  properties_->surface_area = GetSurfaceArea();
  properties_->volume = GetVolume();

  return true;
}

[[nodiscard]] units::length::meter_t Cylinder::GetRadius() const {
  return {properties_->radius};
}

[[nodiscard]] units::length::meter_t Cylinder::GetLength() const {
  return {properties_->length};
}

std::ostream& operator<<(std::ostream& os, const Cylinder& obj) {
  os << std::string(obj.GetClassName()) + " object properties: ";
  os << "\n  - Type        : ";
  os << obj.GetType();
  os << "\n  - Radius      : ";
  os << obj.GetRadius();
  os << "\n  - Length      : ";
  os << obj.GetLength();
  os << "\n  - Volume      : ";
  os << obj.GetVolume();
  os << "\n  - Surface area: ";
  os << obj.GetSurfaceArea();
  os << "\n";
  return os;
}
} // namespace masscalculator::core::shapes
