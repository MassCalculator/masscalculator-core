/**
 * @file aluminium.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Aluminium class that holds the parameters for all the types
 * @version 0.1
 * @date 2020-03-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___ALUMINIUM_H___
#define ___ALUMINIUM_H___
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
  namespace Constants::Aluminium
  {
    /** @brief String constant for A_1100 type */
    const std::string A_1100{"A_1100"};

    /** @brief String constant for A_2011 type */
    const std::string A_2011{"A_2011"};

    /** @brief String constant for A_2014 type */
    const std::string A_2014{"A_2014"};

    /** @brief String constant for A_2024 type */
    const std::string A_2024{"A_2024"};

    /** @brief String constant for A_3003 type */
    const std::string A_3003{"A_3003"};

    /** @brief String constant for A_5052 type */
    const std::string A_5052{"A_5052"};

    /** @brief String constant for A_6061 type */
    const std::string A_6061{"A_6061"};

    /** @brief String constant for A_6063 type */
    const std::string A_6063{"A_6063"};

    /** @brief String constant for A_7075 type */
    const std::string A_7075{"A_7075"};

    /** @brief String constant for UNSPECIFIED type */
    const std::string UNSPECIFIED{"UNSPECIFIED"};

    #ifdef DEBUG
      /**
       * @brief Lua config path when we are in debug mode, it will get the resources from source directory
       * 
       */
      const std::string LuaConfigPath{std::string(getDebugLuaRootPath()) + "/MassCalculator/resources/materials/aluminium_config.lua"};
    #else
      /**
       * @brief Lua config path when we are in release mode, it will get the resources from the install directory
       * 
       */
      const std::string LuaConfigPath{std::string(getenv("HOME")) + "/.MassCalculator/resources/materials/aluminium_config.lua"};
    #endif
  }

  /**
   * @brief Class Aluminium, that holds all the nessesary information for Aluminium and it's types therefore we can use in the interface
   * 
   */
  class Aluminium : public Material<Aluminium>
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
      Properties() : type_{std::make_pair(Constants::Aluminium::UNSPECIFIED, Aluminium::Type::UNSPECIFIED)},
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
     * @brief Enum that holds the Aluminium types
     * TODO: Maybe add the documentation also in a string, in setPropertySpecs so we can use in the app to show some information about the alloy selected
     */
    enum class Type : uint8_t
    {
      BEGIN = 0,
      
      /**
       * @brief This grade is commercially pure aluminum. It is soft and ductile and has excellent workability, making it ideal for applications with difficult forming. 
       * It can be welded using any method, but it is non heat-treatable. It has an excellent resistance to corrosion and is commonly used in the chemical and 
       * food processing industries.
       * Source [Last visit: 2020-03-28]: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/ 
       * 
       */
      A_1100 = BEGIN,

      /**
       * @brief High mechanical strength and excellent machining capabilities are the highlights of this grade. It is often called – Free Machining Alloy (FMA), 
       * an excellent choice for projects done on automatic lathes. The high-speed machining of this grade will produce fine chips that are easily removed. 
       * Alloy 2011 is an excellent choice for production of complex and detailed parts.
       * Source [Last visit: 2020-03-28]: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
       * 
       */
      A_2011,

      /**
       * @brief A copper based alloy with very high strength and excellent machining capabilities. This alloy is commonly used in many aerospace structural applications 
       * due to its resistance.
       * Source [Last visit: 2020-03-28]: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
       * 
       */
      A_2014,

      /**
       * @brief One of the most commonly used high strength aluminum alloys. With its combination of high strength and excellent fatigue resistance, it is commonly used 
       * where a good strength-to-weight ratio is desired.  This grade can be machined to a high finish and it can be formed in the annealed condition with 
       * subsequent heat treating, if needed. The corrosion resistance of this grade is relatively low. When this is an issue, 2024 is commonly used in an 
       * anodized finish or in clad form (thin surface layer of high purity aluminum) known as Alclad.
       * Source [Last visit: 2020-03-28]: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
       * 
       */
      A_2024,

      /**
       * @brief The most widely used of all aluminum alloys. A commercially pure aluminum with added manganese to increase its strength (20% stronger than the 1100 grade). 
       * It has excellent corrosion resistance, and workability. This grade can be deep drawn or spun, welded or brazed.
       * Source [Last visit: 2020-03-28]: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
       * 
       */
      A_3003,

      /**
       * @brief This is the highest strength alloy of the more non heat-treatable grades. Its fatigue strength is higher than most other aluminum grades. 
       * Alloy 5052 has a good resistance to marine atmosphere and salt water corrosion, and excellent workability. It can be easily drawn or formed into intricate shapes.
       * Source [Last visit: 2020-03-28]: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
       * 
       */
      A_5052,

      /**
       * @brief The most versatile of the heat-treatable aluminum alloys, while keeping most of the good qualities of aluminum. This grade has a great range of mechanical 
       * properties and corrosion resistance. It can be fabricated by most of the commonly used techniques and it has good workability in the annealed condition. It is 
       * welded by all methods and can be furnace brazed. As a result, it is used in a wide variety of products and applications where appearance and better corrosion 
       * resistance with good strength are required. The Tube and Angle shapes in this grade typically have rounded corners.
       * Source [Last visit: 2020-03-28]: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
       * 
       */
      A_6061,

      /**
       * @brief Commonly known as an architectural alloy. It has reasonably high tensile properties, excellent finishing characteristics and a high degree of resistance 
       * to corrosion. Most often found in various interior and exterior architectural applications and trim. It is very well suited for anodizing applications. 
       * Commonly known as an architectural alloy. It has reasonably high tensile properties, excellent finishing characteristics and a high degree of resistance to corrosion. 
       * Most often found in various interior and exterior architectural applications and trim. It is very well suited for anodizing applications. 
       * The Tube and Angle shapes in this grade typically have square corners.The Tube and Angle shapes in this grade typically have square corners.
       * Source [Last visit: 2020-03-28]: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
       * 
       */
      A_6063,

      /**
       * @brief This is one of the highest strength aluminum alloys available. It has an excellent strength-to weight ratio, and it is ideally used for highly stressed parts. 
       * This grade can be formed in the annealed condition and subsequently heat treated, if needed. It can also be spot or flash welded (arc and gas not recommended).
       * Source [Last visit: 2020-03-28]: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
       * 
       */
      A_7075,

      /**
       * @brief Unspecified metal alloy
       * 
       */
      UNSPECIFIED,

      END
    };

    /**
     * @brief Construct a new Aluminium object
     * 
     */
    Aluminium(void);

    /**
     * @brief Construct a new Aluminium object and specify the type
     * 
     */
    Aluminium(const Type &type);

    /**
     * @brief Function to initialize the Lua object
     * 
     */
    bool initLuaScript(void);

    /**
     * @brief Set the Type object
     * 
     * @param type Type of the Aluminium
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
     * @brief Destroy the Aluminium object
     * 
     */
    ~Aluminium(void) = default;

    /**
     * @brief Shift operator overload for class Aluminium, this will print all the nessesery informations
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const Aluminium &obj);

    /**
     * @brief Shift operator overload for Types of Aluminium, this will print the name in string
     * 
     */
    friend std::ostream &operator<<(std::ostream &os, const Type &type);

    /**
     * @brief Delete copy constructor
     * 
     */
    Aluminium(const Aluminium&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    Aluminium(Aluminium&&) = default;

    /**
     * @brief Delete assignment operator
     */
    Aluminium& operator=(const Aluminium&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    Aluminium& operator=(Aluminium&&) = default;

    private:
    /**
     * @brief Function to return the class name, not the pointer of the class, I am trying to keep away this function outside of the class
     * 
     * @return std::string Class name as a string
     */
    inline std::string _getClassName(Aluminium *) { return {Constants::Material::Aluminium}; };

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
      {Type::A_1100, [&](){ return this->_setPropertieSpecs({{Constants::Aluminium::A_1100, Type::A_1100}, {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::A_2011, [&](){ return this->_setPropertieSpecs({{Constants::Aluminium::A_2011, Type::A_2011}, {Constants::Color::Metallic}, {2.82_kg_per_cu_m}, {2.83_mps_sq}, {1000.00_K}, {0.33}, {990.0_W}, {10.2_Pa}, {3.85_Pa}}); }},
      {Type::A_2014, [&](){ return this->_setPropertieSpecs({{Constants::Aluminium::A_2014, Type::A_2014}, {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::A_2024, [&](){ return this->_setPropertieSpecs({{Constants::Aluminium::A_2024, Type::A_2024}, {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::A_3003, [&](){ return this->_setPropertieSpecs({{Constants::Aluminium::A_3003, Type::A_3003}, {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::A_5052, [&](){ return this->_setPropertieSpecs({{Constants::Aluminium::A_5052, Type::A_5052}, {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::A_6061, [&](){ return this->_setPropertieSpecs({{Constants::Aluminium::A_6061, Type::A_6061}, {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::A_6063, [&](){ return this->_setPropertieSpecs({{Constants::Aluminium::A_6063, Type::A_6063}, {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }},
      {Type::A_7075, [&](){ return this->_setPropertieSpecs({{Constants::Aluminium::A_7075, Type::A_7075}, {Constants::Color::Metallic}, {2.71_kg_per_cu_m}, {2.83_mps_sq}, {537.778_K}, {0.33}, {990.0_W}, {9.90_Pa}, {3.80_Pa}}); }}
    };

    /**
     * @brief Set the Propertie Specs object
     * 
     * @param type Type of Aluminium
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
#endif//___ALUMINIUM_H___