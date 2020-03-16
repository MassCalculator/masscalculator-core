#include "materials/nickel.hpp"

namespace MassCalculator
{
  Nickel::Nickel(void)
  {
    this->initLuaScript();
  }

  Nickel::Nickel(Nickel::Type type)
  {
    this->initLuaScript();
    
    if(!setType(type))
    {
      std::cerr << "Construction of the object failed\n";
    }
  }

  bool Nickel::initLuaScript(void)
  {
    this->lua_state_.openScript(Constants::LuaConfigPath);
    return true;
  }

  bool Nickel::setType(Nickel::Type type)
  {
    if(!setPropertieSpecs(type))
    {
      std::cerr << "Cannot set the Nickel type\n";
      return false;
    }
    else 
      return true;
  }

  std::pair<std::string, Nickel::Type> Nickel::getType(void) const
  {
    return{this->specific_properties_.type_};
  }

  std::string Nickel::getSpecificColor(void) const
  {
    return{this->specific_properties_.color_};
  }

  double Nickel::getSpecificDensity(void) const
  {
    return{this->specific_properties_.density_};
  }

  double Nickel::getSpecificGravity(void) const
  {
    return{this->specific_properties_.gravity_};
  }

  double Nickel::getSpecificMeltingPoint(void) const
  {
    return{this->specific_properties_.melting_point_};
  }

  double Nickel::getSpecificPoissonsRatio(void) const
  {
    return{this->specific_properties_.poissons_ratio_};
  }

  double Nickel::getSpecificThermalConductivity(void) const
  {
    return{this->specific_properties_.thermal_conductivity_};
  }

  double Nickel::getSpecificModOfElasticityTension(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_tension_};
  }

  double Nickel::getSpecificModOfElasticityTorsion(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_torsion_};
  }

  //private TODO set the values correctly
  bool Nickel::setPropertieSpecs(Nickel::Type type)
  {
    switch (type)
    {
      case Nickel::Type::N_201 :
      {
        this->specific_properties_.type_                       = {"N_201", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        // this->specific_properties_.mod_of_elasticity_torsion_  = TTernaryOperator(checkFromLuaConfig("HasLuaConfig.UseLuaConfig"), getFromLuaConfig<double>("Nickel.Type.A_1100.mod_of_elasticity_torsion"), {3.8});
        break;
      }

      //Data from source: https://suppliersonline.com/propertypages/2011.asp
      case Nickel::Type::N_210 :
      {
        this->specific_properties_.type_                       = {"N_210", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        break;
      }

      case Nickel::Type::N_220 :
      {
        this->specific_properties_.type_                       = {"N_220", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        break;
      }

      case Nickel::Type::N_230 :
      {
        this->specific_properties_.type_                       = {"N_230", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        break;
      }

      case Nickel::Type::N_400 :
      {
        this->specific_properties_.type_                       = {"N_400", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        break;
      }

      default:
      {
        std::cerr << "The type Nickel specified not found, using default Nickel type\n";
        break;
      }
    }

    return true;
  }

  std::ostream &operator << (std::ostream &os, const Nickel &obj)
  {
    os << "  Nickel object properties: " "\n"
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