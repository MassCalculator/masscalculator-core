#include "materials/stainless_steel.hpp"

namespace MassCalculator::Materials
{
  StainlessSteel::StainlessSteel(void)
  {
    if(!this->initLuaScript())
    {
      std::cerr << "Construction of the object failed\n";
    }
  }

  StainlessSteel::StainlessSteel(const StainlessSteel::Type &type)
  {
    if(!setType(type) || !this->initLuaScript())
    {
      std::cerr << "Construction of the object failed\n";
    }
  }

  bool StainlessSteel::initLuaScript(void)
  {
    return this->lua_state_.openScript(Constants::StainlessSteel::LuaConfigPath);
  }

  bool StainlessSteel::setType(const StainlessSteel::Type &type)
  {
    if(!setPropertieSpecs(type))
    {
      std::cerr << "Cannot set the StainlessSteel type\n";
      return false;
    }
    
    return true;
  }

  std::pair<std::string, StainlessSteel::Type> StainlessSteel::getType(void) const
  {
    return{this->specific_properties_.type_};
  }

  std::string StainlessSteel::getSpecificColor(void) const
  {
    return{this->specific_properties_.color_};
  }

  kilograms_per_cubic_meter_t StainlessSteel::getSpecificDensity(void) const
  {
    return{this->specific_properties_.density_};
  }

  meters_per_second_squared_t StainlessSteel::getSpecificGravity(void) const
  {
    return{this->specific_properties_.gravity_};
  }

  kelvin_t StainlessSteel::getSpecificMeltingPoint(void) const
  {
    return{this->specific_properties_.melting_point_};
  }

  double StainlessSteel::getSpecificPoissonsRatio(void) const
  {
    return{this->specific_properties_.poissons_ratio_};
  }

  watt_t StainlessSteel::getSpecificThermalConductivity(void) const
  {
    return{this->specific_properties_.thermal_conductivity_};
  }

  pascal_t StainlessSteel::getSpecificModOfElasticityTension(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_tension_};
  }

  pascal_t StainlessSteel::getSpecificModOfElasticityTorsion(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_torsion_};
  }

  bool StainlessSteel::_setPropertieSpecs(const Properties_t &_properties)
  {
    this->specific_properties_.type_ = {
      TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".UseLuaConfig"}),
        getFromLuaConfig<std::string>(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".type"}),
        {_properties.type_.first}
      ), _properties.type_.second};
    this->specific_properties_.color_ = 
      TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".UseLuaConfig"}),
        getFromLuaConfig<std::string>(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".color"}),
        {_properties.color_}
      );
    this->specific_properties_.density_ = 
      TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".UseLuaConfig"}),
        static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".density"})),
        {_properties.density_}
      );
    this->specific_properties_.gravity_ = 
      TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".UseLuaConfig"}),
        static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".gravity"})),
        {_properties.gravity_}
      );
    this->specific_properties_.melting_point_ = 
      TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".UseLuaConfig"}),
        static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".melting_point"})),
        {_properties.melting_point_}
      );
    this->specific_properties_.poissons_ratio_ = 
      TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".UseLuaConfig"}),
        getFromLuaConfig<double>(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".poissons_ratio"}),
        {_properties.poissons_ratio_}
      );
    this->specific_properties_.thermal_conductivity_ = 
      TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".UseLuaConfig"}),
        static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".thermal_conductivity"})),
        {_properties.thermal_conductivity_}
      );
    this->specific_properties_.mod_of_elasticity_tension_ = 
      TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".UseLuaConfig"}),
        static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".mod_of_elasticity_tension"})),
        {_properties.mod_of_elasticity_tension_}
      );
    this->specific_properties_.mod_of_elasticity_torsion_ = 
      TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".UseLuaConfig"}),
        static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), {this->_getClassName(this) + ".Type." + _properties.type_.first + ".mod_of_elasticity_torsion"})),
        {_properties.mod_of_elasticity_torsion_}
      );
    return true;
  }

  bool StainlessSteel::setPropertieSpecs(const StainlessSteel::Type &type)
  {
    auto _pair = type2func.find(type);

    if(_pair != type2func.end())
    {
      _pair->second();
    }
    else
    {
      std::cerr << "Could not set the values for type: " << type << std::endl;
    }

    return true;
  }

  std::ostream &operator << (std::ostream &os, const StainlessSteel &obj)
  {
    os << "  StainlessSteel object properties: " "\n"
          "   - Type    : " + obj.getType().first + "\n"
          "   - Color   : " + obj.getSpecificColor() + "\n"
          "   - Density : " + units::density::to_string(obj.getSpecificDensity()) + "\n"
          "   - Gravity : " + units::acceleration::to_string(obj.getSpecificGravity()) + "\n"
          "   - Melting point : " + units::temperature::to_string(obj.getSpecificMeltingPoint()) + "\n"
          "   - Poissons ratio: " + std::to_string(obj.getSpecificPoissonsRatio()) + "\n"
          "   - Thermal conductivity         : " + units::power::to_string(obj.getSpecificThermalConductivity()) + "\n"
          "   - Modulus of elasticity tension: " + units::pressure::to_string(obj.getSpecificModOfElasticityTension()) + "\n"
          "   - Modulus of elasticity torsion: " + units::pressure::to_string(obj.getSpecificModOfElasticityTorsion()) + "\n";
    return os;
  }

  std::ostream &operator << (std::ostream &os, const StainlessSteel::Type &type)
  {
    switch(type)
    {
      case StainlessSteel::Type::SS_301: os << Constants::StainlessSteel::SS_301; break;
      case StainlessSteel::Type::SS_302: os << Constants::StainlessSteel::SS_302; break;
      case StainlessSteel::Type::SS_303: os << Constants::StainlessSteel::SS_303; break;
      case StainlessSteel::Type::SS_304: os << Constants::StainlessSteel::SS_304; break;
      case StainlessSteel::Type::SS_305: os << Constants::StainlessSteel::SS_305; break;
      case StainlessSteel::Type::SS_316: os << Constants::StainlessSteel::SS_316; break;
      case StainlessSteel::Type::SS_321: os << Constants::StainlessSteel::SS_321; break;
      case StainlessSteel::Type::SS_409: os << Constants::StainlessSteel::SS_409; break;
      case StainlessSteel::Type::SS_410: os << Constants::StainlessSteel::SS_410; break;
      case StainlessSteel::Type::SS_420: os << Constants::StainlessSteel::SS_420; break;
      case StainlessSteel::Type::SS_430: os << Constants::StainlessSteel::SS_430; break;
      case StainlessSteel::Type::SS_15_5: os << Constants::StainlessSteel::SS_15_5; break;
      case StainlessSteel::Type::SS_17_4: os << Constants::StainlessSteel::SS_17_4; break;
      case StainlessSteel::Type::UNSPECIFIED: os << Constants::StainlessSteel::UNSPECIFIED; break;
      default: os << "Name cannot be found";
    }
    return os;
  }
}//end namespace MassCalculator::Materials