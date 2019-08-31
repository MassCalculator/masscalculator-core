#include "materials/brass.hpp"

namespace MassCalculator
{
  Brass::Brass(Brass::Type type)
  {
    if(!setType(type))
    {
      std::cerr << "Construction of the object failed\n";
    }
  }

  bool Brass::setType(Brass::Type type)
  {
    if(!setPropertieSpecs(type))
    {
      std::cerr << "Cannot set the Brass type\n";
      return false;
    }
    else 
      return true;
  }

  std::pair<std::string, Brass::Type> Brass::getType(void) const
  {
    return{this->specific_properties_.type_};
  }

  std::string Brass::getSpecificColor(void) const
  {
    return{this->specific_properties_.color_};
  }

  double Brass::getSpecificDensity(void) const
  {
    return{this->specific_properties_.density_};
  }

  double Brass::getSpecificGravity(void) const
  {
    return{this->specific_properties_.gravity_};
  }

  double Brass::getSpecificMeltingPoint(void) const
  {
    return{this->specific_properties_.melting_point_};
  }

  double Brass::getSpecificPoissonsRatio(void) const
  {
    return{this->specific_properties_.poissons_ratio_};
  }

  double Brass::getSpecificThermalConductivity(void) const
  {
    return{this->specific_properties_.thermal_conductivity};
  }

  double Brass::getSpecificModOfElasticityTension(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_tension_};
  }

  double Brass::getSpecificModOfElasticityTorsion(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_torsion_};
  }

  //private TODO set the values correctly
  bool Brass::setPropertieSpecs(Brass::Type type)
  {
    switch (type)
    {
      case Brass::Type::B_240LowBrass :
      {
        this->specific_properties_.type_                       = {"B_240LowBrass", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity        = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        // this->specific_properties_.mod_of_elasticity_torsion_  = TTernaryOperator(checkFromLuaConfig("HasLuaConfig.UseLuaConfig"), getFromLuaConfig<double>("Brass.Type.A_1100.mod_of_elasticity_torsion"), {3.8});
        break;
      }

      //Data from source: https://suppliersonline.com/propertypages/2011.asp
      case Brass::Type::B_260Cartridge :
      {
        this->specific_properties_.type_                       = {"B_260Cartridge", type};
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
        std::cerr << "The type Brass specified not found, using default Brass type\n";
        break;
      }
    }

    return true;
  }

// //TODO: add as a value the filepath for Brass config
//   bool Brass::checkFromLuaConfig(std::string value)
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
//   constexpr TLuaReturnType Brass::getFromLuaConfig(std::string value)
//   {
//     return lua_state_.get<TLuaReturnType>(value.c_str());
//   }

  std::ostream &operator << (std::ostream &os, const Brass &obj)
  {
    os << "  Brass object properties: " "\n"
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