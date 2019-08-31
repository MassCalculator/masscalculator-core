#include "materials/alloy_steels.hpp"

namespace MassCalculator
{
  AlloySteels::AlloySteels(AlloySteels::Type type)
  {
    if(!setType(type))
    {
      std::cerr << "Construction of the object failed\n";
    }
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

  double AlloySteels::getSpecificDensity(void) const
  {
    return{this->specific_properties_.density_};
  }

  double AlloySteels::getSpecificGravity(void) const
  {
    return{this->specific_properties_.gravity_};
  }

  double AlloySteels::getSpecificMeltingPoint(void) const
  {
    return{this->specific_properties_.melting_point_};
  }

  double AlloySteels::getSpecificPoissonsRatio(void) const
  {
    return{this->specific_properties_.poissons_ratio_};
  }

  double AlloySteels::getSpecificThermalConductivity(void) const
  {
    return{this->specific_properties_.thermal_conductivity};
  }

  double AlloySteels::getSpecificModOfElasticityTension(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_tension_};
  }

  double AlloySteels::getSpecificModOfElasticityTorsion(void) const
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
        this->specific_properties_.type_                       = {"AS_4135", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity        = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        // this->specific_properties_.mod_of_elasticity_torsion_  = TTernaryOperator(checkFromLuaConfig("HasLuaConfig.UseLuaConfig"), getFromLuaConfig<double>("AlloySteels.Type.A_1100.mod_of_elasticity_torsion"), {3.8});
        break;
      }

      //Data from source: https://suppliersonline.com/propertypages/2011.asp
      case AlloySteels::Type::AS_4140 :
      {
        this->specific_properties_.type_                       = {"AS_4140", type};
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

      case AlloySteels::Type::AS_4340 :
      {
        this->specific_properties_.type_                       = {"AS_4340", type};
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
        std::cerr << "The type AlloySteels specified not found, using default AlloySteels type\n";
        break;
      }
    }

    return true;
  }

// //TODO: add as a value the filepath for AlloySteels config
//   bool AlloySteels::checkFromLuaConfig(std::string value)
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
//   constexpr TLuaReturnType AlloySteels::getFromLuaConfig(std::string value)
//   {
//     return lua_state_.get<TLuaReturnType>(value.c_str());
//   }

  std::ostream &operator << (std::ostream &os, const AlloySteels &obj)
  {
    os << "  AlloySteels object properties: " "\n"
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