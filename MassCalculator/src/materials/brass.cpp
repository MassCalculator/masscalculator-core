#include "materials/brass.hpp"

namespace MassCalculator
{
  Brass::Brass(void)
  {
    this->initLuaScript();
  }

  Brass::Brass(Brass::Type type)
  {
    this->initLuaScript();

    if(!setType(type))
    {
      std::cerr << "Construction of the object failed\n";
    }
  }

  bool Brass::initLuaScript(void)
  {
    this->lua_state_.openScript(Constants::BrassLuaConfigPath);
    return true;
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

  kilograms_per_cubic_meter_t Brass::getSpecificDensity(void) const
  {
    return{this->specific_properties_.density_};
  }

  meters_per_second_squared_t Brass::getSpecificGravity(void) const
  {
    return{this->specific_properties_.gravity_};
  }

  kelvin_t Brass::getSpecificMeltingPoint(void) const
  {
    return{this->specific_properties_.melting_point_};
  }

  double Brass::getSpecificPoissonsRatio(void) const
  {
    return{this->specific_properties_.poissons_ratio_};
  }

  watt_t Brass::getSpecificThermalConductivity(void) const
  {
    return{this->specific_properties_.thermal_conductivity_};
  }

  pascal_t Brass::getSpecificModOfElasticityTension(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_tension_};
  }

  pascal_t Brass::getSpecificModOfElasticityTorsion(void) const
  {
    return{this->specific_properties_.mod_of_elasticity_torsion_};
  }

