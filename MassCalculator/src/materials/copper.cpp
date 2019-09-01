#include "materials/copper.hpp"

namespace MassCalculator
{
  Copper::Copper(Copper::Type type)
  {
    if(!setType(type))
    {
      std::cerr << "Construction of the object failed\n";
    }
  }

  bool Copper::setType(Copper::Type type)
  {
    if(!setPropertieSpecs(type))
    {
      std::cerr << "Cannot set the Copper type\n";
      return false;
    }
    else 
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

  double Copper::getSpecificDensity(void) const
  {
    return{this->specific_properties_.density_};
  }

  double Copper::getSpecificGravity(void) const
  {
    return{this->specific_properties_.gravity_};
  }

  double Copper::getSpecificMeltingPoint(void) const
  {
    return{this->specific_properties_.melting_point_};
  }

  double Copper::getSpecificPoissonsRatio(void) const
  {
    return{this->specific_properties_.poissons_ratio_};
  }

  double Copper::getSpecificThermalConductivity(void) const
  {
    return{this->specific_properties_.thermal_conductivity};
  }

  double Copper::getSpecificModOfElasticityTension(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_tension_};
  }

  double Copper::getSpecificModOfElasticityTorsion(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_torsion_};
  }

  //private TODO set the values correctly
  bool Copper::setPropertieSpecs(Copper::Type type)
  {
    switch (type)
    {
      case Copper::Type::C_101 :
      {
        this->specific_properties_.type_                       = {"C_101", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity        = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        // this->specific_properties_.mod_of_elasticity_torsion_  = TTernaryOperator(checkFromLuaConfig("HasLuaConfig.UseLuaConfig"), getFromLuaConfig<double>("Copper.Type.A_1100.mod_of_elasticity_torsion"), {3.8});
        break;
      }

      //Data from source: https://suppliersonline.com/propertypages/2011.asp
      case Copper::Type::C_102 :
      {
        this->specific_properties_.type_                       = {"C_102", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity        = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        break;
      }

      case Copper::Type::C_103 :
      {
        this->specific_properties_.type_                       = {"C_103", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity        = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        break;
      }

      case Copper::Type::C_110 :
      {
        this->specific_properties_.type_                       = {"C_110", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity        = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        break;
      }

      case Copper::Type::C_122 :
      {
        this->specific_properties_.type_                       = {"C_122", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity        = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        break;
      }

      default:
      {
        std::cerr << "The type Copper specified not found, using default Copper type\n";
        break;
      }
    }

    return true;
  }

// //TODO: add as a value the filepath for Copper config
//   bool Copper::checkFromLuaConfig(std::string value)
//   {
//     if(this->lua_state_.get<bool>(value.c_str()))
//     {
//       return true;
//     }
//     else
//     {
//       return false;
//     }
//   }

//   template<typename TLuaReturnType>
//   constexpr TLuaReturnType Copper::getFromLuaConfig(std::string value)
//   {
//     return lua_state_.get<TLuaReturnType>(value.c_str());
//   }

  std::ostream &operator << (std::ostream &os, const Copper &obj)
  {
    os << "  Copper object properties: " "\n"
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