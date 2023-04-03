/**
 * @file alloy_coppers.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains the class definition for alloy_coppers.
 * The alloy_coppers class holds all the specific properties for the different
 * types of alloy_coppers. It inherits from the base class Material and provides
 * the getters and setters for the alloy_coppers properties.
 * @version 0.2
 * @date 2023-04-03
 *
 * @copyright Copyright (c) 2023, MassCalculator, Org., All rights reserved.
 * @license This project is released under the  MIT license (MIT).
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_INCLUDE_MATERIALS_ALLOY_COPPERS_H_
#define MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_INCLUDE_MATERIALS_ALLOY_COPPERS_H_
#include <cstdint>       // for uint8_t
#include <functional>    // for std::function
#include <memory>        // for std::unique_ptr
#include <ostream>       // fot std::ostream
#include <string>        // for std::string
#include <unordered_map> // for std::unordered_map
#include <utility>       // for std::pair and std::move

#include "lua_handler.h"                       // for LuaScriptHandler
#include "materials/constants/alloy_coppers.h" // for alloycopper::k*
#include "materials/constants/color.h"         // for color::k*
#include "materials/constants/material.h"      // for material::k*
#include "materials/material.h"                // for material
#include "units.h"                             // for units::*

/**
 * @brief Default Materials namespace
 */
namespace masscalculator::materials {

/**
 * @brief Class AlloyCoppers, that holds all the nessesary information for
 * AlloyCoppers and it's types therefore we can use in the interface
 */
class AlloyCoppers : public Material<AlloyCoppers> {
 public:
  enum class Type : uint8_t;

