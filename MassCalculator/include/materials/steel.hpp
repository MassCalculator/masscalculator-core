#ifndef ___STEEL_H___
#define ___STEEL_H___
#include "material.hpp"

/**
 * @brief Default Materials namespace
 * 
 */
namespace MassCalculator::Materials
{
  namespace Constants
  {
    const std::string  S_1010{"S_1010"};
    const std::string  S_1012{"S_1012"};
    const std::string  S_1015{"S_1015"};
    const std::string  S_1018{"S_1018"};
    const std::string  S_1541{"S_1541"};
    const std::string  S_4140{"S_4140"};
    const std::string  S_A36{"S_A36"};

    #ifdef DEBUG
      const std::string SteelLuaConfigPath{std::string(getDebugLuaRootPath()) + "/MassCalculator/resources/materials/steel_config.lua"};
    #else
      const std::string SteelLuaConfigPath{std::string(getenv("HOME")) + "/.MassCalculator/resources/materials/steel_config.lua"};
    #endif
  }

  /**
   * @brief Class Steel, that holds all the nessesary information for Steel and it's types therefore we can use in the interface
   * 
   */
  class Steel : public Material<Steel>
  {
    public: enum class Type : uint8_t;

    /**
     * @brief Struct with material specific properties
     * TODO:Check if this can be moved to the base class
     */
    typedef struct Properties
    {

      /**
       * @brief Private members of Steel class. Values defaulted with brace-enclosed initializer list
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
      std::pair<std::string, Type> type_{Constants::UNSPECIFIED, Steel::Type::UNSPECIFIED};
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
     * @brief Enum that holds the Steel types
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
      S_1010 = BEGIN,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      S_1012,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      S_1015,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      S_1018,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      S_1541,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      S_4140,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      S_A36,

      /**
       * @brief Unspecified metal alloy
       * 
       */
      UNSPECIFIED,

      END
    };

    /**
     * @brief Construct a new Steel object
     * 
     */
    Steel(void);

    /**
     * @brief Construct a new Steel object and specify the type
     * 
     */
    Steel(const Type &type);

    /**
     * @brief Function to initialize the Lua object
     * 
     */
    bool initLuaScript(void);

    /**
     * @brief Set the Type object
     * 
     * @param type Type of the Steel
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
     * @return meters_per_second_squared_t double Gravity of the material
     */
    meters_per_second_squared_t getSpecificGravity(void) const;

    /**
     * @brief Get the Specific Melting Point object
     * 
     * @return kelvin_t The specific melting point of Steel type
     */
    kelvin_t getSpecificMeltingPoint(void) const;

    /**
     * @brief Get the Specific PoissonsRatio object
     * 
     * @return double The specific poissons ratio of Steel type
     */
    double getSpecificPoissonsRatio(void) const;

    /**
     * @brief Get the Specific Thermal Conductivity object
     * 
     * @return watt_t The specific thermal conductivity of Steel type
     */
    watt_t getSpecificThermalConductivity(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Tension object
     * 
     * @return pascal_t The specific modulus of elasticity tension point of Steel type
     */
    pascal_t getSpecificModOfElasticityTension(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Torsion object
     * 
     * @return pascal_t The specific modulus of elasticity torsion point of Steel type
     */
    pascal_t getSpecificModOfElasticityTorsion(void) const;

    /**
     * @brief Destroy the Steel object
     * 
     */
    ~Steel(void) = default;

    /**
     * @brief Shift operator overload for class Steel, this will print all the nessesery informations
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const Steel &obj);

    /**
     * @brief Shift operator overload for Types of Steel, this will print the name in string
     * 
     */
    friend std::ostream &operator << (std::ostream& os, const Type &type);

    /**
     * @brief Delete copy constructor
     * 
     */
    Steel(const Steel&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    Steel(Steel&&) = default;

    /**
     * @brief Delete assignment operator
     */
    Steel& operator=(const Steel&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    Steel& operator=(Steel&&) = default;

    private:
    /**
     * @brief Function to return the class name, not the pointer of the class, I am trying to keep away this function outside of the class
     * 
     * @return std::string Class name as a string
     */
    inline std::string _getClassName(Steel *) { return {"Steel"}; };

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
      {Type::S_1010, [&](){ return this->_setPropertieSpecs({{Constants::S_1010, Type::S_1010}, {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::S_1012, [&](){ return this->_setPropertieSpecs({{Constants::S_1012, Type::S_1012}, {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::S_1015, [&](){ return this->_setPropertieSpecs({{Constants::S_1015, Type::S_1015}, {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::S_1018, [&](){ return this->_setPropertieSpecs({{Constants::S_1018, Type::S_1018}, {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::S_1541, [&](){ return this->_setPropertieSpecs({{Constants::S_1541, Type::S_1541}, {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::S_4140, [&](){ return this->_setPropertieSpecs({{Constants::S_4140, Type::S_4140}, {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::S_A36,  [&](){ return this->_setPropertieSpecs({{Constants::S_A36,  Type::S_A36},  {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }}
    };

    /**
     * @brief Set the Propertie Specs object
     * 
     * @param type Type of Steel
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
#endif//___STEEL_H___