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
#ifndef MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_INCLUDE_MATERIALS_ALLOY_COPPERS_H_
#define MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_INCLUDE_MATERIALS_ALLOY_COPPERS_H_
#include <lua_handler.h>  // for LuaScriptHandler

#include "constants/alloy_coppers.h"  // for alloycopper::k*
#include "constants/material.h"       // for color::k*
#include "material.h"                 // for material
#include "units.h"                    // for units::*
using namespace units::literals;

/**
 * @brief Default Materials namespace
 *
 */
namespace masscalculator::materials {

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
  using Properties = struct Properties {
    /**
     * @brief Type The parameter to save the specific type
     *
     */
    std::pair<std::string, Type> type;

    /**
     * @brief string Parameter to save specific color
     *
     */
    std::string color;

    /**
     * @brief kilograms_per_cubic_meter_t Parameter to save specific density
     *
     */
    units::density::kilograms_per_cubic_meter_t density;

    /**
     * @brief meters_per_second_squared_t Parameter to save specific gravity
     *
     */
    units::acceleration::meters_per_second_squared_t gravity;

    /**
     * @brief kelvin_t Parameter to save specific melting point
     *
     */
    units::temperature::kelvin_t melting_point;

    /**
     * @brief double Parameter to save specific poissons ratio
     *
     */
    double poissons_ratio;

    /**
     * @brief watt_t Parameter to save specific thermal conductivity
     *
     */
    units::power::watt_t thermal_conductivity;

    /**
     * @brief pascal_t Parameter to save specific modulus of elasticity tension
     *
     */
    units::pressure::pascal_t mod_of_elasticity_tension;

    /**
     * @brief Construct a new Properties object with all parameters initialized
     *
     */
    Properties()
        : type{std::make_pair(constants::alloycopper::UNSPECIFIED,
                              AlloyCoppers::Type::UNSPECIFIED)},
          color{""},
          density{0_kg_per_cu_m},
          gravity{0_mps_sq},
          melting_point{0_K},
          poissons_ratio{0},
          thermal_conductivity{0_W},
          mod_of_elasticity_tension{0_Pa} {}

    /**
     * @brief Construct a new Properties object through initializer list
     *
     */
    Properties(std::pair<std::string, Type> type, std::string color,
               units::density::kilograms_per_cubic_meter_t density,
               units::acceleration::meters_per_second_squared_t gravity,
               units::temperature::kelvin_t melting_point,
               double poissons_ratio, units::power::watt_t thermal_conductivity,
               units::pressure::pascal_t mod_of_elasticity_tension)
        : type{std::move(type)},
          color{std::move(color)},
          density{density},
          gravity{gravity},
          melting_point{melting_point},
          poissons_ratio{poissons_ratio},
          thermal_conductivity{thermal_conductivity},
          mod_of_elasticity_tension{mod_of_elasticity_tension} {}
  };

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
  AlloyCoppers();

  /**
   * @brief Construct a new AlloyCoppers object and specify the type
   *
   */
  explicit AlloyCoppers(const Type& type);

  /**
   * @brief Function to initialize the Lua object
   *
   */
  bool InitLuaScript();

  /**
   * @brief Set the Type object
   *
   * @param type Type of the AlloyCoppers
   * @return true If the type is set successfully
   * @return false If the type failed to set
   */
  bool SetType(const Type& type);

  /**
   * @brief Get the Type object
   *
   * @return std::pair<std::string, Type> Pair with type name and type enum
   */
  std::pair<std::string, Type> GetType() const;

  /**
   * @brief Get the Specific color object
   *
   * @return std::string color of the material
   */
  std::string GetSpecificColor() const;

  /**
   * @brief Get the Specific Density object
   *
   * @return kilograms_per_cubic_meter_t Density of the material
   */
  units::density::kilograms_per_cubic_meter_t GetSpecificDensity() const;

  /**
   * @brief Get the Specific Gravity object
   *
   * @return meters_per_second_squared_t double Gravity of the material
   */
  units::acceleration::meters_per_second_squared_t GetSpecificGravity() const;

  /**
   * @brief Get the Specific Melting Point object
   *
   * @return kelvin_t The specific melting point of AlloyCoppers type
   */
  units::temperature::kelvin_t GetSpecificMeltingPoint() const;

  /**
   * @brief Get the Specific PoissonsRatio object
   *
   * @return double The specific poissons ratio of AlloyCoppers type
   */
  double GetSpecificPoissonsRatio() const;

  /**
   * @brief Get the Specific Thermal Conductivity object
   *
   * @return watt_t The specific thermal conductivity of AlloyCoppers type
   */
  units::power::watt_t GetSpecificThermalConductivity() const;

  /**
   * @brief Get the Specific Modulus of Elasticity Tension object
   *
   * @return pascal_t The specific modulus of elasticity tension point of
   * AlloyCoppers type
   */
  units::pressure::pascal_t GetSpecificModOfElasticityTension() const;

