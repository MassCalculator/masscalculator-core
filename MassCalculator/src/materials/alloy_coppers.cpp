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
        this->specific_properties_.type_                       = {"AC_194Iron", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71_kg_per_cu_m};
        this->specific_properties_.gravity_                    = {2.83_mps_sq};
        this->specific_properties_.melting_point_              = {537.778_K};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0_W};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9_Pa};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8_Pa};
        break;
      }

      case AlloyCoppers::Type::AC_195Iron :
      {
        this->specific_properties_.type_                       = {"AC_195Iron", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71_kg_per_cu_m};
        this->specific_properties_.gravity_                    = {2.83_mps_sq};
        this->specific_properties_.melting_point_              = {537.778_K};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0_W};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9_Pa};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8_Pa};
        break;
      }

      case AlloyCoppers::Type::AC_172Beryllium :
      {
        this->specific_properties_.type_                       = {"AC_172Beryllium", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71_kg_per_cu_m};
        this->specific_properties_.gravity_                    = {2.83_mps_sq};
        this->specific_properties_.melting_point_              = {537.778_K};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0_W};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9_Pa};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8_Pa};
        break;
      }

      case AlloyCoppers::Type::AC_182Class2 :
      {
        this->specific_properties_.type_                       = {"AC_182Class2", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71_kg_per_cu_m};
        this->specific_properties_.gravity_                    = {2.83_mps_sq};
        this->specific_properties_.melting_point_              = {537.778_K};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0_W};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9_Pa};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8_Pa};
        break;
      }

      case AlloyCoppers::Type::AC_655Silicon :
      {
        this->specific_properties_.type_                       = {"AC_655Silicon", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71_kg_per_cu_m};
        this->specific_properties_.gravity_                    = {2.83_mps_sq};
        this->specific_properties_.melting_point_              = {537.778_K};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0_W};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9_Pa};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8_Pa};
        break;
      }

      case AlloyCoppers::Type::AC_706Nickel :
      {
        this->specific_properties_.type_                       = {"AC_706Nickel", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71_kg_per_cu_m};
        this->specific_properties_.gravity_                    = {2.83_mps_sq};
        this->specific_properties_.melting_point_              = {537.778_K};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0_W};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9_Pa};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8_Pa};
        break;
      }

      case AlloyCoppers::Type::AC_715NickelSilver :
      {
        this->specific_properties_.type_                       = {"AC_715NickelSilver", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71_kg_per_cu_m};
        this->specific_properties_.gravity_                    = {2.83_mps_sq};
        this->specific_properties_.melting_point_              = {537.778_K};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0_W};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9_Pa};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8_Pa};
        break;
      }

      case AlloyCoppers::Type::AC_725NickelSilver :
      {
        this->specific_properties_.type_                       = {"AC_725NickelSilver", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71_kg_per_cu_m};
        this->specific_properties_.gravity_                    = {2.83_mps_sq};
        this->specific_properties_.melting_point_              = {537.778_K};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0_W};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9_Pa};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8_Pa};
        break;
      }

      case AlloyCoppers::Type::AC_735NickelSilver :
      {
        this->specific_properties_.type_                       = {"AC_735NickelSilver", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71_kg_per_cu_m};
        this->specific_properties_.gravity_                    = {2.83_mps_sq};
        this->specific_properties_.melting_point_              = {537.778_K};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0_W};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9_Pa};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8_Pa};
        break;
      }


      case AlloyCoppers::Type::AC_752NickelSilver :
      {
        this->specific_properties_.type_                       = {"AC_752NickelSilver", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71_kg_per_cu_m};
        this->specific_properties_.gravity_                    = {2.83_mps_sq};
        this->specific_properties_.melting_point_              = {537.778_K};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0_W};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9_Pa};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8_Pa};
        break;
      }


      case AlloyCoppers::Type::AC_762NickelSilver :
      {
        this->specific_properties_.type_                       = {"AC_762NickelSilver", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71_kg_per_cu_m};
        this->specific_properties_.gravity_                    = {2.83_mps_sq};
        this->specific_properties_.melting_point_              = {537.778_K};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0_W};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9_Pa};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8_Pa};
        break;
      }


      case AlloyCoppers::Type::AC_770NickelSilver :
      {
        this->specific_properties_.type_                       = {"AC_770NickelSilver", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71_kg_per_cu_m};
        this->specific_properties_.gravity_                    = {2.83_mps_sq};
        this->specific_properties_.melting_point_              = {537.778_K};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0_W};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9_Pa};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8_Pa};
        break;
      }


      case AlloyCoppers::Type::AC_1751Class3 :
      {
        this->specific_properties_.type_                       = {"AC_1751Class3", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71_kg_per_cu_m};
        this->specific_properties_.gravity_                    = {2.83_mps_sq};
        this->specific_properties_.melting_point_              = {537.778_K};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0_W};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9_Pa};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8_Pa};
        break;
      }


      case AlloyCoppers::Type::AC_1758Nickel :
      {
        this->specific_properties_.type_                       = {"AC_1758Nickel", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71_kg_per_cu_m};
        this->specific_properties_.gravity_                    = {2.83_mps_sq};
        this->specific_properties_.melting_point_              = {537.778_K};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0_W};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9_Pa};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8_Pa};
        break;
      }


      case AlloyCoppers::Type::AC_MoldmaxBeCu :
      {
        this->specific_properties_.type_                       = {"AC_MoldmaxBeCu", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71_kg_per_cu_m};
        this->specific_properties_.gravity_                    = {2.83_mps_sq};
        this->specific_properties_.melting_point_              = {537.778_K};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0_W};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9_Pa};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8_Pa};
        break;
      }


      case AlloyCoppers::Type::AC_ProthermBeCu :
      {
        this->specific_properties_.type_                       = {"AC_ProthermBeCu", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71_kg_per_cu_m};
        this->specific_properties_.gravity_                    = {2.83_mps_sq};
        this->specific_properties_.melting_point_              = {537.778_K};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0_W};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9_Pa};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8_Pa};
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