/**
 * @file alloy_steels.cc
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains the implementation for the alloy_steels class.
 * The alloy_steels class holds all the specific properties for the different
 * types of alloy_steels. It inherits from the base class Material and provides
 * the getters and setters for the alloy_steels properties.
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
#include "masscalculator/masscalculator-core/materials/alloy_steels.h" // for AlloySteels

#include <memory>      // for std::make_unique
#include <ostream>     // fot std::ostream
#include <string>      // for std::string
#include <string_view> // for std::string_view

#include "masscalculator/masscalculator-base/lua_handler.h" // for LuaScriptHandler
#include "masscalculator/masscalculator-base/macro_logger.h" // for LOG_*
#include "masscalculator/masscalculator-core/materials/constants/alloy_steels.h" // for alloysteels::k*
#include "masscalculator/masscalculator-core/materials/constants/properties.h" // for properties::k*
#include "masscalculator/masscalculator-core/materials/material.h" // for material
#include "units.h" // for units::*

namespace masscalculator::core::materials {
AlloySteels::AlloySteels(const std::string_view& type)
    : specific_properties_(std::make_unique<Properties>()),
      lua_state_(std::make_unique<base::LuaScriptHandler>(
          constants::alloysteel::kConfigPath)) {
  if (!SetType(type)) {
    LOG_ERROR("Construction of the object failed. %s", __PRETTY_FUNCTION__);
  }
}

[[nodiscard]] std::string_view AlloySteels::GetType() const {
  return kTypeString.at(specific_properties_->type);
}

[[nodiscard]] AlloySteels::Color AlloySteels::GetSpecificColor() const {
  return specific_properties_->color;
}

[[nodiscard]] units::density::kilograms_per_cubic_meter_t
AlloySteels::GetSpecificDensity() const {
  return {specific_properties_->density};
}

[[nodiscard]] units::temperature::kelvin_t
AlloySteels::GetSpecificMeltingPoint() const {
  return {specific_properties_->melting_point};
}

[[nodiscard]] double AlloySteels::GetSpecificPoissonsRatio() const {
  return specific_properties_->poissons_ratio;
}

[[nodiscard]] units::power::watt_t AlloySteels::GetSpecificThermalConductivity()
    const {
  return {specific_properties_->thermal_conductivity};
}

[[nodiscard]] units::pressure::pascal_t
AlloySteels::GetSpecificModOfElasticityTension() const {
  return {specific_properties_->mod_of_elasticity_tension};
}

bool AlloySteels::SetProperties(const Properties& properties) {
  auto fetch_from_lua_or_default = [&](const std::string& property_name,
                                       auto default_value) {
    using ValueType = decltype(default_value);
    return lua_state_->GetOrDefault<ValueType>(
        std::string(GetClassName()) + "." +
            std::string(kTypeString.at(properties.type)) + "." + property_name,
        default_value);
  };

  specific_properties_->type = kType.at(fetch_from_lua_or_default(
      constants::properties::kTypeKey, kTypeString.at(properties.type)));

  specific_properties_->color = kColor.at(fetch_from_lua_or_default(
      constants::properties::kColorKey, kColorString.at(properties.color)));

  specific_properties_->density = fetch_from_lua_or_default(
      constants::properties::kDensityKey, properties.density);

  specific_properties_->melting_point = fetch_from_lua_or_default(
      constants::properties::kMeltingPointKey, properties.melting_point);

  specific_properties_->poissons_ratio = fetch_from_lua_or_default(
      constants::properties::kPoissonsRatioKey, properties.poissons_ratio);

  specific_properties_->thermal_conductivity =
      fetch_from_lua_or_default(constants::properties::kThermalConductivityKey,
                                properties.thermal_conductivity);

  specific_properties_->mod_of_elasticity_tension = fetch_from_lua_or_default(
      constants::properties::kModOfElasticityTensionKey,
      properties.mod_of_elasticity_tension);

  return true;
}

bool AlloySteels::SetType(const std::string_view& type) {
  auto pair = type2func_.find(kType.at(type));

  if (pair != type2func_.end()) {
    pair->second();
  } else {
    LOG_ERROR("Could not set the values for type: %s",
              std::string(GetType()).c_str());
  }

  return true;
}

std::ostream& operator<<(std::ostream& os, const AlloySteels& obj) {
  os << std::string(obj.GetClassName()) + " object properties: ";
  os << "\n  - Type                         : ";
  os << obj.GetType();
  os << "\n  - Color                        : ";
  os << obj.GetSpecificColor();
  os << "\n  - Density                      : ";
  os << units::density::to_string(obj.GetSpecificDensity());
  os << "\n  - Melting point                : ";
  os << units::temperature::to_string(obj.GetSpecificMeltingPoint());
  os << "\n  - Poissons ratio               : ";
  os << std::to_string(obj.GetSpecificPoissonsRatio());
  os << "\n  - Thermal conductivity         : ";
  os << units::power::to_string(obj.GetSpecificThermalConductivity());
  os << "\n  - Modulus of elasticity tension: ";
  os << units::pressure::to_string(obj.GetSpecificModOfElasticityTension());
  os << "\n";

  return os;
}
} // namespace masscalculator::core::materials
