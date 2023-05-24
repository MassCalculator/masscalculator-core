/**
 * @file object_interface.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains the definition for the Object class.
 * The Object class holds all the properties for an object.
 * @version 0.2
 * @date 2023-04-13
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
#ifndef MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_INTERFACE_OBJECT_INTERFACE_H_
#define MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_INTERFACE_OBJECT_INTERFACE_H_
#include <memory>    // for std::make_unique
#include <stdexcept> // for std::runtime_error

#include "masscalculator/masscalculator-base/macro_logger.h" // for LOG_*
#include "masscalculator/third_party/units/units.h"          // for units::*

// NOLINTNEXTLINE(google-global-names-in-headers,google-build-using-namespace)
using namespace units::literals;

/**
 * @brief MassCalculator Core Interface namespace
 */
namespace masscalculator::core::interface {
/**
 * @brief  Class Object, that holds all the nessesary information from Material
 * and Shape classes
 *
 * @tparam TShape Shape class object
 * @tparam TMaterial Material class object
 */
template <typename TShape, typename TMaterial>
class Object {
 public:
  /**
   * @brief Struct with object specific properties
   */
  using ObjectProperties = struct ObjectProperties {
    units::mass::kilogram_t mass;

    /**
     * @brief Construct a new Properties object with all parameters initialized
     */
    ObjectProperties() : mass{0_kg} {}

    /**
     * @brief Construct a new Properties object through initializer list
     */
    explicit ObjectProperties(units::mass::kilogram_t mass) : mass{mass} {}
  };

  /**
   * @brief Construct a new Object object
   */
  Object() = delete;

  /**
   * @brief Construct a new Object object
   *
   * @param shape Constructed shape object
   * @param material Constructed material object
   */
  explicit Object(const std::unique_ptr<TShape>& shape,
                  const std::unique_ptr<TMaterial>& material);

  constexpr bool SetProperties(const std::unique_ptr<TShape>& shape,
                               const std::unique_ptr<TMaterial>& material);

  /**
   * @brief Get the mass object
   *
   * @return kilogram_t  The calculated mass for specific object and shape
   */
  [[nodiscard]] constexpr units::mass::kilogram_t GetMass() const;

  /**
   * @brief Destroy the Object object
   */
  ~Object() = default;

  /**
   * @brief Delete copy constructor
   */
  Object(const Object&) = delete;

  /**
   * @brief Set move constructor to default
   */
  Object(Object&&) = default;

  /**
   * @brief Delete assignment operator
   */
  Object& operator=(const Object&) = delete;

  /**
   * @brief Allow move assignment operator
   */
  Object& operator=(Object&&) = default;

  /**
   * @brief Function to return "this" derived object
   *
   * @return const TShapeType&
   */
  const Object& ThisObjectType() const {
    return *static_cast<const Object*>(this);
  }

  /**
   * @brief Shift operator overload for class Object, this will print all the
   * calculated properties
   */
  template <typename UShape, typename UMaterial>
  friend std::ostream& operator<<(std::ostream& os,
                                  const Object<UShape, UMaterial>& obj);

 private:
  /**
   * @brief Properties struct to hold the calculated object properties
   */
  std::unique_ptr<ObjectProperties> object_properties_;
};

template <typename TShape, typename TMaterial>
Object<TShape, TMaterial>::Object(const std::unique_ptr<TShape>& shape,
                                  const std::unique_ptr<TMaterial>& material)
    : object_properties_(std::make_unique<ObjectProperties>()) {
  if (object_properties_ == nullptr) {
    throw std::runtime_error{"Object<T, U> failed to initialize..."};
  }

  if (const auto success = SetProperties(shape, material); !success) {
    LOG_ERROR("Construction of the object failed. %s", __PRETTY_FUNCTION__);
    throw std::runtime_error{"Object<T, U> failed to initialize..."};
  }
};

template <typename TShape, typename TMaterial>
constexpr bool Object<TShape, TMaterial>::SetProperties(
    const std::unique_ptr<TShape>& shape,
    const std::unique_ptr<TMaterial>& material) {
  if (shape == nullptr || material == nullptr) {
    LOG_ERROR("Could not set the properties for object.");
    return false;
  }

  object_properties_->mass =
      shape->GetVolume() * material->GetSpecificDensity();

  return true;
}

template <typename TShape, typename TMaterial>
[[nodiscard]] constexpr units::mass::kilogram_t
Object<TShape, TMaterial>::GetMass() const {
  return object_properties_->mass;
};

template <typename TShape, typename TMaterial>
std::ostream& operator<<(std::ostream& os,
                         const Object<TShape, TMaterial>& obj) {
  os << "Object properties: ";
  os << "\n  - Mass: ";
  os << units::mass::to_string(obj.GetMass());
  os << "\n";
  return os;
};
} // namespace masscalculator::core::interface
#endif // MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_INTERFACE_OBJECT_INTERFACE_H_
