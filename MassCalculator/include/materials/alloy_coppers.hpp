/**
 * @file alloy_coppers.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief AlloyCoppers class that holds the parameters for all the types
 * @version 0.1
 * @date 2020-03-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___ALLOY_COPPERS_H___
#define ___ALLOY_COPPERS_H___
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
    const std::string AC_145Tellvirum{"AC_145Tellvirum"};
    const std::string AC_194Iron{"AC_194Iron"};
    const std::string AC_195Iron{"AC_195Iron"};
    const std::string AC_172Beryllium{"AC_172Beryllium"};
    const std::string AC_182Class2{"AC_182Class2"};
    const std::string AC_655Silicon{"AC_655Silicon"};
    const std::string AC_706Nickel{"AC_706Nickel"};
    const std::string AC_715NickelSilver{"AC_715NickelSilver"};
    const std::string AC_725NickelSilver{"AC_725NickelSilver"};
    const std::string AC_735NickelSilver{"AC_735NickelSilver"};
    const std::string AC_752NickelSilver{"AC_752NickelSilver"};
    const std::string AC_762NickelSilver{"AC_762NickelSilver"};
    const std::string AC_770NickelSilver{"AC_770NickelSilver"};
    const std::string AC_1751Class3{"AC_1751Class3"};
    const std::string AC_1758Nickel{"AC_1758Nickel"};
    const std::string AC_MoldmaxBeCu{"AC_MoldmaxBeCu"};
    const std::string AC_ProthermBeCu{"AC_ProthermBeCu"};
    // @@TODO: Check this, for the paths after install the library
    #ifdef DEBUG
      const std::string AlloyCoppersLuaConfigPath{"/home/jimmyhalimi/ws/prototype_ws/MassCalculator/MassCalculator/resources/materials/alloy_coppers_config.lua"};
    #else
      // const std::string home_path_ = getenv("HOME");
      // const std::string AlloyCoppersLuaConfigPath{home_path_ + "/.MassCalculatorResources/materials/alloy_coppers_config.lua"};
      const std::string AlloyCoppersLuaConfigPath{"/home/jimmyhalimi/ws/prototype_ws/MassCalculator/MassCalculator/resources/materials/alloy_coppers_config.lua"};
    #endif
  }

  /**
   * @brief Class AlloyCoppers, that holds all the nessesary information for AlloyCoppers and it's types therefore we can use in the interface
   * 
   */
  class AlloyCoppers : public Material<AlloyCoppers>
  {
    public: enum class Type : uint8_t;

    /**
     * @brief Struct with material specific properties
     * @TODO:Check if this can be moved to the base class, the problem is only in the std::pair<T, Type>, Type cannot be deduced from base to derived
     */
    typedef struct Properties
    {

      /**
       * @brief Private members of AlloyCoppers class. Values defaulted with brace-enclosed initializer list
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
      std::pair<std::string, Type> type_{{Constants::UNSPECIFIED}, {AlloyCoppers::Type::UNSPECIFIED}};
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
     * @brief Enum that holds the AlloyCoppers types
     * 
     */
    enum class Type : uint8_t
    {
      BEGIN = 0,

      /**
       * @brief Tellurium copper also referred to as Alloy 145, Alloy C15400, 145 half-hard tellurium, and TeCu—is a copper-based alloy that contains varying amounts of tellurium and phosphorus. 
       * The tellurium content typically ranges between 0.4–0.7%, while the phosphorus content ranges between 0.004–0.12%.
       * Tellurium copper demonstrates good electrical and thermal conductivity, good formability and high machinability. These properties make it suitable for a wide range of industrial applications.
       * @todo: Add source
       * 
       */
      AC_145Tellvirum = BEGIN,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      AC_194Iron,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      AC_195Iron,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      AC_172Beryllium,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      AC_182Class2,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      AC_655Silicon,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      AC_706Nickel,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      AC_715NickelSilver,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      AC_725NickelSilver,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      AC_735NickelSilver,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      AC_752NickelSilver,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      AC_762NickelSilver,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      AC_770NickelSilver,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      AC_1751Class3,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      AC_1758Nickel,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      AC_MoldmaxBeCu,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      AC_ProthermBeCu,

      /**
       * @brief Unspecified metal alloy
       * 
       */
      UNSPECIFIED,

      END
    };

    /**
     * @brief Construct a new AlloyCoppers object
     * 
     */
    AlloyCoppers(void);

    /**
     * @brief Construct a new AlloyCoppers object and specify the type
     * 
     */
    AlloyCoppers(const Type &type);

    /**
     * @brief Function to initialize the Lua object
     * 
     */
    bool initLuaScript(void);

    /**
     * @brief Set the Type object
     * 
     * @param type Type of the AlloyCoppers
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
     * @return kelvin_t The specific melting point of AlloyCoppers type
     */
    kelvin_t getSpecificMeltingPoint(void) const;

    /**
     * @brief Get the Specific PoissonsRatio object
     * 
     * @return double The specific poissons ratio of AlloyCoppers type
     */
    double getSpecificPoissonsRatio(void) const;

    /**
     * @brief Get the Specific Thermal Conductivity object
     * 
     * @return watt_t The specific thermal conductivity of AlloyCoppers type
     */
    watt_t getSpecificThermalConductivity(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Tension object
     * 
     * @return pascal_t The specific modulus of elasticity tension point of AlloyCoppers type
     */
    pascal_t getSpecificModOfElasticityTension(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Torsion object
     * 
     * @return pascal_t The specific modulus of elasticity torsion point of AlloyCoppers type
     */
    pascal_t getSpecificModOfElasticityTorsion(void) const;

    /**
     * @brief Destroy the AlloyCoppers object
     * 
     */
    ~AlloyCoppers(void) = default;

    /**
     * @brief Shift operator overload for class AlloyCoppers, this will print all the nessesery informations
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const AlloyCoppers &obj);

    /**
     * @brief Shift operator overload for Types of AlloyCoppers, this will print the name in string
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const Type &type);

    /**
     * @brief Delete copy constructor
     * 
     */
    AlloyCoppers(const AlloyCoppers&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    AlloyCoppers(AlloyCoppers&&) = default;

    /**
     * @brief Delete assignment operator
     */
    AlloyCoppers& operator=(const AlloyCoppers&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    AlloyCoppers& operator=(AlloyCoppers&&) = default;

    private:
    /**
     * @brief Function to return the class name, not the pointer of the class, I am trying to keep away this function outside of the class
     * 
     * @return std::string Class name as a string
     */
    inline std::string _getClassName(AlloyCoppers *) { return {"AlloyCoppers"}; };

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
      {Type::AC_145Tellvirum,    [&](){ return this->_setPropertieSpecs({{Constants::AC_145Tellvirum,    Type::AC_145Tellvirum},    {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::AC_194Iron,         [&](){ return this->_setPropertieSpecs({{Constants::AC_194Iron,         Type::AC_194Iron},         {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::AC_195Iron,         [&](){ return this->_setPropertieSpecs({{Constants::AC_195Iron,         Type::AC_195Iron},         {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::AC_182Class2,       [&](){ return this->_setPropertieSpecs({{Constants::AC_182Class2,       Type::AC_182Class2},       {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::AC_655Silicon,      [&](){ return this->_setPropertieSpecs({{Constants::AC_655Silicon,      Type::AC_655Silicon},      {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::AC_706Nickel,       [&](){ return this->_setPropertieSpecs({{Constants::AC_706Nickel,       Type::AC_706Nickel},       {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::AC_715NickelSilver, [&](){ return this->_setPropertieSpecs({{Constants::AC_715NickelSilver, Type::AC_715NickelSilver}, {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::AC_725NickelSilver, [&](){ return this->_setPropertieSpecs({{Constants::AC_725NickelSilver, Type::AC_725NickelSilver}, {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::AC_735NickelSilver, [&](){ return this->_setPropertieSpecs({{Constants::AC_735NickelSilver, Type::AC_735NickelSilver}, {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::AC_752NickelSilver, [&](){ return this->_setPropertieSpecs({{Constants::AC_752NickelSilver, Type::AC_752NickelSilver}, {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::AC_762NickelSilver, [&](){ return this->_setPropertieSpecs({{Constants::AC_762NickelSilver, Type::AC_762NickelSilver}, {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::AC_770NickelSilver, [&](){ return this->_setPropertieSpecs({{Constants::AC_770NickelSilver, Type::AC_770NickelSilver}, {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::AC_1751Class3,      [&](){ return this->_setPropertieSpecs({{Constants::AC_1751Class3,      Type::AC_1751Class3},      {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::AC_1758Nickel,      [&](){ return this->_setPropertieSpecs({{Constants::AC_1758Nickel,      Type::AC_1758Nickel},      {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::AC_MoldmaxBeCu,     [&](){ return this->_setPropertieSpecs({{Constants::AC_MoldmaxBeCu,     Type::AC_MoldmaxBeCu},     {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::AC_ProthermBeCu,    [&](){ return this->_setPropertieSpecs({{Constants::AC_ProthermBeCu,    Type::AC_ProthermBeCu},    {Constants::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, (0.33), {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }}
    };

    /**
     * @brief Set the Propertie Specs object
     * 
     * @param type Type of AlloyCoppers
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
#endif//___ALLOY_COPPERS_H___