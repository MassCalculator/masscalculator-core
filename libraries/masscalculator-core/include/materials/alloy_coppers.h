/**
 * @file alloy_coppers.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief AlloyCoppers class that holds the parameters for all the types
 * @version 0.1
 * @date 2020-03-20
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef ___ALLOY_COPPERS_H___
#define ___ALLOY_COPPERS_H___
#include "material.h"

/**
 * @brief Default Materials namespace
 *
 */
namespace MassCalculator {
namespace Materials {
/**
 * @brief String constants that are used through the code
 *
 */
namespace Constants::AlloyCoppers {
/** @brief String constant for AC_145Tellvirum type */
const std::string AC_145Tellvirum{"AC_145Tellvirum"};

/** @brief String constant for AC_194Iron type */
const std::string AC_194Iron{"AC_194Iron"};

/** @brief String constant for AC_195Iron type */
const std::string AC_195Iron{"AC_195Iron"};

/** @brief String constant for AC_172Beryllium type */
const std::string AC_172Beryllium{"AC_172Beryllium"};

/** @brief String constant for AC_182Class2 type */
const std::string AC_182Class2{"AC_182Class2"};

/** @brief String constant for AC_655Silicon type */
const std::string AC_655Silicon{"AC_655Silicon"};

/** @brief String constant for AC_706Nickel type */
const std::string AC_706Nickel{"AC_706Nickel"};

/** @brief String constant for AC_715NickelSilver type */
const std::string AC_715NickelSilver{"AC_715NickelSilver"};

/** @brief String constant for AC_725NickelSilver type */
const std::string AC_725NickelSilver{"AC_725NickelSilver"};

/** @brief String constant for AC_735NickelSilver type */
const std::string AC_735NickelSilver{"AC_735NickelSilver"};

/** @brief String constant for AC_752NickelSilver type */
const std::string AC_752NickelSilver{"AC_752NickelSilver"};

/** @brief String constant for AC_762NickelSilver type */
const std::string AC_762NickelSilver{"AC_762NickelSilver"};

/** @brief String constant for AC_770NickelSilver type */
const std::string AC_770NickelSilver{"AC_770NickelSilver"};

/** @brief String constant for AC_1751Class3 type */
const std::string AC_1751Class3{"AC_1751Class3"};

/** @brief String constant for AC_1758Nickel type */
const std::string AC_1758Nickel{"AC_1758Nickel"};

/** @brief String constant for AC_MoldmaxBeCu type */
const std::string AC_MoldmaxBeCu{"AC_MoldmaxBeCu"};

/** @brief String constant for AC_ProthermBeCu type */
const std::string AC_ProthermBeCu{"AC_ProthermBeCu"};

/** @brief String constant for UNSPECIFIED type */
const std::string UNSPECIFIED{"UNSPECIFIED"};

/**
 * @brief @todo It will come a time that we will cross_compile, add a Windows
 * tag to.
 *
 */
#ifdef DEBUG
/**
 * @brief Lua config path when we are in debug mode, it will get the resources
 * from source directory
 *
 */
const std::string LuaConfigPath{
    std::string(getDebugLuaRootPath()) +
    "/MassCalculator/resources/materials/alloy_coppers_config.lua"};
#else
/**
 * @brief Lua config path when we are in release mode, it will get the resources
 * from the install directory
 *
 */
const std::string LuaConfigPath{
    std::string(getenv("HOME")) +
    "/.MassCalculator/resources/materials/alloy_coppers_config.lua"};
#endif
}  // namespace Constants::AlloyCoppers

/**
 * @brief Class AlloyCoppers, that holds all the nessesary information for
 * AlloyCoppers and it's types therefore we can use in the interface
 *
 */
class AlloyCoppers : public Material<AlloyCoppers> {
 public:
  enum class Type : uint8_t;

