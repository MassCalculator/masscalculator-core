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

    const std::string LuaConfigPath{"/home/jimmyhalimi/ws/prototype_ws/MassCalculator/MassCalculator/resources/materials/brass_config.lua"};
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
    struct Properties
    {

      /**
       * @brief Private members of Brass class. Values defaulted with brace-enclosed initializer list
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
      std::pair<std::string, Type> type_{Constants::UNSPECIFIED, Brass::Type::UNSPECIFIED};
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
     * @brief Enum that holds the Brass types Source: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
     * TODO: Maybe add the documentation also in a string, in setPropertySpecs so we can use in the app to show some information about the alloy selected
     */
    enum class Type : uint8_t
    {
      BEGIN = 0,
      /**
       * @brief This grade is commercially pure Brass. It is soft and ductile and has excellent workability, making it ideal for applications with difficult forming. 
       * It can be welded using any method, but it is non heat-treatable. It has an excellent resistance to corrosion and is commonly used in the chemical and 
       * food processing industries.
       * 
       */
      B_240Low = BEGIN,

      /**
       * @brief High mechanical strength and excellent machining capabilities are the highlights of this grade. It is often called – Free Machining Alloy (FMA), 
       * an excellent choice for projects done on automatic lathes. The high-speed machining of this grade will produce fine chips that are easily removed. 
       * Alloy 2011 is an excellent choice for production of complex and detailed parts.
       * 
       */
      B_260Cartridge,

      B_353Leaded,

      B_360,

      B_365,

      B_380,

      B_385,

      B_464,

      UNSPECIFIED,

      END
    };

    friend std::ostream& operator<<(std::ostream& os, Type type)
    {
      switch(type)
      {
        case Type::B_240Low: os << Constants::B_240Low; break;
        case Type::B_260Cartridge: os << Constants::B_260Cartridge; break;
        case Type::B_353Leaded: os << Constants::B_353Leaded; break;
        case Type::B_360: os << Constants::B_360; break;
        case Type::B_365: os << Constants::B_365; break;
        case Type::B_380: os << Constants::B_380; break;
        case Type::B_385: os << Constants::B_385; break;
        case Type::B_464: os << Constants::B_464; break;
        case Type::UNSPECIFIED: os << Constants::UNSPECIFIED; break;
        default: os << "Name cannot be found";
      }
      return os;
    }

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
     * @return const double The specific melting point of Brass type
     */
    double getSpecificMeltingPoint(void) const;

    /**
     * @brief Get the Specific PoissonsRatio object
     * 
     * @return double The specific poissons ratio of Brass type
     */
    double getSpecificPoissonsRatio(void) const;

    /**
     * @brief Get the Specific Thermal Conductivity object
     * 
     * @return double The specific thermal conductivity of Brass type
     */
    double getSpecificThermalConductivity(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Tension object
     * 
     * @return const double The specific modulus of elasticity tension point of Brass type
     */
    double getSpecificModOfElasticityTension(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Torsion object
     * 
     * @return const double The specific modulus of elasticity torsion point of Brass type
     */
    double getSpecificModOfElasticityTorsion(void) const;

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

    private:
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

    /**
     * @brief Set the Propertie Specs object
     * 
     * @param type Type of Brass
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