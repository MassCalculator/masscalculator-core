#include "materials/alloy_steels.hpp"

namespace MassCalculator
{
  AlloySteels::AlloySteels(void)
  {
    this->initLuaScript();
  }

  AlloySteels::AlloySteels(AlloySteels::Type type)
  {
    this->initLuaScript();

    if(!setType(type))
    {
      std::cerr << "Construction of the object failed\n";
    }
  }

  bool AlloySteels::initLuaScript(void)
  {
    this->lua_state_.openScript(Constants::AlloySteelsLuaConfigPath);
    return true;
  }

  bool AlloySteels::setType(AlloySteels::Type type)
  {
    if(!setPropertieSpecs(type))
    {
      std::cerr << "Cannot set the AlloySteels type\n";
      return false;
    }
    else 
      return true;
  }

  std::pair<std::string, AlloySteels::Type> AlloySteels::getType(void) const
  {
    return{this->specific_properties_.type_};
  }

  std::string AlloySteels::getSpecificColor(void) const
  {
    return{this->specific_properties_.color_};
  }

  kilograms_per_cubic_meter_t AlloySteels::getSpecificDensity(void) const
  {
    return{this->specific_properties_.density_};
  }

  meters_per_second_squared_t AlloySteels::getSpecificGravity(void) const
  {
    return{this->specific_properties_.gravity_};
  }

  kelvin_t AlloySteels::getSpecificMeltingPoint(void) const
  {
    return{this->specific_properties_.melting_point_};
  }

  double AlloySteels::getSpecificPoissonsRatio(void) const
  {
    return{this->specific_properties_.poissons_ratio_};
  }

  watt_t AlloySteels::getSpecificThermalConductivity(void) const
  {
    return{this->specific_properties_.thermal_conductivity_};
  }

  pascal_t AlloySteels::getSpecificModOfElasticityTension(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_tension_};
  }

  pascal_t AlloySteels::getSpecificModOfElasticityTorsion(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_torsion_};
  }

  //private TODO set the values correctly
  bool AlloySteels::setPropertieSpecs(AlloySteels::Type type)
  {
    switch (type)
    {
      case AlloySteels::Type::AS_4135 :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4135.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloySteels.Type.AS_4135.type"),
            {Constants::AS_4135}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4135.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloySteels.Type.AS_4135.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4135.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloySteels.Type.AS_4135.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4135.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloySteels.Type.AS_4135.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4135.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloySteels.Type.AS_4135.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4135.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "AlloySteels.Type.AS_4135.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4135.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloySteels.Type.AS_4135.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4135.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloySteels.Type.AS_4135.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4135.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloySteels.Type.AS_4135.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      //Data from source: https://suppliersonline.com/propertypages/2011.asp
      case AlloySteels::Type::AS_4140 :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4140.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloySteels.Type.AS_4140.type"),
            {Constants::AS_4140}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4140.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloySteels.Type.AS_4140.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4140.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloySteels.Type.AS_4140.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4140.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloySteels.Type.AS_4140.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4140.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloySteels.Type.AS_4140.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4140.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "AlloySteels.Type.AS_4140.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4140.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloySteels.Type.AS_4140.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4140.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloySteels.Type.AS_4140.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4140.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloySteels.Type.AS_4140.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      case AlloySteels::Type::AS_4340 :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4340.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloySteels.Type.AS_4340.type"),
            {Constants::AS_4340}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4340.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloySteels.Type.AS_4340.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4340.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloySteels.Type.AS_4340.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4340.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloySteels.Type.AS_4340.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4340.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloySteels.Type.AS_4340.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4340.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "AlloySteels.Type.AS_4340.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4340.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloySteels.Type.AS_4340.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4340.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloySteels.Type.AS_4340.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloySteels.Type.AS_4340.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloySteels.Type.AS_4340.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      default:
      {
        std::cerr << "The type AlloySteels specified not found, using default AlloySteels type\n";
        break;
      }
    }

    return true;
  }

  std::ostream &operator << (std::ostream &os, const AlloySteels &obj)
  {
    os << "  AlloySteels object properties: " "\n"
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
}//end namespace MassCalculator