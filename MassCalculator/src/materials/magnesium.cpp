#include "materials/magnesium.hpp"

namespace MassCalculator
{
  Magnesium::Magnesium(void)
  {
    this->initLuaScript();
  }

  Magnesium::Magnesium(Magnesium::Type type)
  {
    this->initLuaScript();

    if(!setType(type))
    {
      std::cerr << "Construction of the object failed\n";
    }
  }

  bool Magnesium::initLuaScript(void)
  {
    this->lua_state_.openScript(Constants::MagnesiumLuaConfigPath);
    return true;
  }

  bool Magnesium::setType(Magnesium::Type type)
  {
    if(!setPropertieSpecs(type))
    {
      std::cerr << "Cannot set the Magnesium type\n";
      return false;
    }
    else 
      return true;
  }

  std::pair<std::string, Magnesium::Type> Magnesium::getType(void) const
  {
    return{this->specific_properties_.type_};
  }

  std::string Magnesium::getSpecificColor(void) const
  {
    return{this->specific_properties_.color_};
  }

  double Magnesium::getSpecificDensity(void) const
  {
    return{this->specific_properties_.density_};
  }

  double Magnesium::getSpecificGravity(void) const
  {
    return{this->specific_properties_.gravity_};
  }

  double Magnesium::getSpecificMeltingPoint(void) const
  {
    return{this->specific_properties_.melting_point_};
  }

  double Magnesium::getSpecificPoissonsRatio(void) const
  {
    return{this->specific_properties_.poissons_ratio_};
  }

  double Magnesium::getSpecificThermalConductivity(void) const
  {
    return{this->specific_properties_.thermal_conductivity_};
  }

  double Magnesium::getSpecificModOfElasticityTension(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_tension_};
  }

  double Magnesium::getSpecificModOfElasticityTorsion(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_torsion_};
  }

  //private TODO set the values correctly
  bool Magnesium::setPropertieSpecs(Magnesium::Type type)
  {
    switch (type)
    {
      case Magnesium::Type::M_AZ31B :
      {
        this->specific_properties_.type_                       = {"M_AZ31B", type};
        this->specific_properties_.color_                      = {"Metallic"};
        this->specific_properties_.density_                    = {2.71};
        this->specific_properties_.gravity_                    = {2.83};
        this->specific_properties_.melting_point_              = {537.778};
        this->specific_properties_.poissons_ratio_             = {0.33};
        this->specific_properties_.thermal_conductivity_       = {990.0};
        this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
        this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
        // this->specific_properties_.mod_of_elasticity_torsion_  = TTernaryOperator(checkFromLuaConfig("HasLuaConfig.UseLuaConfig"), getFromLuaConfig<double>("Magnesium.Type.A_1100.mod_of_elasticity_torsion"), {3.8});
        break;
      }

      default:
      {
        std::cerr << "The type Magnesium specified not found, using default Magnesium type\n";
        break;
      }
    }

    return true;
  }

  std::ostream &operator << (std::ostream &os, const Magnesium &obj)
  {
    os << "  Magnesium object properties: " "\n"
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