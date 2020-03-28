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
  namespace Constants
  {
    const std::string  SquareBar{"SquareBar"};
    const std::string  Bar{"Bar"};
    const std::string  Cylinder{"Cylinder"};
    const std::string  SquareTubing{"SquareTubing"};
    const std::string  Pipe{"Pipe"};
    const std::string  Ellipse{"Ellipse"};
    const std::string  TBar{"TBar"};
    const std::string  Beam{"Beam"};
    const std::string  Channel{"Channel"};
    const std::string  Angle{"Angle"};
    const std::string  HexagonBar{"HexagonBar"};
    const std::string  OctagonBar{"OctagonBar"};
    const std::string  Sheet{"Sheet"};
    const std::string  S_UNSPECIFIED{"S_UNSPECIFIED"};
  }

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
          case Type::SquareBar: os << Constants::SquareBar; break;
          case Type::Bar: os << Constants::Bar; break;
          case Type::Cylinder: os << Constants::Cylinder; break;
          case Type::SquareTubing: os << Constants::SquareTubing; break;
          case Type::Pipe: os << Constants::Pipe; break;
          case Type::Ellipse: os << Constants::Ellipse; break;
          case Type::TBar: os << Constants::TBar; break;
          case Type::Beam: os << Constants::Beam; break;
          case Type::Channel: os << Constants::Channel; break;
          case Type::Angle: os << Constants::Angle; break;
          case Type::HexagonBar: os << Constants::HexagonBar; break;
          case Type::OctagonBar: os << Constants::OctagonBar; break;
          case Type::Sheet: os << Constants::Sheet; break;
          case Type::UNSPECIFIED: os << Constants::S_UNSPECIFIED; break;
          default: os << "Name cannot be found";
        }
        return os;
    }
#if 0

static_cast<TShapeType*>(this)->getType()

