#include "materials/alloy_coppers.h" // for AlloyCoppers

#include "masscalculator/base/macro_logger.hpp" // for LOG_*
#include "materials/constants/alloy_coppers.h"  // for alloycopper::k*
#include "materials/constants/material.h"       // for properties::k*
#include "units.h"                              // for units::*

namespace masscalculator::materials {
AlloyCoppers::AlloyCoppers() {
  if (!InitLuaScript()) {
    LOG_ERROR("Construction of the object failed. %s", __PRETTY_FUNCTION__);
  }
}

AlloyCoppers::AlloyCoppers(const AlloyCoppers::Type& type) {
  if (!SetType(type) || !InitLuaScript()) {
    LOG_ERROR("Construction of the object failed. %s", __PRETTY_FUNCTION__);
  }
}

// @todo(jimmyhalimi): Initialise usig unique pointer and make unique.
bool AlloyCoppers::InitLuaScript() {
  return lua_state_.openScript(constants::alloycopper::kLuaConfigPath);
}

bool AlloyCoppers::SetType(const AlloyCoppers::Type& type) {
  if (!SetPropertieSpecs(type)) {
    LOG_ERROR("Cannot set the AlloyCoppers type. %s", __PRETTY_FUNCTION__);
    return false;
  }

  return true;
}

std::pair<std::string, AlloyCoppers::Type> AlloyCoppers::GetType() const {
  return {specific_properties_.type};
}

std::string AlloyCoppers::GetSpecificColor() const {
  return {specific_properties_.color};
}

units::density::kilograms_per_cubic_meter_t AlloyCoppers::GetSpecificDensity()
    const {
  return {specific_properties_.density};
}

units::acceleration::meters_per_second_squared_t
AlloyCoppers::GetSpecificGravity() const {
  return {specific_properties_.gravity};
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

// @todo(jimmyhalimi): Leaving this function here temporarily. Needs to be
// transfered to LuaScriptHandler
/**
 * @brief Helper function to check from Lua script
 *
 * @param lua_state Lua state as forwarded reference
 * @param value Lua parameter that we want to check
 * @return true if parameter is true
 * @return false if parameter is false
 */
bool CheckFromLuaConfig(LuaScriptHandler&& lua_state,
                        const std::string& value) {
  if (lua_state.isInitialized()) {
    if (lua_state.get<bool>(value.c_str())) {
      return true;
    }

    return false;
  }

  return false;
}

// @todo(jimmyhalimi): Leaving this function here temporarily. Needs to be
// transfered to LuaScriptHandler
/**
 * @brief Template helper function to get the value from Lua config in the
 * datatype we want
 *
 * @tparam TLuaReturnType Return type we want
 * @param lua_state Lua state as forwarded reference
 * @param value Lua parameter that we want to get
 * @return constexpr TLuaReturnType
 */
template <typename TLuaReturnType>
constexpr TLuaReturnType GetFromLuaConfig(LuaScriptHandler&& lua_state,
                                          const std::string& value) {
  return lua_state.get<TLuaReturnType>(value);
}

bool AlloyCoppers::SetPropertieSpecs(const Properties& properties) {
  auto fetch_from_lua_or_default = [&](const std::string& property_name,
                                       auto default_value) {
    using ValueType = decltype(default_value);
    if (CheckFromLuaConfig(std::move(lua_state_),
                           {GetClassName(this) + ".Type." +
                            properties.type.first + ".UseLuaConfig"})) {
      return static_cast<ValueType>(GetFromLuaConfig<std::decay_t<ValueType>>(
          std::move(lua_state_),
          {GetClassName(this) + ".Type." + properties.type.first + "." +
           property_name}));
    }

    return default_value;
  };

  // @todo(jimmyhalimi): Here I cast to double to fool the decltype because in
  // LuaScriptHandler we don't have the units::*
  specific_properties_.type = {
      fetch_from_lua_or_default(constants::properties::kTypeKey,
                                properties.type.first),
      properties.type.second};
  specific_properties_.color = fetch_from_lua_or_default(
      constants::properties::kColorKey, properties.color);
  specific_properties_.density =
      static_cast<units::density::kilograms_per_cubic_meter_t>(
          fetch_from_lua_or_default(constants::properties::kDensityKey,
                                    static_cast<double>(properties.density)));
  specific_properties_.gravity =
      static_cast<units::acceleration::meters_per_second_squared_t>(
          fetch_from_lua_or_default(constants::properties::kGravityKey,
                                    static_cast<double>(properties.gravity)));
  specific_properties_.melting_point =
      static_cast<units::temperature::kelvin_t>(fetch_from_lua_or_default(
          constants::properties::kMeltingPointKey,
          static_cast<double>(properties.melting_point)));
  specific_properties_.poissons_ratio = fetch_from_lua_or_default(
      constants::properties::kPoissonsRatioKey, properties.poissons_ratio);
  specific_properties_.thermal_conductivity =
      static_cast<units::power::watt_t>(fetch_from_lua_or_default(
          constants::properties::kThermalConductivityKey,
          static_cast<double>(properties.thermal_conductivity)));
  specific_properties_.mod_of_elasticity_tension =
      static_cast<units::pressure::pascal_t>(fetch_from_lua_or_default(
          constants::properties::kModOfElasticityTensionKey,
          static_cast<double>(properties.mod_of_elasticity_tension)));

  return true;
}

bool AlloyCoppers::SetPropertieSpecs(const AlloyCoppers::Type& type) {
  auto pair = type2func_.find(type);

  if (pair != type2func_.end()) {
    pair->second();
  } else {
    LOG_ERROR("Could not set the values for type: %s", GetType().first.c_str());
  }

  return true;
}

std::ostream& operator<<(std::ostream& os, const AlloyCoppers& obj) {
  os << "  AlloyCoppers object properties: "
        "\n"
        "   - Type    : " +
            obj.GetType().first +
            "\n"
            "   - Color   : " +
            obj.GetSpecificColor() +
            "\n"
            "   - Density : " +
            units::density::to_string(obj.GetSpecificDensity()) +
            "\n"
            "   - Gravity : " +
            units::acceleration::to_string(obj.GetSpecificGravity()) +
            "\n"
            "   - Melting point : " +
            units::temperature::to_string(obj.GetSpecificMeltingPoint()) +
            "\n"
            "   - Poissons ratio: " +
            std::to_string(obj.GetSpecificPoissonsRatio()) +
            "\n"
            "   - Thermal conductivity         : " +
            units::power::to_string(obj.GetSpecificThermalConductivity()) +
            "\n"
            "   - Modulus of elasticity tension: " +
            units::pressure::to_string(
                obj.GetSpecificModOfElasticityTension()) +
            "\n";
  return os;
}

std::ostream& operator<<(std::ostream& os, const AlloyCoppers::Type& type) {
  switch (type) {
    case AlloyCoppers::Type::k145Telluirum:
      os << constants::alloycopper::k145Telluirum;
      break;
    case AlloyCoppers::Type::k194Iron:
      os << constants::alloycopper::k194Iron;
      break;
    case AlloyCoppers::Type::k195Iron:
      os << constants::alloycopper::k195Iron;
      break;
    case AlloyCoppers::Type::k172Beryllium:
      os << constants::alloycopper::k172Beryllium;
      break;
    case AlloyCoppers::Type::k182Class2:
      os << constants::alloycopper::k182Class2;
      break;
    case AlloyCoppers::Type::k655Silicon:
      os << constants::alloycopper::k655Silicon;
      break;
    case AlloyCoppers::Type::k706Nickel:
      os << constants::alloycopper::k706Nickel;
      break;
    case AlloyCoppers::Type::k715NickelSilver:
      os << constants::alloycopper::k715NickelSilver;
      break;
    case AlloyCoppers::Type::k725NickelSilver:
      os << constants::alloycopper::k725NickelSilver;
      break;
    case AlloyCoppers::Type::k735NickelSilver:
      os << constants::alloycopper::k735NickelSilver;
      break;
    case AlloyCoppers::Type::k752NickelSilver:
      os << constants::alloycopper::k752NickelSilver;
      break;
    case AlloyCoppers::Type::k762NickelSilver:
      os << constants::alloycopper::k762NickelSilver;
      break;
    case AlloyCoppers::Type::k770NickelSilver:
      os << constants::alloycopper::k770NickelSilver;
      break;
    case AlloyCoppers::Type::k1751Class3:
      os << constants::alloycopper::k1751Class3;
      break;
    case AlloyCoppers::Type::k1758Nickel:
      os << constants::alloycopper::k1758Nickel;
      break;
    case AlloyCoppers::Type::kMoldmaxBeCu:
      os << constants::alloycopper::kMoldmaxBeCu;
      break;
    case AlloyCoppers::Type::kProthermBeCu:
      os << constants::alloycopper::kProthermBeCu;
      break;
    case AlloyCoppers::Type::kUnspecified:
      os << constants::alloycopper::kUnspecified;
      break;
    default:
      os << "Name cannot be found";
  }
  return os;
}
} // namespace masscalculator::materials
