#include "materials/copper.hpp"

namespace MassCalculator
{
  Copper::Copper(void)
  {
    if(!this->initLuaScript())
    {
      std::cerr << "Construction of the object failed\n";
    }
  }

  Copper::Copper(const Copper::Type &type)
  {
    if(!setType(type) || !this->initLuaScript())
    {
      std::cerr << "Construction of the object failed\n";
    }
  }

  bool Copper::initLuaScript(void)
  {
    return this->lua_state_.openScript(Constants::CopperLuaConfigPath);
  }

  bool Copper::setType(const Copper::Type &type)
  {
    if(!setPropertieSpecs(type))
    {
      std::cerr << "Cannot set the Copper type\n";
      return false;
    }
    
    return true;
  }

  std::pair<std::string, Copper::Type> Copper::getType(void) const
  {
    return{this->specific_properties_.type_};
  }

  std::string Copper::getSpecificColor(void) const
  {
    return{this->specific_properties_.color_};
  }

  kilograms_per_cubic_meter_t Copper::getSpecificDensity(void) const
  {
    return{this->specific_properties_.density_};
  }

  meters_per_second_squared_t Copper::getSpecificGravity(void) const
  {
    return{this->specific_properties_.gravity_};
  }

  kelvin_t Copper::getSpecificMeltingPoint(void) const
  {
    return{this->specific_properties_.melting_point_};
  }

  double Copper::getSpecificPoissonsRatio(void) const
  {
    return{this->specific_properties_.poissons_ratio_};
  }

  watt_t Copper::getSpecificThermalConductivity(void) const
  {
    return{this->specific_properties_.thermal_conductivity_};
  }

  pascal_t Copper::getSpecificModOfElasticityTension(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_tension_};
  }

  pascal_t Copper::getSpecificModOfElasticityTorsion(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_torsion_};
  }

  bool Copper::_setPropertieSpecs(const Properties_t &_properties)
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

  bool Copper::setPropertieSpecs(const Copper::Type &type)
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

  std::ostream &operator << (std::ostream &os, const Copper &obj)
  {
    os << "  Copper object properties: " "\n"
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

  std::ostream &operator << (std::ostream &os, const Copper::Type &type)
  {
    switch(type)
    {
      case Copper::Type::C_101: os << Constants::C_101; break;
      case Copper::Type::C_102: os << Constants::C_102; break;
      case Copper::Type::C_103: os << Constants::C_103; break;
      case Copper::Type::C_110: os << Constants::C_110; break;
      case Copper::Type::C_122: os << Constants::C_122; break;
      case Copper::Type::UNSPECIFIED: os << Constants::UNSPECIFIED; break;
      default: os << "Name cannot be found";
    }
    return os;
  }
}//end namespace MassCalculator