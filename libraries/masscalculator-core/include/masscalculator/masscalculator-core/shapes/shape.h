/**
 * @file shape.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains the base class for Shapes.
 * This class is inherited by all Shape types and provides the prototypes
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
#ifndef MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_SHAPES_SHAPE_H_
#define MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_SHAPES_SHAPE_H_
#include <functional>    // for std::function
#include <string_view>   // for std::string_view
#include <unordered_map> // for std::unordered_map

#include "masscalculator/masscalculator-base/immutable_map.h" // for ImmutableMap
#include "masscalculator/masscalculator-core/shapes/constants/shape.h" // for shape::k*
#include "masscalculator/third_party/units/units.h" // for units::*

// NOLINTNEXTLINE(google-global-names-in-headers,google-build-using-namespace)
using namespace units::literals;

/**
 * @brief Default Shapes namespace
 */
namespace masscalculator::core::shapes {
/**
 * @brief Writing repeated static_casts in CRTP base classes quickly becomes
 * cumbersome, as it does not add much meaning to the code. With this template
 * struct, I get rid of it and handled both const and non-const cases
 *
 * @tparam TShape Shape type template argument
 */
template <typename TShape>
struct Crtp {
  /**
   * @brief
   *
   * @return TShape&
   */
  TShape& ShapeType() { return static_cast<TShape&>(*this); }

  /**
   * @brief
   *
   * @return TShape const&
   */
  TShape const& ShapeType() const { return static_cast<TShape const&>(*this); }
};

/**
 * @brief Template base class Shape
 *
 */
template <typename TShapeType>
class Shape : public Crtp<TShapeType> {
 public:
  /**
   * @brief Enumeration that holds the material colors.
   */
  enum class Type : uint8_t {
    kBegin = 0,
    kAngle = kBegin,
    kBar,
    kBeam,
    kChannel,
    kCylinder,
    kDxfShape,
    kEllipse,
    kHexagonBar,
    kOctagonBar,
    kPipe,
    kSheet,
    kSquareBar,
    kSquareTubing,
    kStlShape,
    kTBar,
    kUnspecified,
    kEnd = kUnspecified
  };

  /**
   * @brief Struct with generic shape properties
   */
  using GenericProperties = struct GenericProperties {
    /**
     * @brief Type The parameter to save the specific type
     */
    Type type;

    /**
     * @brief cubic_meter_t Parameter to save calculated volume
     */
    units::volume::cubic_meter_t volume;

    /**
     * @brief square_meter_t Parameter to save calculated surface_area
     */
    units::area::square_meter_t surface_area;

    /**
     * @brief Construct a new GenericProperties object with all parameters
     * initialized
     */
    GenericProperties()
        : type{Type::kUnspecified}, volume{0_cu_m}, surface_area{0_sq_m} {}

    /**
     * @brief Construct a new GenericProperties object through initializer list
     */
    explicit GenericProperties(Type type, units::volume::cubic_meter_t volume,
                               units::area::square_meter_t surface_area)
        : type{type}, volume{volume}, surface_area{surface_area} {}
  };

  /**
   * @brief Construct a new Shape object
   */
  Shape() = default;

  /**
   * @brief Construct a new Shape object
   *
   * @param type Type of the Shape
   */
  template <class... Args>
  explicit Shape(const Args&... args) {
    this->ShapeType()(args...);
  }
  /**
   * @brief Set the Size object
   *
   * @tparam Args Variable argument parsing
   * @param args Arguments parsed to set the size, acording to the shape
   * specified
   * @return true If the size is set successfully
   * @return false If the size failed to set
   */
  template <class... Args>
  constexpr bool SetSize(const Args&... args) {
    return this->ShapeType().SetSize(args...);
  }

  /**
   * @brief Get the Type object
   *
   * @return Type Type of the Shape from Derived class
   */
  [[nodiscard]] constexpr Type GetType() const {
    return this->ShapeType().GetType();
  }

