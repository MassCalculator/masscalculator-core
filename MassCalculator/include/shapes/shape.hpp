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

#include <dxflib/dl_dxf.h>

//TODO: Check the units library, and the include_directories in CMake
//#include "../3rdParty/include/units.h"
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
    //TODO: Add a properties struct, according to the type for a specific shape
    public:
    /**
     * @brief Enum that holds all the Shapes that are available to use
     * TODO: Check the shapes, and see how we can use this to set the shape, maybe use a stdLLpair with the shape and shape name
     * 
     */
    enum class Type : uint8_t
    {
      BEGIN = 0,
      SquareBar = BEGIN,
      Bar,
      Cylinder,
      SquareTubing,
      Pipe,
      Ellipse,
      TBar,
      Beam,
      Channel,
      Angle,
      HexagonBar,
      OctagonBar,
      Sheet,
      UNSPECIFIED,
      END
    };

    friend std::ostream& operator<<(std::ostream& os, Type type)
    {
        switch(type)
        {
            case Type::SquareBar: os << "SquareBar"; break;
            case Type::Bar: os << "Bar"; break;
            case Type::Cylinder: os << "Cylinder"; break;
            case Type::SquareTubing: os << "SquareTubing"; break;
            case Type::Pipe: os << "Pipe"; break;
            case Type::Ellipse: os << "Ellipse"; break;
            case Type::TBar: os << "TBar"; break;
            case Type::Beam: os << "Beam"; break;
            case Type::Channel: os << "Channel"; break;
            case Type::Angle: os << "Angle"; break;
            case Type::HexagonBar: os << "HexagonBar"; break;
            case Type::OctagonBar: os << "OctagonBar"; break;
            case Type::Sheet: os << "Sheet"; break;
            case Type::UNSPECIFIED: os << "UNSPECIFIED"; break;
            default: os << "Name cannot be found";
        }
        return os;
    }

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
    constexpr double getRadius(void)
    {
      return{static_cast<TShapeType*>(this)->getRadius()}; 
    }

    /**
     * @brief Get the Diameter object
     * 
     * @return const double Diameter of the Shape from Derived class
     */
    constexpr double getDiameter(void)
    {
      return{static_cast<TShapeType*>(this)->getDiameter()};
    }

    /**
     * @brief Get the Length object
     * 
     * @return const double Length of the Shape from Derived class
     */
    constexpr double getLength(void)
    {
      return{static_cast<TShapeType*>(this)->getLength()};
    }

    /**
     * @brief Get the Volume object
     * 
     * @return const double Volume of the Shape from Derived class
     */
    constexpr double getVolume(void)
    {
      return{static_cast<TShapeType*>(this)->getVolume()};
    }

    /**
     * @brief Get the Surface Area object
     * 
     * @return const double Surface Area of the Shape from Derived class
     */
    constexpr double getSurfaceArea(void)
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

  template <>
  class Shape<int> 
  { 
    public:
      enum class Type : uint8_t
      {
        BEGIN = 0,
        Cylinder = BEGIN,
        Pipe,
        Hexagon,
        Octagon,
        UNSPECIFIED,
        END
      };

      friend std::ostream& operator<<(std::ostream& os, Type type)
      {
          switch(type)
          {
              case Type::Cylinder: os << "Cylinder"; break;
              case Type::Pipe: os << "Pipe"; break;
              case Type::Hexagon: os << "Hexagon"; break;
              case Type::Octagon: os << "Octagon"; break;
              case Type::UNSPECIFIED: os << "UNSPECIFIED"; break;
              default: os << "Name cannot be found";
          }
          return os;
      }
  };

}//end namespace MassCalculator
#endif