  /**
   * @brief Struct with material specific properties
   * @todo: Check if this can be moved to the base class, the problem is only in
   * the std::pair<T, Type>, Type cannot be deduced from base to derived
   */
  typedef struct Properties {
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
    Properties()
        : type_{std::make_pair(Constants::AlloyCoppers::UNSPECIFIED,
                               AlloyCoppers::Type::UNSPECIFIED)},
          color_{""},
          density_{0_kg_per_cu_m},
          gravity_{0_mps_sq},
          melting_point_{0_K},
          poissons_ratio_{0},
          thermal_conductivity_{0_W},
          mod_of_elasticity_tension_{0_Pa},
          mod_of_elasticity_torsion_{0_Pa} {}

    /**
     * @brief Construct a new Properties object through initializer list
     *
     */
    Properties(std::pair<std::string, Type> type, std::string color,
               kilograms_per_cubic_meter_t density,
               meters_per_second_squared_t gravity, kelvin_t melting_point,
               double poissons_ratio, watt_t thermal_conductivity,
               pascal_t mod_of_elasticity_tension,
               pascal_t mod_of_elasticity_torsion)
        : type_{type},
          color_{color},
          density_{density},
          gravity_{gravity},
          melting_point_{melting_point},
          poissons_ratio_{poissons_ratio},
          thermal_conductivity_{thermal_conductivity},
          mod_of_elasticity_tension_{mod_of_elasticity_tension},
          mod_of_elasticity_torsion_{mod_of_elasticity_torsion} {}
  } Properties_t;

 public:
  /**
   * @brief Enum that holds the AlloyCoppers types
   *
   */
  enum class Type : uint8_t {
    BEGIN = 0,

    /**
     * @brief Tellurium copper also referred to as Alloy 145, Alloy C15400, 145
     * half-hard tellurium, and TeCu—is a copper-based alloy that contains
     * varying amounts of tellurium and phosphorus. The tellurium content
     * typically ranges between 0.4–0.7%, while the phosphorus content ranges
     * between 0.004–0.12%. Tellurium copper demonstrates good electrical and
     * thermal conductivity, good formability and high machinability. These
     * properties make it suitable for a wide range of industrial applications.
     * @todo: Add source
     *
     */
    AC_145Tellvirum = BEGIN,

    /**
     * @brief @todo Add a short summary brief for this type of metal alloy.
     * @todo: Add source
     *
     */
    AC_194Iron,

    /**
     * @brief @todo Add a short summary brief for this type of metal alloy.
     * @todo: Add source
     *
     */
    AC_195Iron,

    /**
     * @brief @todo Add a short summary brief for this type of metal alloy.
     * @todo: Add source
     *
     */
    AC_172Beryllium,

    /**
     * @brief @todo Add a short summary brief for this type of metal alloy.
     * @todo: Add source
     *
     */
    AC_182Class2,

    /**
     * @brief @todo Add a short summary brief for this type of metal alloy.
     * @todo: Add source
     *
     */
    AC_655Silicon,

    /**
     * @brief @todo Add a short summary brief for this type of metal alloy.
     * @todo: Add source
     *
     */
    AC_706Nickel,

    /**
     * @brief @todo Add a short summary brief for this type of metal alloy.
     * @todo: Add source
     *
     */
    AC_715NickelSilver,

    /**
     * @brief @todo Add a short summary brief for this type of metal alloy.
     * @todo: Add source
     *
     */
    AC_725NickelSilver,

    /**
     * @brief @todo Add a short summary brief for this type of metal alloy.
     * @todo: Add source
     *
     */
    AC_735NickelSilver,

    /**
     * @brief @todo Add a short summary brief for this type of metal alloy.
     * @todo: Add source
     *
     */
    AC_752NickelSilver,

    /**
     * @brief @todo Add a short summary brief for this type of metal alloy.
     * @todo: Add source
     *
     */
    AC_762NickelSilver,

    /**
     * @brief @todo Add a short summary brief for this type of metal alloy.
     * @todo: Add source
     *
     */
    AC_770NickelSilver,

    /**
     * @brief @todo Add a short summary brief for this type of metal alloy.
     * @todo: Add source
     *
     */
    AC_1751Class3,

    /**
     * @brief @todo Add a short summary brief for this type of metal alloy.
     * @todo: Add source
     *
     */
    AC_1758Nickel,

