/**
 * @file material.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains the base class for Materials.
 * This class is inherited by all Material types and provides the prototypes
 * for the derived classes to be accessed from its object pointer.
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
#ifndef MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_MATERIAL_H_
#define MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_MATERIAL_H_
#include <functional>    // for std::function
#include <string_view>   // for std::string_view
#include <unordered_map> // for std::unordered_map

#include "masscalculator/masscalculator-base/immutable_map.h" // for ImmutableMap
#include "masscalculator/masscalculator-base/lua_handler.h" // for LuaScriptHandler
#include "masscalculator/masscalculator-core/materials/constants/color.h" // for color::k*
#include "masscalculator/masscalculator-core/materials/constants/properties.h" // for properties::k*
#include "masscalculator/third_party/units/units.h" // for units::*

// NOLINTNEXTLINE(google-global-names-in-headers,google-build-using-namespace)
using namespace units::literals;

/**
 * @brief MassCalculator Core Materials namespace
 */
namespace masscalculator::core::materials {
/**
 * @brief Writing repeated static_casts in CRTP base classes quickly becomes
 * cumbersome, as it does not add much meaning to the code. With this template
 * struct, I get rid of it and handled both const and non-const cases
 *
 * @tparam TMaterial Material type template argument
 */
template <typename TMaterial>
struct Crtp {
  /**
   * @brief
   *
   * @return TMaterial&
   */
  TMaterial& MaterialType() { return static_cast<TMaterial&>(*this); }

  /**
   * @brief
   *
   * @return TMaterial const&
   */
  TMaterial const& MaterialType() const {
    return static_cast<TMaterial const&>(*this);
  }
};

/**
 * @brief Template base class Material
 *
 */
template <typename TMaterialType>
class Material : public Crtp<TMaterialType> {
 public:
  /**
   * @brief Enumeration that holds the material colors.
   */
  enum class Color : uint8_t {
    kBegin = 0,
    kMetallic = kBegin,
    kDarkTone,
    kUnspecified,
    kEnd = kUnspecified
  };

  /**
   * @brief Struct with material specific properties
   */
  using Properties = struct Properties {
    /**
     * @brief TMaterialType::Type The parameter to save the specific type
     */
    typename TMaterialType::Type type;

    /**
     * @brief Color Parameter to save specific color
     */
    Color color;

    /**
     * @brief kilograms_per_cubic_meter_t Parameter to save specific density
     */
    units::density::kilograms_per_cubic_meter_t density;

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
        : type{TMaterialType::Type::kUnspecified},
          color{Color::kUnspecified},
          density{0_kg_per_cu_m},
          melting_point{0_K},
          poissons_ratio{0},
          thermal_conductivity{0_W},
          mod_of_elasticity_tension{0_Pa} {}

    /**
     * @brief Construct a new Properties object through initializer list
     */
    explicit Properties(typename TMaterialType::Type type, Color color,
                        units::density::kilograms_per_cubic_meter_t density,
                        units::temperature::kelvin_t melting_point,
                        double poissons_ratio,
                        units::power::watt_t thermal_conductivity,
                        units::pressure::pascal_t mod_of_elasticity_tension)
        : type{type},
          color{color},
          density{density},
          melting_point{melting_point},
          poissons_ratio{poissons_ratio},
          thermal_conductivity{thermal_conductivity},
          mod_of_elasticity_tension{mod_of_elasticity_tension} {}
  };

  /**
   * @brief Construct a new Material object
   */
  Material() = default;

  /**
   * @brief Construct a new Material object
   *
   * @param type Type of the Material
   */
  explicit Material(const std::string_view& type) {
    this->MaterialType()(type);
  }

  /**
   * @brief Get the Type object
   *
   * @return std::string_view Type of the Material
   */
  [[nodiscard]] constexpr std::string_view GetType() const {
    return this->MaterialType().kTypeString.at(specific_properties->type);
  }

  /**
   * @brief Get the Specific Color object
   *
   * @return Color Color of the material
   */
  [[nodiscard]] constexpr Color GetSpecificColor() const {
    return specific_properties->color;
  }

  /**
   * @brief Get the Specific Density object
   *
   * @return kilograms_per_cubic_meter_t Density of the material
   */
  [[nodiscard]] constexpr units::density::kilograms_per_cubic_meter_t
  GetSpecificDensity() const {
    return {specific_properties->density};
  }

  /**
   * @brief Get the Specific Melting Point object
   *
   * @return kelvin_t The specific melting point of TMaterialType type
   */
  [[nodiscard]] constexpr units::temperature::kelvin_t GetSpecificMeltingPoint()
      const {
    return {specific_properties->melting_point};
  }

  /**
   * @brief Get the Specific PoissonsRatio object
   *
   * @return double The specific poissons ratio of TMaterialType type
   */
  [[nodiscard]] constexpr double GetSpecificPoissonsRatio() const {
    return specific_properties->poissons_ratio;
  }

  /**
   * @brief Get the Specific Thermal Conductivity object
   *
   * @return watt_t The specific thermal conductivity of TMaterialType type
   */
  [[nodiscard]] constexpr units::power::watt_t GetSpecificThermalConductivity()
      const {
    return {specific_properties->thermal_conductivity};
  }

  /**
   * @brief Get the Specific Modulus of Elasticity Tension object
   *
   * @return pascal_t The specific modulus of elasticity tension point of
   * TMaterialType type
   */
  [[nodiscard]] constexpr units::pressure::pascal_t
  GetSpecificModOfElasticityTension() const {
    return {specific_properties->mod_of_elasticity_tension};
  }

