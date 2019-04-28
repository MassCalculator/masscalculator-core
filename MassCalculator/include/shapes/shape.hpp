/**
 * @file shape.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief TODO add brief
 * @version 0.1
 * @date 2019-04-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef ___SHAPE_H___
#define ___SHAPE_H___
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

#include "../3rdParty/include/units.h"
//#include "units.h"

/**
 * @brief 
 * 
 */
namespace MassCalculator
{
  /**
   * @brief 
   * 
   */
  template<typename TShapeType>
  class Shape 
  {
    public:
    enum class Type : uint8_t
    {
      Cylinder = 0,
      Pipe,
      Hexagon,
      Octagon
    };

    Shape(void) = default;

    //Check the other Cylinder constructor

    /**
     * @brief Construct a new Shape object
     * 
     */
    Shape(Type type)
    {
      static_cast<TShapeType*>(this)(type);
    };

    /**
     * @brief Set the Size object
     * 
     * @tparam Args 
     * @param args 
     * @return true 
     * @return false 
     */
    template<class... Args>
    bool setSize(const Args&... args)
    {
      static_cast<TShapeType*>(this)->setSize(args...);

      return true;
    }

    /**
     * @brief Get the Radius object
     * 
     * @return const double 
     */
    const double getRadius(void)
    {
      return{static_cast<TShapeType*>(this)->getRadius()}; 
    }

    /**
     * @brief Get the Diameter object
     * 
     * @return const double 
     */
    const double getDiameter(void)
    {
      return{static_cast<TShapeType*>(this)->getDiameter()};
    }

    /**
     * @brief Get the Length object
     * 
     * @return const double 
     */
    const double getLength(void)
    {
      return{static_cast<TShapeType*>(this)->getLength()};
    }

    /**
     * @brief Get the Volume object
     * 
     * @return const double 
     */
    const double getVolume(void)
    {
      return{static_cast<TShapeType*>(this)->getVolume()};
    }

    /**
     * @brief Get the Surface Area object
     * 
     * @return const double 
     */
    const double getSurfaceArea(void)
    {
      return{static_cast<TShapeType*>(this)->getSurfaceArea()};
    }

    //Leave it for now, it needs to be deleted
    double getMass()
    {
      return{static_cast<TShapeType*>(this)->getMass()};
    }

    /**
     * @brief Destroy the Shape object
     * 
     */
    ~Shape(void) = default;

    /**
     * @brief Shift operator template overload, for the base class Shape
     * 
     */
    template <typename TShape>
    friend std::ostream &operator << (std::ostream &os, const Shape<TShape> &obj)
    {
      os << "\n" "Shape" "\n" << obj.thisTShapeType();
      return os;
    }

    private:
    /**
     * @brief Delete copy constructor
     * 
     */
    Shape(const Shape&) = delete;

    /**
     * @brief Set move constructor to default
     * 
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
     * @brief TODO
     * 
     * @return const TShapeType& 
     */
    const TShapeType& thisTShapeType() const { return *static_cast<const TShapeType*>(this); }

  };

}//end namespace MassCalculator
#endif