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

  double Aluminium::getSpecificDensity(void) const
  {
    return{this->specific_properties_.density_};
  }

  double Aluminium::getSpecificGravity(void) const
  {
    return{this->specific_properties_.gravity_};
  }

  double Aluminium::getSpecificMeltingPoint(void) const
  {
    return{this->specific_properties_.melting_point_};
  }

  double Aluminium::getSpecificPoissonsRatio(void) const
  {
    return{this->specific_properties_.poissons_ratio_};
  }

  double Aluminium::getSpecificThermalConductivity(void) const
  {
    return{this->specific_properties_.thermal_conductivity_};
  }

  double Aluminium::getSpecificModOfElasticityTension(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_tension_};
  }

  double Aluminium::getSpecificModOfElasticityTorsion(void) const
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
        this->specific_properties_.type_                       = {Constants::A_1100, type};
        this->specific_properties_.color_                      = {Constants::Metallic};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_        = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        // this->specific_properties_.mod_of_elasticity_torsion_  = TTernaryOperator(checkFromLuaConfig("HasLuaConfig.UseLuaConfig"), getFromLuaConfig<double>("Aluminium.Type.A_1100.mod_of_elasticity_torsion"), {3.8});
        break;
      }

      //Data from source: https://suppliersonline.com/propertypages/2011.asp
      case Aluminium::Type::A_2011 :
      {
        // this->specific_properties_ = {{"A_2011", type}, {"Metallic"}, {2.71}, {2.83}, {537.778}, {0.33}, {990.0}, {9.9}, {3.8}};

        this->specific_properties_.type_                       = {Constants::A_2011, type};
        this->specific_properties_.color_                      = {Constants::DarkTone};
        this->specific_properties_.density_                    = {2.82}; //g/cm3
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {1000};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_        = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {10.2};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.85};
        break;
      }

      case Aluminium::Type::A_2014 :
      {
        this->specific_properties_.type_                       = {Constants::A_2014, type};
        this->specific_properties_.color_                      = {Constants::Metallic};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_        = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        break;
      }

      case Aluminium::Type::A_2024 :
      {
        this->specific_properties_.type_                       = {Constants::A_2024, type};
        this->specific_properties_.color_                      = {Constants::Metallic};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_        = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        break;
      }

      case Aluminium::Type::A_3003 :
      {
        this->specific_properties_.type_                       = {Constants::A_3003, type};
        this->specific_properties_.color_                      = {Constants::Metallic};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_        = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        break;
      }

      case Aluminium::Type::A_5052 :
      {
        this->specific_properties_.type_                       = {Constants::A_5052, type};
        this->specific_properties_.color_                      = {Constants::Metallic};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_        = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        break;
      }

      case Aluminium::Type::A_6061 :
      {
        this->specific_properties_.type_                       = {Constants::A_6061, type};
        this->specific_properties_.color_                      = {Constants::Metallic};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_        = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        break;
      }

      case Aluminium::Type::A_6063 :
      {
        this->specific_properties_.type_                       = {Constants::A_6063, type};
        this->specific_properties_.color_                      = {Constants::Metallic};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_        = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        break;
      }

      case Aluminium::Type::A_7075 :
      {
        this->specific_properties_.type_                       = {Constants::A_7075, type};
        this->specific_properties_.color_                      = {Constants::Metallic};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_        = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
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
          "   - Density : " + std::to_string(obj.getSpecificDensity()) + "\n"
          "   - Gravity : " + std::to_string(obj.getSpecificGravity()) + "\n"
          "   - Melting point : " + std::to_string(obj.getSpecificMeltingPoint()) + "\n"
          "   - Poissons ratio: " + std::to_string(obj.getSpecificPoissonsRatio()) + "\n"
          "   - Thermal conductivity         : " + std::to_string(obj.getSpecificThermalConductivity()) + "\n"
          "   - Modulus of elasticity tension: " + std::to_string(obj.getSpecificModOfElasticityTension()) + "\n"
          "   - Modulus of elasticity torsion: " + std::to_string(obj.getSpecificModOfElasticityTorsion()) + "\n";
    return os;
  }
}//end namespace MassCalculator