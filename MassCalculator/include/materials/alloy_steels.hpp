/**
 * @file alloy_steels.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Alloy Steels class that holds the parameters for all the types
 * @version 0.1
 * @date 2020-03-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___ALLOY_STEELS_H___
#define ___ALLOY_STEELS_H___
#include "material.hpp"

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator
{
    /**
   * @brief String constants that are used through the code
   * 
   */
  namespace Constants
  {
    const std::string AS_4135{"AS_4135"};
    const std::string AS_4140{"AS_4140"};
    const std::string AS_4340{"AS_4340"};

    const std::string AlloySteelsLuaConfigPath{"/home/jimmyhalimi/ws/prototype_ws/MassCalculator/MassCalculator/resources/materials/alloy_steels_config.lua"};
  }

  /**
   * @brief Class AlloySteels, that holds all the nessesary information for AlloySteels and it's types therefore we can use in the interface
   * 
   */
  class AlloySteels : public Material<AlloySteels>
  {
    public: enum class Type : uint8_t;

    /**
     * @brief Struct with material specific properties
     * TODO:Check if this can be moved to the base class
     */
    typedef struct Properties
    {

      /**
       * @brief Private members of AlloySteels class. Values defaulted with brace-enclosed initializer list
       * and will be set from the constructor.
       * 
       * @param type_ Type The parameter to save the specific type
       * @param color_ string Parameter to save specific color
       * @param density_ kilograms_per_cubic_meter_t Parameter to save specific density
       * @param gravity_ meters_per_second_squared_t Parameter to save specific gravity
       * @param melting_point_ kelvin_t Parameter to save specific melting point
       * @param poissons_ratio_ double Parameter to save specific poissons ratio
       * @param thermal_conductivity_ watt_t Parameter to save specific thermal conductivity
       * @param mod_of_elasticity_tension_ pascal_t Parameter to save specific modulus of elasticity tension
       * @param mod_of_elasticity_torsion_ pascal_t Parameter to save specific modulus of elasticity torsion
       * 
       */
      std::pair<std::string, Type> type_{Constants::UNSPECIFIED, AlloySteels::Type::UNSPECIFIED};
      std::string color_{0};
      kilograms_per_cubic_meter_t density_{0_kg_per_cu_m};
      meters_per_second_squared_t gravity_{0_mps_sq};
      kelvin_t melting_point_{0_K};
      double poissons_ratio_{0};
      watt_t thermal_conductivity_{0_W};
      pascal_t mod_of_elasticity_tension_{0_Pa};
      pascal_t mod_of_elasticity_torsion_{0_Pa};
    }Properties_t;

    public:
    /**
     * @brief Enum that holds the AlloySteels types Source: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
     * TODO: Maybe add the documentation also in a string, in setPropertySpecs so we can use in the app to show some information about the alloy selected
     */
    enum class Type : uint8_t
    {
      BEGIN = 0,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      AS_4135 = BEGIN,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      AS_4140,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      AS_4340,

      /**
       * @brief Unspecified metal alloy
       * 
       */
      UNSPECIFIED,

      END
    };

    friend std::ostream& operator<<(std::ostream& os, Type type)
    {
      switch(type)
      {
        case Type::AS_4135: os << Constants::AS_4135; break;
        case Type::AS_4140: os << Constants::AS_4140; break;
        case Type::AS_4340: os << Constants::AS_4340; break;
        case Type::UNSPECIFIED: os << Constants::UNSPECIFIED; break;
        default: os << "Name cannot be found";
      }
      return os;
    }

    /**
     * @brief Construct a new AlloySteels object
     * 
     */
    AlloySteels(void);

    /**
     * @brief Construct a new AlloySteels object and specify the type
     * 
     */
    AlloySteels(Type type);

    /**
     * @brief Function to initialize the Lua object
     * 
     */
    bool initLuaScript(void);

    /**
     * @brief Set the Type object
     * 
     * @param type Type of the AlloySteels
     * @return true If the type is set successfully
     * @return false If the type failed to set
     */
    bool setType(Type type);

    /**
     * @brief Get the Type object
     * 
     * @return const std::pair<std::string, Type> Pair with type name and type enum
     */
    std::pair<std::string, Type> getType(void) const;

    /**
     * @brief Get the Specific Color object
     * 
     * @return const std::string Color of the material
     */
    std::string getSpecificColor(void) const;

    /**
     * @brief Get the Specific Density object
     * 
     * @return const kilograms_per_cubic_meter_t Density of the material
     */
    kilograms_per_cubic_meter_t getSpecificDensity(void) const;

    /**
     * @brief Get the Specific Gravity object
     * 
     * @return const meters_per_second_squared_t Gravity of the material
     */
    meters_per_second_squared_t getSpecificGravity(void) const;

    /**
     * @brief Get the Specific Melting Point object
     * 
     * @return const kelvin_t The specific melting point of AlloySteels type
     */
    kelvin_t getSpecificMeltingPoint(void) const;

    /**
     * @brief Get the Specific PoissonsRatio object
     * 
     * @return double The specific poissons ratio of AlloySteels type
     */
    double getSpecificPoissonsRatio(void) const;

    /**
     * @brief Get the Specific Thermal Conductivity object
     * 
     * @return watt_t The specific thermal conductivity of AlloySteels type
     */
    watt_t getSpecificThermalConductivity(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Tension object
     * 
     * @return const pascal_t The specific modulus of elasticity tension point of AlloySteels type
     */
    pascal_t getSpecificModOfElasticityTension(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Torsion object
     * 
     * @return const pascal_t The specific modulus of elasticity torsion point of AlloySteels type
     */
    pascal_t getSpecificModOfElasticityTorsion(void) const;

    /**
     * @brief Destroy the AlloySteels object
     * 
     */
    ~AlloySteels(void) = default;

    /**
     * @brief Shift operator overload for class AlloySteels, this will print all the nessesery informations
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const AlloySteels &obj);

    private:
    /**
     * @brief Delete copy constructor
     * 
     */
    AlloySteels(const AlloySteels&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    AlloySteels(AlloySteels&&) = default;

    /**
     * @brief Delete assignment operator
     */
    AlloySteels& operator=(const AlloySteels&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    AlloySteels& operator=(AlloySteels&&) = default;

    /**
     * @brief Set the Propertie Specs object
     * 
     * @param type Type of AlloySteels
     * @return true If the specifications of propertie are successfully set
     * @return false  If the specifications of propertie failed to set
     */
    bool setPropertieSpecs(Type type);

    /**
     * @brief Properties struct to hold the specific object properties
     * 
     */
    Properties_t specific_properties_;

    /**
     * @brief Lua Handler object to get the config for metals from LuaScript is necessary
     * 
     */
    LuaScriptHandler lua_state_;

  };
}//end namespace MassCalculator
#endif//___ALLOY_STEELS_H___