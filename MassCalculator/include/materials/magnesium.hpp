#ifndef ___MAGNESIUM_H___
#define ___MAGNESIUM_H___
#include "material.hpp"

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator
{
  namespace Constants
  {
    const std::string  M_AZ31B{"M_AZ31B"};

    const std::string MagnesiumLuaConfigPath{"/home/jimmyhalimi/ws/prototype_ws/MassCalculator/MassCalculator/resources/materials/magnesium_config.lua"};
  }

  /**
   * @brief Class Magnesium, that holds all the nessesary information for Magnesium and it's types therefore we can use in the interface
   * 
   */
  class Magnesium : public Material<Magnesium>
  {
    public: enum class Type : uint8_t;

    /**
     * @brief Struct with material specific properties
     * TODO:Check if this can be moved to the base class
     */
    typedef struct Properties
    {

      /**
       * @brief Private members of Magnesium class. Values defaulted with brace-enclosed initializer list
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
      std::pair<std::string, Type> type_{Constants::UNSPECIFIED, Magnesium::Type::UNSPECIFIED};
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
     * @brief Enum that holds the Magnesium types Source: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
     * TODO: Maybe add the documentation also in a string, in setPropertySpecs so we can use in the app to show some information about the alloy selected
     */
    enum class Type : uint8_t
    {
      BEGIN = 0,
      /**
       * @brief This grade is commercially pure Magnesium. It is soft and ductile and has excellent workability, making it ideal for applications with difficult forming. 
       * It can be welded using any method, but it is non heat-treatable. It has an excellent resistance to corrosion and is commonly used in the chemical and 
       * food processing industries.
       * 
       */
      M_AZ31B = BEGIN,

      UNSPECIFIED,

      END
    };

    friend std::ostream& operator<<(std::ostream& os, Type type)
    {
      switch(type)
      {
        case Type::M_AZ31B: os << Constants::M_AZ31B; break;
        case Type::UNSPECIFIED: os << Constants::UNSPECIFIED; break;
        default: os << "Name cannot be found";
      }
      return os;
    }

    /**
     * @brief Construct a new Magnesium object
     * 
     */
    Magnesium(void);

    /**
     * @brief Construct a new Magnesium object and specify the type
     * 
     */
    Magnesium(Type type);

    /**
     * @brief Function to initialize the Lua object
     * 
     */
    bool initLuaScript(void);

    /**
     * @brief Set the Type object
     * 
     * @param type Type of the Magnesium
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
     * @return const double The specific melting point of Magnesium type
     */
    double getSpecificMeltingPoint(void) const;

    /**
     * @brief Get the Specific PoissonsRatio object
     * 
     * @return double The specific poissons ratio of Magnesium type
     */
    double getSpecificPoissonsRatio(void) const;

    /**
     * @brief Get the Specific Thermal Conductivity object
     * 
     * @return double The specific thermal conductivity of Magnesium type
     */
    double getSpecificThermalConductivity(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Tension object
     * 
     * @return const double The specific modulus of elasticity tension point of Magnesium type
     */
    double getSpecificModOfElasticityTension(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Torsion object
     * 
     * @return const double The specific modulus of elasticity torsion point of Magnesium type
     */
    double getSpecificModOfElasticityTorsion(void) const;

    /**
     * @brief Destroy the Magnesium object
     * 
     */
    ~Magnesium(void) = default;

    /**
     * @brief Shift operator overload for class Magnesium, this will print all the nessesery informations
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const Magnesium &obj);

    private:
    /**
     * @brief Delete copy constructor
     * 
     */
    Magnesium(const Magnesium&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    Magnesium(Magnesium&&) = default;

    /**
     * @brief Delete assignment operator
     */
    Magnesium& operator=(const Magnesium&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    Magnesium& operator=(Magnesium&&) = default;

    /**
     * @brief Set the Propertie Specs object
     * 
     * @param type Type of Magnesium
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
}//end namespace MassCalculator
#endif