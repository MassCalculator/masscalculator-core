#ifndef ___STEEL_H___
#define ___STEEL_H___
#include "material.hpp"

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator
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

    const std::string SteelLuaConfigPath{"/home/jimmyhalimi/ws/prototype_ws/MassCalculator/MassCalculator/resources/materials/steel_config.lua"};
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
    struct Properties
    {

      /**
       * @brief Private members of Steel class. Values defaulted with brace-enclosed initializer list
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
      std::pair<std::string, Type> type_{Constants::UNSPECIFIED, Steel::Type::UNSPECIFIED};
      std::string color_{0};
      double density_{0};
      double gravity_{0};
      double melting_point_{0};
      double poissons_ratio_{0};
      double thermal_conductivity_{0};
      double mod_of_elasticity_tension_{0};
      double mod_of_elasticity_torsion_{0};
    }specific_properties_;

    public:
    /**
     * @brief Enum that holds the Steel types Source: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
     * TODO: Maybe add the documentation also in a string, in setPropertySpecs so we can use in the app to show some information about the alloy selected
     */
    enum class Type : uint8_t
    {
      BEGIN = 0,
      /**
       * @brief This grade is commercially pure Steel. It is soft and ductile and has excellent workability, making it ideal for applications with difficult forming. 
       * It can be welded using any method, but it is non heat-treatable. It has an excellent resistance to corrosion and is commonly used in the chemical and 
       * food processing industries.
       * 
       */
      S_1010 = BEGIN,

      /**
       * @brief High mechanical strength and excellent machining capabilities are the highlights of this grade. It is often called – Free Machining Alloy (FMA), 
       * an excellent choice for projects done on automatic lathes. The high-speed machining of this grade will produce fine chips that are easily removed. 
       * Alloy 2011 is an excellent choice for production of complex and detailed parts.
       * 
       */
      S_1012,

      /**
       * @brief A copper based alloy with very high strength and excellent machining capabilities. This alloy is commonly used in many aerospace structural applications 
       * due to its resistance.
       * 
       */
      S_1015,

      /**
       * @brief One of the most commonly used high strength aluminum alloys. With its combination of high strength and excellent fatigue resistance, it is commonly used 
       * where a good strength-to-weight ratio is desired.  This grade can be machined to a high finish and it can be formed in the annealed condition with 
       * subsequent heat treating, if needed. The corrosion resistance of this grade is relatively low. When this is an issue, 2024 is commonly used in an 
       * anodized finish or in clad form (thin surface layer of high purity aluminum) known as Alclad.
       * 
       */
      S_1018,

      /**
       * @brief The most widely used of all aluminum alloys. A commercially pure aluminum with added manganese to increase its strength (20% stronger than the 1100 grade). 
       * It has excellent corrosion resistance, and workability. This grade can be deep drawn or spun, welded or brazed.
       * 
       */
      S_1541,

      /**
       * @brief This is the highest strength alloy of the more non heat-treatable grades. Its fatigue strength is higher than most other aluminum grades. 
       * Alloy 5052 has a good resistance to marine atmosphere and salt water corrosion, and excellent workability. It can be easily drawn or formed into intricate shapes.
       * 
       */
      S_4140,

      /**
       * @brief The most versatile of the heat-treatable aluminum alloys, while keeping most of the good qualities of aluminum. This grade has a great range of mechanical 
       * properties and corrosion resistance. It can be fabricated by most of the commonly used techniques and it has good workability in the annealed condition. It is 
       * welded by all methods and can be furnace brazed. As a result, it is used in a wide variety of products and applications where appearance and better corrosion 
       * resistance with good strength are required. The Tube and Angle shapes in this grade typically have rounded corners.
       * 
       */
      S_A36,

      UNSPECIFIED,

      END
    };

    friend std::ostream& operator<<(std::ostream& os, Type type)
    {
      switch(type)
      {
        case Type::S_1010: os << Constants::S_1010; break;
        case Type::S_1012: os << Constants::S_1012; break;
        case Type::S_1015: os << Constants::S_1015; break;
        case Type::S_1018: os << Constants::S_1018; break;
        case Type::S_1541: os << Constants::S_1541; break;
        case Type::S_4140: os << Constants::S_4140; break;
        case Type::S_A36: os << Constants::S_A36; break;
        case Type::UNSPECIFIED: os << Constants::UNSPECIFIED; break;
        default: os << "Name cannot be found";
      }
      return os;
    }

    /**
     * @brief Construct a new Steel object
     * 
     */
    Steel(void);

    /**
     * @brief Construct a new Steel object and specify the type
     * 
     */
    Steel(Type type);

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
     * @return const double The specific melting point of Steel type
     */
    double getSpecificMeltingPoint(void) const;

    /**
     * @brief Get the Specific PoissonsRatio object
     * 
     * @return double The specific poissons ratio of Steel type
     */
    double getSpecificPoissonsRatio(void) const;

    /**
     * @brief Get the Specific Thermal Conductivity object
     * 
     * @return double The specific thermal conductivity of Steel type
     */
    double getSpecificThermalConductivity(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Tension object
     * 
     * @return const double The specific modulus of elasticity tension point of Steel type
     */
    double getSpecificModOfElasticityTension(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Torsion object
     * 
     * @return const double The specific modulus of elasticity torsion point of Steel type
     */
    double getSpecificModOfElasticityTorsion(void) const;

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

    private:
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

    /**
     * @brief Set the Propertie Specs object
     * 
     * @param type Type of Steel
     * @return true If the specifications of propertie are successfully set
     * @return false  If the specifications of propertie failed to set
     */
    bool setPropertieSpecs(Type type);

    /**
     * @brief Lua Handler object to get the config for metals from LuaScript is necessary
     * 
     */
    LuaScriptHandler lua_state_;
    
  };
}//end namespace MassCalculator
#endif