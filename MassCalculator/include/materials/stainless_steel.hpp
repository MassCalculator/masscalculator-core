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

    const std::string StainlessSteelLuaConfigPath{"../MassCalculator/resources/materials/stainless_steel_config.lua"};
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
       * @param density_ double Parameter to save specific density
       * @param gravity_ double Parameter to save specific gravity
       * @param melting_point_ double Parameter to save specific melting point
       * @param poissons_ratio_ double Parameter to save specific poissons ratio
       * @param thermal_conductivity_ double Parameter to save specific thermal conductivity
       * @param mod_of_elasticity_tension_ double Parameter to save specific modulus of elasticity tension
       * @param mod_of_elasticity_torsion_ double Parameter to save specific modulus of elasticity torsion
       * 
       */
      std::pair<std::string, Type> type_{Constants::UNSPECIFIED, StainlessSteel::Type::UNSPECIFIED};
      std::string color_{0};
      double density_{0};
      double gravity_{0};
      double melting_point_{0};
      double poissons_ratio_{0};
      double thermal_conductivity_{0};
      double mod_of_elasticity_tension_{0};
      double mod_of_elasticity_torsion_{0};
    }Properties_t;

    public:
    /**
     * @brief Enum that holds the StainlessSteel types Source: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
     * TODO: Maybe add the documentation also in a string, in setPropertySpecs so we can use in the app to show some information about the alloy selected
     */
    enum class Type : uint8_t
    {
      BEGIN = 0,
      /**
       * @brief This grade is commercially pure StainlessSteel. It is soft and ductile and has excellent workability, making it ideal for applications with difficult forming. 
       * It can be welded using any method, but it is non heat-treatable. It has an excellent resistance to corrosion and is commonly used in the chemical and 
       * food processing industries.
       * 
       */
      SS_301 = BEGIN,

      /**
       * @brief High mechanical strength and excellent machining capabilities are the highlights of this grade. It is often called – Free Machining Alloy (FMA), 
       * an excellent choice for projects done on automatic lathes. The high-speed machining of this grade will produce fine chips that are easily removed. 
       * Alloy 2011 is an excellent choice for production of complex and detailed parts.
       * 
       */
      SS_302,

      /**
       * @brief A copper based alloy with very high strength and excellent machining capabilities. This alloy is commonly used in many aerospace structural applications 
       * due to its resistance.
       * 
       */
      SS_303,

      /**
       * @brief One of the most commonly used high strength aluminum alloys. With its combination of high strength and excellent fatigue resistance, it is commonly used 
       * where a good strength-to-weight ratio is desired.  This grade can be machined to a high finish and it can be formed in the annealed condition with 
       * subsequent heat treating, if needed. The corrosion resistance of this grade is relatively low. When this is an issue, 2024 is commonly used in an 
       * anodized finish or in clad form (thin surface layer of high purity aluminum) known as Alclad.
       * 
       */
      SS_304,

      /**
       * @brief The most widely used of all aluminum alloys. A commercially pure aluminum with added manganese to increase its strength (20% stronger than the 1100 grade). 
       * It has excellent corrosion resistance, and workability. This grade can be deep drawn or spun, welded or brazed.
       * 
       */
      SS_305,

      /**
       * @brief This is the highest strength alloy of the more non heat-treatable grades. Its fatigue strength is higher than most other aluminum grades. 
       * Alloy 5052 has a good resistance to marine atmosphere and salt water corrosion, and excellent workability. It can be easily drawn or formed into intricate shapes.
       * 
       */
      SS_316,

      /**
       * @brief The most versatile of the heat-treatable aluminum alloys, while keeping most of the good qualities of aluminum. This grade has a great range of mechanical 
       * properties and corrosion resistance. It can be fabricated by most of the commonly used techniques and it has good workability in the annealed condition. It is 
       * welded by all methods and can be furnace brazed. As a result, it is used in a wide variety of products and applications where appearance and better corrosion 
       * resistance with good strength are required. The Tube and Angle shapes in this grade typically have rounded corners.
       * 
       */
      SS_321,

      /**
       * @brief Commonly known as an architectural alloy. It has reasonably high tensile properties, excellent finishing characteristics and a high degree of resistance 
       * to corrosion. Most often found in various interior and exterior architectural applications and trim. It is very well suited for anodizing applications. 
       * Commonly known as an architectural alloy. It has reasonably high tensile properties, excellent finishing characteristics and a high degree of resistance to corrosion. 
       * Most often found in various interior and exterior architectural applications and trim. It is very well suited for anodizing applications. 
       * The Tube and Angle shapes in this grade typically have square corners.The Tube and Angle shapes in this grade typically have square corners.
       * 
       */
      SS_409,

      /**
       * @brief This is one of the highest strength aluminum alloys available. It has an excellent strength-to weight ratio, and it is ideally used for highly stressed parts. 
       * This grade can be formed in the annealed condition and subsequently heat treated, if needed. It can also be spot or flash welded (arc and gas not recommended).
       * 
       */
      SS_410,

      SS_420,

      SS_430,

      SS_15_5,

      SS_17_4,

      UNSPECIFIED,

      END
    };

    friend std::ostream& operator<<(std::ostream& os, Type type)
    {
      switch(type)
      {
        case Type::SS_301: os << Constants::SS_301; break;
        case Type::SS_302: os << Constants::SS_302; break;
        case Type::SS_303: os << Constants::SS_303; break;
        case Type::SS_304: os << Constants::SS_304; break;
        case Type::SS_305: os << Constants::SS_305; break;
        case Type::SS_316: os << Constants::SS_316; break;
        case Type::SS_321: os << Constants::SS_321; break;
        case Type::SS_409: os << Constants::SS_409; break;
        case Type::SS_410: os << Constants::SS_410; break;
        case Type::SS_420: os << Constants::SS_420; break;
        case Type::SS_430: os << Constants::SS_430; break;
        case Type::SS_15_5: os << Constants::SS_15_5; break;
        case Type::SS_17_4: os << Constants::SS_17_4; break;
        case Type::UNSPECIFIED: os << Constants::UNSPECIFIED; break;
        default: os << "Name cannot be found";
      }
      return os;
    }

    /**
     * @brief Construct a new StainlessSteel object
     * 
     */
    StainlessSteel(void);

    /**
     * @brief Construct a new StainlessSteel object and specify the type
     * 
     */
    StainlessSteel(Type type);

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
     * @return const double Density of the material
     */
    double getSpecificDensity(void) const;

    /**
     * @brief Get the Specific Gravity object
     * 
     * @return const double Gravity of the material
     */
    double getSpecificGravity(void) const;

    /**
     * @brief Get the Specific Melting Point object
     * 
     * @return const double The specific melting point of StainlessSteel type
     */
    double getSpecificMeltingPoint(void) const;

    /**
     * @brief Get the Specific PoissonsRatio object
     * 
     * @return double The specific poissons ratio of StainlessSteel type
     */
    double getSpecificPoissonsRatio(void) const;

    /**
     * @brief Get the Specific Thermal Conductivity object
     * 
     * @return double The specific thermal conductivity of StainlessSteel type
     */
    double getSpecificThermalConductivity(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Tension object
     * 
     * @return const double The specific modulus of elasticity tension point of StainlessSteel type
     */
    double getSpecificModOfElasticityTension(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Torsion object
     * 
     * @return const double The specific modulus of elasticity torsion point of StainlessSteel type
     */
    double getSpecificModOfElasticityTorsion(void) const;

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

    private:
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

    /**
     * @brief Set the Propertie Specs object
     * 
     * @param type Type of StainlessSteel
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
}//end namespace MassCalculator::Materials
#endif//___STAINLESS_STEEL_H___