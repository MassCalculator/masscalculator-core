/**
 * @file brass.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Brass class that holds the parameters for all the types
 * @version 0.1
 * @date 2020-03-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___BRASS_H___
#define ___BRASS_H___
#include "material.hpp"

/**
 * @brief Default Materials namespace
 * 
 */
namespace MassCalculator::Materials
{
  /**
   * @brief String constants that are used through the code
   * 
   */
  namespace Constants::Brass
  {
    /** @brief String constant for B_240Low type */
    const std::string B_240Low{"B_240Low"};

    /** @brief String constant for B_260Cartridge type */
    const std::string B_260Cartridge{"B_260Cartridge"};

    /** @brief String constant for B_353Leaded type */
    const std::string B_353Leaded{"B_353Leaded"};

    /** @brief String constant for B_360 type */
    const std::string B_360{"B_360"};

    /** @brief String constant for B_365 type */
    const std::string B_365{"B_365"};

    /** @brief String constant for B_380 type */
    const std::string B_380{"B_380"};

    /** @brief String constant for B_385 type */
    const std::string B_385{"B_385"};

    /** @brief String constant for B_464 type */
    const std::string B_464{"B_464"};

    /** @brief String constant for UNSPECIFIED type */
    const std::string UNSPECIFIED{"UNSPECIFIED"};

    #ifdef DEBUG
      /**
       * @brief Lua config path when we are in debug mode, it will get the resources from source directory
       * 
       */
      const std::string LuaConfigPath{std::string(getDebugLuaRootPath()) + "/MassCalculator/resources/materials/brass_config.lua"};
    #else
      /**
       * @brief Lua config path when we are in release mode, it will get the resources from the install directory
       * 
       */
      const std::string LuaConfigPath{std::string(getenv("HOME")) + "/.MassCalculator/resources/materials/brass_config.lua"};
    #endif
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
     * 
     */
    typedef struct Properties
    {
      /**
       * @brief Type The parameter to save the specific type
       * 
       */
      std::pair<std::string, Type> type_;

      /**
       * @brief string Parameter to save specific color
       * 
       */
      std::string color_;

      /**
       * @brief kilograms_per_cubic_meter_t Parameter to save specific density
       * 
       */
      kilograms_per_cubic_meter_t density_;

      /**
       * @brief meters_per_second_squared_t Parameter to save specific gravity
       * 
       */
      meters_per_second_squared_t gravity_;

      /**
       * @brief kelvin_t Parameter to save specific melting point
       * 
       */
      kelvin_t melting_point_;

      /**
       * @brief double Parameter to save specific poissons ratio
       * 
       */
      double poissons_ratio_;

      /**
       * @brief watt_t Parameter to save specific thermal conductivity
       * 
       */
      watt_t thermal_conductivity_;

      /**
       * @brief pascal_t Parameter to save specific modulus of elasticity tension
       * 
       */
      pascal_t mod_of_elasticity_tension_;

      /**
       * @brief pascal_t Parameter to save specific modulus of elasticity torsion
       * 
       */
      pascal_t mod_of_elasticity_torsion_;

      /**
       * @brief Construct a new Properties object with all parameters initialized
       * 
       */
      Properties() : type_{std::make_pair(Constants::Brass::UNSPECIFIED, Brass::Type::UNSPECIFIED)},
                     color_{""},
                     density_{0_kg_per_cu_m},
                     gravity_{0_mps_sq},
                     melting_point_{0_K},
                     poissons_ratio_{0},
                     thermal_conductivity_{0_W},
                     mod_of_elasticity_tension_{0_Pa},
                     mod_of_elasticity_torsion_{0_Pa} { }

      /**
       * @brief Construct a new Properties object through initializer list
       * 
       */
      Properties(std::pair<std::string, Type> type,
                 std::string color,
                 kilograms_per_cubic_meter_t density,
                 meters_per_second_squared_t gravity,
                 kelvin_t melting_point,
                 double poissons_ratio,
                 watt_t thermal_conductivity,
                 pascal_t mod_of_elasticity_tension,
                 pascal_t mod_of_elasticity_torsion) : type_{type},
                                                       color_{color},
                                                       density_{density},
                                                       gravity_{gravity},
                                                       melting_point_{melting_point},
                                                       poissons_ratio_{poissons_ratio},
                                                       thermal_conductivity_{thermal_conductivity},
                                                       mod_of_elasticity_tension_{mod_of_elasticity_tension},
                                                       mod_of_elasticity_torsion_{mod_of_elasticity_torsion} { }
    }Properties_t;

    public:
    /**
     * @brief Enum that holds the Brass types
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
      B_240Low = BEGIN,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_260Cartridge,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_353Leaded,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_360,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_365,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_380,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      B_385,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
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
    Brass(const Type &type);

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
     * @return kelvin_t The specific melting point of Brass type
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
     * @return pascal_t The specific modulus of elasticity tension point of Brass type
     */
    pascal_t getSpecificModOfElasticityTension(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Torsion object
     * 
     * @return pascal_t The specific modulus of elasticity torsion point of Brass type
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
    friend std::ostream &operator << (std::ostream &os, const Type &type);

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
    inline std::string _getClassName(Brass *) { return {Constants::Material::Brass}; };

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
      {Type::B_240Low,       [&](){ return this->_setPropertieSpecs({{Constants::Brass::B_240Low,       Type::B_240Low},       {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_260Cartridge, [&](){ return this->_setPropertieSpecs({{Constants::Brass::B_260Cartridge, Type::B_260Cartridge}, {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_353Leaded,    [&](){ return this->_setPropertieSpecs({{Constants::Brass::B_353Leaded,    Type::B_353Leaded},    {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_360,          [&](){ return this->_setPropertieSpecs({{Constants::Brass::B_360,          Type::B_360},          {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_365,          [&](){ return this->_setPropertieSpecs({{Constants::Brass::B_365,          Type::B_365},          {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_380,          [&](){ return this->_setPropertieSpecs({{Constants::Brass::B_380,          Type::B_380},          {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_385,          [&](){ return this->_setPropertieSpecs({{Constants::Brass::B_385,          Type::B_385},          {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_464,          [&](){ return this->_setPropertieSpecs({{Constants::Brass::B_464,          Type::B_464},          {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }}
    };

    /**
     * @brief Set the Propertie Specs object
     * 
     * @param type Type of Brass
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
#endif//___BRASS_H___