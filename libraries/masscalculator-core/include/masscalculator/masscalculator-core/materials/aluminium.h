/**
 * @file aluminium.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains the class definition for aluminium.
 * The aluminium class holds all the specific properties for the different
 * types of aluminium. It inherits from the base class Material and provides
 * the getters and setters for the aluminium properties.
 * @version 0.2
 * @date 2023-06-02
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
#ifndef MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_ALUMINIUM_H_
#define MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_ALUMINIUM_H_
#include <cstdint>       // for uint8_t
#include <functional>    // for std::function
#include <string>        // for std::string
#include <string_view>   // for std::string_view
#include <unordered_map> // for std::unordered_map
#include <utility>       // for std::move

#include "masscalculator/masscalculator-base/immutable_map.h" // for ImmutableMap
#include "masscalculator/masscalculator-core/materials/constants/aluminium.h" // for aluminium::k*
#include "masscalculator/masscalculator-core/materials/constants/color.h" // for color::k*
#include "masscalculator/masscalculator-core/materials/constants/material.h" // for material::k*
#include "masscalculator/masscalculator-core/materials/material.h" // for Material<T>

/**
 * @brief MassCalculator Core Materials namespace
 */
namespace masscalculator::core::materials {
/**
 * @brief Class Aluminium, that holds all the nessesary information for
 * Aluminium and it's types therefore we can use in the interface
 */
class Aluminium : public Material<Aluminium> {
 public:
  /**
   * @brief Enum that holds the Aluminium types
   */
  enum class SubType : uint8_t {
    kBegin = 0,

    /**
     * @brief This grade is commercially pure aluminum. It is soft and ductile
     * and has excellent workability, making it ideal for applications with
     * difficult forming. It can be welded using any method, but it is non
     * heat-treatable. It has an excellent resistance to corrosion and is
     * commonly used in the chemical and food processing industries.
     *
     * @source:
     * https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
     */
    k1100 = kBegin,

    /**
     * @brief High mechanical strength and excellent machining capabilities are
     * the highlights of this grade. It is often called – Free Machining Alloy
     * (FMA), an excellent choice for projects done on automatic lathes. The
     * high-speed machining of this grade will produce fine chips that are
     * easily removed. Alloy 2011 is an excellent choice for production of
     * complex and detailed parts.
     *
     * @source:
     * https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
     */
    k2011,

    /**
     * @brief A copper based alloy with very high strength and excellent
     * machining capabilities. This alloy is commonly used in many aerospace
     * structural applications due to its resistance.
     *
     * @source:
     * https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
     */
    k2014,

    /**
     * @brief One of the most commonly used high strength aluminum alloys. With
     * its combination of high strength and excellent fatigue resistance, it is
     * commonly used where a good strength-to-mass ratio is desired.  This grade
     * can be machined to a high finish and it can be formed in the annealed
     * condition with subsequent heat treating, if needed. The corrosion
     * resistance of this grade is relatively low. When this is an issue, 2024
     * is commonly used in an anodized finish or in clad form (thin surface
     * layer of high purity aluminum) known as Alclad.
     *
     * @source:
     * https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
     */
    k2024,

    /**
     * @brief The most widely used of all aluminum alloys. A commercially pure
     * aluminum with added manganese to increase its strength (20% stronger than
     * the 1100 grade). It has excellent corrosion resistance, and workability.
     * This grade can be deep drawn or spun, welded or brazed.
     *
     * @source:
     * https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
     */
    k3003,

    /**
     * @brief This is the highest strength alloy of the more non heat-treatable
     * grades. Its fatigue strength is higher than most other aluminum grades.
     * Alloy 5052 has a good resistance to marine atmosphere and salt water
     * corrosion, and excellent workability. It can be easily drawn or formed
     * into intricate shapes.
     *
     * @source:
     * https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
     */
    k5052,

    /**
     * @brief The most versatile of the heat-treatable aluminum alloys, while
     * keeping most of the good qualities of aluminum. This grade has a great
     * range of mechanical properties and corrosion resistance. It can be
     * fabricated by most of the commonly used techniques and it has good
     * workability in the annealed condition. It is welded by all methods and
     * can be furnace brazed. As a result, it is used in a wide variety of
     * products and applications where appearance and better corrosion
     * resistance with good strength are required. The Tube and Angle shapes in
     * this grade typically have rounded corners.
     *
     * @source:
     * https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
     */
    k6061,

    /**
     * @brief Commonly known as an architectural alloy. It has reasonably high
     * tensile properties, excellent finishing characteristics and a high degree
     * of resistance to corrosion. Most often found in various interior and
     * exterior architectural applications and trim. It is very well suited for
     * anodizing applications. Commonly known as an architectural alloy. It has
     * reasonably high tensile properties, excellent finishing characteristics
     * and a high degree of resistance to corrosion. Most often found in various
     * interior and exterior architectural applications and trim. It is very
     * well suited for anodizing applications. The Tube and Angle shapes in this
     * grade typically have square corners.The Tube and Angle shapes in this
     * grade typically have square corners.
     *
     * @source:
     * https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
     */
    k6063,

    /**
     * @brief This is one of the highest strength aluminum alloys available. It
     * has an excellent strength-to mass ratio, and it is ideally used for
     * highly stressed parts. This grade can be formed in the annealed condition
     * and subsequently heat treated, if needed. It can also be spot or flash
     * welded (arc and gas not recommended).
     *
     * @source:
     * https://www.metalsupermarkets.com/what-aluminum-grade-should-i-use/
     */
    k7075,

