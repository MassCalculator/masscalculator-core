/**
 * @file alloy_steels.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains the class definition for alloy_steels.
 * The alloy_steels class holds all the specific properties for the different
 * types of alloy_steels. It inherits from the base class Material and provides
 * the getters and setters for the alloy_steels properties.
 * @version 0.2
 * @date 2023-04-14
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
#ifndef MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_ALLOY_STEELS_H_
#define MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_ALLOY_STEELS_H_
#include <cstdint>       // for uint8_t
#include <functional>    // for std::function
#include <string>        // for std::string
#include <string_view>   // for std::string_view
#include <unordered_map> // for std::unordered_map
#include <utility>       // for std::move

#include "masscalculator/masscalculator-base/immutable_map.h" // for ImmutableMap
#include "masscalculator/masscalculator-core/materials/constants/alloy_steels.h" // for alloysteels::k*
#include "masscalculator/masscalculator-core/materials/constants/color.h" // for color::k*
#include "masscalculator/masscalculator-core/materials/constants/material.h" // for material::k*
#include "masscalculator/masscalculator-core/materials/material.h" // for Material<T>

/**
 * @brief MassCalculator Core Materials namespace
 */
namespace masscalculator::core::materials {
/**
 * @brief Class AlloySteels, that holds all the nessesary information for
 * AlloySteels and it's types therefore we can use in the interface
 */
class AlloySteels : public Material<AlloySteels> {
 public:
  /**
   * @brief Enum that holds the AlloySteels types
   */
  enum class SubType : uint8_t {
    kBegin = 0,

    /**
     * @brief @todo(jimmyhalimi): Add a brief for the alloy.
     *
     * @source: @todo(jimmyhalimi): Add the source of the brief for the alloy.
     */
    k4135 = kBegin,

    /**
     * @brief @todo(jimmyhalimi): Add a brief for the alloy.
     *
     * @source: @todo(jimmyhalimi): Add the source of the brief for the alloy.
     */
    k4140,

    /**
     * @brief @todo(jimmyhalimi): Add a brief for the alloy.
     *
     * @source: @todo(jimmyhalimi): Add the source of the brief for the alloy.
     */
    k4340,

    /**
     * @brief Unspecified metal alloy
     */
    kUnspecified,

    kEnd = kUnspecified
  };

  /**
   * @brief Construct a new Alloy Steels object
   *
   * @param sub_type SubType of AlloySteels
   */
  explicit AlloySteels(const std::string_view& sub_type);

  /**
   * @brief Set the Propertie Specs object
   *
   * @param sub_type SubType of AlloySteels
   * @return true If the specifications of propertie are successfully set
   * @return false  If the specifications of propertie failed to set
   */
  bool SetSubType(const std::string_view& sub_type);

  /**
   * @brief Get the Type object
   *
   * @return constexpr Type of material class: AlloySteels
   */
  [[nodiscard]] inline constexpr Type GetType() const {
    return kType.at(constants::material::kAlloySteels);
  }

  /**
   * @brief Destroy the AlloySteels object
   */
  ~AlloySteels() = default;

  /**
   * @brief Delete copy constructor
   */
  AlloySteels(const AlloySteels&) = delete;

  /**
   * @brief Set move constructor to default
   */
  AlloySteels(AlloySteels&&) = default;

  /**
   * @brief Delete assignment operator
   */
  AlloySteels& operator=(const AlloySteels&) = delete;

  /**
   * @brief Allow move assignment operator
   */
  AlloySteels& operator=(AlloySteels&&) = default;

  /**
   * @brief A map used to convert a string representation of a sub_type to an
   * enum value.
   */
  static constexpr base::ImmutableMap<std::string_view, AlloySteels::SubType, 4>
      kSubType{{{{constants::alloysteel::k4135, AlloySteels::SubType::k4135},
                 {constants::alloysteel::k4140, AlloySteels::SubType::k4140},
                 {constants::alloysteel::k4340, AlloySteels::SubType::k4340},
                 {constants::alloysteel::kUnspecified,
                  AlloySteels::SubType::kUnspecified}}}};

  /**
   * @brief A map used to convert an enum value of type Type to its string
   * representation.
   */
  static constexpr base::ImmutableMap<AlloySteels::SubType, std::string_view, 4>
      kSubTypeString{
          {{{AlloySteels::SubType::k4135, constants::alloysteel::k4135},
            {AlloySteels::SubType::k4140, constants::alloysteel::k4140},
            {AlloySteels::SubType::k4340, constants::alloysteel::k4340},
            {AlloySteels::SubType::kUnspecified,
             constants::alloysteel::kUnspecified}}}};

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
      {SubType::k4135,
       [&]() {
         return SetProperties(Properties{SubType::k4135,
                                         Color::kMetallic,
                                         {10.0_kg_per_cu_m},
                                         {10.0_K},
                                         0.1,
                                         {10.0_W},
                                         {10.0_GPa}});
       }},
      {SubType::k4140,
       [&]() {
         return SetProperties(Properties{SubType::k4140,
                                         Color::kMetallic,
                                         {10.0_kg_per_cu_m},
                                         {10.0_K},
                                         0.1,
                                         {10.0_W},
                                         {10.0_GPa}});
       }},
      {SubType::k4340, [&]() {
         return SetProperties(Properties{SubType::k4340,
                                         Color::kMetallic,
                                         {10.0_kg_per_cu_m},
                                         {10.0_K},
                                         0.1,
                                         {10.0_W},
                                         {10.0_GPa}});
       }}};
};
} // namespace masscalculator::core::materials
#endif // MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_ALLOY_STEELS_H_
