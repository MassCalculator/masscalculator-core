/**
 * @file material.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This class is the base class for the Materials, this will be inherited
 * from all the Material types, and holds the prototypes so the derived classes
 * can be accessed from it's object pointer
 * @version 0.2
 * @date 2020-03-28
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef ___MATERIAL_H___
#define ___MATERIAL_H___
#include <functional>     // for std::function
#include <unordered_map>  // for std::unordered_map

#include "units.h"  // for units::*

/**
 * @brief Default Materials namespace
 */
namespace masscalculator::materials {
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
class Material : Crtp<TMaterialType> {
 public:
  enum class Type : uint8_t;

  enum class Color : uint8_t { kBegin = 0, kMetallic = kBegin, kDarkTone };

 public:
  /**
   * @brief Construct a new Material object
   *
   */
  Material() = default;

  /**
   * @brief Construct a new Material object
   *
   * @param type Type of the Material
   */
  explicit Material(const Type& type) { this->MaterialType()(type); }

  /**
   * @brief Init the Lua config file
   *
   */
  bool InitLuaScript() {
    this->MaterialType()->InitLuaScript();
    return true;
  }

  /**
   * @brief Set the Type object
   *
   * @param type Type of the Material
   * @return true If the type is set successfully
   * @return false If the type failed to set
   */
  bool SetType(const Type& type) {
    this->MaterialType()->SetType(type);
    return true;
  }

  /**
   * @brief Get the Type object
   *
   * @return const std::pair<std::string, Type> Pair with type name and type
   * enum from Derived class
   */
  constexpr std::pair<std::string, Type> GetType() const {
    return std::make_pair(this->MaterialType()->GetType());
  }

  /**
   * @brief Get the Specific Color object
   *
   * @return const std::string Color of the material from Derived class
   */
  [[nodiscard]] constexpr Color GetSpecificColor() const {
    return {this->MaterialType()->GetSpecificColor()};
  }

  /**
   * @brief Get the Specific Density object
   *
   * @return kilograms_per_cubic_meter_t Density of the material from Derived
   * class
   */
  [[nodiscard]] constexpr units::density::kilograms_per_cubic_meter_t
  GetSpecificDensity() const {
    return {this->MaterialType()->GetSpecificDensity()};
  }

  /**
   * @brief Get the Specific Gravity object
   *
   * @return meters_per_second_squared_t Gravity of the material from Derived
   * class
   */
  [[nodiscard]] constexpr units::acceleration::meters_per_second_squared_t
  GetSpecificGravity() const {
    return {this->MaterialType()->GetSpecificGravity()};
  }

  /**
   * @brief Get the Specific Melting Point object
   *
   * @return kelvin_t The specific melting point of Material type from Derived
   * class
   */
  [[nodiscard]] constexpr units::temperature::kelvin_t GetSpecificMeltingPoint()
      const {
    return {this->MaterialType()->GetSpecificMeltingPoint()};
  }

  /**
   * @brief Get the Specific PoissonsRatio object
   *
   * @return double The specific poissons ratio of Material type from Derived
   * class
   */
  [[nodiscard]] constexpr double GetSpecificPoissonsRatio() const {
    return {this->MaterialType()->GetSpecificPoissonsRatio()};
  }

  /**
   * @brief Get the Specific Thermal Conductivity object
   *
   * @return watt_t The specific thermal conductivity of Material type from
   * Derived class
   */
  [[nodiscard]] constexpr units::power::watt_t GetSpecificThermalConductivity()
      const {
    return {this->MaterialType()->GetSpecificThermalConductivity()};
  }

  /**
   * @brief Get the Specific Modulus of Elasticity Tension object
   *
   * @return pascal_t The specific modulus of elasticity tension point of
   * Material type from Derived class
   */
  [[nodiscard]] constexpr units::pressure::pascal_t
  GetSpecificModOfElasticityTension() const {
    return {this->MaterialType()->GetSpecificModOfElasticityTension()};
  }

  /**
   * @brief Destroy the Material object
   *
   */
  ~Material() = default;

  /**
   * @brief Delete copy constructor
   *
   */
  Material(const Material&) = delete;

  /**
   * @brief Set move constructor to default
   *
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
   *
   */
  template <typename TMaterial>
  friend std::ostream& operator<<(std::ostream& os,
                                  const Material<TMaterialType>& obj);
};

template <typename TMaterial>
std::ostream& operator<<(std::ostream& os, const Material<TMaterial>& obj) {
  // @todo(jimmyhalimi): This causes segmentation fault, it works if you comment
  // out headers in materials.hh and you move implementation in the class
  // @todo@(jimmyhalimi): Update: The error is caused in interface when calling
  // with make unique base object.
  os << "\nMaterial\n" << obj.ThisTMaterialType();
  return os;
}
}  // namespace masscalculator::materials
#endif  //___MATERIAL_H___