    /**
     * @brief @todo Add a short summary brief for this type of metal alloy.
     * @todo: Add source
     *
     */
    AC_MoldmaxBeCu,

    /**
     * @brief @todo Add a short summary brief for this type of metal alloy.
     * @todo: Add source
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

  /**
   * @brief Construct a new AlloyCoppers object
   *
   */
  AlloyCoppers(void);

  /**
   * @brief Construct a new AlloyCoppers object and specify the type
   *
   */
  AlloyCoppers(const Type& type);

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
  bool setType(const Type& type);

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
   * @return meters_per_second_squared_t double Gravity of the material
   */
  meters_per_second_squared_t getSpecificGravity(void) const;

  /**
   * @brief Get the Specific Melting Point object
   *
   * @return kelvin_t The specific melting point of AlloyCoppers type
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
   * @return pascal_t The specific modulus of elasticity tension point of
   * AlloyCoppers type
   */
  pascal_t getSpecificModOfElasticityTension(void) const;

  /**
   * @brief Get the Specific Modulus of Elasticity Torsion object
   *
   * @return pascal_t The specific modulus of elasticity torsion point of
   * AlloyCoppers type
   */
  pascal_t getSpecificModOfElasticityTorsion(void) const;

  /**
   * @brief Destroy the AlloyCoppers object
   *
   */
  ~AlloyCoppers(void) = default;

  /**
   * @brief Shift operator overload for class AlloyCoppers, this will print all
   * the nessesery informations
   *
   */
  friend std::ostream& operator<<(std::ostream& os, const AlloyCoppers& obj);

  /**
   * @brief Shift operator overload for Types of AlloyCoppers, this will print
   * the name in string
   *
   */
  friend std::ostream& operator<<(std::ostream& os, const Type& type);

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

 private:
  /**
   * @brief Function to return the class name, not the pointer of the class, I
   * am trying to keep away this function outside of the class
   *
   * @return std::string Class name as a string
   */
  inline std::string _getClassName(AlloyCoppers*) {
    return {Constants::Material::AlloyCoppers};
  };

  /**
   * @brief Function to set the static propertie values
   *
   * @param _properties Structure of the constant properties
   * @return true If properties are correctly set
   * @return false If properties have failed to set
   */
  bool _setPropertieSpecs(const Properties_t& _properties);

