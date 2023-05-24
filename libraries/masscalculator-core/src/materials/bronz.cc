#include "materials/bronz.hpp"

namespace MassCalculator::Materials
{
  Bronz::Bronz(void)
  {
    if(!this->initLuaScript())
    {
      LOG_ERROR("Construction of the object failed. %s", __PRETTY_FUNCTION__);
    }
  }

  Bronz::Bronz(const Bronz::Type &type)
  {
    if(!setType(type) || !this->initLuaScript())
    {
      LOG_ERROR("Construction of the object failed. %s", __PRETTY_FUNCTION__);
    }
  }

  bool Bronz::initLuaScript(void)
  {
    return this->lua_state_.openScript(Constants::Bronz::LuaConfigPath);
  }

  bool Bronz::setType(const Bronz::Type &type)
  {
    if(!setPropertieSpecs(type))
    {
      LOG_ERROR("Cannot set the Bronz type. %s", __PRETTY_FUNCTION__);
      return false;
    }
    
    return true;
  }

  std::pair<std::string, Bronz::Type> Bronz::getType(void) const
  {
    return{this->specific_properties_.type_};
  }

  std::string Bronz::getSpecificColor(void) const
  {
    return{this->specific_properties_.color_};
  }

  kilograms_per_cubic_meter_t Bronz::getSpecificDensity(void) const
  {
    return{this->specific_properties_.density_};
  }

  meters_per_second_squared_t Bronz::getSpecificGravity(void) const
  {
    return{this->specific_properties_.gravity_};
  }

  kelvin_t Bronz::getSpecificMeltingPoint(void) const
  {
    return{this->specific_properties_.melting_point_};
  }

  double Bronz::getSpecificPoissonsRatio(void) const
  {
    return{this->specific_properties_.poissons_ratio_};
  }

  watt_t Bronz::getSpecificThermalConductivity(void) const
  {
    return{this->specific_properties_.thermal_conductivity_};
  }

  pascal_t Bronz::getSpecificModOfElasticityTension(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_tension_};
  }

  pascal_t Bronz::getSpecificModOfElasticityTorsion(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_torsion_};
  }

  bool Bronz::_setPropertieSpecs(const Properties_t &_properties)
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

  bool Bronz::setPropertieSpecs(const Bronz::Type &type)
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

  std::ostream &operator << (std::ostream &os, const Bronz &obj)
  {
    os << "  Bronz object properties: " "\n"
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

  std::ostream &operator << (std::ostream &os, const Bronz::Type &type)
  {
    switch(type)
    {
      case Bronz::Type::B_18Al: os << Constants::Bronz::B_18Al; break;
      case Bronz::Type::B_21Al: os << Constants::Bronz::B_21Al; break;
      case Bronz::Type::B_314Commercial: os << Constants::Bronz::B_314Commercial; break;
      case Bronz::Type::B_485Naval: os << Constants::Bronz::B_485Naval; break;
      case Bronz::Type::B_510Phos: os << Constants::Bronz::B_510Phos; break;
      case Bronz::Type::B_524Phos: os << Constants::Bronz::B_524Phos; break;
      case Bronz::Type::B_532Phos: os << Constants::Bronz::B_532Phos; break;
      case Bronz::Type::B_534Phos: os << Constants::Bronz::B_534Phos; break;
      case Bronz::Type::B_544Phos: os << Constants::Bronz::B_544Phos; break;
      case Bronz::Type::B_613Al: os << Constants::Bronz::B_613Al; break;
      case Bronz::Type::B_614Al: os << Constants::Bronz::B_614Al; break;
      case Bronz::Type::B_623Al: os << Constants::Bronz::B_623Al; break;
      case Bronz::Type::B_624Al: os << Constants::Bronz::B_624Al; break;
      case Bronz::Type::B_625Al: os << Constants::Bronz::B_625Al; break;
      case Bronz::Type::B_630NiAl: os << Constants::Bronz::B_630NiAl; break;
      case Bronz::Type::B_642AlSi: os << Constants::Bronz::B_642AlSi; break;
      case Bronz::Type::B_932Bearing: os << Constants::Bronz::B_932Bearing; break;
      case Bronz::Type::B_954Al: os << Constants::Bronz::B_954Al; break;
      case Bronz::Type::B_OilLite: os << Constants::Bronz::B_OilLite; break;
      case Bronz::Type::UNSPECIFIED: os << Constants::Bronz::UNSPECIFIED; break;
      default: os << "Name cannot be found";
    }
    return os;
  }
}//end namespace MassCalculator::Materials