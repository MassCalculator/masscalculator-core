/**
 * @file copper.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Copper class that holds the parameters for all the types
 * @version 0.1
 * @date 2020-03-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___COPPER_H___
#define ___COPPER_H___
#include "material.hpp"

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator
{
  namespace Constants
  {
    const std::string  C_101{"C_101"};
    const std::string  C_102{"C_102"};
    const std::string  C_103{"C_103"};
    const std::string  C_110{"C_110"};
    const std::string  C_122{"C_122"};

    const std::string CopperLuaConfigPath{"/home/jimmyhalimi/ws/prototype_ws/MassCalculator/MassCalculator/resources/materials/copper_config.lua"};
  }

  /**
   * @brief Class Copper, that holds all the nessesary information for Copper and it's types therefore we can use in the interface
   * 
   */
  class Copper : public Material<Copper>
  {
    public: enum class Type : uint8_t;

    /**
     * @brief Struct with material specific properties
     * TODO:Check if this can be moved to the base class
     */
    typedef struct Properties
    {

      /**
       * @brief Private members of Copper class. Values defaulted with brace-enclosed initializer list
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
      std::pair<std::string, Type> type_{Constants::UNSPECIFIED, Copper::Type::UNSPECIFIED};
      std::string color_{""};
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
     * @brief Enum that holds the Copper types Source: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
     * TODO: Maybe add the documentation also in a string, in setPropertySpecs so we can use in the app to show some information about the alloy selected
     */
    enum class Type : uint8_t
    {
      BEGIN = 0,
      
      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      C_101 = BEGIN,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      C_102,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      C_103,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      C_110,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      C_122,

      /**
       * @brief Unspecified metal alloy
       * 
       */
      UNSPECIFIED,

      END
    };

    /**
     * @brief Construct a new Copper object
     * 
     */
    Copper(void);

    /**
     * @brief Construct a new Copper object and specify the type
     * 
     */
    Copper(const Type &type);

    /**
     * @brief Function to initialize the Lua object
     * 
     */
    bool initLuaScript(void);

    /**
     * @brief Set the Type object
     * 
     * @param type Type of the Copper
     * @return true If the type is set successfully
     * @return false If the type failed to set
     */
    bool setType(const Type &type);

    /**
     * @brief Get the Type object
     * 
     * @return std::pair<std::string, Type> Pair with type name and type enum
     */
    std::pair<std::string, Type> getType(void) const;

    /**
     * @brief Get the Specific Color object
     * 
     * @return std::string Color of the material
     */
    std::string getSpecificColor(void) const;

    /**
     * @brief Get the Specific Density object
     * 
     * @return kilograms_per_cubic_meter_t Density of the material
     */
    kilograms_per_cubic_meter_t getSpecificDensity(void) const;

    /**
     * @brief Get the Specific Gravity object
     * 
     * @return meters_per_second_squared_t Gravity of the material
     */
    meters_per_second_squared_t getSpecificGravity(void) const;

    /**
     * @brief Get the Specific Melting Point object
     * 
     * @return kelvin_t The specific melting point of Copper type
     */
    kelvin_t getSpecificMeltingPoint(void) const;

    /**
     * @brief Get the Specific PoissonsRatio object
     * 
     * @return double The specific poissons ratio of Copper type
     */
    double getSpecificPoissonsRatio(void) const;

    /**
     * @brief Get the Specific Thermal Conductivity object
     * 
     * @return watt_t The specific thermal conductivity of Copper type
     */
    watt_t getSpecificThermalConductivity(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Tension object
     * 
     * @return pascal_t The specific modulus of elasticity tension point of Copper type
     */
    pascal_t getSpecificModOfElasticityTension(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Torsion object
     * 
     * @return pascal_t The specific modulus of elasticity torsion point of Copper type
     */
    pascal_t getSpecificModOfElasticityTorsion(void) const;

    /**
     * @brief Destroy the Copper object
     * 
     */
    ~Copper(void) = default;

    /**
     * @brief Shift operator overload for class Copper, this will print all the nessesery informations
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const Copper &obj);

    /**
     * @brief Shift operator overload for Types of AlloySteels, this will print the name in string
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const Type &type);

    /**
     * @brief Delete copy constructor
     * 
     */
    Copper(const Copper&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    Copper(Copper&&) = default;

    /**
     * @brief Delete assignment operator
     */
    Copper& operator=(const Copper&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    Copper& operator=(Copper&&) = default;

    private:
    /**
     * @brief Function to return the class name, not the pointer of the class, I am trying to keep away this function outside of the class
     * 
     * @return std::string Class name as a string
     */
    inline std::string _getClassName(Copper *) { return {"Copper"}; };

    /**
     * @brief Function to set the static propertie values
     * 
     * @param _properties Structure of the constant properties
     * @return true If properties are correctly set
     * @return false If properties have failed to set
     */
    bool _setPropertieSpecs(const Properties_t &_properties);

    /**
     * @brief Unordered map, and a lambda parsed as std::function. This is all done to eliminate the switch statement
     * Here we set also the values accordingly to SI @todo Set values properly
     * 
     */
    std::unordered_map<Type, std::function<void()>> type2func
    {
      {Type::C_101, [&](){ return this->_setPropertieSpecs({{Constants::C_101, Type::C_101}, {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::C_102, [&](){ return this->_setPropertieSpecs({{Constants::C_102, Type::C_102}, {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::C_103, [&](){ return this->_setPropertieSpecs({{Constants::C_103, Type::C_103}, {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::C_110, [&](){ return this->_setPropertieSpecs({{Constants::C_110, Type::C_110}, {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::C_122, [&](){ return this->_setPropertieSpecs({{Constants::C_122, Type::C_122}, {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }}
    };

    /**
     * @brief Set the Propertie Specs object
     * 
     * @param type Type of Copper
     * @return true If the specifications of propertie are successfully set
     * @return false  If the specifications of propertie failed to set
     */
    bool setPropertieSpecs(const Type &type);

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
#endif//___COPPER_H___