  //private TODO set the values correctly
  bool Brass::setPropertieSpecs(Brass::Type type)
  {
    switch (type)
    {
      case Brass::Type::B_240Low :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), "Brass.Type.B_240Low.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Brass.Type.B_240Low.type"),
            {Constants::B_240Low}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), "Brass.Type.B_240Low.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Brass.Type.B_240Low.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), "Brass.Type.B_240Low.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Brass.Type.B_240Low.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), "Brass.Type.B_240Low.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Brass.Type.B_240Low.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), "Brass.Type.B_240Low.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Brass.Type.B_240Low.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), "Brass.Type.B_240Low.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "Brass.Type.B_240Low.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), "Brass.Type.B_240Low.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Brass.Type.B_240Low.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), "Brass.Type.B_240Low.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Brass.Type.B_240Low.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), "Brass.Type.B_240Low.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Brass.Type.B_240Low.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      case Brass::Type::B_260Cartridge :
      {
        this->specific_properties_.type_ = {
          TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), "Brass.Type.B_260Cartridge.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Brass.Type.B_260Cartridge.type"),
            {Constants::B_260Cartridge}
          ), type};
        this->specific_properties_.color_ = 
          TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), "Brass.Type.B_260Cartridge.UseLuaConfig"),
            getFromLuaConfig<std::string>(std::move(this->lua_state_), "Brass.Type.B_260Cartridge.color"),
            {Constants::Metallic}
          );
        this->specific_properties_.density_ = 
          TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), "Brass.Type.B_260Cartridge.UseLuaConfig"),
            static_cast<kilograms_per_cubic_meter_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Brass.Type.B_260Cartridge.density")),
            {2.71_kg_per_cu_m}
          );
        this->specific_properties_.gravity_ = 
          TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), "Brass.Type.B_260Cartridge.UseLuaConfig"),
            static_cast<meters_per_second_squared_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Brass.Type.B_260Cartridge.gravity")),
            {2.83_mps_sq}
          );
        this->specific_properties_.melting_point_ = 
          TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), "Brass.Type.B_260Cartridge.UseLuaConfig"),
            static_cast<kelvin_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Brass.Type.B_260Cartridge.melting_point")),
            {537.778_K}
          );
        this->specific_properties_.poissons_ratio_ = 
          TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), "Brass.Type.B_260Cartridge.UseLuaConfig"),
            getFromLuaConfig<double>(std::move(this->lua_state_), "Brass.Type.B_260Cartridge.poissons_ratio"),
            {0.33}
          );
        this->specific_properties_.thermal_conductivity_ = 
          TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), "Brass.Type.B_260Cartridge.UseLuaConfig"),
            static_cast<watt_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Brass.Type.B_260Cartridge.thermal_conductivity")),
            {990.0_W}
          );
        this->specific_properties_.mod_of_elasticity_tension_ = 
          TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), "Brass.Type.B_260Cartridge.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Brass.Type.B_260Cartridge.mod_of_elasticity_tension")),
            {9.9_Pa}
          );
        this->specific_properties_.mod_of_elasticity_torsion_ = 
          TTernaryOperator(checkFromLuaConfig(std::move(this->lua_state_), "Brass.Type.B_260Cartridge.UseLuaConfig"),
            static_cast<pascal_t>(getFromLuaConfig<double>(std::move(this->lua_state_), "Brass.Type.B_260Cartridge.mod_of_elasticity_torsion")),
            {3.8_Pa}
          );
        break;
      }

      // case Brass::Type::B_353Leaded :
      // {
      //   this->specific_properties_.type_                       = {"B_353Leaded", type};
      //   this->specific_properties_.color_                      = {"Metallic"};
      //   this->specific_properties_.density_                    = {2.71};
      //   this->specific_properties_.gravity_                    = {2.83};
      //   this->specific_properties_.melting_point_              = {537.778};
      //   this->specific_properties_.poissons_ratio_             = {0.33};
      //   this->specific_properties_.thermal_conductivity_       = {990.0};
      //   this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
      //   this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
      //   break;
      // }

      // case Brass::Type::B_360 :
      // {
      //   this->specific_properties_.type_                       = {"B_360", type};
      //   this->specific_properties_.color_                      = {"Metallic"};
      //   this->specific_properties_.density_                    = {2.71};
      //   this->specific_properties_.gravity_                    = {2.83};
      //   this->specific_properties_.melting_point_              = {537.778};
      //   this->specific_properties_.poissons_ratio_             = {0.33};
      //   this->specific_properties_.thermal_conductivity_       = {990.0};
      //   this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
      //   this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
      //   break;
      // }

      // case Brass::Type::B_365 :
      // {
      //   this->specific_properties_.type_                       = {"B_365", type};
      //   this->specific_properties_.color_                      = {"Metallic"};
      //   this->specific_properties_.density_                    = {2.71};
      //   this->specific_properties_.gravity_                    = {2.83};
      //   this->specific_properties_.melting_point_              = {537.778};
      //   this->specific_properties_.poissons_ratio_             = {0.33};
      //   this->specific_properties_.thermal_conductivity_       = {990.0};
      //   this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
      //   this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
      //   break;
      // }

      // case Brass::Type::B_380 :
      // {
      //   this->specific_properties_.type_                       = {"B_380", type};
      //   this->specific_properties_.color_                      = {"Metallic"};
      //   this->specific_properties_.density_                    = {2.71};
      //   this->specific_properties_.gravity_                    = {2.83};
      //   this->specific_properties_.melting_point_              = {537.778};
      //   this->specific_properties_.poissons_ratio_             = {0.33};
      //   this->specific_properties_.thermal_conductivity_       = {990.0};
      //   this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
      //   this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
      //   break;
      // }

      // case Brass::Type::B_385 :
      // {
      //   this->specific_properties_.type_                       = {"B_385", type};
      //   this->specific_properties_.color_                      = {"Metallic"};
      //   this->specific_properties_.density_                    = {2.71};
      //   this->specific_properties_.gravity_                    = {2.83};
      //   this->specific_properties_.melting_point_              = {537.778};
      //   this->specific_properties_.poissons_ratio_             = {0.33};
      //   this->specific_properties_.thermal_conductivity_       = {990.0};
      //   this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
      //   this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
      //   break;
      // }

      // case Brass::Type::B_464 :
      // {
      //   this->specific_properties_.type_                       = {"B_464", type};
      //   this->specific_properties_.color_                      = {"Metallic"};
      //   this->specific_properties_.density_                    = {2.71};
      //   this->specific_properties_.gravity_                    = {2.83};
      //   this->specific_properties_.melting_point_              = {537.778};
      //   this->specific_properties_.poissons_ratio_             = {0.33};
      //   this->specific_properties_.thermal_conductivity_       = {990.0};
      //   this->specific_properties_.mod_of_elasticity_tension_  = {9.9};
      //   this->specific_properties_.mod_of_elasticity_torsion_  = {3.8};
      //   break;
      // }

      default:
      {
        std::cerr << "The type Brass specified not found, using default Brass type\n";
        break;
      }
    }

    return true;
  }

  std::ostream &operator << (std::ostream &os, const Brass &obj)
  {
    os << "  Brass object properties: " "\n"
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

  std::ostream &operator << (std::ostream& os, Brass::Type type)
  {
    switch(type)
    {
      case Brass::Type::B_240Low: os << Constants::B_240Low; break;
      case Brass::Type::B_260Cartridge: os << Constants::B_260Cartridge; break;
      case Brass::Type::B_353Leaded: os << Constants::B_353Leaded; break;
      case Brass::Type::B_360: os << Constants::B_360; break;
      case Brass::Type::B_365: os << Constants::B_365; break;
      case Brass::Type::B_380: os << Constants::B_380; break;
      case Brass::Type::B_385: os << Constants::B_385; break;
      case Brass::Type::B_464: os << Constants::B_464; break;
      case Brass::Type::UNSPECIFIED: os << Constants::UNSPECIFIED; break;
      default: os << "Name cannot be found";
    }
    return os;
  }
}//end namespace MassCalculator