  /**
   * @brief Set the Propertie Specs object
   *
   * @param type Type of TMaterialType
   * @return true If the specifications of propertie are successfully set
   * @return false  If the specifications of propertie failed to set
   */
  constexpr bool SetType(const std::string_view& type) {
    return this->MaterialType().SetType(type);
  }

  /**
   * @brief Destroy the Material object
   */
  ~Material() = default;

  /**
   * @brief Delete copy constructor
   */
  Material(const Material&) = delete;

  /**
   * @brief Set move constructor to default
   */
  Material(Material&&) = default;

  /**
   * @brief Delete assignment operator
   */
  Material& operator=(const Material&) = delete;

  /**
   * @brief Allow move assignment operator
   */
  Material& operator=(Material&&) = default;

  /**
   * @brief Function to return "this" derived object
   *
   * @return const TMaterialType&
   */
  const TMaterialType& ThisTMaterialType() const {
    return *static_cast<const TMaterialType*>(this);
  }

  /**
   * @brief Shift operator template overload, for the base class Material
   */
  friend std::ostream& operator<<(std::ostream& os,
                                  const Material<TMaterialType>& obj) {
    os << "Material " << obj.ThisTMaterialType();

    return os;
  }

  /**
   * @brief Shift operator overload for class TMaterialType, this will print all
   * the nessesery informations
   */
  friend std::ostream& operator<<(std::ostream& os, const TMaterialType& obj) {
    os << std::string(obj.GetClassName()) + " object properties: ";
    os << "\n  - Type                         : ";
    os << obj.GetType();
    os << "\n  - Color                        : ";
    os << obj.GetSpecificColor();
    os << "\n  - Density                      : ";
    os << units::density::to_string(obj.GetSpecificDensity());
    os << "\n  - Melting point                : ";
    os << units::temperature::to_string(obj.GetSpecificMeltingPoint());
    os << "\n  - Poissons ratio               : ";
    os << std::to_string(obj.GetSpecificPoissonsRatio());
    os << "\n  - Thermal conductivity         : ";
    os << units::power::to_string(obj.GetSpecificThermalConductivity());
    os << "\n  - Modulus of elasticity tension: ";
    os << units::pressure::to_string(obj.GetSpecificModOfElasticityTension());
    os << "\n";

    return os;
  }

  /**
   * @brief Shift operator template overload, for the class Color
   */
  friend std::ostream& operator<<(std::ostream& os,
                                  const Material<TMaterialType>::Color& color) {
    os << kColorString.at(color);

    return os;
  }

 protected:
  /**
   * @brief Function to set the static propertie values
   *
   * @param properties Structure of the constant properties
   * @return true If properties are correctly set
   * @return false If properties have failed to set
   */
  bool SetProperties(const Properties& properties) {
    auto fetch_from_lua_or_default = [&](const std::string& property_name,
                                         auto default_value) {
      using ValueType = decltype(default_value);
      return lua_state->GetOrDefault<ValueType>(
          std::string(this->MaterialType().GetClassName()) + "." +
              std::string(
                  this->MaterialType().kTypeString.at(properties.type)) +
              "." + property_name,
          default_value);
    };

    specific_properties->type =
        this->MaterialType().kType.at(fetch_from_lua_or_default(
            constants::properties::kTypeKey,
            this->MaterialType().kTypeString.at(properties.type)));

    specific_properties->color = kColor.at(fetch_from_lua_or_default(
        constants::properties::kColorKey, kColorString.at(properties.color)));

    specific_properties->density = fetch_from_lua_or_default(
        constants::properties::kDensityKey, properties.density);

    specific_properties->melting_point = fetch_from_lua_or_default(
        constants::properties::kMeltingPointKey, properties.melting_point);

    specific_properties->poissons_ratio = fetch_from_lua_or_default(
        constants::properties::kPoissonsRatioKey, properties.poissons_ratio);

    specific_properties->thermal_conductivity = fetch_from_lua_or_default(
        constants::properties::kThermalConductivityKey,
        properties.thermal_conductivity);

    specific_properties->mod_of_elasticity_tension = fetch_from_lua_or_default(
        constants::properties::kModOfElasticityTensionKey,
        properties.mod_of_elasticity_tension);

    return true;
  }

  /**
   * @brief Properties struct to hold the specific object properties
   */
  std::unique_ptr<Properties> specific_properties;

  /**
   * @brief Lua Handler object to get the config for metals from LuaScript is
   * necessary
   */
  std::unique_ptr<base::LuaScriptHandler> lua_state;

  /**
   * @brief A map used to convert a string representation of a color to an enum
   * value.
   */
  static constexpr base::ImmutableMap<std::string_view, Color, 3> kColor{
      {{{constants::color::kMetallic, Color::kMetallic},
        {constants::color::kDarkTone, Color::kDarkTone},
        {constants::color::kUnspecified, Color::kUnspecified}}}};

  /**
   * @brief A map used to convert an enum value of type Color to its string
   * representation.
   */
  static constexpr base::ImmutableMap<Color, std::string_view, 3> kColorString{
      {{{Color::kMetallic, constants::color::kMetallic},
        {Color::kDarkTone, constants::color::kDarkTone},
        {Color::kUnspecified, constants::color::kUnspecified}}}};
};
} // namespace masscalculator::core::materials
#endif // MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_MATERIAL_H_
