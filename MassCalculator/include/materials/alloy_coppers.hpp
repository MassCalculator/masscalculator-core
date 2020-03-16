#ifndef ___ALLOY_COPPERS_H___
#define ___ALLOY_COPPERS_H___
#include "material.hpp"

#include "helper_functions.hpp"
using namespace MassCalculator::HelperClasses;

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator
{
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
    //TODO: Check this, for the paths after install the library
    #ifdef DEBUG
      const std::string LuaConfigPath{"/home/jimmyhalimi/ws/prototype_ws/MassCalculator/MassCalculator/resources/materials/alloy_coppers_config.lua"};
    #else
      const std::string LuaConfigPath{"/home/jimmyhalimi/ws/prototype_ws/MassCalculator/MassCalculator/resources/materials/alloy_coppers_config.lua"};
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
     * TODO:Check if this can be moved to the base class
     */
    typedef struct Properties
    {

      /**
       * @brief Private members of AlloyCoppers class. Values defaulted with brace-enclosed initializer list
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
      std::pair<std::string, Type> type_{Constants::UNSPECIFIED, AlloyCoppers::Type::UNSPECIFIED};
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
     * @brief Enum that holds the AlloyCoppers types Source: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
     * TODO: Maybe add the documentation also in a string, in setPropertySpecs so we can use in the app to show some information about the alloy selected
     */
    enum class Type : uint8_t
    {
      BEGIN = 0,
      /**
       * @brief This grade is commercially pure AlloyCoppers. It is soft and ductile and has excellent workability, making it ideal for applications with difficult forming. 
       * It can be welded using any method, but it is non heat-treatable. It has an excellent resistance to corrosion and is commonly used in the chemical and 
       * food processing industries.
       * 
       */
      AC_145Tellvirum = BEGIN,

      /**
       * @brief High mechanical strength and excellent machining capabilities are the highlights of this grade. It is often called – Free Machining Alloy (FMA), 
       * an excellent choice for projects done on automatic lathes. The high-speed machining of this grade will produce fine chips that are easily removed. 
       * Alloy 2011 is an excellent choice for production of complex and detailed parts.
       * 
       */
      AC_194Iron,

      /**
       * @brief A copper based alloy with very high strength and excellent machining capabilities. This alloy is commonly used in many aerospace structural applications 
       * due to its resistance.
       * 
       */
      AC_195Iron,

      /**
       * @brief One of the most commonly used high strength aluminum alloys. With its combination of high strength and excellent fatigue resistance, it is commonly used 
       * where a good strength-to-weight ratio is desired.  This grade can be machined to a high finish and it can be formed in the annealed condition with 
       * subsequent heat treating, if needed. The corrosion resistance of this grade is relatively low. When this is an issue, 2024 is commonly used in an 
       * anodized finish or in clad form (thin surface layer of high purity aluminum) known as Alclad.
       * 
       */
      AC_172Beryllium,

      /**
       * @brief The most widely used of all aluminum alloys. A commercially pure aluminum with added manganese to increase its strength (20% stronger than the 1100 grade). 
       * It has excellent corrosion resistance, and workability. This grade can be deep drawn or spun, welded or brazed.
       * 
       */
      AC_182Class2,

      /**
       * @brief This is the highest strength alloy of the more non heat-treatable grades. Its fatigue strength is higher than most other aluminum grades. 
       * Alloy 5052 has a good resistance to marine atmosphere and salt water corrosion, and excellent workability. It can be easily drawn or formed into intricate shapes.
       * 
       */
      AC_655Silicon,

      /**
       * @brief The most versatile of the heat-treatable aluminum alloys, while keeping most of the good qualities of aluminum. This grade has a great range of mechanical 
       * properties and corrosion resistance. It can be fabricated by most of the commonly used techniques and it has good workability in the annealed condition. It is 
       * welded by all methods and can be furnace brazed. As a result, it is used in a wide variety of products and applications where appearance and better corrosion 
       * resistance with good strength are required. The Tube and Angle shapes in this grade typically have rounded corners.
       * 
       */
      AC_706Nickel,

      /**
       * @brief Commonly known as an architectural alloy. It has reasonably high tensile properties, excellent finishing characteristics and a high degree of resistance 
       * to corrosion. Most often found in various interior and exterior architectural applications and trim. It is very well suited for anodizing applications. 
       * Commonly known as an architectural alloy. It has reasonably high tensile properties, excellent finishing characteristics and a high degree of resistance to corrosion. 
       * Most often found in various interior and exterior architectural applications and trim. It is very well suited for anodizing applications. 
       * The Tube and Angle shapes in this grade typically have square corners.The Tube and Angle shapes in this grade typically have square corners.
       * 
       */
      AC_715NickelSilver,

      /**
       * @brief This is one of the highest strength aluminum alloys available. It has an excellent strength-to weight ratio, and it is ideally used for highly stressed parts. 
       * This grade can be formed in the annealed condition and subsequently heat treated, if needed. It can also be spot or flash welded (arc and gas not recommended).
       * 
       */
      AC_725NickelSilver,

      AC_735NickelSilver,

      AC_752NickelSilver,

      AC_762NickelSilver,

      AC_770NickelSilver,

      AC_1751Class3,

      AC_1758Nickel,

      AC_MoldmaxBeCu,

      AC_ProthermBeCu,

      UNSPECIFIED,

      END
    };

    friend std::ostream& operator<<(std::ostream& os, Type type)
    {
      switch(type)
      {
        case Type::AC_145Tellvirum: os << Constants::AC_145Tellvirum; break;
        case Type::AC_194Iron: os << Constants::AC_194Iron; break;
        case Type::AC_195Iron: os << Constants::AC_195Iron; break;
        case Type::AC_172Beryllium: os << Constants::AC_172Beryllium; break;
        case Type::AC_182Class2: os << Constants::AC_182Class2; break;
        case Type::AC_655Silicon: os << Constants::AC_655Silicon; break;
        case Type::AC_706Nickel: os << Constants::AC_706Nickel; break;
        case Type::AC_715NickelSilver: os << Constants::AC_715NickelSilver; break;
        case Type::AC_725NickelSilver: os << Constants::AC_725NickelSilver; break;
        case Type::AC_735NickelSilver: os << Constants::AC_735NickelSilver; break;
        case Type::AC_752NickelSilver: os << Constants::AC_752NickelSilver; break;
        case Type::AC_762NickelSilver: os << Constants::AC_762NickelSilver; break;
        case Type::AC_770NickelSilver: os << Constants::AC_770NickelSilver; break;
        case Type::AC_1751Class3: os << Constants::AC_1751Class3; break;
        case Type::AC_1758Nickel: os << Constants::AC_1758Nickel; break;
        case Type::AC_MoldmaxBeCu: os << Constants::AC_MoldmaxBeCu; break;
        case Type::AC_ProthermBeCu: os << Constants::AC_ProthermBeCu; break;
        case Type::UNSPECIFIED: os << Constants::UNSPECIFIED; break;
        default: os << "Name cannot be found";
      }
      return os;
    }

    /**
     * @brief Construct a new AlloyCoppers object
     * 
     */
    AlloyCoppers(void);

    /**
     * @brief Construct a new AlloyCoppers object and specify the type
     * 
     */
    AlloyCoppers(Type type);

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
     * @return const double The specific melting point of AlloyCoppers type
     */
    double getSpecificMeltingPoint(void) const;

    /**
     * @brief Get the Specific PoissonsRatio object
     * 
     * @return double The specific poissons ratio of AlloyCoppers type
     */
    double getSpecificPoissonsRatio(void) const;

    /**
     * @brief Get the Specific Thermal Conductivity object
     * 
     * @return double The specific thermal conductivity of AlloyCoppers type
     */
    double getSpecificThermalConductivity(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Tension object
     * 
     * @return const double The specific modulus of elasticity tension point of AlloyCoppers type
     */
    double getSpecificModOfElasticityTension(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Torsion object
     * 
     * @return const double The specific modulus of elasticity torsion point of AlloyCoppers type
     */
    double getSpecificModOfElasticityTorsion(void) const;

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

    private:
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

    /**
     * @brief Set the Propertie Specs object
     * 
     * @param type Type of AlloyCoppers
     * @return true If the specifications of propertie are successfully set
     * @return false  If the specifications of propertie failed to set
     */
    bool setPropertieSpecs(Type type);

    //TODO: Check this method, with typedef, and convert in all places like this
    Properties_t specific_properties_;

    /**
     * @brief Lua Handler object to get the config for metals from LuaScript is necessary
     * 
     */
    LuaScriptHandler lua_state_;

  };
}//end namespace MassCalculator
#endif//___ALLOY_COPPERS_H___