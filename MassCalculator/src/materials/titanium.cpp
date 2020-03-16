#include "materials/titanium.hpp"

namespace MassCalculator
{
  Titanium::Titanium(void)
  {
    this->initLuaScript();
  }

  Titanium::Titanium(Titanium::Type type)
  {
    this->initLuaScript();
    
    if(!setType(type))
    {
      std::cerr << "Construction of the object failed\n";
    }
  }

  bool Titanium::setType(Titanium::Type type)
  {
    if(!setPropertieSpecs(type))
    {
      std::cerr << "Cannot set the Titanium type\n";
      return false;
    }
    else 
      return true;
  }

  bool Titanium::initLuaScript(void)
  {
    this->lua_state_.openScript(Constants::TitaniumLuaConfigPath);
    return true;
  }

  std::pair<std::string, Titanium::Type> Titanium::getType(void) const
  {
    return{this->specific_properties_.type_};
  }

  std::string Titanium::getSpecificColor(void) const
  {
    return{this->specific_properties_.color_};
  }

  double Titanium::getSpecificDensity(void) const
  {
    return{this->specific_properties_.density_};
  }

  double Titanium::getSpecificGravity(void) const
  {
    return{this->specific_properties_.gravity_};
  }

  double Titanium::getSpecificMeltingPoint(void) const
  {
    return{this->specific_properties_.melting_point_};
  }

  double Titanium::getSpecificPoissonsRatio(void) const
  {
    return{this->specific_properties_.poissons_ratio_};
  }

  double Titanium::getSpecificThermalConductivity(void) const
  {
    return{this->specific_properties_.thermal_conductivity_};
  }

  double Titanium::getSpecificModOfElasticityTension(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_tension_};
  }

  double Titanium::getSpecificModOfElasticityTorsion(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_torsion_};
  }

  //private TODO set the values correctly
  bool Titanium::setPropertieSpecs(Titanium::Type type)
  {
    switch (type)
    {
      case Titanium::Type::T_6Al4V :
      {
        this->specific_properties_.type_                       = {"T_6Al4V", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_        = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        // this->specific_properties_.mod_of_elasticity_torsion_  = TTernaryOperator(checkFromLuaConfig("HasLuaConfig.UseLuaConfig"), getFromLuaConfig<double>("Titanium.Type.A_1100.mod_of_elasticity_torsion"), {3.8});
        break;
      }

      //Data from source: https://suppliersonline.com/propertypages/2011.asp
      case Titanium::Type::T_Grade2 :
      {
        this->specific_properties_.type_                       = {"T_Grade2", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_        = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        break;
      }

      case Titanium::Type::T_Grade4 :
      {
        this->specific_properties_.type_                       = {"T_Grade4", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_        = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        break;
      }

      case Titanium::Type::T_Grade5 :
      {
        this->specific_properties_.type_                       = {"T_Grade5", type};
        this->specific_properties_.color_                      = {"Metallic"};
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
        std::cerr << "The type Titanium specified not found, using default Titanium type\n";
        break;
      }
    }

    return true;
  }

  std::ostream &operator << (std::ostream &os, const Titanium &obj)
  {
    os << "  Titanium object properties: " "\n"
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