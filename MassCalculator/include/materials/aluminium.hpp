#ifndef ___ALUMINIUM_H___
#define ___ALUMINIUM_H___
#include "material.hpp"

// Lua is written in C, so compiler needs to know how to link its libraries
extern "C" {
  #include "lua5.1/lua.h"
  #include "lua5.1/lualib.h"
  #include "lua5.1/lauxlib.h"
}

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator
{
  /**
   * @brief Class Aluminium, that holds all the nessesary information for Aluminium and it's types therefore we can use in the interface
   * 
   */
  class Aluminium : public Material<Aluminium>
  {
    public: enum class Type : uint8_t;

    /**
     * @brief Struct with material specific properties
     * TODO:Check if this can be moved to the base class
     */
    struct Properties
    {

      /**
       * @brief Private members of Aluminium class. Values defaulted with brace-enclosed initializer list
       * and will be set from the constructor.
       * 
       * @param type_ Type The parameter to save the specific type
       * @param specific_color_ string Parameter to save specific color
       * @param specific_density_ double Parameter to save specific density
       * @param specific_volume_ double Parameter to save specific volume
       * @param specific_mass_ double Parameter to save specific mass
       * @param specific_weight_ double Parameter to save specific weight
       * @param specific_melting_point_ double Parameter to save specific melting point
       * @param specific_boiling_point_ double Parameter to save specific boiling point
       * 
       */
      std::pair<std::string, Type> type_{"UNSPECIFIED", Aluminium::Type::UNSPECIFIED};
      std::string color_{0};
      double density_{0};
      double gravity_{0};
      double melting_point_{0};
      double poissons_ratio_{0};
      double thermal_conductivity{0};
      double mod_of_elasticity_tension_{0};
      double mod_of_elasticity_torsion_{0};
    }specific_properties_;

    public:
    /**
     * @brief Enum that holds the aluminium types Source: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
     * TODO: Maybe add the documentation also in a string, in setPropertySpecs so we can use in the app to show some information about the alloy selected
     */
    enum class Type : uint8_t
    {
      /**
       * @brief This grade is commercially pure aluminum. It is soft and ductile and has excellent workability, making it ideal for applications with difficult forming. 
       * It can be welded using any method, but it is non heat-treatable. It has an excellent resistance to corrosion and is commonly used in the chemical and 
       * food processing industries.
       * 
       */
      A_1100 = 0,

      /**
       * @brief High mechanical strength and excellent machining capabilities are the highlights of this grade. It is often called – Free Machining Alloy (FMA), 
       * an excellent choice for projects done on automatic lathes. The high-speed machining of this grade will produce fine chips that are easily removed. 
       * Alloy 2011 is an excellent choice for production of complex and detailed parts.
       * 
       */
      A_2011,

      /**
       * @brief A copper based alloy with very high strength and excellent machining capabilities. This alloy is commonly used in many aerospace structural applications 
       * due to its resistance.
       * 
       */
      A_2014,

      /**
       * @brief One of the most commonly used high strength aluminum alloys. With its combination of high strength and excellent fatigue resistance, it is commonly used 
       * where a good strength-to-weight ratio is desired.  This grade can be machined to a high finish and it can be formed in the annealed condition with 
       * subsequent heat treating, if needed. The corrosion resistance of this grade is relatively low. When this is an issue, 2024 is commonly used in an 
       * anodized finish or in clad form (thin surface layer of high purity aluminum) known as Alclad.
       * 
       */
      A_2024,

      /**
       * @brief The most widely used of all aluminum alloys. A commercially pure aluminum with added manganese to increase its strength (20% stronger than the 1100 grade). 
       * It has excellent corrosion resistance, and workability. This grade can be deep drawn or spun, welded or brazed.
       * 
       */
      A_3003,

      /**
       * @brief This is the highest strength alloy of the more non heat-treatable grades. Its fatigue strength is higher than most other aluminum grades. 
       * Alloy 5052 has a good resistance to marine atmosphere and salt water corrosion, and excellent workability. It can be easily drawn or formed into intricate shapes.
       * 
       */
      A_5052,

      /**
       * @brief The most versatile of the heat-treatable aluminum alloys, while keeping most of the good qualities of aluminum. This grade has a great range of mechanical 
       * properties and corrosion resistance. It can be fabricated by most of the commonly used techniques and it has good workability in the annealed condition. It is 
       * welded by all methods and can be furnace brazed. As a result, it is used in a wide variety of products and applications where appearance and better corrosion 
       * resistance with good strength are required. The Tube and Angle shapes in this grade typically have rounded corners.
       * 
       */
      A_6061,

      /**
       * @brief Commonly known as an architectural alloy. It has reasonably high tensile properties, excellent finishing characteristics and a high degree of resistance 
       * to corrosion. Most often found in various interior and exterior architectural applications and trim. It is very well suited for anodizing applications. 
       * Commonly known as an architectural alloy. It has reasonably high tensile properties, excellent finishing characteristics and a high degree of resistance to corrosion. 
       * Most often found in various interior and exterior architectural applications and trim. It is very well suited for anodizing applications. 
       * The Tube and Angle shapes in this grade typically have square corners.The Tube and Angle shapes in this grade typically have square corners.
       * 
       */
      A_6063,

      /**
       * @brief This is one of the highest strength aluminum alloys available. It has an excellent strength-to weight ratio, and it is ideally used for highly stressed parts. 
       * This grade can be formed in the annealed condition and subsequently heat treated, if needed. It can also be spot or flash welded (arc and gas not recommended).
       * 
       */
      A_7075,

      UNSPECIFIED
    };

    /**
     * @brief Construct a new Aluminium object
     * 
     */
    Aluminium(void) = default;

    /**
     * @brief Construct a new Aluminium object and specify the type
     * 
     */
    Aluminium(Type type);

    /**
     * @brief Set the Type object
     * 
     * @param type Type of the Aluminium
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
     * @return const double The specific melting point of Aluminium type
     */
    double getSpecificMeltingPoint(void) const;

    /**
     * @brief Get the Specific PoissonsRatio object
     * 
     * @return double The specific poissons ratio of Aluminium type
     */
    double getSpecificPoissonsRatio(void) const;

    /**
     * @brief Get the Specific Thermal Conductivity object
     * 
     * @return double The specific thermal conductivity of Aluminium type
     */
    double getSpecificThermalConductivity(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Tension object
     * 
     * @return const double The specific modulus of elasticity tension point of Aluminium type
     */
    double getSpecificModOfElasticityTension(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Torsion object
     * 
     * @return const double The specific modulus of elasticity torsion point of Aluminium type
     */
    double getSpecificModOfElasticityTorsion(void) const;

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

    private:
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

    /**
     * @brief Set the Propertie Specs object
     * 
     * @param type Type of Aluminium
     * @return true If the specifications of propertie are successfully set
     * @return false  If the specifications of propertie failed to set
     */
    bool setPropertieSpecs(Type type);

  };
}//end namespace MassCalculator
#endif