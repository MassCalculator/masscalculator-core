#include "materials/aluminium.h"

namespace MassCalculator
{
  Aluminium::Aluminium(Aluminium::Type type)
  {
    if(!setType(type))
    {
      std::cerr << "Construction of the object failed\n";
    }
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

  const std::pair<std::string, Aluminium::Type> Aluminium::getType(void) const
  {
    return{this->specific_properties_.type_};
  }

  const std::string Aluminium::getSpecificColor(void) const
  {
    return{this->specific_properties_.specific_color_};
  }

  const double Aluminium::getSpecificDensity(void) const
  {
    return{this->specific_properties_.specific_density_};
  }

  const double Aluminium::getSpecificVolume(void) const
  {
    return{this->specific_properties_.specific_volume_};
  }

  const double Aluminium::getSpecificMass(void) const
  {
    return{this->specific_properties_.specific_mass_};
  }

  const double Aluminium::getSpecificWeight(void) const
  {
    return{this->specific_properties_.specific_weight_};
  }

  const double Aluminium::getSpecificMeltingPoint(void) const
  {
    return{this->specific_properties_.specific_melting_point_};
  }

  const double Aluminium::getSpecificBoilingPoint(void) const
  {
    return{this->specific_properties_.specific_boiling_point_};
  }

  //private TODO set the values correctly
  bool Aluminium::setPropertieSpecs(Aluminium::Type type)
  {
    switch (type)
    {
      case Aluminium::Type::A_1100 :
      {
        this->specific_properties_.type_                    = {"A_1100", type};
        this->specific_properties_.specific_color_          = {"Metallic"};
        this->specific_properties_.specific_density_        = {1.0};
        this->specific_properties_.specific_volume_         = {1.0};
        this->specific_properties_.specific_mass_           = {1.0};
        this->specific_properties_.specific_weight_         = {1.0};
        this->specific_properties_.specific_melting_point_  = {1.0};
        this->specific_properties_.specific_boiling_point_  = {1};
        break;
      }

      case Aluminium::Type::A_2011 :
      {
        this->specific_properties_.specific_mass_ = 1;
        break;
      }

      case Aluminium::Type::A_2014 :
      {
        this->specific_properties_.specific_mass_ = 1;
        break;
      }

      case Aluminium::Type::A_2024 :
      {
        this->specific_properties_.specific_mass_ = 1;
        break;
      }

      case Aluminium::Type::A_3003 :
      {
        this->specific_properties_.specific_mass_ = 1;
        break;
      }

      case Aluminium::Type::A_5052 :
      {
        this->specific_properties_.specific_mass_ = 1;
        break;
      }

      case Aluminium::Type::A_6061 :
      {
        this->specific_properties_.specific_mass_ = 1;
        break;
      }

      case Aluminium::Type::A_6063 :
      {
        this->specific_properties_.specific_mass_ = 1;
        break;
      }

      case Aluminium::Type::A_7075 :
      {
        this->specific_properties_.specific_mass_ = 1;
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

  /**
   * @brief Shift operator overload for class Aluminium, this will print all the nessesery informations
   * 
   */
  std::ostream &operator << (std::ostream &os, const Aluminium &obj)
  {
    os << "Aluminium object properties: " "\n"
          " - Type   : " + obj.specific_properties_.type_.first + "\n"
          " - Color  : " + obj.specific_properties_.specific_color_ + "\n"
          " - Density: " + std::to_string(obj.specific_properties_.specific_density_) + "\n"
          " - Volume : " + std::to_string(obj.specific_properties_.specific_volume_) + "\n"
          " - Mass   : " + std::to_string(obj.specific_properties_.specific_mass_) + "\n"
          " - Weight : " + std::to_string(obj.specific_properties_.specific_weight_) + "\n"
          " - Melting point: " + std::to_string(obj.specific_properties_.specific_melting_point_) + "\n"
          " - Boiling point: " + std::to_string(obj.specific_properties_.specific_boiling_point_) + "\n";
    return os;
  }
}//end namespace MassCalculator