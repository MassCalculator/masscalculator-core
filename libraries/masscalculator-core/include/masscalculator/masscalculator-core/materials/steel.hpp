/**
 * @file steel.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Steel class that holds the parameters for all the types
 * @version 0.1
 * @date 2020-03-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___STEEL_H___
#define ___STEEL_H___
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
  namespace Constants::Steel
  {
    /** @brief String constant for S_1010 type */
    const std::string S_1010{"S_1010"};

    /** @brief String constant for S_1012 type */
    const std::string S_1012{"S_1012"};

    /** @brief String constant for S_1015 type */
    const std::string S_1015{"S_1015"};

    /** @brief String constant for S_1018 type */
    const std::string S_1018{"S_1018"};

    /** @brief String constant for S_1541 type */
    const std::string S_1541{"S_1541"};

    /** @brief String constant for S_4140 type */
    const std::string S_4140{"S_4140"};

    /** @brief String constant for S_A36 type */
    const std::string S_A36{"S_A36"};

    /** @brief String constant for UNSPECIFIED type */
    const std::string UNSPECIFIED{"UNSPECIFIED"};

    #ifdef DEBUG
      /**
       * @brief Lua config path when we are in debug mode, it will get the resources from source directory
       * 
       */
      const std::string LuaConfigPath{std::string(getDebugLuaRootPath()) + "/MassCalculator/resources/materials/steel_config.lua"};
    #else
      /**
       * @brief Lua config path when we are in release mode, it will get the resources from the install directory
       * 
       */
      const std::string LuaConfigPath{std::string(getenv("HOME")) + "/.MassCalculator/resources/materials/steel_config.lua"};
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
      Properties() : type_{std::make_pair(Constants::Steel::UNSPECIFIED, Steel::Type::UNSPECIFIED)},
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
    inline std::string _getClassName(Steel *) { return {Constants::Material::Steel}; };

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
      {Type::S_1010, [&](){ return this->_setPropertieSpecs({{Constants::Steel::S_1010, Type::S_1010}, {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::S_1012, [&](){ return this->_setPropertieSpecs({{Constants::Steel::S_1012, Type::S_1012}, {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::S_1015, [&](){ return this->_setPropertieSpecs({{Constants::Steel::S_1015, Type::S_1015}, {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::S_1018, [&](){ return this->_setPropertieSpecs({{Constants::Steel::S_1018, Type::S_1018}, {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::S_1541, [&](){ return this->_setPropertieSpecs({{Constants::Steel::S_1541, Type::S_1541}, {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::S_4140, [&](){ return this->_setPropertieSpecs({{Constants::Steel::S_4140, Type::S_4140}, {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }},
      {Type::S_A36,  [&](){ return this->_setPropertieSpecs({{Constants::Steel::S_A36,  Type::S_A36},  {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.9_Pa}, {3.8_Pa}}); }}
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