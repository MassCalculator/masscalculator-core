#include "materials/alloy_coppers.h"  // for AlloyCoppers

#include "units.h"  // for units::*

namespace masscalculator::materials {
AlloyCoppers::AlloyCoppers() {
  if (!this->InitLuaScript()) {
    LOG_ERROR("Construction of the object failed. %s", __PRETTY_FUNCTION__);
  }
}

AlloyCoppers::AlloyCoppers(const AlloyCoppers::Type& type) {
  if (!SetType(type) || !this->InitLuaScript()) {
    LOG_ERROR("Construction of the object failed. %s", __PRETTY_FUNCTION__);
  }
}

// initialise usig unique pointer make unique
bool AlloyCoppers::InitLuaScript() {
  return this->lua_state_.openScript(constants::alloycopper::UNSPECIFIED);
}

bool AlloyCoppers::SetType(const AlloyCoppers::Type& type) {
  if (!SetPropertieSpecs(type)) {
    LOG_ERROR("Cannot set the AlloyCoppers type. %s", __PRETTY_FUNCTION__);
    return false;
  }

  return true;
}

std::pair<std::string, AlloyCoppers::Type> AlloyCoppers::GetType() const {
  return {this->specific_properties_.type};
}

std::string AlloyCoppers::GetSpecificColor() const {
  return {this->specific_properties_.color};
}

units::density::kilograms_per_cubic_meter_t AlloyCoppers::GetSpecificDensity()
    const {
  return {this->specific_properties_.density};
}

units::acceleration::meters_per_second_squared_t
AlloyCoppers::GetSpecificGravity() const {
  return {this->specific_properties_.gravity};
}

units::temperature::kelvin_t AlloyCoppers::GetSpecificMeltingPoint() const {
  return {this->specific_properties_.melting_point};
}

double AlloyCoppers::GetSpecificPoissonsRatio() const {
  return this->specific_properties_.poissons_ratio;
}

units::power::watt_t AlloyCoppers::GetSpecificThermalConductivity() const {
  return {this->specific_properties_.thermal_conductivity};
}

units::pressure::pascal_t AlloyCoppers::GetSpecificModOfElasticityTension()
    const {
  return {this->specific_properties_.mod_of_elasticity_tension};
}

bool AlloyCoppers::_setPropertieSpecs(const Properties& properties) {
  // this->specific_properties_.type_ = {
  //     TTernaryOperator(
  //         checkFromLuaConfig(std::move(this->lua_state_),
  //         {this->_getClassName(this) + ".Type." + _properties.type_.first +
  //         ".UseLuaConfig"}),
  //         getFromLuaConfig<std::string>(std::move(this->lua_state_),
  //         {this->_getClassName(this) + ".Type." + _properties.type_.first +
  //         ".type"}), {_properties.type_.first}),
  //     _properties.type_.second};
  // this->specific_properties_.color_ = TTernaryOperator(
  //     checkFromLuaConfig(std::move(this->lua_state_),
  //                        {this->_getClassName(this) + ".Type." +
  //                         _properties.type_.first + ".UseLuaConfig"}),
  //     getFromLuaConfig<std::string>(std::move(this->lua_state_),
  //                                   {this->_getClassName(this) + ".Type." +
  //                                    _properties.type_.first + ".color"}),
  //     {_properties.color_});
  // this->specific_properties_.density_ = TTernaryOperator(
  //     checkFromLuaConfig(std::move(this->lua_state_),
  //                        {this->_getClassName(this) + ".Type." +
  //                         _properties.type_.first + ".UseLuaConfig"}),
  //     static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(
  //         std::move(this->lua_state_), {this->_getClassName(this) + ".Type."
  //         +
  //                                       _properties.type_.first +
  //                                       ".density"})),
  //     {_properties.density_});
  // this->specific_properties_.gravity_ = TTernaryOperator(
  //     checkFromLuaConfig(std::move(this->lua_state_),
  //                        {this->_getClassName(this) + ".Type." +
  //                         _properties.type_.first + ".UseLuaConfig"}),
  //     static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(
  //         std::move(this->lua_state_), {this->_getClassName(this) + ".Type."
  //         +
  //                                       _properties.type_.first +
  //                                       ".gravity"})),
  //     {_properties.gravity_});
  // this->specific_properties_.melting_point_ = TTernaryOperator(
  //     checkFromLuaConfig(std::move(this->lua_state_),
  //                        {this->_getClassName(this) + ".Type." +
  //                         _properties.type_.first + ".UseLuaConfig"}),
  //     static_cast<kelvin_t>(getFromLuaConfig<double>(
  //         std::move(this->lua_state_),
  //         {this->_getClassName(this) + ".Type." + _properties.type_.first +
  //          ".melting_point"})),
  //     {_properties.melting_point_});
  // this->specific_properties_.poissons_ratio_ = TTernaryOperator(
  //     checkFromLuaConfig(std::move(this->lua_state_),
  //                        {this->_getClassName(this) + ".Type." +
  //                         _properties.type_.first + ".UseLuaConfig"}),
  //     getFromLuaConfig<double>(std::move(this->lua_state_),
  //                              {this->_getClassName(this) + ".Type." +
  //                               _properties.type_.first +
  //                               ".poissons_ratio"}),
  //     {_properties.poissons_ratio_});
  // this->specific_properties_.thermal_conductivity_ = TTernaryOperator(
  //     checkFromLuaConfig(std::move(this->lua_state_),
  //                        {this->_getClassName(this) + ".Type." +
  //                         _properties.type_.first + ".UseLuaConfig"}),
  //     static_cast<watt_t>(getFromLuaConfig<double>(
  //         std::move(this->lua_state_),
  //         {this->_getClassName(this) + ".Type." + _properties.type_.first +
  //          ".thermal_conductivity"})),
  //     {_properties.thermal_conductivity_});
  // this->specific_properties_.mod_of_elasticity_tension_ = TTernaryOperator(
  //     checkFromLuaConfig(std::move(this->lua_state_),
  //                        {this->_getClassName(this) + ".Type." +
  //                         _properties.type_.first + ".UseLuaConfig"}),
  //     static_cast<pascal_t>(getFromLuaConfig<double>(
  //         std::move(this->lua_state_),
  //         {this->_getClassName(this) + ".Type." + _properties.type_.first +
  //          ".mod_of_elasticity_tension"})),
  //     {_properties.mod_of_elasticity_tension_});
  // this->specific_properties_.mod_of_elasticity_torsion_ = TTernaryOperator(
  //     checkFromLuaConfig(std::move(this->lua_state_),
  //                        {this->_getClassName(this) + ".Type." +
  //                         _properties.type_.first + ".UseLuaConfig"}),
  //     static_cast<pascal_t>(getFromLuaConfig<double>(
  //         std::move(this->lua_state_),
  //         {this->_getClassName(this) + ".Type." + _properties.type_.first +
  //          ".mod_of_elasticity_torsion"})),
  //     {_properties.mod_of_elasticity_torsion_});
  return true;
}

bool AlloyCoppers::SetPropertieSpecs(const AlloyCoppers::Type& type) {
  auto pair = type2func_.find(type);

  if (pair != type2func_.end()) {
    pair->second();
  } else {
    LOG_ERROR("Could not set the values for type: %s",
              this->GetType().first.c_str());
  }

  return true;
}

std::ostream& operator<<(std::ostream& os, const AlloyCoppers& obj) {
  // os << "  AlloyCoppers object properties: "
  //       "\n"
  //       "   - Type    : " +
  //           obj.GetType().first +
  //           "\n"
  //           "   - Color   : " +
  //           obj.GetSpecificColor() +
  //           "\n"
  //           "   - Density : " +
  //           units::density::to_string(obj.GetSpecificDensity()) +
  //           "\n"
  //           "   - Gravity : " +
  //           units::acceleration::to_string(obj.GetSpecificGravity()) +
  //           "\n"
  //           "   - Melting point : " +
  //           units::temperature::to_string(obj.GetSpecificMeltingPoint()) +
  //           "\n"
  //           "   - Poissons ratio: " +
  //           std::to_string(obj.GetSpecificPoissonsRatio()) +
  //           "\n"
  //           "   - Thermal conductivity         : " +
  //           units::power::to_string(obj.GetSpecificThermalConductivity()) +
  //           "\n"
  //           "   - Modulus of elasticity tension: " +
  //           units::pressure::to_string(
  //               obj.GetSpecificModOfElasticityTension()) +
  //           "\n";
  return os;
}

std::ostream& operator<<(std::ostream& os, const AlloyCoppers::Type& type) {
  switch (type) {
    case AlloyCoppers::Type::AC_145Tellvirum:
      os << constants::alloycopper::k145Telluirum;
      break;
    case AlloyCoppers::Type::AC_194Iron:
      os << constants::alloycopper::AC_194Iron;
      break;
    case AlloyCoppers::Type::AC_195Iron:
      os << constants::alloycopper::AC_195Iron;
      break;
    case AlloyCoppers::Type::AC_172Beryllium:
      os << constants::alloycopper::AC_172Beryllium;
      break;
    case AlloyCoppers::Type::AC_182Class2:
      os << constants::alloycopper::AC_182Class2;
      break;
    case AlloyCoppers::Type::AC_655Silicon:
      os << constants::alloycopper::AC_655Silicon;
      break;
    case AlloyCoppers::Type::AC_706Nickel:
      os << constants::alloycopper::AC_706Nickel;
      break;
    case AlloyCoppers::Type::AC_715NickelSilver:
      os << constants::alloycopper::AC_715NickelSilver;
      break;
    case AlloyCoppers::Type::AC_725NickelSilver:
      os << constants::alloycopper::AC_725NickelSilver;
      break;
    case AlloyCoppers::Type::AC_735NickelSilver:
      os << constants::alloycopper::AC_735NickelSilver;
      break;
    case AlloyCoppers::Type::AC_752NickelSilver:
      os << constants::alloycopper::AC_752NickelSilver;
      break;
    case AlloyCoppers::Type::AC_762NickelSilver:
      os << constants::alloycopper::AC_762NickelSilver;
      break;
    case AlloyCoppers::Type::AC_770NickelSilver:
      os << constants::alloycopper::AC_770NickelSilver;
      break;
    case AlloyCoppers::Type::AC_1751Class3:
      os << constants::alloycopper::AC_1751Class3;
      break;
    case AlloyCoppers::Type::AC_1758Nickel:
      os << constants::alloycopper::AC_1758Nickel;
      break;
    case AlloyCoppers::Type::AC_MoldmaxBeCu:
      os << constants::alloycopper::AC_MoldmaxBeCu;
      break;
    case AlloyCoppers::Type::AC_ProthermBeCu:
      os << constants::alloycopper::AC_ProthermBeCu;
      break;
    case AlloyCoppers::Type::UNSPECIFIED:
      os << constants::alloycopper::UNSPECIFIED;
      break;
    default:
      os << "Name cannot be found";
  }
  return os;
}
}  // namespace masscalculator::materials
