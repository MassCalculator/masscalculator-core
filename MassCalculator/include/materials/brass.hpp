#ifndef ___BRASS_H___
#define ___BRASS_H___
#include "material.hpp"

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator
{
  namespace Constants
  {
    const std::string B_240Low{"B_240Low"};
    const std::string B_260Cartridge{"B_260Cartridge"};
    const std::string B_353Leaded{"B_353Leaded"};
    const std::string B_360{"B_360"};
    const std::string B_365{"B_365"};
    const std::string B_380{"B_380"};
    const std::string B_385{"B_385"};
    const std::string B_464{"B_464"};

    const std::string BrassLuaConfigPath{"/home/jimmyhalimi/ws/prototype_ws/MassCalculator/MassCalculator/resources/materials/brass_config.lua"};
  }

  /**
   * @brief Class Brass, that holds all the nessesary information for Brass and it's types therefore we can use in the interface
   * 
   */
  class Brass : public Material<Brass>
  {
    public: enum class Type : uint8_t;

    /**
     * @brief Struct with material specific properties
     * TODO:Check if this can be moved to the base class
     */
    typedef struct Properties
    {

      /**
       * @brief Private members of Brass class. Values defaulted with brace-enclosed initializer list
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
      std::pair<std::string, Type> type_{Constants::UNSPECIFIED, Brass::Type::UNSPECIFIED};
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
     * @brief Enum that holds the Brass types Source: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
     * TODO: Maybe add the documentation also in a string, in setPropertySpecs so we can use in the app to show some information about the alloy selected
     */
    enum class Type : uint8_t
    {
      BEGIN = 0,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      B_240Low = BEGIN,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      B_260Cartridge,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      B_353Leaded,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      B_360,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      B_365,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      B_380,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      B_385,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      B_464,

      /**
       * @brief Unspecified metal alloy
       * 
       */
      UNSPECIFIED,

      END
    };

    /**
     * @brief Construct a new Brass object
     * 
     */
    Brass(void);

    /**
     * @brief Construct a new Brass object and specify the type
     * 
     */
    Brass(Type type);

    /**
     * @brief Function to initialize the Lua object
     * 
     */
    bool initLuaScript(void);

    /**
     * @brief Set the Type object
     * 
     * @param type Type of the Brass
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
     * @return const kelvin_t The specific melting point of Brass type
     */
    kelvin_t getSpecificMeltingPoint(void) const;

    /**
     * @brief Get the Specific PoissonsRatio object
     * 
     * @return double The specific poissons ratio of Brass type
     */
    double getSpecificPoissonsRatio(void) const;

    /**
     * @brief Get the Specific Thermal Conductivity object
     * 
     * @return watt_t The specific thermal conductivity of Brass type
     */
    watt_t getSpecificThermalConductivity(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Tension object
     * 
     * @return const pascal_t The specific modulus of elasticity tension point of Brass type
     */
    pascal_t getSpecificModOfElasticityTension(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Torsion object
     * 
     * @return const pascal_t The specific modulus of elasticity torsion point of Brass type
     */
    pascal_t getSpecificModOfElasticityTorsion(void) const;

    /**
     * @brief Destroy the Brass object
     * 
     */
    ~Brass(void) = default;

    /**
     * @brief Shift operator overload for class Brass, this will print all the nessesery informations
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const Brass &obj);

    /**
     * @brief Shift operator overload for Types of Brass, this will print the name in string
     * 
     */
    friend std::ostream &operator << (std::ostream& os, Type type);

    /**
     * @brief Delete copy constructor
     * 
     */
    Brass(const Brass&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    Brass(Brass&&) = default;

    /**
     * @brief Delete assignment operator
     */
    Brass& operator=(const Brass&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    Brass& operator=(Brass&&) = default;

    private:
    /**
     * @brief Function to return the class name, not the pointer of the class, I am trying to keep away this function outside of the class
     * 
     * @return std::string Class name as a string
     */
    inline std::string _getClassName(Brass *) { return {"Brass"}; };

    /**
     * @brief Function to set the static propertie values
     * 
     * @param _properties Structure of the constant properties
     * @return true If properties are correctly set
     * @return false If properties have failed to set
     */
    bool _setPropertieSpecs(Properties_t _properties);

    /**
     * @brief Unordered map, and a lambda parsed as std::function. This is all done to eliminate the switch statement
     * Here we set also the values accordingly to SI @todo Set values properly
     * 
     */
    std::unordered_map<Type, std::function<void()>> type2func
    {
      {Type::B_240Low,       [&](){ return this->_setPropertieSpecs({{Constants::B_240Low,       Type::B_240Low},       {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_260Cartridge, [&](){ return this->_setPropertieSpecs({{Constants::B_260Cartridge, Type::B_260Cartridge}, {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_353Leaded,    [&](){ return this->_setPropertieSpecs({{Constants::B_353Leaded,    Type::B_353Leaded},    {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_360,          [&](){ return this->_setPropertieSpecs({{Constants::B_360,          Type::B_360},          {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_365,          [&](){ return this->_setPropertieSpecs({{Constants::B_365,          Type::B_365},          {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_380,          [&](){ return this->_setPropertieSpecs({{Constants::B_380,          Type::B_380},          {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_385,          [&](){ return this->_setPropertieSpecs({{Constants::B_385,          Type::B_385},          {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_464,          [&](){ return this->_setPropertieSpecs({{Constants::B_464,          Type::B_464},          {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }}
    };

    /**
     * @brief Set the Propertie Specs object
     * 
     * @param type Type of Brass
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
#endif