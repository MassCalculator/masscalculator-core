#include "materials/steel.hpp"

namespace MassCalculator
{
  Steel::Steel(Steel::Type type)
  {
    if(!setType(type))
    {
      std::cerr << "Construction of the object failed\n";
    }
  }

  bool Steel::setType(Steel::Type type)
  {
    if(!setPropertieSpecs(type))
    {
      std::cerr << "Cannot set the Steel type\n";
      return false;
    }
    else 
      return true;
  }

  std::pair<std::string, Steel::Type> Steel::getType(void) const
  {
    return{this->specific_properties_.type_};
  }

  std::string Steel::getSpecificColor(void) const
  {
    return{this->specific_properties_.color_};
  }

  double Steel::getSpecificDensity(void) const
  {
    return{this->specific_properties_.density_};
  }

  double Steel::getSpecificGravity(void) const
  {
    return{this->specific_properties_.gravity_};
  }

  double Steel::getSpecificMeltingPoint(void) const
  {
    return{this->specific_properties_.melting_point_};
  }

  double Steel::getSpecificPoissonsRatio(void) const
  {
    return{this->specific_properties_.poissons_ratio_};
  }

  double Steel::getSpecificThermalConductivity(void) const
  {
    return{this->specific_properties_.thermal_conductivity};
  }

  double Steel::getSpecificModOfElasticityTension(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_tension_};
  }

  double Steel::getSpecificModOfElasticityTorsion(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_torsion_};
  }

  //private TODO set the values correctly
  bool Steel::setPropertieSpecs(Steel::Type type)
  {
    switch (type)
    {
      case Steel::Type::S_1010 :
      {
        this->specific_properties_.type_                       = {"S_1010", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity        = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        // this->specific_properties_.mod_of_elasticity_torsion_  = TTernaryOperator(checkFromLuaConfig("HasLuaConfig.UseLuaConfig"), getFromLuaConfig<double>("Steel.Type.A_1100.mod_of_elasticity_torsion"), {3.8});
        break;
      }

      //Data from source: https://suppliersonline.com/propertypages/2011.asp
      case Steel::Type::S_1012 :
      {
        this->specific_properties_.type_                       = {"S_1012", type};
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

      case Steel::Type::S_1015 :
      {
        this->specific_properties_.type_                       = {"S_1015", type};
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

      case Steel::Type::S_1018 :
      {
        this->specific_properties_.type_                       = {"S_1018", type};
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

      case Steel::Type::S_1541 :
      {
        this->specific_properties_.type_                       = {"S_1541", type};
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

      case Steel::Type::S_4140 :
      {
        this->specific_properties_.type_                       = {"S_4140", type};
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

      case Steel::Type::S_A36 :
      {
        this->specific_properties_.type_                       = {"S_A36", type};
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
        std::cerr << "The type Steel specified not found, using default Steel type\n";
        break;
      }
    }

    return true;
  }

// //TODO: add as a value the filepath for Steel config
//   bool Steel::checkFromLuaConfig(std::string value)
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
//   constexpr TLuaReturnType Steel::getFromLuaConfig(std::string value)
//   {
//     return lua_state_.get<TLuaReturnType>(value.c_str());
//   }

  std::ostream &operator << (std::ostream &os, const Steel &obj)
  {
    os << "  Steel object properties: " "\n"
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