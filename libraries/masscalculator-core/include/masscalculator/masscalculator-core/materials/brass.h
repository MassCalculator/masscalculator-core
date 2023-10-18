/**
 * @file brass.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains the class definition for brass.
 * The brass class holds all the specific properties for the different
 * types of brass. It inherits from the base class Material and provides
 * the getters and setters for the brass properties.
 * @version 0.2
 * @date 2023-10-18
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
#ifndef MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_BRASS_H_
#define MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_BRASS_H_
#include <cstdint>       // for uint8_t
#include <functional>    // for std::function
#include <string>        // for std::string
#include <string_view>   // for std::string_view
#include <unordered_map> // for std::unordered_map
#include <utility>       // for std::move

#include "masscalculator/masscalculator-base/immutable_map.h" // for ImmutableMap
#include "masscalculator/masscalculator-core/materials/constants/brass.h" // for brass::k*
#include "masscalculator/masscalculator-core/materials/constants/color.h" // for color::k*
#include "masscalculator/masscalculator-core/materials/constants/material.h" // for material::k*
#include "masscalculator/masscalculator-core/materials/material.h" // for Material<T>

/**
 * @brief MassCalculator Core Materials namespace
 */
namespace masscalculator::core::materials {
/**
 * @brief Class Brass, that holds all the nessesary information for
 * Brass and it's types therefore we can use in the interface
 */
class Brass : public Material<Brass> {
 public:
  /**
   * @brief Enum that holds the Brass types
   */
  enum class SubType : uint8_t {
    kBegin = 0,

    /**
     * @brief @todo(jimmyhalimi): Add a brief for the alloy.
     *
     * @source: @todo(jimmyhalimi): Add the source of the brief for the alloy.
     */
    k240Low = kBegin,

    /**
     * @brief @todo(jimmyhalimi): Add a brief for the alloy.
     *
     * @source: @todo(jimmyhalimi): Add the source of the brief for the alloy.
     */
    k260Cartridge,

    /**
     * @brief @todo(jimmyhalimi): Add a brief for the alloy.
     *
     * @source: @todo(jimmyhalimi): Add the source of the brief for the alloy.
     */
    k353Leaded,

    /**
     * @brief @todo(jimmyhalimi): Add a brief for the alloy.
     *
     * @source: @todo(jimmyhalimi): Add the source of the brief for the alloy.
     */
    k360,

    /**
     * @brief @todo(jimmyhalimi): Add a brief for the alloy.
     *
     * @source: @todo(jimmyhalimi): Add the source of the brief for the alloy.
     */
    k365,

    /**
     * @brief @todo(jimmyhalimi): Add a brief for the alloy.
     *
     * @source: @todo(jimmyhalimi): Add the source of the brief for the alloy.
     */
    k380,

    /**
     * @brief @todo(jimmyhalimi): Add a brief for the alloy.
     *
     * @source: @todo(jimmyhalimi): Add the source of the brief for the alloy.
     */
    k385,

    /**
     * @brief @todo(jimmyhalimi): Add a brief for the alloy.
     *
     * @source: @todo(jimmyhalimi): Add the source of the brief for the alloy.
     */
    k464,

    /**
     * @brief Unspecified metal alloy
     */
    kUnspecified,

    kEnd = kUnspecified
  };

  /**
   * @brief Construct a new Brass object
   *
   * @param sub_type SubType of Brass
   */
  explicit Brass(const std::string_view& sub_type);

  /**
   * @brief Set the Propertie Specs object
   *
   * @param sub_type SubType of Brass
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
    return kType.at(constants::material::kBrass);
  }

  /**
   * @brief Destroy the Brass object
   */
  ~Brass() = default;

  /**
   * @brief Delete copy constructor
   */
  Brass(const Brass&) = delete;

