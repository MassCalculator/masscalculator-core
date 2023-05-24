/**
 * @file cylinder.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains the definition for the cylinder class.
 * The cylinder class holds all the specific properties for the cylinder shape.
 * It inherits from the base class Shape and provides the getters and setters
 * for the cylinder properties.
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
#ifndef MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_SHAPES_CYLINDER_H_
#define MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_SHAPES_CYLINDER_H_
#include <memory>  // for std::unique_ptr
#include <ostream> // fot std::ostream

#include "masscalculator/masscalculator-core/shapes/constants/shape.h" // for shape::k*
#include "masscalculator/masscalculator-core/shapes/shape.h" // for Shape<T>
#include "masscalculator/third_party/units/units.h"          // for units::*

/**
 * @brief MassCalculator Core Shapes namespace
 */
namespace masscalculator::core::shapes {
/**
 * @brief Class Cylinder, that holds all the nessesary information for Cylinder
 * and it's details therefore we can use in the interface
 */
class Cylinder : public Shape<Cylinder> {
  /**
   * @brief Struct with shape specific properties
   */
  using Properties = struct SpecificProperties : GenericProperties {
    /**
     * @brief meter_t Parameter to save radius of the cylinder
     */
    units::length::meter_t radius;

    /**
     * @brief meter_t Parameter to save length of the cylinder
     */
    units::length::meter_t length;

    /**
     * @brief Construct a new Properties object with all three parameters
     * initialized
     */
    SpecificProperties() : radius{0_m}, length{0_m} {}

    /**
     * @brief Construct a new Properties object and set radius and length
     */
    explicit SpecificProperties(units::length::meter_t radius,
                                units::length::meter_t length)
        : radius{radius}, length{length} {}
  };

 public:
  /**
   * @brief Construct a new Cylinder object
   *
   * @param radius Radius of the Cylinder in meter
   * @param length Length of the Cylinder in meter
   */
  explicit Cylinder(units::length::meter_t radius,
                    units::length::meter_t length);

  /**
   * @brief Set the Size object
   *
   * @param radius Radius of the Cylinder in meter
   * @param length Length of the Cylinder in meter
   * @return true If setting the size is successful
   * @return false If setting the size fails
   */
  bool SetSize(units::length::meter_t radius, units::length::meter_t length);

  /**
   * @brief Get the Volume object
   *
   * @return cubic_meter Volume of the Cylinder
   */
  [[nodiscard]] units::volume::cubic_meter_t GetVolume() const;

  /**
   * @brief Get the Surface Area object
   *
   * @return square_meter Surface Are of the Cylinder
   */
  [[nodiscard]] units::area::square_meter_t GetSurfaceArea() const;

  /**
   * @brief Get the type as string
   *
   * @return std::string Type as string
   */
  [[nodiscard]] Type GetType() const;

  /**
   * @brief Destroy the Cylinder object
   */
  ~Cylinder() = default;

  /**
   * @brief Shift operator overload for class Cylinder, this will print all the
   * nessesery informations
   */
  friend std::ostream& operator<<(std::ostream& os, const Cylinder& obj);

  /**
   * @brief Delete copy constructor
   */
  Cylinder(const Cylinder&) = delete;

  /**
   * @brief Set move constructor to default
   */
  Cylinder(Cylinder&&) = default;

  /**
   * @brief Delete assignment operator
   */
  Cylinder& operator=(const Cylinder&) = delete;

  /**
   * @brief Allow move assignment operator
   */
  Cylinder& operator=(Cylinder&&) = default;

 private:
  /**
   * @brief Function to return the class name, not the pointer of the class, I
   * am trying to keep away this function outside of the class
   *
   * @return std::string Class name as a string
   */
  [[nodiscard]] inline constexpr auto GetClassName() const {
    return constants::shape::kCylinder;
  };

  /**
   * @brief Function to set the calculated propertie values
   *
   * @return true If properties are correctly set
   * @return false If properties have failed to set
   */
  bool SetGenericProperties();

  /**
   * @brief Get the Radius object
   *
   * @return meter_t Radius of the Cylinder
   */
  [[nodiscard]] units::length::meter_t GetRadius() const;

  /**
   * @brief Get the Length object
   *
   * @return meter_t Length of the Cylinder
   */
  [[nodiscard]] units::length::meter_t GetLength() const;

  /**
   * @brief Properties struct to hold the specific object properties
   */
  std::unique_ptr<SpecificProperties> properties_;
};
} // namespace masscalculator::core::shapes
#endif // MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_SHAPES_CYLINDER_H_
