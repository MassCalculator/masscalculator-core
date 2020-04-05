/**
 * @file stainless_steel.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief StainlessSteel class that holds the parameters for all the types
 * @version 0.1
 * @date 2020-03-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___STAINLESS_STEEL_H___
#define ___STAINLESS_STEEL_H___
#include "material.hpp"

/**
 * @brief Default Materials namespace
 * 
 */
namespace MassCalculator::Materials
{
  namespace Constants
  {
    const std::string  SS_301{"SS_301"};
    const std::string  SS_302{"SS_302"};
    const std::string  SS_303{"SS_303"};
    const std::string  SS_304{"SS_304"};
    const std::string  SS_305{"SS_305"};
    const std::string  SS_316{"SS_316"};
    const std::string  SS_321{"SS_321"};
    const std::string  SS_409{"SS_409"};
    const std::string  SS_410{"SS_410"};
    const std::string  SS_420{"SS_420"};
    const std::string  SS_430{"SS_430"};
    const std::string  SS_15_5{"SS_15_5"};
    const std::string  SS_17_4{"SS_17_4"};

    #ifdef DEBUG
      const std::string StainlessSteelLuaConfigPath{std::string(getDebugLuaRootPath()) + "/MassCalculator/resources/materials/stainless_steel_config.lua"};
    #else
      const std::string StainlessSteelLuaConfigPath{std::string(getenv("HOME")) + "/.MassCalculator/resources/materials/stainless_steel_config.lua"};
    #endif
  }

  /**
   * @brief Class StainlessSteel, that holds all the nessesary information for StainlessSteel and it's types therefore we can use in the interface
   * 
   */
  class StainlessSteel : public Material<StainlessSteel>
  {
    public: enum class Type : uint8_t;

    /**
     * @brief Struct with material specific properties
     * TODO:Check if this can be moved to the base class
     */
    typedef struct Properties
    {

      /**
       * @brief Private members of StainlessSteel class. Values defaulted with brace-enclosed initializer list
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
      std::pair<std::string, Type> type_{Constants::UNSPECIFIED, StainlessSteel::Type::UNSPECIFIED};
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
     * @brief Enum that holds the Plastic types
     * 
     */
    enum class Type : uint8_t
    {
      BEGIN = 0,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      SS_301 = BEGIN,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      SS_302,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      SS_303,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      SS_304,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      SS_305,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      SS_316,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      SS_321,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      SS_409,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      SS_410,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      SS_420,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      SS_430,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      SS_15_5,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      SS_17_4,

      /**
       * @brief Unspecified metal alloy
       * 
       */
      UNSPECIFIED,

      END
    };

    /**
     * @brief Construct a new StainlessSteel object
     * 
     */
    StainlessSteel(void);

    /**
     * @brief Construct a new StainlessSteel object and specify the type
     * 
     */
    StainlessSteel(const Type &type);

    /**
     * @brief Function to initialize the Lua object
     * 
     */
    bool initLuaScript(void);

    /**
     * @brief Set the Type object
     * 
     * @param type Type of the StainlessSteel
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
     * @return kelvin_t The specific melting point of Aluminium type
     */
    kelvin_t getSpecificMeltingPoint(void) const;

    /**
     * @brief Get the Specific PoissonsRatio object
     * 
     * @return double The specific poissons ratio of Aluminium type
     */
    double getSpecificPoissonsRatio(void) const;

    /**
     * @brief Get the Specific Thermal Conductivity object
     * 
     * @return watt_t The specific thermal conductivity of Aluminium type
     */
    watt_t getSpecificThermalConductivity(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Tension object
     * 
     * @return pascal_t The specific modulus of elasticity tension point of Aluminium type
     */
    pascal_t getSpecificModOfElasticityTension(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Torsion object
     * 
     * @return pascal_t The specific modulus of elasticity torsion point of Aluminium type
     */
    pascal_t getSpecificModOfElasticityTorsion(void) const;

    /**
     * @brief Destroy the StainlessSteel object
     * 
     */
    ~StainlessSteel(void) = default;

    /**
     * @brief Shift operator overload for class StainlessSteel, this will print all the nessesery informations
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const StainlessSteel &obj);

    /**
     * @brief Shift operator overload for Types of StainlessSteel, this will print the name in string
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const StainlessSteel::Type &type);

    /**
     * @brief Delete copy constructor
     * 
     */
    StainlessSteel(const StainlessSteel&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    StainlessSteel(StainlessSteel&&) = default;

    /**
     * @brief Delete assignment operator
     */
    StainlessSteel& operator=(const StainlessSteel&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    StainlessSteel& operator=(StainlessSteel&&) = default;

    private:
    /**
     * @brief Function to return the class name, not the pointer of the class, I am trying to keep away this function outside of the class
     * 
     * @return std::string Class name as a string
     */
    inline std::string _getClassName(StainlessSteel *) { return {"StainlessSteel"}; };

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
      {Type::SS_301,  [&](){ return this->_setPropertieSpecs({{Constants::SS_301,  Type::SS_301},  {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::SS_302,  [&](){ return this->_setPropertieSpecs({{Constants::SS_302,  Type::SS_302},  {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::SS_303,  [&](){ return this->_setPropertieSpecs({{Constants::SS_303,  Type::SS_303},  {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::SS_304,  [&](){ return this->_setPropertieSpecs({{Constants::SS_304,  Type::SS_304},  {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::SS_305,  [&](){ return this->_setPropertieSpecs({{Constants::SS_305,  Type::SS_305},  {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::SS_316,  [&](){ return this->_setPropertieSpecs({{Constants::SS_316,  Type::SS_316},  {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::SS_321,  [&](){ return this->_setPropertieSpecs({{Constants::SS_321,  Type::SS_321},  {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::SS_409,  [&](){ return this->_setPropertieSpecs({{Constants::SS_409,  Type::SS_409},  {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::SS_410,  [&](){ return this->_setPropertieSpecs({{Constants::SS_410,  Type::SS_410},  {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::SS_420,  [&](){ return this->_setPropertieSpecs({{Constants::SS_420,  Type::SS_420},  {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::SS_430,  [&](){ return this->_setPropertieSpecs({{Constants::SS_430,  Type::SS_430},  {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::SS_15_5, [&](){ return this->_setPropertieSpecs({{Constants::SS_15_5, Type::SS_15_5}, {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::SS_17_4, [&](){ return this->_setPropertieSpecs({{Constants::SS_17_4, Type::SS_17_4}, {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }}
    };

    /**
     * @brief Set the Propertie Specs object
     * 
     * @param type Type of StainlessSteel
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
}//end namespace MassCalculator::Materials
#endif//___STAINLESS_STEEL_H___