  /**
   * @brief Get the Volume object
   *
   * @return cubic_meter_t Volume of the Shape from Derived class
   */
  [[nodiscard]] constexpr units::volume::cubic_meter_t GetVolume() const {
    return this->ShapeType().GetVolume();
  }

  /**
   * @brief Get the Surface Area object
   *
   * @return square_meter_t Surface Area of the Shape from Derived class
   */
  [[nodiscard]] constexpr units::area::square_meter_t GetSurfaceArea() const {
    return this->ShapeType().GetSurfaceArea();
  }

  /**
   * @brief Destroy the Shape object
   */
  ~Shape() = default;

  /**
   * @brief Delete copy constructor
   */
  Shape(const Shape&) = delete;

  /**
   * @brief Set move constructor to default
   */
  Shape(Shape&&) = default;

  /**
   * @brief Delete assignment operator
   */
  Shape& operator=(const Shape&) = delete;

  /**
   * @brief Allow move assignment operator
   */
  Shape& operator=(Shape&&) = default;

  /**
   * @brief Function to return "this" derived object
   *
   * @return const TShapeType&
   */
  const TShapeType& ThisTShapeType() const {
    return *static_cast<const TShapeType*>(this);
  }

  /**
   * @brief Shift operator template overload, for the base class Shape
   */
  friend std::ostream& operator<<(std::ostream& os,
                                  const Shape<TShapeType>& obj) {
    os << "Shape " << obj.ThisTShapeType();
    return os;
  }

  friend std::ostream& operator<<(std::ostream& os,
                                  const Shape<TShapeType>::Type& shape) {
    os << kTypeString.at(shape);

    return os;
  }

 protected:
  /**
   * @brief A map used to convert a string representation of a shape to an enum
   * value.
   */
  static constexpr base::ImmutableMap<std::string_view, Type, 16> kType{
      {{{constants::shape::kAngle, Type::kAngle},
        {constants::shape::kBar, Type::kBar},
        {constants::shape::kBeam, Type::kBeam},
        {constants::shape::kChannel, Type::kChannel},
        {constants::shape::kCylinder, Type::kCylinder},
        {constants::shape::kDxfShape, Type::kDxfShape},
        {constants::shape::kEllipse, Type::kEllipse},
        {constants::shape::kHexagonBar, Type::kHexagonBar},
        {constants::shape::kOctagonBar, Type::kOctagonBar},
        {constants::shape::kPipe, Type::kPipe},
        {constants::shape::kSheet, Type::kSheet},
        {constants::shape::kSquareBar, Type::kSquareBar},
        {constants::shape::kSquareTubing, Type::kSquareTubing},
        {constants::shape::kStlShape, Type::kStlShape},
        {constants::shape::kTBar, Type::kTBar},
        {constants::shape::kUnspecified, Type::kUnspecified}}}};

  /**
   * @brief A map used to convert an enum value of type Type to its string
   * representation.
   */
  static constexpr base::ImmutableMap<Type, std::string_view, 16> kTypeString{
      {{{Type::kAngle, constants::shape::kAngle},
        {Type::kBar, constants::shape::kBar},
        {Type::kBeam, constants::shape::kBeam},
        {Type::kChannel, constants::shape::kChannel},
        {Type::kCylinder, constants::shape::kCylinder},
        {Type::kDxfShape, constants::shape::kDxfShape},
        {Type::kEllipse, constants::shape::kEllipse},
        {Type::kHexagonBar, constants::shape::kHexagonBar},
        {Type::kOctagonBar, constants::shape::kOctagonBar},
        {Type::kPipe, constants::shape::kPipe},
        {Type::kSheet, constants::shape::kSheet},
        {Type::kSquareBar, constants::shape::kSquareBar},
        {Type::kSquareTubing, constants::shape::kSquareTubing},
        {Type::kStlShape, constants::shape::kStlShape},
        {Type::kTBar, constants::shape::kTBar},
        {Type::kUnspecified, constants::shape::kUnspecified}}}};
};
} // namespace masscalculator::core::shapes
#endif // MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_SHAPES_SHAPE_H_