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
#ifndef MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_ALLOY_COPPERS_H_
#define MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_ALLOY_COPPERS_H_
#include <cstdint>       // for uint8_t
#include <functional>    // for std::function
#include <string>        // for std::string
#include <string_view>   // for std::string_view
#include <unordered_map> // for std::unordered_map
#include <utility>       // for std::move

#include "masscalculator/masscalculator-base/immutable_map.h" // for ImmutableMap
#include "masscalculator/masscalculator-core/materials/constants/alloy_coppers.h" // for alloycopper::k*
#include "masscalculator/masscalculator-core/materials/constants/color.h" // for color::k*
#include "masscalculator/masscalculator-core/materials/constants/material.h" // for material::k*
#include "masscalculator/masscalculator-core/materials/material.h" // for Material<T>

/**
 * @brief MassCalculator Core Materials namespace
 */
namespace masscalculator::core::materials {
/**
 * @brief Class AlloyCoppers, that holds all the nessesary information for
 * AlloyCoppers and it's types therefore we can use in the interface
 */
class AlloyCoppers : public Material<AlloyCoppers> {
 public:
  /**
   * @brief Enum that holds the AlloyCoppers types
   */
  enum class SubType : uint8_t {
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
   * @brief Construct a new Alloy Coppers object
   *
   * @param sub_type SubType of AlloyCoppers
   */
  explicit AlloyCoppers(const std::string_view& sub_type);

  /**
   * @brief Set the Propertie Specs object
   *
   * @param sub_type SubType of AlloyCoppers
   * @return true If the specifications of propertie are successfully set
   * @return false  If the specifications of propertie failed to set
   */
  bool SetSubType(const std::string_view& sub_type);

  /**
   * @brief Get the Type object
   *
   * @return constexpr Type of material class: AlloyCoppers
   */
  [[nodiscard]] inline constexpr Type GetType() const {
    return kType.at(constants::material::kAlloyCoppers);
  }

  /**
   * @brief Destroy the AlloyCoppers object
   */
  ~AlloyCoppers() = default;

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

  /**
   * @brief A map used to convert a string representation of a sub_type to an
   * enum value.
   */
  static constexpr base::ImmutableMap<std::string_view, AlloyCoppers::SubType,
                                      18>
      kSubType{
          {{{constants::alloycopper::k145Telluirum,
             AlloyCoppers::SubType::k145Telluirum},
            {constants::alloycopper::k194Iron, AlloyCoppers::SubType::k194Iron},
            {constants::alloycopper::k195Iron, AlloyCoppers::SubType::k195Iron},
            {constants::alloycopper::k172Beryllium,
             AlloyCoppers::SubType::k172Beryllium},
            {constants::alloycopper::k182Class2,
             AlloyCoppers::SubType::k182Class2},
            {constants::alloycopper::k655Silicon,
             AlloyCoppers::SubType::k655Silicon},
            {constants::alloycopper::k706Nickel,
             AlloyCoppers::SubType::k706Nickel},
            {constants::alloycopper::k715NickelSilver,
             AlloyCoppers::SubType::k715NickelSilver},
            {constants::alloycopper::k725NickelSilver,
             AlloyCoppers::SubType::k725NickelSilver},
            {constants::alloycopper::k735NickelSilver,
             AlloyCoppers::SubType::k735NickelSilver},
            {constants::alloycopper::k752NickelSilver,
             AlloyCoppers::SubType::k752NickelSilver},
            {constants::alloycopper::k762NickelSilver,
             AlloyCoppers::SubType::k762NickelSilver},
            {constants::alloycopper::k770NickelSilver,
             AlloyCoppers::SubType::k770NickelSilver},
            {constants::alloycopper::k1751Class3,
             AlloyCoppers::SubType::k1751Class3},
            {constants::alloycopper::k1758Nickel,
             AlloyCoppers::SubType::k1758Nickel},
            {constants::alloycopper::kMoldmaxBeCu,
             AlloyCoppers::SubType::kMoldmaxBeCu},
            {constants::alloycopper::kProthermBeCu,
             AlloyCoppers::SubType::kProthermBeCu},
            {constants::alloycopper::kUnspecified,
             AlloyCoppers::SubType::kUnspecified}}}};

