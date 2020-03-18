#include "materials/alloy_coppers.hpp"

namespace MassCalculator
{
  AlloyCoppers::AlloyCoppers(void)
  {
    this->initLuaScript();
  }

  AlloyCoppers::AlloyCoppers(AlloyCoppers::Type type)
  {
    this->initLuaScript();

    if(!setType(type))
    {
      std::cerr << "Construction of the object failed\n";
    }
  }

  bool AlloyCoppers::initLuaScript(void)
  {
    this->lua_state_.openScript(Constants::AlloyCoppersLuaConfigPath);
    return true;
  }

  bool AlloyCoppers::setType(AlloyCoppers::Type type)
  {
    if(!setPropertieSpecs(type))
    {
      std::cerr << "Cannot set the AlloyCoppers type\n";
      return false;
    }
    else 
      return true;
  }

  std::pair<std::string, AlloyCoppers::Type> AlloyCoppers::getType(void) const
  {
    return{this->specific_properties_.type_};
  }

  std::string AlloyCoppers::getSpecificColor(void) const
  {
    return{this->specific_properties_.color_};
  }

  kilograms_per_cubic_meter_t AlloyCoppers::getSpecificDensity(void) const
  {
    return{this->specific_properties_.density_};
  }

  meters_per_second_squared_t AlloyCoppers::getSpecificGravity(void) const
  {
    return{this->specific_properties_.gravity_};
  }

  kelvin_t AlloyCoppers::getSpecificMeltingPoint(void) const
  {
    return{this->specific_properties_.melting_point_};
  }

  double AlloyCoppers::getSpecificPoissonsRatio(void) const
  {
    return{this->specific_properties_.poissons_ratio_};
  }

  watt_t AlloyCoppers::getSpecificThermalConductivity(void) const
  {
    return{this->specific_properties_.thermal_conductivity_};
  }