    /**
     * @brief Unspecified metal alloy
     */
    kUnspecified,

    kEnd = kUnspecified
  };

  /**
   * @brief Construct a new Aluminium object
   *
   * @param sub_type SubType of Aluminium
   */
  explicit Aluminium(const std::string_view& sub_type);

  /**
   * @brief Set the Propertie Specs object
   *
   * @param sub_type SubType of Aluminium
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
    return kType.at(constants::material::kAluminium);
  }

  /**
   * @brief Destroy the Aluminium object
   */
  ~Aluminium() = default;

  /**
   * @brief Delete copy constructor
   */
  Aluminium(const Aluminium&) = delete;

  /**
   * @brief Set move constructor to default
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
   * @brief A map used to convert a string representation of a SubType to an
   * enum value.
   */
  static constexpr base::ImmutableMap<std::string_view, Aluminium::SubType, 10>
      kSubType{{{{constants::aluminium::k1100, Aluminium::SubType::k1100},
                 {constants::aluminium::k2011, Aluminium::SubType::k2011},
                 {constants::aluminium::k2014, Aluminium::SubType::k2014},
                 {constants::aluminium::k2024, Aluminium::SubType::k2024},
                 {constants::aluminium::k3003, Aluminium::SubType::k3003},
                 {constants::aluminium::k5052, Aluminium::SubType::k5052},
                 {constants::aluminium::k6061, Aluminium::SubType::k6061},
                 {constants::aluminium::k6063, Aluminium::SubType::k6063},
                 {constants::aluminium::k7075, Aluminium::SubType::k7075},
                 {constants::aluminium::kUnspecified,
                  Aluminium::SubType::kUnspecified}}}};

  /**
   * @brief A map used to convert an enum value of type Type to its string
   * representation.
   */
  static constexpr base::ImmutableMap<Aluminium::SubType, std::string_view, 10>
      kSubTypeString{{{{Aluminium::SubType::k1100, constants::aluminium::k1100},
                       {Aluminium::SubType::k2011, constants::aluminium::k2011},
                       {Aluminium::SubType::k2014, constants::aluminium::k2014},
                       {Aluminium::SubType::k2024, constants::aluminium::k2024},
                       {Aluminium::SubType::k3003, constants::aluminium::k3003},
                       {Aluminium::SubType::k5052, constants::aluminium::k5052},
                       {Aluminium::SubType::k6061, constants::aluminium::k6061},
                       {Aluminium::SubType::k6063, constants::aluminium::k6063},
                       {Aluminium::SubType::k7075, constants::aluminium::k7075},
                       {Aluminium::SubType::kUnspecified,
                        constants::aluminium::kUnspecified}}}};

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
   * @source: @todo(jimmyhalimi): Add the source of the properties for alloy.
   */
  std::unordered_map<SubType, std::function<void()>> sub_type2func_{
      {SubType::k1100,
       [&]() {
         return SetProperties(Properties{SubType::k1100,
                                         Color::kMetallic,
                                         {10.0_kg_per_cu_m},
                                         {10.0_K},
                                         0.1,
                                         {10.0_W},
                                         {10.0_GPa}});
       }},
      {SubType::k2011,
       [&]() {
         return SetProperties(Properties{SubType::k2011,
                                         Color::kMetallic,
                                         {10.0_kg_per_cu_m},
                                         {10.0_K},
                                         0.1,
                                         {10.0_W},
                                         {10.0_GPa}});
       }},
      {SubType::k2014,
       [&]() {
         return SetProperties(Properties{SubType::k2014,
                                         Color::kMetallic,
                                         {10.0_kg_per_cu_m},
                                         {10.0_K},
                                         0.1,
                                         {10.0_W},
                                         {10.0_GPa}});
       }},
      {SubType::k2024,
       [&]() {
         return SetProperties(Properties{SubType::k2024,
                                         Color::kMetallic,
                                         {10.0_kg_per_cu_m},
                                         {10.0_K},
                                         0.1,
                                         {10.0_W},
                                         {10.0_GPa}});
       }},
      {SubType::k3003,
       [&]() {
         return SetProperties(Properties{SubType::k3003,
                                         Color::kMetallic,
                                         {10.0_kg_per_cu_m},
                                         {10.0_K},
                                         0.1,
                                         {10.0_W},
                                         {10.0_GPa}});
       }},
      {SubType::k5052,
       [&]() {
         return SetProperties(Properties{SubType::k5052,
                                         Color::kMetallic,
                                         {10.0_kg_per_cu_m},
                                         {10.0_K},
                                         0.1,
                                         {10.0_W},
                                         {10.0_GPa}});
       }},
      {SubType::k6061,
       [&]() {
         return SetProperties(Properties{SubType::k6061,
                                         Color::kMetallic,
                                         {10.0_kg_per_cu_m},
                                         {10.0_K},
                                         0.1,
                                         {10.0_W},
                                         {10.0_GPa}});
       }},
      {SubType::k6063,
       [&]() {
         return SetProperties(Properties{SubType::k6063,
                                         Color::kMetallic,
                                         {10.0_kg_per_cu_m},
                                         {10.0_K},
                                         0.1,
                                         {10.0_W},
                                         {10.0_GPa}});
       }},
      {SubType::k7075, [&]() {
         return SetProperties(Properties{SubType::k7075,
                                         Color::kMetallic,
                                         {10.0_kg_per_cu_m},
                                         {10.0_K},
                                         0.1,
                                         {10.0_W},
                                         {10.0_GPa}});
       }}};
};
} // namespace masscalculator::core::materials
#endif // MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_ALUMINIUM_H_
