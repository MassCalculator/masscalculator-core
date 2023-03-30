/**
 * @file nickel.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Nickel class that holds the parameters for all the types
 * @version 0.1
 * @date 2020-03-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___NICKEL_H___
#define ___NICKEL_H___
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
  namespace Constants::Nickel
  {
    /** @brief String constant for N_201 type */
    const std::string N_201{"N_201"};

    /** @brief String constant for N_210 type */
    const std::string N_210{"N_210"};

    /** @brief String constant for N_220 type */
    const std::string N_220{"N_220"};

    /** @brief String constant for N_230 type */
    const std::string N_230{"N_230"};

    /** @brief String constant for N_400 type */
    const std::string N_400{"N_400"};

    /** @brief String constant for UNSPECIFIED type */
    const std::string UNSPECIFIED{"UNSPECIFIED"};

    #ifdef DEBUG
      /**
       * @brief Lua config path when we are in debug mode, it will get the resources from source directory
       * 
       */
      const std::string LuaConfigPath{std::string(getDebugLuaRootPath()) + "/MassCalculator/resources/materials/nickel_config.lua"};
    #else
      /**
       * @brief Lua config path when we are in release mode, it will get the resources from the install directory
       * 
       */
      const std::string LuaConfigPath{std::string(getenv("HOME")) + "/.MassCalculator/resources/materials/nickel_config.lua"};
    #endif
  }

  /**
   * @brief Class Nickel, that holds all the nessesary information for Nickel and it's types therefore we can use in the interface
   * 
   */
  class Nickel : public Material<Nickel>
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
      Properties() : type_{std::make_pair(Constants::Nickel::UNSPECIFIED, Nickel::Type::UNSPECIFIED)},
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
     * @brief Enum that holds the Nickel types
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
      N_201 = BEGIN,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      N_210,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      N_220,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      N_230,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * @todo: Add source
       * 
       */
      N_400,

      /**
       * @brief Unspecified metal alloy
       * 
       */
      UNSPECIFIED,

      END
    };

    /**
     * @brief Construct a new Nickel object
     * 
     */
    Nickel(void);

    /**
     * @brief Construct a new Nickel object and specify the type
     * 
     */
    Nickel(const Type &type);

    /**
     * @brief Function to initialize the Lua object
     * 
     */
    bool initLuaScript(void);

    /**
     * @brief Set the Type object
     * 
     * @param type Type of the Nickel
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
     * @brief Destroy the Nickel object
     * 
     */
    ~Nickel(void) = default;

    /**
     * @brief Shift operator overload for class Nickel, this will print all the nessesery informations
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const Nickel &obj);

    /**
     * @brief Shift operator overload for Types of Nickel, this will print the name in string
     * 
     */
    friend std::ostream &operator<<(std::ostream &os, const Type &type);

    /**
     * @brief Delete copy constructor
     * 
     */
    Nickel(const Nickel&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    Nickel(Nickel&&) = default;

    /**
     * @brief Delete assignment operator
     */
    Nickel& operator=(const Nickel&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    Nickel& operator=(Nickel&&) = default;

    private:
    /**
     * @brief Function to return the class name, not the pointer of the class, I am trying to keep away this function outside of the class
     * 
     * @return std::string Class name as a string
     */
    inline std::string _getClassName(Nickel *) { return {Constants::Material::Nickel}; };

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
      {Type::N_201, [&](){ return this->_setPropertieSpecs({{Constants::Nickel::N_201, Type::N_201}, {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::N_210, [&](){ return this->_setPropertieSpecs({{Constants::Nickel::N_210, Type::N_210}, {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::N_220, [&](){ return this->_setPropertieSpecs({{Constants::Nickel::N_220, Type::N_220}, {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::N_230, [&](){ return this->_setPropertieSpecs({{Constants::Nickel::N_230, Type::N_230}, {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::N_400, [&](){ return this->_setPropertieSpecs({{Constants::Nickel::N_400, Type::N_400}, {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }}
    };

    /**
     * @brief Set the Propertie Specs object
     * 
     * @param type Type of Nickel
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
#endif//___NICKEL_H___