  pascal_t AlloyCoppers::getSpecificModOfElasticityTension(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_tension_};
  }

  pascal_t AlloyCoppers::getSpecificModOfElasticityTorsion(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_torsion_};
  }

  //private TODO set the values correctly
  bool AlloyCoppers::setPropertieSpecs(AlloyCoppers::Type type)
  {
    switch (type)
    {
      //TODO: Static cast until the template specialisation in lua handler are made.
      case AlloyCoppers::Type::AC_145Tellvirum :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_145Tellvirum.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_145Tellvirum.type"),
            {Constants::AC_145Tellvirum}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_145Tellvirum.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_145Tellvirum.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_145Tellvirum.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_145Tellvirum.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_145Tellvirum.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_145Tellvirum.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_145Tellvirum.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_145Tellvirum.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_145Tellvirum.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_145Tellvirum.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_145Tellvirum.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_145Tellvirum.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_145Tellvirum.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_145Tellvirum.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_145Tellvirum.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_145Tellvirum.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      //Data from source: https://suppliersonline.com/propertypages/2011.asp
      case AlloyCoppers::Type::AC_194Iron :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_194Iron.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_194Iron.type"),
            {Constants::AC_194Iron}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_194Iron.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_194Iron.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_194Iron.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_194Iron.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_194Iron.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_194Iron.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_194Iron.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_194Iron.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_194Iron.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_194Iron.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_194Iron.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_194Iron.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_194Iron.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_194Iron.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_194Iron.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_194Iron.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      case AlloyCoppers::Type::AC_195Iron :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_195Iron.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_195Iron.type"),
            {Constants::AC_195Iron}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_195Iron.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_195Iron.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_195Iron.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_195Iron.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_195Iron.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_195Iron.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_195Iron.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_195Iron.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_195Iron.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_195Iron.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_195Iron.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_195Iron.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_195Iron.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_195Iron.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_195Iron.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_195Iron.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      case AlloyCoppers::Type::AC_172Beryllium :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_172Beryllium.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_172Beryllium.type"),
            {Constants::AC_172Beryllium}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_172Beryllium.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_172Beryllium.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_172Beryllium.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_172Beryllium.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_172Beryllium.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_172Beryllium.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_172Beryllium.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_172Beryllium.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_172Beryllium.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_172Beryllium.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_172Beryllium.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_172Beryllium.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_172Beryllium.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_172Beryllium.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_172Beryllium.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_172Beryllium.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      case AlloyCoppers::Type::AC_182Class2 :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_182Class2.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_182Class2.type"),
            {Constants::AC_182Class2}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_182Class2.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_182Class2.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_182Class2.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_182Class2.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_182Class2.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_182Class2.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_182Class2.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_182Class2.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_182Class2.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_182Class2.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_182Class2.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_182Class2.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_182Class2.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_182Class2.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_182Class2.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_182Class2.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      case AlloyCoppers::Type::AC_655Silicon :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_655Silicon.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_655Silicon.type"),
            {Constants::AC_655Silicon}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_655Silicon.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_655Silicon.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_655Silicon.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_655Silicon.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_655Silicon.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_655Silicon.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_655Silicon.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_655Silicon.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_655Silicon.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_655Silicon.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_655Silicon.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_655Silicon.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_655Silicon.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_655Silicon.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_655Silicon.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_655Silicon.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      case AlloyCoppers::Type::AC_706Nickel :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_706Nickel.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_706Nickel.type"),
            {Constants::AC_706Nickel}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_706Nickel.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_706Nickel.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_706Nickel.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_706Nickel.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_706Nickel.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_706Nickel.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_706Nickel.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_706Nickel.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_706Nickel.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_706Nickel.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_706Nickel.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_706Nickel.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_706Nickel.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_706Nickel.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_706Nickel.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_706Nickel.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      case AlloyCoppers::Type::AC_715NickelSilver :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_715NickelSilver.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_715NickelSilver.type"),
            {Constants::AC_715NickelSilver}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_715NickelSilver.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_715NickelSilver.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_715NickelSilver.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_715NickelSilver.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_715NickelSilver.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_715NickelSilver.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_715NickelSilver.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_715NickelSilver.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_715NickelSilver.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_715NickelSilver.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_715NickelSilver.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_715NickelSilver.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_715NickelSilver.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_715NickelSilver.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_715NickelSilver.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_715NickelSilver.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      case AlloyCoppers::Type::AC_725NickelSilver :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_725NickelSilver.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_725NickelSilver.type"),
            {Constants::AC_725NickelSilver}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_725NickelSilver.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_725NickelSilver.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_725NickelSilver.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_725NickelSilver.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_725NickelSilver.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_725NickelSilver.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_725NickelSilver.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_725NickelSilver.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_725NickelSilver.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_725NickelSilver.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_725NickelSilver.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_725NickelSilver.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_725NickelSilver.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_725NickelSilver.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_725NickelSilver.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_725NickelSilver.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      case AlloyCoppers::Type::AC_735NickelSilver :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_735NickelSilver.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_735NickelSilver.type"),
            {Constants::AC_735NickelSilver}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_735NickelSilver.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_735NickelSilver.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_735NickelSilver.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_735NickelSilver.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_735NickelSilver.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_735NickelSilver.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_735NickelSilver.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_735NickelSilver.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_735NickelSilver.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_735NickelSilver.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_735NickelSilver.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_735NickelSilver.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_735NickelSilver.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_735NickelSilver.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_735NickelSilver.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_735NickelSilver.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }


      case AlloyCoppers::Type::AC_752NickelSilver :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_752NickelSilver.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_752NickelSilver.type"),
            {Constants::AC_752NickelSilver}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_752NickelSilver.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_752NickelSilver.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_752NickelSilver.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_752NickelSilver.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_752NickelSilver.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_752NickelSilver.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_752NickelSilver.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_752NickelSilver.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_752NickelSilver.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_752NickelSilver.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_752NickelSilver.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_752NickelSilver.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_752NickelSilver.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_752NickelSilver.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_752NickelSilver.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_752NickelSilver.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }


      case AlloyCoppers::Type::AC_762NickelSilver :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_762NickelSilver.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_762NickelSilver.type"),
            {Constants::AC_762NickelSilver}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_762NickelSilver.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_762NickelSilver.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_762NickelSilver.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_762NickelSilver.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_762NickelSilver.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_762NickelSilver.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_762NickelSilver.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_762NickelSilver.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_762NickelSilver.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_762NickelSilver.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_762NickelSilver.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_762NickelSilver.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_762NickelSilver.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_762NickelSilver.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_762NickelSilver.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_762NickelSilver.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }


      case AlloyCoppers::Type::AC_770NickelSilver :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_770NickelSilver.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_770NickelSilver.type"),
            {Constants::AC_770NickelSilver}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_770NickelSilver.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_770NickelSilver.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_770NickelSilver.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_770NickelSilver.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_770NickelSilver.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_770NickelSilver.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_770NickelSilver.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_770NickelSilver.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_770NickelSilver.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_770NickelSilver.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_770NickelSilver.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_770NickelSilver.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_770NickelSilver.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_770NickelSilver.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_770NickelSilver.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_770NickelSilver.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }


      case AlloyCoppers::Type::AC_1751Class3 :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1751Class3.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1751Class3.type"),
            {Constants::AC_1751Class3}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1751Class3.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1751Class3.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1751Class3.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1751Class3.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1751Class3.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1751Class3.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1751Class3.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1751Class3.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1751Class3.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1751Class3.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1751Class3.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1751Class3.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1751Class3.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1751Class3.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1751Class3.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1751Class3.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }


      case AlloyCoppers::Type::AC_1758Nickel :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1758Nickel.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1758Nickel.type"),
            {Constants::AC_1758Nickel}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1758Nickel.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1758Nickel.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1758Nickel.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1758Nickel.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1758Nickel.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1758Nickel.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1758Nickel.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1758Nickel.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1758Nickel.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1758Nickel.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1758Nickel.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1758Nickel.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1758Nickel.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1758Nickel.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1758Nickel.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_1758Nickel.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }


      case AlloyCoppers::Type::AC_MoldmaxBeCu :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_MoldmaxBeCu.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_MoldmaxBeCu.type"),
            {Constants::AC_MoldmaxBeCu}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_MoldmaxBeCu.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_MoldmaxBeCu.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_MoldmaxBeCu.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_MoldmaxBeCu.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_MoldmaxBeCu.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_MoldmaxBeCu.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_MoldmaxBeCu.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_MoldmaxBeCu.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_MoldmaxBeCu.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_MoldmaxBeCu.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_MoldmaxBeCu.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_MoldmaxBeCu.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_MoldmaxBeCu.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_MoldmaxBeCu.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_MoldmaxBeCu.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_MoldmaxBeCu.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }


      case AlloyCoppers::Type::AC_ProthermBeCu :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_ProthermBeCu.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_ProthermBeCu.type"),
            {Constants::AC_ProthermBeCu}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_ProthermBeCu.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_ProthermBeCu.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_ProthermBeCu.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_ProthermBeCu.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_ProthermBeCu.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_ProthermBeCu.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_ProthermBeCu.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_ProthermBeCu.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_ProthermBeCu.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_ProthermBeCu.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_ProthermBeCu.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_ProthermBeCu.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_ProthermBeCu.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_ProthermBeCu.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator( checkFromLuaConfig(std::move(this->lua_state_), "AlloyCoppers.Type.AC_ProthermBeCu.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "AlloyCoppers.Type.AC_ProthermBeCu.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      default:
      {
        std::cerr << "The type AlloyCoppers specified not found, using default AlloyCoppers type\n";
        break;
      }
    }

    return true;
  }

  std::ostream &operator << (std::ostream &os, const AlloyCoppers &obj)
  {
    os << "  AlloyCoppers object properties: " "\n"
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