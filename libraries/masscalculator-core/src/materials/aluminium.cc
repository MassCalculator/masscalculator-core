#include "materials/aluminium.hpp"

namespace MassCalculator::Materials
{
  Aluminium::Aluminium(void)
  {
    if(!this->initLuaScript())
    {
      LOG_ERROR("Construction of the object failed. %s", __PRETTY_FUNCTION__);
    }
  }

  Aluminium::Aluminium(const Aluminium::Type &type)
  {
    if(!setType(type) || !this->initLuaScript())
    {
      LOG_ERROR("Construction of the object failed. %s", __PRETTY_FUNCTION__);
    }
  }

  bool Aluminium::initLuaScript(void)
  {
    return this->lua_state_.openScript(Constants::Aluminium::LuaConfigPath);
  }

  bool Aluminium::setType(const Aluminium::Type &type)
  {
    if(!setPropertieSpecs(type))
    {
      LOG_ERROR("Cannot set the Aluminium type. %s", __PRETTY_FUNCTION__);
      return false;
    }
    
    return true;
  }

  std::pair<std::string, Aluminium::Type> Aluminium::getType(void) const
  {
    return{this->specific_properties_.type_};
  }

  std::string Aluminium::getSpecificColor(void) const
  {
    return{this->specific_properties_.color_};
  }

  kilograms_per_cubic_meter_t Aluminium::getSpecificDensity(void) const
  {
    return{this->specific_properties_.density_};
  }

  meters_per_second_squared_t Aluminium::getSpecificGravity(void) const
  {
    return{this->specific_properties_.gravity_};
  }

  kelvin_t Aluminium::getSpecificMeltingPoint(void) const
  {
    return{this->specific_properties_.melting_point_};
  }

  double Aluminium::getSpecificPoissonsRatio(void) const
  {
    return{this->specific_properties_.poissons_ratio_};
  }

  watt_t Aluminium::getSpecificThermalConductivity(void) const
  {
    return{this->specific_properties_.thermal_conductivity_};
  }

  pascal_t Aluminium::getSpecificModOfElasticityTension(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_tension_};
  }

  pascal_t Aluminium::getSpecificModOfElasticityTorsion(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_torsion_};
  }

  bool Aluminium::_setPropertieSpecs(const Properties_t &_properties)
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

  bool Aluminium::setPropertieSpecs(const Aluminium::Type &type)
  {
    auto _pair = type2func.find(type);

    if(_pair != type2func.end())
    {
      _pair->second();
    }
    else
    {
      LOG_ERROR("Could not set the values for type: %s", this->getType().first.c_str());
    }

    return true;
  }

  std::ostream &operator << (std::ostream &os, const Aluminium &obj)
  {
    os << "  Aluminium object properties: " "\n"
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

  std::ostream &operator << (std::ostream &os, const Aluminium::Type &type)
  {
    switch(type)
    {
      case Aluminium::Type::A_1100: os << Constants::Aluminium::A_1100; break;
      case Aluminium::Type::A_2011: os << Constants::Aluminium::A_2011; break;
      case Aluminium::Type::A_2014: os << Constants::Aluminium::A_2014; break;
      case Aluminium::Type::A_2024: os << Constants::Aluminium::A_2024; break;
      case Aluminium::Type::A_3003: os << Constants::Aluminium::A_3003; break;
      case Aluminium::Type::A_5052: os << Constants::Aluminium::A_5052; break;
      case Aluminium::Type::A_6061: os << Constants::Aluminium::A_6061; break;
      case Aluminium::Type::A_6063: os << Constants::Aluminium::A_6063; break;
      case Aluminium::Type::A_7075: os << Constants::Aluminium::A_7075; break;
      case Aluminium::Type::UNSPECIFIED: os << Constants::Aluminium::UNSPECIFIED; break;
      default: os << "Name cannot be found";
    }
    return os;
  }
}//end namespace MassCalculator::Materials