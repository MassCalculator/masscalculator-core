#include "materials/aluminium.hpp"

namespace MassCalculator
{
  Aluminium::Aluminium(void)
  {
    this->initLuaScript();
  }

  Aluminium::Aluminium(Aluminium::Type type)
  {
    this->initLuaScript();

    if(!setType(type))
    {
      std::cerr << "Construction of the object failed\n";
    }
  }

  bool Aluminium::initLuaScript(void)
  {
    this->lua_state_.openScript(Constants::AluminiumLuaConfigPath);
    return true;
  }

  bool Aluminium::setType(Aluminium::Type type)
  {
    if(!setPropertieSpecs(type))
    {
      std::cerr << "Cannot set the aluminium type\n";
      return false;
    }
    else 
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

  //private TODO set the values correctly
  bool Aluminium::setPropertieSpecs(Aluminium::Type type)
  {
    switch (type)
    {
      case Aluminium::Type::A_1100 :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_1100.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Aluminium.Type.A_1100.type"),
            {Constants::A_1100}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_1100.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Aluminium.Type.A_1100.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_1100.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_1100.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_1100.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_1100.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_1100.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_1100.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_1100.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_1100.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_1100.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_1100.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_1100.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_1100.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_1100.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_1100.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      case Aluminium::Type::A_2011 :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2011.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Aluminium.Type.A_2011.type"),
            {Constants::A_2011}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2011.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Aluminium.Type.A_2011.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2011.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_2011.density")),
            {2.82_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2011.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_2011.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2011.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_2011.melting_point")),
            {1000_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2011.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_2011.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2011.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_2011.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2011.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_2011.mod_of_elasticity_tension")),
            {10.2_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2011.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_2011.mod_of_elasticity_torsion")),
            {3.85_Pa}
          );
        break;
      }

      case Aluminium::Type::A_2014 :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2014.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Aluminium.Type.A_2014.type"),
            {Constants::A_2014}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2014.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Aluminium.Type.A_2014.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2014.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_2014.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2014.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_2014.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2014.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_2014.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2014.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_2014.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2014.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_2014.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2014.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_2014.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2014.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_2014.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      case Aluminium::Type::A_2024 :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2024.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Aluminium.Type.A_2024.type"),
            {Constants::A_2024}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2024.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Aluminium.Type.A_2024.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2024.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_2024.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2024.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_2024.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2024.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_2024.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2024.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_2024.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2024.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_2024.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2024.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_2024.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_2024.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_2024.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      case Aluminium::Type::A_3003 :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_3003.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Aluminium.Type.A_3003.type"),
            {Constants::A_3003}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_3003.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Aluminium.Type.A_3003.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_3003.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_3003.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_3003.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_3003.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_3003.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_3003.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_3003.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_3003.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_3003.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_3003.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_3003.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_3003.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_3003.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_3003.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      case Aluminium::Type::A_5052 :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_5052.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Aluminium.Type.A_5052.type"),
            {Constants::A_5052}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_5052.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Aluminium.Type.A_5052.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_5052.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_5052.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_5052.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_5052.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_5052.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_5052.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_5052.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_5052.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_5052.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_5052.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_5052.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_5052.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_5052.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_5052.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      case Aluminium::Type::A_6061 :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_6061.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Aluminium.Type.A_6061.type"),
            {Constants::A_6061}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_6061.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Aluminium.Type.A_6061.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_6061.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_6061.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_6061.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_6061.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_6061.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_6061.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_6061.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_6061.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_6061.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_6061.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_6061.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_6061.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_6061.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_6061.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      case Aluminium::Type::A_6063 :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_6063.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Aluminium.Type.A_6063.type"),
            {Constants::A_6063}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_6063.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Aluminium.Type.A_6063.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_6063.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_6063.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_6063.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_6063.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_6063.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_6063.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_6063.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_6063.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_6063.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_6063.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_6063.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_6063.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_6063.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_6063.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      case Aluminium::Type::A_7075 :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_7075.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Aluminium.Type.A_7075.type"),
            {Constants::A_7075}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_7075.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Aluminium.Type.A_7075.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_7075.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_7075.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_7075.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_7075.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_7075.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_7075.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_7075.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_7075.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_7075.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_7075.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_7075.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_7075.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "Aluminium.Type.A_7075.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Aluminium.Type.A_7075.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      default:
      {
        std::cerr << "The type aluminium specified not found, using default aluminium type\n";
        break;
      }
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

  std::ostream &operator << (std::ostream& os, Aluminium::Type type)
  {
    switch(type)
    {
      case Aluminium::Type::A_1100: os << Constants::A_1100; break;
      case Aluminium::Type::A_2011: os << Constants::A_2011; break;
      case Aluminium::Type::A_2014: os << Constants::A_2014; break;
      case Aluminium::Type::A_2024: os << Constants::A_2024; break;
      case Aluminium::Type::A_3003: os << Constants::A_3003; break;
      case Aluminium::Type::A_5052: os << Constants::A_5052; break;
      case Aluminium::Type::A_6061: os << Constants::A_6061; break;
      case Aluminium::Type::A_6063: os << Constants::A_6063; break;
      case Aluminium::Type::A_7075: os << Constants::A_7075; break;
      case Aluminium::Type::UNSPECIFIED: os << Constants::UNSPECIFIED; break;
      default: os << "Name cannot be found";
    }
    return os;
  }
}//end namespace MassCalculator