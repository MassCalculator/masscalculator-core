/**
 * @file alloy_coppers.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Alloy Coppers class that holds the parameters for all the types
 * @version 0.1
 * @date 2020-03-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___ALLOY_COPPERS_H___
#define ___ALLOY_COPPERS_H___
#include "material.hpp"

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator
{
  /**
   * @brief String constants that are used through the code
   * 
   */
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
    // @@TODO: Check this, for the paths after install the library
    #ifdef DEBUG
      const std::string AlloyCoppersLuaConfigPath{"/home/jimmyhalimi/ws/prototype_ws/MassCalculator/MassCalculator/resources/materials/alloy_coppers_config.lua"};
    #else
      // const std::string home_path_ = getenv("HOME");
      // const std::string AlloyCoppersLuaConfigPath{home_path_ + "/.MassCalculatorResources/materials/alloy_coppers_config.lua"};
      const std::string AlloyCoppersLuaConfigPath{"/home/jimmyhalimi/ws/prototype_ws/MassCalculator/MassCalculator/resources/materials/alloy_coppers_config.lua"};
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
     * @TODO:Check if this can be moved to the base class, the problem is only in the std::pair<T, Type>, Type cannot be deduced from base to derived
     */
    typedef struct Properties
    {

      /**
       * @brief Private members of AlloyCoppers class. Values defaulted with brace-enclosed initializer list
       * and will be set from the constructor.
       * 
       * @param type_ Type The parameter to save the specific type
       * @param color_ string Parameter to save specific color
       * @param density_ kilograms_per_cubic_meter_t Parameter to save specific density
       * @param gravity_ meters_per_second_squared_t Parameter to save specific gravity
       * @param melting_point_ kelvin_t Parameter to save specific melting point
       * @param poissons_ratio_ double Parameter to save specific poissons ratio
       * @param thermal_conductivity_ watt_t Parameter to save specific thermal conductivity
       * @param mod_of_elasticity_tension_ pascal_t Parameter to save specific modulus of elasticity tension
       * @param mod_of_elasticity_torsion_ pascal_t Parameter to save specific modulus of elasticity torsion
       * 
       */
      std::pair<std::string, Type> type_{Constants::UNSPECIFIED, AlloyCoppers::Type::UNSPECIFIED};
      std::string color_{0};
      kilograms_per_cubic_meter_t density_{0_kg_per_cu_m};
      meters_per_second_squared_t gravity_{0_mps_sq};
      kelvin_t melting_point_{0_K};
      double poissons_ratio_{0};
      watt_t thermal_conductivity_{0_W};
      pascal_t mod_of_elasticity_tension_{0_Pa};
      pascal_t mod_of_elasticity_torsion_{0_Pa};
    }Properties_t;

    public:
    /**
     * @brief Enum that holds the AlloyCoppers types Source: https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
     * @TODO: Maybe add the documentation also in a string, in setPropertySpecs so we can use in the app to show some information about the alloy selected
     */
    enum class Type : uint8_t
    {
      BEGIN = 0,

      /**
       * @brief Tellurium copper also referred to as Alloy 145, Alloy C15400, 145 half-hard tellurium, and TeCu—is a copper-based alloy that contains varying amounts of tellurium and phosphorus. 
       * The tellurium content typically ranges between 0.4–0.7%, while the phosphorus content ranges between 0.004–0.12%.
       * Tellurium copper demonstrates good electrical and thermal conductivity, good formability and high machinability. These properties make it suitable for a wide range of industrial applications.
       * 
       */
      AC_145Tellvirum = BEGIN,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      AC_194Iron,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      AC_195Iron,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      AC_172Beryllium,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      AC_182Class2,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      AC_655Silicon,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      AC_706Nickel,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      AC_715NickelSilver,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      AC_725NickelSilver,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      AC_735NickelSilver,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      AC_752NickelSilver,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      AC_762NickelSilver,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      AC_770NickelSilver,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      AC_1751Class3,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      AC_1758Nickel,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      AC_MoldmaxBeCu,

      /**
       * @brief @todo Add a short summary brief for this type of metal alloy. 
       * 
       */
      AC_ProthermBeCu,

      /**
       * @brief Unspecified metal alloy
       * 
       */
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
     * @return const kilograms_per_cubic_meter_t Density of the material
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
     * @return const kelvin_t The specific melting point of AlloyCoppers type
     */
    kelvin_t getSpecificMeltingPoint(void) const;

    /**
     * @brief Get the Specific PoissonsRatio object
     * 
     * @return double The specific poissons ratio of AlloyCoppers type
     */
    double getSpecificPoissonsRatio(void) const;

    /**
     * @brief Get the Specific Thermal Conductivity object
     * 
     * @return watt_t The specific thermal conductivity of AlloyCoppers type
     */
    watt_t getSpecificThermalConductivity(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Tension object
     * 
     * @return const pascal_t The specific modulus of elasticity tension point of AlloyCoppers type
     */
    pascal_t getSpecificModOfElasticityTension(void) const;

    /**
     * @brief Get the Specific Modulus of Elasticity Torsion object
     * 
     * @return const pascal_t The specific modulus of elasticity torsion point of AlloyCoppers type
     */
    pascal_t getSpecificModOfElasticityTorsion(void) const;

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
#endif//___ALLOY_COPPERS_H___