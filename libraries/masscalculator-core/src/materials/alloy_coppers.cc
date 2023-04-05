/**
 * @file alloy_coppers.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains the implementation for the alloy_coppers class.
 * The alloy_coppers class holds all the specific properties for the different
 * types of alloy_coppers. It inherits from the base class Material and provides
 * the getters and setters for the alloy_coppers properties.
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
#include "materials/alloy_coppers.h" // for AlloyCoppers

#include <memory>  // for std::unique_ptr
#include <ostream> // fot std::ostream
#include <string>  // for std::string
#include <utility> // for std::pair and std::move

#include "lua_handler.h"                        // for LuaScriptHandler
#include "masscalculator/base/immutable_map.h"  // for ImmutableMap
#include "masscalculator/base/macro_logger.hpp" // for LOG_*
#include "materials/constants/alloy_coppers.h"  // for alloycopper::k*
#include "materials/constants/properties.h"     // for properties::k*
#include "materials/material.h"                 // for material
#include "units.h"                              // for units::*

namespace masscalculator::materials {

namespace {
constexpr base::ImmutableMap<std::string_view, AlloyCoppers::Type, 17> kType{{{
    {constants::alloycopper::k145Telluirum, AlloyCoppers::Type::k145Telluirum},
    {constants::alloycopper::k194Iron, AlloyCoppers::Type::k194Iron},
    {constants::alloycopper::k195Iron, AlloyCoppers::Type::k195Iron},
    {constants::alloycopper::k172Beryllium, AlloyCoppers::Type::k172Beryllium},
    {constants::alloycopper::k182Class2, AlloyCoppers::Type::k182Class2},
    {constants::alloycopper::k655Silicon, AlloyCoppers::Type::k655Silicon},
    {constants::alloycopper::k706Nickel, AlloyCoppers::Type::k706Nickel},
    {constants::alloycopper::k715NickelSilver,
     AlloyCoppers::Type::k715NickelSilver},
    {constants::alloycopper::k725NickelSilver,
     AlloyCoppers::Type::k725NickelSilver},
    {constants::alloycopper::k735NickelSilver,
     AlloyCoppers::Type::k735NickelSilver},
    {constants::alloycopper::k752NickelSilver,
     AlloyCoppers::Type::k752NickelSilver},
    {constants::alloycopper::k762NickelSilver,
     AlloyCoppers::Type::k762NickelSilver},
    {constants::alloycopper::k770NickelSilver,
     AlloyCoppers::Type::k770NickelSilver},
    {constants::alloycopper::k1751Class3, AlloyCoppers::Type::k1751Class3},
    {constants::alloycopper::k1758Nickel, AlloyCoppers::Type::k1758Nickel},
    {constants::alloycopper::kMoldmaxBeCu, AlloyCoppers::Type::kMoldmaxBeCu},
    {constants::alloycopper::kProthermBeCu, AlloyCoppers::Type::kProthermBeCu},
}}};

constexpr base::ImmutableMap<AlloyCoppers::Type, std::string_view, 17>
    kTypeString{
        {{{AlloyCoppers::Type::k145Telluirum,
           constants::alloycopper::k145Telluirum},
          {AlloyCoppers::Type::k194Iron, constants::alloycopper::k194Iron},
          {AlloyCoppers::Type::k195Iron, constants::alloycopper::k195Iron},
          {AlloyCoppers::Type::k172Beryllium,
           constants::alloycopper::k172Beryllium},
          {AlloyCoppers::Type::k182Class2, constants::alloycopper::k182Class2},
          {AlloyCoppers::Type::k655Silicon,
           constants::alloycopper::k655Silicon},
          {AlloyCoppers::Type::k706Nickel, constants::alloycopper::k706Nickel},
          {AlloyCoppers::Type::k715NickelSilver,
           constants::alloycopper::k715NickelSilver},
          {AlloyCoppers::Type::k725NickelSilver,
           constants::alloycopper::k725NickelSilver},
          {AlloyCoppers::Type::k735NickelSilver,
           constants::alloycopper::k735NickelSilver},
          {AlloyCoppers::Type::k752NickelSilver,
           constants::alloycopper::k752NickelSilver},
          {AlloyCoppers::Type::k762NickelSilver,
           constants::alloycopper::k762NickelSilver},
          {AlloyCoppers::Type::k770NickelSilver,
           constants::alloycopper::k770NickelSilver},
          {AlloyCoppers::Type::k1751Class3,
           constants::alloycopper::k1751Class3},
          {AlloyCoppers::Type::k1758Nickel,
           constants::alloycopper::k1758Nickel},
          {AlloyCoppers::Type::kMoldmaxBeCu,
           constants::alloycopper::kMoldmaxBeCu},
          {AlloyCoppers::Type::kProthermBeCu,
           constants::alloycopper::kProthermBeCu}}}};
} // namespace

AlloyCoppers::AlloyCoppers(const AlloyCoppers::Type& type)
    : lua_state_(std::make_unique<LuaScriptHandler>(
          constants::alloycopper::kConfigPath)) {
  if (!SetType(type)) {
    LOG_ERROR("Construction of the object failed. %s", __PRETTY_FUNCTION__);
  }
}

AlloyCoppers::Type AlloyCoppers::GetType() const {
  return specific_properties_.type;
}

AlloyCoppers::Color AlloyCoppers::GetSpecificColor() const {
  return specific_properties_.color;
}

units::density::kilograms_per_cubic_meter_t AlloyCoppers::GetSpecificDensity()
    const {
  return {specific_properties_.density};
}

units::temperature::kelvin_t AlloyCoppers::GetSpecificMeltingPoint() const {
  return {specific_properties_.melting_point};
}

double AlloyCoppers::GetSpecificPoissonsRatio() const {
  return specific_properties_.poissons_ratio;
}

units::power::watt_t AlloyCoppers::GetSpecificThermalConductivity() const {
  return {specific_properties_.thermal_conductivity};
}

units::pressure::pascal_t AlloyCoppers::GetSpecificModOfElasticityTension()
    const {
  return {specific_properties_.mod_of_elasticity_tension};
}

bool AlloyCoppers::SetProperties(const Properties& properties) {
  auto fetch_from_lua_or_default = [&](const std::string& property_name,
                                       auto default_value) {
    using ValueType = decltype(default_value);
    return lua_state_->GetOrDefault<ValueType>(
        std::string(GetClassName()) + "." +
            std::string(kTypeString.at(properties.type)) + "." + property_name,
        default_value);
  };

  specific_properties_.type = kType.at(fetch_from_lua_or_default(
      constants::properties::kTypeKey, kTypeString.at(properties.type)));

  specific_properties_.color = kColor.at(fetch_from_lua_or_default(
      constants::properties::kColorKey, kColorString.at(properties.color)));

  specific_properties_.density = fetch_from_lua_or_default(
      constants::properties::kDensityKey, properties.density);

  specific_properties_.melting_point = fetch_from_lua_or_default(
      constants::properties::kMeltingPointKey, properties.melting_point);

  specific_properties_.poissons_ratio = fetch_from_lua_or_default(
      constants::properties::kPoissonsRatioKey, properties.poissons_ratio);

  specific_properties_.thermal_conductivity =
      fetch_from_lua_or_default(constants::properties::kThermalConductivityKey,
                                properties.thermal_conductivity);

  specific_properties_.mod_of_elasticity_tension = fetch_from_lua_or_default(
      constants::properties::kModOfElasticityTensionKey,
      properties.mod_of_elasticity_tension);

  return true;
}

bool AlloyCoppers::SetType(const AlloyCoppers::Type& type) {
  auto pair = type2func_.find(type);

  if (pair != type2func_.end()) {
    pair->second();
  } else {
    LOG_ERROR("Could not set the values for type: %s",
              std::string(kTypeString.at(GetType())).c_str());
  }

  return true;
}

std::ostream& operator<<(std::ostream& os, const AlloyCoppers& obj) {
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

std::ostream& operator<<(std::ostream& os, const AlloyCoppers::Type& type) {
  os << kTypeString.at(type);

  return os;
}
} // namespace masscalculator::materials