#endif
    Shape(void)
    {
      // thisTShapeType();
      // type_ = formatStringToEnum(thisTShapeType().getType());

      // switch(type_)
      // {
      //   case Type::SquareBar:
      //   {
      //     std::cout << "SquareBar Set Case\n";
      //     break;
      //     [[fallthrough]];
      //   }
      //   case Type::Bar:
      //   {
      //     std::cout << "Bar Set Case\n";
      //     break;
      //     [[fallthrough]];
      //   }
      //   case Type::Cylinder:
      //   {
      //     std::cout << "Cylinder Set Case\n";
      //     break;
      //     [[fallthrough]];
      //   }
      //   case Type::SquareTubing:
      //   {
      //     std::cout << "SquareTubing Set Case\n";
      //     break;
      //     [[fallthrough]];
      //   }
      //   case Type::Pipe:
      //   {
      //     std::cout << "Pipe Set Case\n";
      //     break;
      //     [[fallthrough]];
      //   }
      //   case Type::Ellipse:
      //   {
      //     std::cout << "Ellipse Set Case\n";
      //     break;
      //     [[fallthrough]];
      //   }
      //   case Type::TBar:
      //   {
      //     std::cout << "TBar Set Case\n";
      //     break;
      //     [[fallthrough]];
      //   }
      //   case Type::Beam:
      //   {
      //     std::cout << "Beam Set Case\n";
      //     break;
      //     [[fallthrough]];
      //   }
      //   case Type::Channel:
      //   {
      //     std::cout << "Channel Set Case\n";
      //     break;
      //     [[fallthrough]];
      //   }
      //   case Type::Angle:
      //   {
      //     std::cout << "Angle Set Case\n";
      //     break;
      //     [[fallthrough]];
      //   }
      //   case Type::HexagonBar:
      //   {
      //     std::cout << "HexagonBar Set Case\n";
      //     break;
      //     [[fallthrough]];
      //   }
      //   case Type::OctagonBar:
      //   {
      //     std::cout << "OctagonBar Set Case\n";
      //     break;
      //     [[fallthrough]];
      //   }
      //   case Type::Sheet:
      //   {
      //     std::cout << "Sheet Set Case\n";
      //     break;
      //     [[fallthrough]];
      //   }
      //   case Type::UNSPECIFIED:
      //   {
      //     std::cout << "UNSPECIFIED Set Case\n";
      //     break;
      //     [[fallthrough]];
      //   }
      //   default:
      //   {
      //     std::cout << "Default Set Case: " << type_ << std::endl;
      //     break;
      //     [[fallthrough]];
      //   }
      // }
    }

    //TODO: Check the other Cylinder constructor, and add it here, also use the enum, and if cylinder is selected, allow to use this
    //Also add this kind of style for other shapes too, so we can choose between constructor with args, or empty constructor and then set the sizes
    //Cylinder(double diameter, double length);

    // /**
    //  * @brief Construct a new Shape object
    //  * 
    //  */
    // Shape(Type type)
    // {
    //   static_cast<TShapeType*>(this)(type);
    // };

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
    double getRadius(void)
    {
      return{static_cast<TShapeType*>(this)->getRadius()}; 
    }

    /**
     * @brief Get the Type object
     * 
     * @return const string Type of the Shape from Derived class
     */
    std::string getType(void)
    {
      return{static_cast<TShapeType*>(this)->getType()};
    }

    /**
     * @brief Get the Diameter object
     * 
     * @return const double Diameter of the Shape from Derived class
     */
    double getDiameter(void)
    {
      return{static_cast<TShapeType*>(this)->getDiameter()};
    }

    /**
     * @brief Get the Length object
     * 
     * @return const double Length of the Shape from Derived class
     */
    double getLength(void)
    {
      return{static_cast<TShapeType*>(this)->getLength()};
    }

    /**
     * @brief Get the Volume object
     * 
     * @return const double Volume of the Shape from Derived class
     */
    double getVolume(void)
    {
      return{static_cast<TShapeType*>(this)->getVolume()};
    }

    /**
     * @brief Get the Surface Area object
     * 
     * @return const double Surface Area of the Shape from Derived class
     */
    double getSurfaceArea(void)
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

    public:
    /**
     * @brief Delete copy constructor
     * 
     */
    Shape(const Shape&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    public: Shape(Shape&&) = default;

    /**
     * @brief Delete assignment operator
     */
    Shape& operator=(const Shape&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    Shape& operator=(Shape&&) = default;

    Type formatStringToEnum(std::string format) 
    {
      return previewFormatToEnum(format);
    }

    Type previewFormatToEnum(const std::string format) 
    {
      return
        !format.c_str() ?
          Type::UNSPECIFIED :
          !format.compare(Constants::SquareBar) ?
            Type::SquareBar :
          !format.compare(Constants::Bar) ?
            Type::Bar :
          !format.compare(Constants::Cylinder) ?
            Type::Cylinder :
          !format.compare(Constants::SquareTubing) ?
            Type::SquareTubing :
          !format.compare(Constants::Pipe) ?
            Type::Pipe :
          !format.compare(Constants::Ellipse) ?
            Type::Ellipse :
          !format.compare(Constants::TBar) ?
            Type::TBar :
          !format.compare(Constants::Beam) ?
            Type::Beam :
          !format.compare(Constants::Channel) ?
            Type::Channel :
          !format.compare(Constants::Angle) ?
            Type::Angle :
          !format.compare(Constants::HexagonBar) ?
            Type::HexagonBar :
          !format.compare(Constants::OctagonBar) ?
            Type::OctagonBar :
          !format.compare(Constants::Sheet) ?
            Type::Sheet :
          !format.compare(Constants::S_UNSPECIFIED) ?
            Type::UNSPECIFIED : 
        Type::UNSPECIFIED;
    }

    /**
     * @brief Function to return "this" derived object
     * 
     * @return const TShapeType& 
     */
    const TShapeType& thisTShapeType() const { return *static_cast<const TShapeType*>(this); }

    Type type_;

  };

  template <>
  class Shape<int> 
  { 
    public:
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
          case Type::SquareBar: os << Constants::SquareBar; break;
          case Type::Bar: os << Constants::Bar; break;
          case Type::Cylinder: os << Constants::Cylinder; break;
          case Type::SquareTubing: os << Constants::SquareTubing; break;
          case Type::Pipe: os << Constants::Pipe; break;
          case Type::Ellipse: os << Constants::Ellipse; break;
          case Type::TBar: os << Constants::TBar; break;
          case Type::Beam: os << Constants::Beam; break;
          case Type::Channel: os << Constants::Channel; break;
          case Type::Angle: os << Constants::Angle; break;
          case Type::HexagonBar: os << Constants::HexagonBar; break;
          case Type::OctagonBar: os << Constants::OctagonBar; break;
          case Type::Sheet: os << Constants::Sheet; break;
          case Type::UNSPECIFIED: os << Constants::S_UNSPECIFIED; break;
          default: os << "Name cannot be found";
        }
        return os;
      }
  };

}//end namespace MassCalculator
#endif