  /**
   * @brief A map used to convert an enum value of sub_type SubType to its
   * string representation.
   */
  static constexpr base::ImmutableMap<AlloyCoppers::SubType, std::string_view,
                                      18>
      kSubTypeString{
          {{{AlloyCoppers::SubType::k145Telluirum,
             constants::alloycopper::k145Telluirum},
            {AlloyCoppers::SubType::k194Iron, constants::alloycopper::k194Iron},
            {AlloyCoppers::SubType::k195Iron, constants::alloycopper::k195Iron},
            {AlloyCoppers::SubType::k172Beryllium,
             constants::alloycopper::k172Beryllium},
            {AlloyCoppers::SubType::k182Class2,
             constants::alloycopper::k182Class2},
            {AlloyCoppers::SubType::k655Silicon,
             constants::alloycopper::k655Silicon},
            {AlloyCoppers::SubType::k706Nickel,
             constants::alloycopper::k706Nickel},
            {AlloyCoppers::SubType::k715NickelSilver,
             constants::alloycopper::k715NickelSilver},
            {AlloyCoppers::SubType::k725NickelSilver,
             constants::alloycopper::k725NickelSilver},
            {AlloyCoppers::SubType::k735NickelSilver,
             constants::alloycopper::k735NickelSilver},
            {AlloyCoppers::SubType::k752NickelSilver,
             constants::alloycopper::k752NickelSilver},
            {AlloyCoppers::SubType::k762NickelSilver,
             constants::alloycopper::k762NickelSilver},
            {AlloyCoppers::SubType::k770NickelSilver,
             constants::alloycopper::k770NickelSilver},
            {AlloyCoppers::SubType::k1751Class3,
             constants::alloycopper::k1751Class3},
            {AlloyCoppers::SubType::k1758Nickel,
             constants::alloycopper::k1758Nickel},
            {AlloyCoppers::SubType::kMoldmaxBeCu,
             constants::alloycopper::kMoldmaxBeCu},
            {AlloyCoppers::SubType::kProthermBeCu,
             constants::alloycopper::kProthermBeCu},
            {AlloyCoppers::SubType::kUnspecified,
             constants::alloycopper::kUnspecified}}}};

  /**
   * @brief Function to return the class name.
   *
   * @return std::string_view Class name as a string
   */
  [[nodiscard]] inline constexpr auto GetClassName() const {
    return kTypeString.at(GetType());
  };

