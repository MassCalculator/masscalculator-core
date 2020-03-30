/**
 * @file bronz.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Bronz class that holds the parameters for all the types
 * @version 0.1
 * @date 2020-03-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___BRONZ_H___
#define ___BRONZ_H___
#include "material.hpp"

/**
 * @brief Default Materials namespace
 * 
 */
namespace MassCalculator::Materials
{
  namespace Constants
  {
    const std::string B_18Al{"B_18Al"};
    const std::string B_21Al{"B_21Al"};
    const std::string B_314Commercial{"B_314Commercial"};
    const std::string B_485Naval{"B_485Naval"};
    const std::string B_510Phos{"B_510Phos"};
    const std::string B_524Phos{"B_524Phos"};
    const std::string B_532Phos{"B_532Phos"};
    const std::string B_534Phos{"B_534Phos"};
    const std::string B_544Phos{"B_544Phos"};
    const std::string B_613Al{"B_613Al"};
    const std::string B_614Al{"B_614Al"};
    const std::string B_623Al{"B_623Al"};
    const std::string B_624Al{"B_624Al"};
    const std::string B_625Al{"B_625Al"};
    const std::string B_630NiAl{"B_630NiAl"};
    const std::string B_642AlSi{"B_642AlSi"};
    const std::string B_932Bearing{"B_932Bearing"};
    const std::string B_954Al{"B_954Al"};
    const std::string B_OilLite{"B_OilLite"};

    #ifdef DEBUG
      const std::string BronzLuaConfigPath{std::string(getDebugLuaRootPath()) + "/MassCalculator/resources/materials/bronz_config.lua"};
    #else
      const std::string BronzLuaConfigPath{std::string(getenv("HOME")) + "/.MassCalculator/resources/materials/bronz_config.lua"};
    #endif
  }

  /**
   * @brief Class Bronz, that holds all the nessesary information for Bronz and it's types therefore we can use in the interface
   * 
   */
  class Bronz : public Material<Bronz>
  {
    public: enum class Type : uint8_t;

    /**
     * @brief Struct with material specific properties
     * TODO:Check if this can be moved to the base class
     */
    typedef struct Properties
    {

      /**
       * @brief Private members of Bronz class. Values defaulted with brace-enclosed initializer list
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
      std::pair<std::string, Type> type_{Constants::UNSPECIFIED, Bronz::Type::UNSPECIFIED};
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
     * @brief Enum that holds the Bronz types Source: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
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
      B_18Al = BEGIN,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_21Al,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_314Commercial,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_425Am,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_485Naval,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_510Phos,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_524Phos,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_532Phos,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_534Phos,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_544Phos,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_613Al,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_614Al,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_623Al,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_624Al,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_625Al,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_630NiAl,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_642AlSi,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_932Bearing,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_954Al,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       */
      B_OilLite,

      /**
       * @brief Unspecified metal alloy
       * 
       */
      UNSPECIFIED,

      END
    };

    /**
     * @brief Construct a new Bronz object
     * 
     */
    Bronz(void);

    /**
     * @brief Construct a new Bronz object and specify the type
     * 
     */
    Bronz(const Type &type);

    /**
     * @brief Function to initialize the Lua object
     * 
     */
    bool initLuaScript(void);

    /**
     * @brief Set the Type object
     * 
     * @param type Type of the Bronz
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
     * @return kelvin_t The specific melting point of Bronz type
     */
    kelvin_t getSpecificMeltingPoint(void) const;

    /**
     * @brief Get the Specific PoissonsRatio object
     * 
     * @return double The specific poissons ratio of Bronz type
     */
    double getSpecificPoissonsRatio(void) const;

    /**
     * @brief Get the Specific Thermal Conductivity object
     * 
     * @return watt_t The specific thermal conductivity of Bronz type
     */
    watt_t getSpecificThermalConductivity(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Tension object
     * 
     * @return pascal_t The specific modulus of elasticity tension point of Bronz type
     */
    pascal_t getSpecificModOfElasticityTension(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Torsion object
     * 
     * @return pascal_t The specific modulus of elasticity torsion point of Bronz type
     */
    pascal_t getSpecificModOfElasticityTorsion(void) const;

    /**
     * @brief Destroy the Bronz object
     * 
     */
    ~Bronz(void) = default;

    /**
     * @brief Shift operator overload for class Bronz, this will print all the nessesery informations
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const Bronz &obj);

    /**
     * @brief Shift operator overload for Types of Bronz, this will print the name in string
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const Type &type);

    /**
     * @brief Delete copy constructor
     * 
     */
    Bronz(const Bronz&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    Bronz(Bronz&&) = default;

    /**
     * @brief Delete assignment operator
     */
    Bronz& operator=(const Bronz&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    Bronz& operator=(Bronz&&) = default;

    private:
    /**
     * @brief Function to return the class name, not the pointer of the class, I am trying to keep away this function outside of the class
     * 
     * @return std::string Class name as a string
     */
    inline std::string _getClassName(Bronz *) { return {"Bronz"}; };

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
      {Type::B_18Al,          [&](){ return this->_setPropertieSpecs({{Constants::B_18Al,          Type::B_18Al},          {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_21Al,          [&](){ return this->_setPropertieSpecs({{Constants::B_21Al,          Type::B_21Al},          {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_314Commercial, [&](){ return this->_setPropertieSpecs({{Constants::B_314Commercial, Type::B_314Commercial}, {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_485Naval,      [&](){ return this->_setPropertieSpecs({{Constants::B_485Naval,      Type::B_485Naval},      {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_510Phos,       [&](){ return this->_setPropertieSpecs({{Constants::B_510Phos,       Type::B_510Phos},       {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_524Phos,       [&](){ return this->_setPropertieSpecs({{Constants::B_524Phos,       Type::B_524Phos},       {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_532Phos,       [&](){ return this->_setPropertieSpecs({{Constants::B_532Phos,       Type::B_532Phos},       {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_534Phos,       [&](){ return this->_setPropertieSpecs({{Constants::B_534Phos,       Type::B_534Phos},       {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_544Phos,       [&](){ return this->_setPropertieSpecs({{Constants::B_544Phos,       Type::B_544Phos},       {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_613Al,         [&](){ return this->_setPropertieSpecs({{Constants::B_613Al,         Type::B_613Al},         {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_614Al,         [&](){ return this->_setPropertieSpecs({{Constants::B_614Al,         Type::B_614Al},         {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_623Al,         [&](){ return this->_setPropertieSpecs({{Constants::B_623Al,         Type::B_623Al},         {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_624Al,         [&](){ return this->_setPropertieSpecs({{Constants::B_624Al,         Type::B_624Al},         {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_625Al,         [&](){ return this->_setPropertieSpecs({{Constants::B_625Al,         Type::B_625Al},         {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_630NiAl,       [&](){ return this->_setPropertieSpecs({{Constants::B_630NiAl,       Type::B_630NiAl},       {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_642AlSi,       [&](){ return this->_setPropertieSpecs({{Constants::B_642AlSi,       Type::B_642AlSi},       {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_932Bearing,    [&](){ return this->_setPropertieSpecs({{Constants::B_932Bearing,    Type::B_932Bearing},    {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_954Al,         [&](){ return this->_setPropertieSpecs({{Constants::B_954Al,         Type::B_954Al},         {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_OilLite,       [&](){ return this->_setPropertieSpecs({{Constants::B_OilLite,       Type::B_OilLite},       {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }}
    };

    /**
     * @brief Set the Propertie Specs object
     * 
     * @param type Type of Bronz
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
#endif//___BRONZ_H___