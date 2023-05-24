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
  /**
   * @brief String constants that are used through the code
   * 
   */
  namespace Constants::Bronz
  {
    /** @brief String constant for B_18Al type */
    const std::string B_18Al{"B_18Al"};

    /** @brief String constant for B_21Al type */
    const std::string B_21Al{"B_21Al"};

    /** @brief String constant for B_314Commercial type */
    const std::string B_314Commercial{"B_314Commercial"};

    /** @brief String constant for B_485Naval type */
    const std::string B_485Naval{"B_485Naval"};

    /** @brief String constant for B_510Phos type */
    const std::string B_510Phos{"B_510Phos"};

    /** @brief String constant for B_524Phos type */
    const std::string B_524Phos{"B_524Phos"};

    /** @brief String constant for B_532Phos type */
    const std::string B_532Phos{"B_532Phos"};

    /** @brief String constant for B_534Phos type */
    const std::string B_534Phos{"B_534Phos"};

    /** @brief String constant for B_544Phos type */
    const std::string B_544Phos{"B_544Phos"};

    /** @brief String constant for B_613Al type */
    const std::string B_613Al{"B_613Al"};

    /** @brief String constant for B_614Al type */
    const std::string B_614Al{"B_614Al"};

    /** @brief String constant for B_623Al type */
    const std::string B_623Al{"B_623Al"};

    /** @brief String constant for B_624Al type */
    const std::string B_624Al{"B_624Al"};

    /** @brief String constant for B_625Al type */
    const std::string B_625Al{"B_625Al"};

    /** @brief String constant for B_630NiAl type */
    const std::string B_630NiAl{"B_630NiAl"};

    /** @brief String constant for B_642AlSi type */
    const std::string B_642AlSi{"B_642AlSi"};

    /** @brief String constant for B_932Bearing type */
    const std::string B_932Bearing{"B_932Bearing"};

    /** @brief String constant for B_954Al type */
    const std::string B_954Al{"B_954Al"};

    /** @brief String constant for B_OilLite type */
    const std::string B_OilLite{"B_OilLite"};

    /** @brief String constant for UNSPECIFIED type */
    const std::string UNSPECIFIED{"UNSPECIFIED"};

    #ifdef DEBUG
      /**
       * @brief Lua config path when we are in debug mode, it will get the resources from source directory
       * 
       */
      const std::string LuaConfigPath{std::string(getDebugLuaRootPath()) + "/MassCalculator/resources/materials/bronz_config.lua"};
    #else
      /**
       * @brief Lua config path when we are in release mode, it will get the resources from the install directory
       * 
       */
      const std::string LuaConfigPath{std::string(getenv("HOME")) + "/.MassCalculator/resources/materials/bronz_config.lua"};
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
      Properties() : type_{std::make_pair(Constants::Bronz::UNSPECIFIED, Bronz::Type::UNSPECIFIED)},
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
     * @brief Enum that holds the Bronz types
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
    inline std::string _getClassName(Bronz *) { return {Constants::Material::Bronz}; };

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
      {Type::B_18Al,          [&](){ return this->_setPropertieSpecs({{Constants::Bronz::B_18Al,          Type::B_18Al},          {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_21Al,          [&](){ return this->_setPropertieSpecs({{Constants::Bronz::B_21Al,          Type::B_21Al},          {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_314Commercial, [&](){ return this->_setPropertieSpecs({{Constants::Bronz::B_314Commercial, Type::B_314Commercial}, {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_485Naval,      [&](){ return this->_setPropertieSpecs({{Constants::Bronz::B_485Naval,      Type::B_485Naval},      {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_510Phos,       [&](){ return this->_setPropertieSpecs({{Constants::Bronz::B_510Phos,       Type::B_510Phos},       {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_524Phos,       [&](){ return this->_setPropertieSpecs({{Constants::Bronz::B_524Phos,       Type::B_524Phos},       {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_532Phos,       [&](){ return this->_setPropertieSpecs({{Constants::Bronz::B_532Phos,       Type::B_532Phos},       {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_534Phos,       [&](){ return this->_setPropertieSpecs({{Constants::Bronz::B_534Phos,       Type::B_534Phos},       {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_544Phos,       [&](){ return this->_setPropertieSpecs({{Constants::Bronz::B_544Phos,       Type::B_544Phos},       {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_613Al,         [&](){ return this->_setPropertieSpecs({{Constants::Bronz::B_613Al,         Type::B_613Al},         {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_614Al,         [&](){ return this->_setPropertieSpecs({{Constants::Bronz::B_614Al,         Type::B_614Al},         {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_623Al,         [&](){ return this->_setPropertieSpecs({{Constants::Bronz::B_623Al,         Type::B_623Al},         {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_624Al,         [&](){ return this->_setPropertieSpecs({{Constants::Bronz::B_624Al,         Type::B_624Al},         {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_625Al,         [&](){ return this->_setPropertieSpecs({{Constants::Bronz::B_625Al,         Type::B_625Al},         {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_630NiAl,       [&](){ return this->_setPropertieSpecs({{Constants::Bronz::B_630NiAl,       Type::B_630NiAl},       {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_642AlSi,       [&](){ return this->_setPropertieSpecs({{Constants::Bronz::B_642AlSi,       Type::B_642AlSi},       {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_932Bearing,    [&](){ return this->_setPropertieSpecs({{Constants::Bronz::B_932Bearing,    Type::B_932Bearing},    {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_954Al,         [&](){ return this->_setPropertieSpecs({{Constants::Bronz::B_954Al,         Type::B_954Al},         {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::B_OilLite,       [&](){ return this->_setPropertieSpecs({{Constants::Bronz::B_OilLite,       Type::B_OilLite},       {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }}
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