 private:
  /**
   * @brief Convert a string representation of a unit to its corresponding SI
   * unit using an unordered map and a lambda function.
   * Instead of using a switch statement, an unordered map is used with a lambda
   * function to eliminate the need for a large switch statement. The function
   * sets the values accordingly to SI units.
   *
   * @source: GPT 4.0
   */
  std::unordered_map<SubType, std::function<void()>> sub_type2func_{
      {SubType::k145Telluirum,
       [&]() {
         return SetProperties(Properties{SubType::k145Telluirum,
                                         Color::kMetallic,
                                         {8940_kg_per_cu_m},
                                         {1323.15_K},
                                         0.34,
                                         {315.0_W},
                                         {128_GPa}});
       }},
      {SubType::k194Iron,
       [&]() {
         return SetProperties(Properties{SubType::k194Iron,
                                         Color::kMetallic,
                                         {7874_kg_per_cu_m},
                                         {1811.15_K},
                                         0.29,
                                         {80.4_W},
                                         {211_GPa}});
       }},
      {SubType::k195Iron,
       [&]() {
         return SetProperties(Properties{SubType::k195Iron,
                                         Color::kMetallic,
                                         {7874_kg_per_cu_m},
                                         {1811.15_K},
                                         0.29,
                                         {80.4_W},
                                         {211_GPa}});
       }},
      {SubType::k172Beryllium,
       [&]() {
         return SetProperties(Properties{SubType::k172Beryllium,
                                         Color::kMetallic,
                                         {8300_kg_per_cu_m},
                                         {1356.15_K},
                                         0.30,
                                         {209_W},
                                         {140_GPa}});
       }},
      {SubType::k182Class2,
       [&]() {
         return SetProperties(Properties{SubType::k182Class2,
                                         Color::kMetallic,
                                         {8300_kg_per_cu_m},
                                         {1356.15_K},
                                         0.30,
                                         {209_W},
                                         {140_GPa}});
       }},
      {SubType::k655Silicon,
       [&]() {
         return SetProperties(Properties{SubType::k655Silicon,
                                         Color::kMetallic,
                                         {2330_kg_per_cu_m},
                                         {1687_K},
                                         0.22,
                                         {149_W},
                                         {50_GPa}});
       }},
      {SubType::k706Nickel,
       [&]() {
         return SetProperties(Properties{SubType::k706Nickel,
                                         Color::kMetallic,
                                         {8908_kg_per_cu_m},
                                         {1728_K},
                                         0.31,
                                         {91_W},
                                         {207_GPa}});
       }},
      {SubType::k715NickelSilver,
       [&]() {
         return SetProperties(Properties{SubType::k715NickelSilver,
                                         Color::kMetallic,
                                         {8400_kg_per_cu_m},
                                         {1373_K},
                                         0.37,
                                         {94_W},
                                         {130_GPa}});
       }},
      {SubType::k725NickelSilver,
       [&]() {
         return SetProperties(Properties{SubType::k725NickelSilver,
                                         Color::kMetallic,
                                         {8450_kg_per_cu_m},
                                         {1373_K},
                                         0.37,
                                         {93_W},
                                         {130_GPa}});
       }},
      {SubType::k735NickelSilver,
       [&]() {
         return SetProperties(Properties{SubType::k735NickelSilver,
                                         Color::kMetallic,
                                         {8500_kg_per_cu_m},
                                         {1373_K},
                                         0.37,
                                         {92_W},
                                         {130_GPa}});
       }},
      {SubType::k752NickelSilver,
       [&]() {
         return SetProperties(Properties{SubType::k752NickelSilver,
                                         Color::kMetallic,
                                         {8600_kg_per_cu_m},
                                         {1373_K},
                                         0.37,
                                         {90_W},
                                         {130_GPa}});
       }},
      {SubType::k762NickelSilver,
       [&]() {
         return SetProperties(Properties{SubType::k762NickelSilver,
                                         Color::kMetallic,
                                         {8650_kg_per_cu_m},
                                         {1373_K},
                                         0.37,
                                         {89_W},
                                         {130_GPa}});
       }},
      {SubType::k770NickelSilver,
       [&]() {
         return SetProperties(Properties{SubType::k770NickelSilver,
                                         Color::kMetallic,
                                         {8700_kg_per_cu_m},
                                         {1373_K},
                                         0.37,
                                         {88_W},
                                         {130_GPa}});
       }},
      {SubType::k1751Class3,
       [&]() {
         return SetProperties(Properties{SubType::k1751Class3,
                                         Color::kMetallic,
                                         {8920_kg_per_cu_m},
                                         {1400_K},
                                         0.31,
                                         {42_W},
                                         {110_GPa}});
       }},
      {SubType::k1758Nickel,
       [&]() {
         return SetProperties(Properties{SubType::k1758Nickel,
                                         Color::kMetallic,
                                         {8908_kg_per_cu_m},
                                         {1728_K},
                                         0.31,
                                         {91_W},
                                         {207_GPa}});
       }},
      {SubType::kMoldmaxBeCu,
       [&]() {
         return SetProperties(Properties{SubType::kMoldmaxBeCu,
                                         Color::kMetallic,
                                         {8250_kg_per_cu_m},
                                         {1356.15_K},
                                         0.30,
                                         {209_W},
                                         {140_GPa}});
       }},
      {SubType::kProthermBeCu, [&]() {
         return SetProperties(Properties{SubType::kProthermBeCu,
                                         Color::kMetallic,
                                         {8250_kg_per_cu_m},
                                         {1356.15_K},
                                         0.30,
                                         {209_W},
                                         {140_GPa}});
       }}};
};
} // namespace masscalculator::core::materials
#endif // MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_ALLOY_COPPERS_H_