  /**
   * @brief Struct with material specific properties
   * @todo(jimmyhalimi): Check if this can be moved to the base class, the
   * problem is only in the std::pair<T, Type>, Type cannot be deduced from base
   * to derived
   */
  using Properties = struct Properties {
    /**
     * @brief Type The parameter to save the specific type
     * @todo(jimmyhalimi): Check if we can change this type, and use
     * immutable_map to convert string to enum
     */
    std::pair<std::string, Type> type;

    /**
     * @brief string Parameter to save specific color
     * @todo(jimmyhalimi): Check if we can change this type, and use
     * immutable_map to convert string to enum
     */
    std::string color;

    /**
     * @brief kilograms_per_cubic_meter_t Parameter to save specific density
     */
    units::density::kilograms_per_cubic_meter_t density;

    /**
     * @brief meters_per_second_squared_t Parameter to save specific gravity
     */
    units::acceleration::meters_per_second_squared_t gravity;

    /**
     * @brief kelvin_t Parameter to save specific melting point
     */
    units::temperature::kelvin_t melting_point;

    /**
     * @brief double Parameter to save specific poissons ratio
     */
    double poissons_ratio;

    /**
     * @brief watt_t Parameter to save specific thermal conductivity
     */
    units::power::watt_t thermal_conductivity;

    /**
     * @brief pascal_t Parameter to save specific modulus of elasticity tension
     */
    units::pressure::pascal_t mod_of_elasticity_tension;

    /**
     * @brief Construct a new Properties object with all parameters initialized
     */
    Properties()
        : type{std::make_pair(constants::alloycopper::kUnspecified,
                              AlloyCoppers::Type::kUnspecified)},
          color{""},
          density{0_kg_per_cu_m},
          gravity{0_mps_sq},
          melting_point{0_K},
          poissons_ratio{0},
          thermal_conductivity{0_W},
          mod_of_elasticity_tension{0_Pa} {}

    /**
     * @brief Construct a new Properties object through initializer list
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
   */
  enum class Type : uint8_t {
    kBegin = 0,

    /**
     * @brief Tellurium copper, also referred to as Alloy 145, Alloy C15400, 145
     * half-hard tellurium, and TeCu, is a copper-based alloy that contains
     * varying amounts of tellurium and phosphorus. The tellurium content
     * typically ranges between 0.4% and 0.7%, while the phosphorus content
     * ranges between 0.004% and 0.12%. Tellurium copper demonstrates good
     * electrical and thermal conductivity, good formability, and high
     * machinability. These properties make it suitable for a wide range of
     * industrial applications.
     *
     * @source: ASM Handbook Volume 2: Properties and Selection: Nonferrous
     * Alloys and Special-Purpose Materials (10th Edition), American Society for
     * Metals, 1990, p. 127-128.
     */
    k145Telluirum = kBegin,

    /**
     * @brief Alloy Copper 194 Iron is a type of copper-based alloy that
     * contains iron and other elements. This alloy is known for its excellent
     * strength and wear resistance, as well as its good electrical and thermal
     * conductivity. Alloy Copper 194 Iron is used in a variety of applications,
     * including electrical and electronic components, as well as in the
     * automotive and aerospace industries.
     *
     * @source:
     * https://www.farmerscopper.com/copper-alloys/copper-alloy-194-iron/
     */
    k194Iron,

    /**
     * @brief Alloy 195 Iron is an iron-based alloy that is composed of
     * approximately 92% iron, 5% nickel, and 3% chromium. It is known for its
     * high strength, excellent corrosion resistance, and good magnetic
     * properties. Alloy 195 Iron is commonly used in a variety of industrial
     * applications, including electrical equipment, aerospace components, and
     * automotive parts.
     *
     * @source: https://www.azom.com/article.aspx?ArticleID=15804
     */
    k195Iron,

    /**
     * @brief Alloy 172 Beryllium Copper, also known as Beryllium Bronze and
     * UNS C17200, is a copper alloy with 1.8–2% beryllium and sometimes other
     * elements. The alloy combines high strength with non-magnetic and
     * non-sparking qualities. It is also highly resistant to corrosion and
     * wear, making it useful in applications such as aircraft bushings,
     * bearings, and non-sparking tools.
     *
     * @source: https://www.azom.com/article.aspx?ArticleID=2860
     */
    k172Beryllium,

    /**
     * @brief Alloy 182 is a Ni-Cr-Fe alloy material with additions of
     * molybdenum, vanadium and zirconium. It is primarily used for welding
     * high-temperature, high-pressure pipe systems containing carbon steels. It
     * exhibits good high-temperature strength and oxidation resistance.
     *
     * @source: https://www.azom.com/article.aspx?ArticleID=14153
     */
    k182Class2,

    /**
     * @brief Alloy 655 is a high-silicon aluminum alloy with excellent
     * casting characteristics and is commonly used for intricate and complex
     * castings. It also exhibits good machinability, weldability, and corrosion
     * resistance.
     *
     * @source: https://www.azom.com/article.aspx?ArticleID=1721
     */
    k655Silicon,

    /**
     * @brief Alloy 706 is a nickel-iron-chromium alloy with additions of
     * copper, molybdenum, and titanium. It offers good resistance to corrosion
     * and excellent strength at high temperatures. Alloy 706 is primarily used
     * in offshore and marine applications, such as seawater handling and
     * cooling systems.
     *
     * @source: https://www.azom.com/article.aspx?ArticleID=14134
     */
    k706Nickel,

    /**
     * @brief Alloy K715, also known as Nickel Silver, German Silver, or
     * Electrum, is a copper-based alloy that contains copper, nickel, and zinc.
     * It has a silver-like appearance and is highly corrosion-resistant. It is
     * commonly used in the production of musical instruments, silverware, and
     * decorative objects.
     *
     * @source: https://en.wikipedia.org/wiki/Nickel_silver
     */
    k715NickelSilver,

    /**
     * @brief Alloy 725 is a nickel-chromium-molybdenum-niobium alloy that
     * is highly resistant to corrosion and has high mechanical strength.
     * It is used in a wide range of applications such as chemical
     * processing, nuclear power generation, and offshore oil and gas
     * production.
     *
     * @source: https://www.azom.com/article.aspx?ArticleID=14745
     */
    k725NickelSilver,

    /**
     * @brief Nickel Silver 735 is a copper-nickel-zinc alloy with 63% copper,
     * 30% nickel, and 7% zinc. It has good formability, good corrosion
     * resistance, and excellent strength. It is commonly used in electrical and
     * automotive applications.
     *
     * @source:
     * https://www.matweb.com/search/datasheettext.aspx?matguid=731c36ed1b684876a545c43b28d94a32
     */
    k735NickelSilver,

    /**
     * @brief Nickel Silver 752 is a copper-nickel-zinc alloy with 65% copper,
     * 18% nickel, and 17% zinc. It has good formability, good corrosion
     * resistance, and excellent strength. It is commonly used in the
     * manufacture of coins, springs, and musical instruments.
     *
     * @source:
     * https://www.matweb.com/search/datasheettext.aspx?matguid=6f1a6b7ee6c540d6a6e80fa9b4e4bc4d
     */
    k752NickelSilver,

    /**
     * @brief Nickel Silver 762 is a copper-nickel-zinc alloy with 65% copper,
     * 18% nickel, and 17% zinc. It has good formability, good corrosion
     * resistance, and excellent strength. It is commonly used in the
     * manufacture of coins, springs, and musical instruments.
     *
     * @source:
     * https://www.matweb.com/search/datasheettext.aspx?matguid=6f1a6b7ee6c540d6a6e80fa9b4e4bc4d
     */
    k762NickelSilver,

    /**
     * @brief Nickel Silver 770 is a copper-nickel-zinc alloy with 60% copper,
     * 20% nickel, and 20% zinc. It has good formability, good corrosion
     * resistance, and excellent strength. It is commonly used in the
     * manufacture of coins, springs, and musical instruments.
     *
     * @source:
     * https://www.matweb.com/search/datasheettext.aspx?matguid=3e3c2b832d684ef480f74e794a4a4c4b
     */
    k770NickelSilver,

    /**
     * @brief Alloy 1751 is a high-strength copper-nickel-zinc alloy (also known
     * as nickel silver) that offers good corrosion resistance and high fatigue
     * strength. It is commonly used for marine hardware, musical instruments,
     * fasteners, and decorative fittings.
     *
     * @source:
     * https://www.farmerscopper.com/copper-nickel-alloys/1751-copper-nickel-zinc-c7521/
     */
    k1751Class3,

    /**
     * @brief Alloy 1758 is a nickel-copper alloy with high corrosion resistance
     * and good strength. It is commonly used in chemical processing, marine,
     * and oil and gas applications.
     *
     * @source: https://www.azom.com/properties.aspx?ArticleID=944
     */
    k1758Nickel,

    /**
     * @brief MoldMAX is a high-conductivity beryllium copper mold alloy that
     * offers good thermal conductivity and resistance to corrosion and erosion.
     * It is commonly used for plastic injection molding and blow molding.
     *
     * @source:
     * https://www.farmerscopper.com/beryllium-copper/moldmax-properties/
     */
    kMoldmaxBeCu,

    /**
     * @brief Protherm is a beryllium copper alloy that offers high strength and
     * conductivity, as well as resistance to thermal fatigue and corrosion. It
     * is commonly used for plastic injection molding and blow molding.
     *
     * @source: https://www.lk-moulds.com/protherm/
     */
    kProthermBeCu,

    /**
     * @brief Unspecified metal alloy
     */
    kUnspecified,

    kEnd = kUnspecified
  };

  /**
   * @brief Construct a new AlloyCoppers object
   */
  AlloyCoppers();

  /**
   * @brief Construct a new AlloyCoppers object and specify the type
   */
  explicit AlloyCoppers(const Type& type);

  /**
   * @brief Function to initialize the Lua object
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
  [[nodiscard]] std::pair<std::string, Type> GetType() const;

  /**
   * @brief Get the Specific color object
   *
   * @return std::string color of the material
   */
  [[nodiscard]] std::string GetSpecificColor() const;

  /**
   * @brief Get the Specific Density object
   *
   * @return kilograms_per_cubic_meter_t Density of the material
   */
  [[nodiscard]] units::density::kilograms_per_cubic_meter_t GetSpecificDensity()
      const;

  /**
   * @brief Get the Specific Gravity object
   *
   * @return meters_per_second_squared_t double Gravity of the material
   */
  [[nodiscard]] units::acceleration::meters_per_second_squared_t
  GetSpecificGravity() const;

  /**
   * @brief Get the Specific Melting Point object
   *
   * @return kelvin_t The specific melting point of AlloyCoppers type
   */
  [[nodiscard]] units::temperature::kelvin_t GetSpecificMeltingPoint() const;

  /**
   * @brief Get the Specific PoissonsRatio object
   *
   * @return double The specific poissons ratio of AlloyCoppers type
   */
  [[nodiscard]] double GetSpecificPoissonsRatio() const;

  /**
   * @brief Get the Specific Thermal Conductivity object
   *
   * @return watt_t The specific thermal conductivity of AlloyCoppers type
   */
  [[nodiscard]] units::power::watt_t GetSpecificThermalConductivity() const;

  /**
   * @brief Get the Specific Modulus of Elasticity Tension object
   *
   * @return pascal_t The specific modulus of elasticity tension point of
   * AlloyCoppers type
   */
  [[nodiscard]] units::pressure::pascal_t GetSpecificModOfElasticityTension()
      const;

  /**
   * @brief Destroy the AlloyCoppers object
   */
  ~AlloyCoppers() = default;

  /**
   * @brief Shift operator overload for class AlloyCoppers, this will print all
   * the nessesery informations
   */
  friend std::ostream& operator<<(std::ostream& os, const AlloyCoppers& obj);

  /**
   * @brief Shift operator overload for Types of AlloyCoppers, this will print
   * the name in string
   */
  friend std::ostream& operator<<(std::ostream& os, const Type& type);

  /**
   * @brief Delete copy constructor
   */
  AlloyCoppers(const AlloyCoppers&) = delete;

  /**
   * @brief Set move constructor to default
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
  inline std::string GetClassName(AlloyCoppers* /*unused*/) {
    return {constants::material::kAlloyCoppers};
  };

