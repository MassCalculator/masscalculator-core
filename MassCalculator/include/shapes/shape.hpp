/**
 * @file shape.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This class is the base class for the Shapes, this will be inherited from all the Shape types, and holds the prototypes
 * so the derived classes can be accessed from it's object pointer
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

//TODO: Check the units library, and the include_directories in CMake
#include "../3rdParty/include/units.h"
//#include "units.h"

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator
{
  /**
   * @brief Template base class Shape
   * 
   */
  template<typename TShapeType>
  class Shape 
  {
    public:
    /**
     * @brief Enum that holds all the Shapes that are available to use
     * TODO: Check the shapes, and see how we can use this to set the shape, maybe use a stdLLpair with the shape and shape name
     * 
     */
    enum class Type : uint8_t
    {
      Cylinder = 0,
      Pipe,
      Hexagon,
      Octagon
    };

    Shape(void) = default;

    //TODO: Check the other Cylinder constructor, and add it here, also use the enum, and if cylinder is selected, allow to use this
    //Also add this kind of style for other shapes too, so we can choose between constructor with args, or empty constructor and then set the sizes
    //Cylinder(double diameter, double length);

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
     * @tparam Args Variable argument parsing
     * @param args Arguments parsed to set the size, acording to the shape specified
     * @return true If the size is set successfully
     * @return false If the size failed to set
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
     * @return const double Radius of the Shape from Derived class
     */
    const double getRadius(void)
    {
      return{static_cast<TShapeType*>(this)->getRadius()}; 
    }

    /**
     * @brief Get the Diameter object
     * 
     * @return const double Diameter of the Shape from Derived class
     */
    const double getDiameter(void)
    {
      return{static_cast<TShapeType*>(this)->getDiameter()};
    }

    /**
     * @brief Get the Length object
     * 
     * @return const double Length of the Shape from Derived class
     */
    const double getLength(void)
    {
      return{static_cast<TShapeType*>(this)->getLength()};
    }

    /**
     * @brief Get the Volume object
     * 
     * @return const double Volume of the Shape from Derived class
     */
    const double getVolume(void)
    {
      return{static_cast<TShapeType*>(this)->getVolume()};
    }

    /**
     * @brief Get the Surface Area object
     * 
     * @return const double Surface Area of the Shape from Derived class
     */
    const double getSurfaceArea(void)
    {
      return{static_cast<TShapeType*>(this)->getSurfaceArea()};
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
     * @brief Function to return "this" derived object
     * 
     * @return const TShapeType& 
     */
    const TShapeType& thisTShapeType() const { return *static_cast<const TShapeType*>(this); }

  };

}//end namespace MassCalculator
#endif