  /**
   * @brief Set move constructor to default
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
   * @brief A map used to convert a string representation of a SubType to an
   * enum value.
   */
  static constexpr base::ImmutableMap<std::string_view, Brass::SubType, 10>
      kSubType{
          {{{constants::brass::k240Low, Brass::SubType::k240Low},
            {constants::brass::k260Cartridge, Brass::SubType::k260Cartridge},
            {constants::brass::k353Leaded, Brass::SubType::k353Leaded},
            {constants::brass::k360, Brass::SubType::k360},
            {constants::brass::k365, Brass::SubType::k365},
            {constants::brass::k380, Brass::SubType::k380},
            {constants::brass::k385, Brass::SubType::k385},
            {constants::brass::k464, Brass::SubType::k464},
            {constants::brass::kUnspecified, Brass::SubType::kUnspecified}}}};

  /**
   * @brief A map used to convert an enum value of type Type to its string
   * representation.
   */
  static constexpr base::ImmutableMap<Brass::SubType, std::string_view, 10>
      kSubTypeString{
          {{{Brass::SubType::k240Low, constants::brass::k240Low},
            {Brass::SubType::k260Cartridge, constants::brass::k260Cartridge},
            {Brass::SubType::k353Leaded, constants::brass::k353Leaded},
            {Brass::SubType::k360, constants::brass::k360},
            {Brass::SubType::k365, constants::brass::k365},
            {Brass::SubType::k380, constants::brass::k380},
            {Brass::SubType::k385, constants::brass::k385},
            {Brass::SubType::k464, constants::brass::k464},
            {Brass::SubType::kUnspecified, constants::brass::kUnspecified}}}};

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
      {SubType::k240Low,
       [&]() {
         return SetProperties(Properties{SubType::k240Low,
                                         Color::kMetallic,
                                         {10.0_kg_per_cu_m},
                                         {10.0_K},
                                         0.1,
                                         {10.0_W},
                                         {10.0_GPa}});
       }},
      {SubType::k260Cartridge,
       [&]() {
         return SetProperties(Properties{SubType::k260Cartridge,
                                         Color::kMetallic,
                                         {10.0_kg_per_cu_m},
                                         {10.0_K},
                                         0.1,
                                         {10.0_W},
                                         {10.0_GPa}});
       }},
      {SubType::k353Leaded,
       [&]() {
         return SetProperties(Properties{SubType::k353Leaded,
                                         Color::kMetallic,
                                         {10.0_kg_per_cu_m},
                                         {10.0_K},
                                         0.1,
                                         {10.0_W},
                                         {10.0_GPa}});
       }},
      {SubType::k360,
       [&]() {
         return SetProperties(Properties{SubType::k360,
                                         Color::kMetallic,
                                         {10.0_kg_per_cu_m},
                                         {10.0_K},
                                         0.1,
                                         {10.0_W},
                                         {10.0_GPa}});
       }},
      {SubType::k365,
       [&]() {
         return SetProperties(Properties{SubType::k365,
                                         Color::kMetallic,
                                         {10.0_kg_per_cu_m},
                                         {10.0_K},
                                         0.1,
                                         {10.0_W},
                                         {10.0_GPa}});
       }},
      {SubType::k380,
       [&]() {
         return SetProperties(Properties{SubType::k380,
                                         Color::kMetallic,
                                         {10.0_kg_per_cu_m},
                                         {10.0_K},
                                         0.1,
                                         {10.0_W},
                                         {10.0_GPa}});
       }},
      {SubType::k385,
       [&]() {
         return SetProperties(Properties{SubType::k385,
                                         Color::kMetallic,
                                         {10.0_kg_per_cu_m},
                                         {10.0_K},
                                         0.1,
                                         {10.0_W},
                                         {10.0_GPa}});
       }},
      {SubType::k464, [&]() {
         return SetProperties(Properties{SubType::k464,
                                         Color::kMetallic,
                                         {10.0_kg_per_cu_m},
                                         {10.0_K},
                                         0.1,
                                         {10.0_W},
                                         {10.0_GPa}});
       }}};
};
} // namespace masscalculator::core::materials
#endif // MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_BRASS_H_