  /**
   * @brief Function to set the static propertie values
   *
   * @param _properties Structure of the constant properties
   * @return true If properties are correctly set
   * @return false If properties have failed to set
   */
  bool SetPropertieSpecs(const Properties& properties);

  /**
   * @brief Convert a string representation of a unit to its corresponding SI
   * unit using an unordered map and a lambda function.
   * Instead of using a switch statement, an unordered map is used with a lambda
   * function to eliminate the need for a large switch statement. The function
   * sets the values accordingly to SI units.
   *
   * @source: GPT 4.0
   */
  std::unordered_map<Type, std::function<void()>> type2func_{
      {Type::k145Telluirum,
       [&]() {
         return this->SetPropertieSpecs(
             {{constants::alloycopper::k145Telluirum, Type::k145Telluirum},
              {constants::color::kMetallic},
              {8940_kg_per_cu_m},
              {9.81_mps_sq},
              {1323.15_K},
              0.34,
              {315.0_W},
              {128_GPa}});
       }},
      {Type::k194Iron,
       [&]() {
         return this->SetPropertieSpecs(
             {{constants::alloycopper::k194Iron, Type::k194Iron},
              {constants::color::kMetallic},
              {7874_kg_per_cu_m},
              {9.81_mps_sq},
              {1811.15_K},
              0.29,
              {80.4_W},
              {211_GPa}});
       }},
      {Type::k195Iron,
       [&]() {
         return this->SetPropertieSpecs(
             {{constants::alloycopper::k195Iron, Type::k195Iron},
              {constants::color::kMetallic},
              {7874_kg_per_cu_m},
              {9.81_mps_sq},
              {1811.15_K},
              0.29,
              {80.4_W},
              {211_GPa}});
       }},
      {Type::k182Class2,
       [&]() {
         return this->SetPropertieSpecs(
             {{constants::alloycopper::k182Class2, Type::k182Class2},
              {constants::color::kMetallic},
              {8300_kg_per_cu_m},
              {9.81_mps_sq},
              {1356.15_K},
              0.30,
              {209_W},
              {140_GPa}});
       }},
      {Type::k655Silicon,
       [&]() {
         return this->SetPropertieSpecs(
             {{constants::alloycopper::k655Silicon, Type::k655Silicon},
              {constants::color::kMetallic},
              {2330_kg_per_cu_m},
              {9.81_mps_sq},
              {1687_K},
              0.22,
              {149_W},
              {50_GPa}});
       }},
      {Type::k706Nickel,
       [&]() {
         return this->SetPropertieSpecs(
             {{constants::alloycopper::k706Nickel, Type::k706Nickel},
              {constants::color::kMetallic},
              {8908_kg_per_cu_m},
              {9.81_mps_sq},
              {1728_K},
              0.31,
              {91_W},
              {207_GPa}});
       }},
      {Type::k715NickelSilver,
       [&]() {
         return this->SetPropertieSpecs(
             {{constants::alloycopper::k715NickelSilver,
               Type::k715NickelSilver},
              {constants::color::kMetallic},
              {8400_kg_per_cu_m},
              {9.81_mps_sq},
              {1373_K},
              0.37,
              {94_W},
              {130_GPa}});
       }},
      {Type::k725NickelSilver,
       [&]() {
         return this->SetPropertieSpecs(
             {{constants::alloycopper::k725NickelSilver,
               Type::k725NickelSilver},
              {constants::color::kMetallic},
              {8450_kg_per_cu_m},
              {9.81_mps_sq},
              {1373_K},
              0.37,
              {93_W},
              {130_GPa}});
       }},
      {Type::k735NickelSilver,
       [&]() {
         return this->SetPropertieSpecs(
             {{constants::alloycopper::k735NickelSilver,
               Type::k735NickelSilver},
              {constants::color::kMetallic},
              {8500_kg_per_cu_m},
              {9.81_mps_sq},
              {1373_K},
              0.37,
              {92_W},
              {130_GPa}});
       }},
      {Type::k752NickelSilver,
       [&]() {
         return this->SetPropertieSpecs(
             {{constants::alloycopper::k752NickelSilver,
               Type::k752NickelSilver},
              {constants::color::kMetallic},
              {8600_kg_per_cu_m},
              {9.81_mps_sq},
              {1373_K},
              0.37,
              {90_W},
              {130_GPa}});
       }},
      {Type::k762NickelSilver,
       [&]() {
         return this->SetPropertieSpecs(
             {{constants::alloycopper::k762NickelSilver,
               Type::k762NickelSilver},
              {constants::color::kMetallic},
              {8650_kg_per_cu_m},
              {9.81_mps_sq},
              {1373_K},
              0.37,
              {89_W},
              {130_GPa}});
       }},
      {Type::k770NickelSilver,
       [&]() {
         return this->SetPropertieSpecs(
             {{constants::alloycopper::k770NickelSilver,
               Type::k770NickelSilver},
              {constants::color::kMetallic},
              {8700_kg_per_cu_m},
              {9.81_mps_sq},
              {1373_K},
              0.37,
              {88_W},
              {130_GPa}});
       }},
      {Type::k1751Class3,
       [&]() {
         return this->SetPropertieSpecs(
             {{constants::alloycopper::k1751Class3, Type::k1751Class3},
              {constants::color::kMetallic},
              {8920_kg_per_cu_m},
              {9.81_mps_sq},
              {1400_K},
              0.31,
              {42_W},
              {110_GPa}});
       }},
      {Type::k1758Nickel,
       [&]() {
         return this->SetPropertieSpecs(
             {{constants::alloycopper::k1758Nickel, Type::k1758Nickel},
              {constants::color::kMetallic},
              {8908_kg_per_cu_m},
              {9.81_mps_sq},
              {1728_K},
              0.31,
              {91_W},
              {207_GPa}});
       }},
      {Type::kMoldmaxBeCu,
       [&]() {
         return this->SetPropertieSpecs(
             {{constants::alloycopper::kMoldmaxBeCu, Type::kMoldmaxBeCu},
              {constants::color::kMetallic},
              {8250_kg_per_cu_m},
              {9.81_mps_sq},
              {1356.15_K},
              0.30,
              {209_W},
              {140_GPa}});
       }},
      {Type::kProthermBeCu, [&]() {
         return this->SetPropertieSpecs(
             {{constants::alloycopper::kProthermBeCu, Type::kProthermBeCu},
              {constants::color::kMetallic},
              {8250_kg_per_cu_m},
              {9.81_mps_sq},
              {1356.15_K},
              0.30,
              {209_W},
              {140_GPa}});
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
   */
  Properties specific_properties_;

  /**
   * @brief Lua Handler object to get the config for metals from LuaScript is
   * necessary
   */
  LuaScriptHandler lua_state_;
  // std::unique_ptr<LuaScriptHandler> lua_state_;
};
} // namespace masscalculator::materials
#endif // MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_INCLUDE_MATERIALS_ALLOY_COPPERS_H_