  /**
   * @brief Unordered map, and a lambda parsed as std::function. This is all
   * done to eliminate the switch statement Here we set also the values
   * accordingly to SI @todo Set values properly
   *
   */
  std::unordered_map<Type, std::function<void()>> type2func{
      {Type::AC_145Tellvirum,
       [&]() {
         return this->_setPropertieSpecs(
             {{Constants::AlloyCoppers::AC_145Tellvirum, Type::AC_145Tellvirum},
              {Constants::Color::Metallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {9.9_Pa},
              {3.8_Pa}});
       }},
      {Type::AC_194Iron,
       [&]() {
         return this->_setPropertieSpecs(
             {{Constants::AlloyCoppers::AC_194Iron, Type::AC_194Iron},
              {Constants::Color::Metallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {9.9_Pa},
              {3.8_Pa}});
       }},
      {Type::AC_195Iron,
       [&]() {
         return this->_setPropertieSpecs(
             {{Constants::AlloyCoppers::AC_195Iron, Type::AC_195Iron},
              {Constants::Color::Metallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {9.9_Pa},
              {3.8_Pa}});
       }},
      {Type::AC_182Class2,
       [&]() {
         return this->_setPropertieSpecs(
             {{Constants::AlloyCoppers::AC_182Class2, Type::AC_182Class2},
              {Constants::Color::Metallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {9.9_Pa},
              {3.8_Pa}});
       }},
      {Type::AC_655Silicon,
       [&]() {
         return this->_setPropertieSpecs(
             {{Constants::AlloyCoppers::AC_655Silicon, Type::AC_655Silicon},
              {Constants::Color::Metallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {9.9_Pa},
              {3.8_Pa}});
       }},
      {Type::AC_706Nickel,
       [&]() {
         return this->_setPropertieSpecs(
             {{Constants::AlloyCoppers::AC_706Nickel, Type::AC_706Nickel},
              {Constants::Color::Metallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {9.9_Pa},
              {3.8_Pa}});
       }},
      {Type::AC_715NickelSilver,
       [&]() {
         return this->_setPropertieSpecs(
             {{Constants::AlloyCoppers::AC_715NickelSilver,
               Type::AC_715NickelSilver},
              {Constants::Color::Metallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {9.9_Pa},
              {3.8_Pa}});
       }},
      {Type::AC_725NickelSilver,
       [&]() {
         return this->_setPropertieSpecs(
             {{Constants::AlloyCoppers::AC_725NickelSilver,
               Type::AC_725NickelSilver},
              {Constants::Color::Metallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {9.9_Pa},
              {3.8_Pa}});
       }},
      {Type::AC_735NickelSilver,
       [&]() {
         return this->_setPropertieSpecs(
             {{Constants::AlloyCoppers::AC_735NickelSilver,
               Type::AC_735NickelSilver},
              {Constants::Color::Metallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {9.9_Pa},
              {3.8_Pa}});
       }},
      {Type::AC_752NickelSilver,
       [&]() {
         return this->_setPropertieSpecs(
             {{Constants::AlloyCoppers::AC_752NickelSilver,
               Type::AC_752NickelSilver},
              {Constants::Color::Metallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {9.9_Pa},
              {3.8_Pa}});
       }},
      {Type::AC_762NickelSilver,
       [&]() {
         return this->_setPropertieSpecs(
             {{Constants::AlloyCoppers::AC_762NickelSilver,
               Type::AC_762NickelSilver},
              {Constants::Color::Metallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {9.9_Pa},
              {3.8_Pa}});
       }},
      {Type::AC_770NickelSilver,
       [&]() {
         return this->_setPropertieSpecs(
             {{Constants::AlloyCoppers::AC_770NickelSilver,
               Type::AC_770NickelSilver},
              {Constants::Color::Metallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {9.9_Pa},
              {3.8_Pa}});
       }},
      {Type::AC_1751Class3,
       [&]() {
         return this->_setPropertieSpecs(
             {{Constants::AlloyCoppers::AC_1751Class3, Type::AC_1751Class3},
              {Constants::Color::Metallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {9.9_Pa},
              {3.8_Pa}});
       }},
      {Type::AC_1758Nickel,
       [&]() {
         return this->_setPropertieSpecs(
             {{Constants::AlloyCoppers::AC_1758Nickel, Type::AC_1758Nickel},
              {Constants::Color::Metallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {9.9_Pa},
              {3.8_Pa}});
       }},
      {Type::AC_MoldmaxBeCu,
       [&]() {
         return this->_setPropertieSpecs(
             {{Constants::AlloyCoppers::AC_MoldmaxBeCu, Type::AC_MoldmaxBeCu},
              {Constants::Color::Metallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {9.9_Pa},
              {3.8_Pa}});
       }},
      {Type::AC_ProthermBeCu, [&]() {
         return this->_setPropertieSpecs(
             {{Constants::AlloyCoppers::AC_ProthermBeCu, Type::AC_ProthermBeCu},
              {Constants::Color::Metallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {9.9_Pa},
              {3.8_Pa}});
       }}};

  /**
   * @brief Set the Propertie Specs object
   *
   * @param type Type of AlloyCoppers
   * @return true If the specifications of propertie are successfully set
   * @return false  If the specifications of propertie failed to set
   */
  bool setPropertieSpecs(const Type& type);

  /**
   * @brief Properties struct to hold the specific object properties
   *
   */
  Properties_t specific_properties_;

  /**
   * @brief Lua Handler object to get the config for metals from LuaScript is
   * necessary
   *
   */
  LuaScriptHandler lua_state_;
};
}  // namespace Materials
}  // namespace MassCalculator
#endif  //___ALLOY_COPPERS_H___