  /**
   * @brief Destroy the AlloyCoppers object
   *
   */
  ~AlloyCoppers() = default;

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
    return {constants::material::kAlloyCoppers};
  };

  /**
   * @brief Function to set the static propertie values
   *
   * @param _properties Structure of the constant properties
   * @return true If properties are correctly set
   * @return false If properties have failed to set
   */
  bool _setPropertieSpecs(const Properties& properties);

  /**
   * @brief Unordered map, and a lambda parsed as std::function. This is all
   * done to eliminate the switch statement Here we set also the values
   * accordingly to SI @todo Set values properly
   *
   */
  std::unordered_map<Type, std::function<void()>> type2func_{
      {Type::AC_145Tellvirum,
       [&]() {
         return this->_setPropertieSpecs(
             {{constants::alloycopper::k145Telluirum, Type::AC_145Tellvirum},
              {constants::color::kMetallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              0.33,
              {990.0_W},
              {3.8_Pa}});
       }},
      {Type::AC_194Iron,
       [&]() {
         return this->_setPropertieSpecs(
             {{constants::alloycopper::AC_194Iron, Type::AC_194Iron},
              {constants::color::kMetallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {3.8_Pa}});
       }},
      {Type::AC_195Iron,
       [&]() {
         return this->_setPropertieSpecs(
             {{constants::alloycopper::AC_195Iron, Type::AC_195Iron},
              {constants::color::kMetallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {3.8_Pa}});
       }},
      {Type::AC_182Class2,
       [&]() {
         return this->_setPropertieSpecs(
             {{constants::alloycopper::AC_182Class2, Type::AC_182Class2},
              {constants::color::kMetallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {3.8_Pa}});
       }},
      {Type::AC_655Silicon,
       [&]() {
         return this->_setPropertieSpecs(
             {{constants::alloycopper::AC_655Silicon, Type::AC_655Silicon},
              {constants::color::kMetallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {3.8_Pa}});
       }},
      {Type::AC_706Nickel,
       [&]() {
         return this->_setPropertieSpecs(
             {{constants::alloycopper::AC_706Nickel, Type::AC_706Nickel},
              {constants::color::kMetallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {3.8_Pa}});
       }},
      {Type::AC_715NickelSilver,
       [&]() {
         return this->_setPropertieSpecs(
             {{constants::alloycopper::AC_715NickelSilver,
               Type::AC_715NickelSilver},
              {constants::color::kMetallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {3.8_Pa}});
       }},
      {Type::AC_725NickelSilver,
       [&]() {
         return this->_setPropertieSpecs(
             {{constants::alloycopper::AC_725NickelSilver,
               Type::AC_725NickelSilver},
              {constants::color::kMetallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {3.8_Pa}});
       }},
      {Type::AC_735NickelSilver,
       [&]() {
         return this->_setPropertieSpecs(
             {{constants::alloycopper::AC_735NickelSilver,
               Type::AC_735NickelSilver},
              {constants::color::kMetallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {3.8_Pa}});
       }},
      {Type::AC_752NickelSilver,
       [&]() {
         return this->_setPropertieSpecs(
             {{constants::alloycopper::AC_752NickelSilver,
               Type::AC_752NickelSilver},
              {constants::color::kMetallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {3.8_Pa}});
       }},
      {Type::AC_762NickelSilver,
       [&]() {
         return this->_setPropertieSpecs(
             {{constants::alloycopper::AC_762NickelSilver,
               Type::AC_762NickelSilver},
              {constants::color::kMetallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {3.8_Pa}});
       }},
      {Type::AC_770NickelSilver,
       [&]() {
         return this->_setPropertieSpecs(
             {{constants::alloycopper::AC_770NickelSilver,
               Type::AC_770NickelSilver},
              {constants::color::kMetallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {3.8_Pa}});
       }},
      {Type::AC_1751Class3,
       [&]() {
         return this->_setPropertieSpecs(
             {{constants::alloycopper::AC_1751Class3, Type::AC_1751Class3},
              {constants::color::kMetallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {3.8_Pa}});
       }},
      {Type::AC_1758Nickel,
       [&]() {
         return this->_setPropertieSpecs(
             {{constants::alloycopper::AC_1758Nickel, Type::AC_1758Nickel},
              {constants::color::kMetallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {3.8_Pa}});
       }},
      {Type::AC_MoldmaxBeCu,
       [&]() {
         return this->_setPropertieSpecs(
             {{constants::alloycopper::AC_MoldmaxBeCu, Type::AC_MoldmaxBeCu},
              {constants::color::kMetallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {3.8_Pa}});
       }},
      {Type::AC_ProthermBeCu, [&]() {
         return this->_setPropertieSpecs(
             {{constants::alloycopper::AC_ProthermBeCu, Type::AC_ProthermBeCu},
              {constants::color::kMetallic},
              {2.71_kg_per_cu_m},
              {2.83_mps_sq},
              {537.778_K},
              {0.33},
              {990.0_W},
              {3.8_Pa}});
       }}};

  /**
   * @brief Set the Propertie Specs object
   *
   * @param type Type of AlloyCoppers
   * @return true If the specifications of propertie are successfully set
   * @return false  If the specifications of propertie failed to set
   */
  bool SetPropertieSpecs(const Type& type);

  /**
   * @brief Properties struct to hold the specific object properties
   *
   */
  Properties specific_properties_;

  /**
   * @brief Lua Handler object to get the config for metals from LuaScript is
   * necessary
   *
   */
  LuaScriptHandler lua_state_;
};
}  // namespace masscalculator::materials
#endif  // MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_INCLUDE_MATERIALS_ALLOY_COPPERS_H_