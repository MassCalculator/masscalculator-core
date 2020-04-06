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

#include "../../3rdParty/include/units.h"
using namespace units::literals;
using namespace units::length;
using namespace units::volume;
using namespace units::area;

/**
 * @brief Default Shapes namespace
 * 
 */
namespace MassCalculator::Shapes
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
   * @brief Writing repeated static_casts in CRTP base classes quickly becomes cumbersome, as it does not add much meaning to the code.
   * With this template struct, I get rid of it and handled both const and non-const cases
   * 
   * @tparam TShapes Material type template argument
   */
  template <typename TShape>
  struct crtp
  {
    TShape& shapeType() { return static_cast<TShape&>(*this); }
    TShape const& shapeType() const { return static_cast<TShape const&>(*this); }
  };

  /**
   * @brief Template base class Shape
   * 
   */
  template<typename TShapeType>
  class Shape : crtp<TShapeType>
  {
    // public: enum class Type : uint8_t;
    //TODO: Add a properties struct, according to the type for a specific shape

    // public: typedef struct Properties
    // {

    //   /**
    //    * @brief 
    //    * @todo This won't work, but leaving here so I don't forget. Try to deduce enumeration type from derived class in compile time
    //    * 
    //    * @param type_ Type The parameter to save the specific type
    //    * @param color_ string Parameter to save specific color
    //    * @param density_ kilograms_per_cubic_meter_t Parameter to save specific density
    //    * @param gravity_ meters_per_second_squared_t Parameter to save specific gravity
    //    * @param melting_point_ kelvin_t Parameter to save specific melting point
    //    * @param poissons_ratio_ double Parameter to save specific poissons ratio
    //    * @param thermal_conductivity_ watt_t Parameter to save specific thermal conductivity
    //    * @param mod_of_elasticity_tension_ pascal_t Parameter to save specific modulus of elasticity tension
    //    * @param mod_of_elasticity_torsion_ pascal_t Parameter to save specific modulus of elasticity torsion
    //    * 
    //    */
    //   std::pair<std::string, Type> type_;
    //   std::string color_;
    //   kilograms_per_cubic_meter_t density_;
    //   meters_per_second_squared_t gravity_;
    //   kelvin_t melting_point_;
    //   double poissons_ratio_;
    //   watt_t thermal_conductivity_;
    //   pascal_t mod_of_elasticity_tension_;
    //   pascal_t mod_of_elasticity_torsion_;

    //   Properties() : type_{{Constants::UNSPECIFIED}, { }},
    //                       // type_{{Constants::UNSPECIFIED}, {TShapesType::Type::UNSPECIFIED}}, //I would love to do this
    //                       color_{""},
    //                       density_{0_kg_per_cu_m},
    //                       gravity_{0_mps_sq},
    //                       melting_point_{0_K},
    //                       poissons_ratio_{0},
    //                       thermal_conductivity_{0_W},
    //                       mod_of_elasticity_tension_{0_Pa},
    //                       mod_of_elasticity_torsion_{0_Pa} { }

    // }Properties_t;

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

  #if 0

  this->shapeType()->getType()

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
    //   this->shapeType()(type);
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
    constexpr bool setSize(const Args&... args)
    {
      //todo fix this
      // this->shapeType()->setSize(args...);
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
      return{this->shapeType()->getRadius()}; 
    }

    /**
     * @brief Get the Type object
     * 
     * @return const string Type of the Shape from Derived class
     */
    constexpr std::string getType(void)
    {
      return{this->shapeType()->getType()};
    }

    /**
     * @brief Get the Diameter object
     * 
     * @return const double Diameter of the Shape from Derived class
     */
    constexpr double getDiameter(void)
    {
      return{this->shapeType()->getDiameter()};
    }

    /**
     * @brief Get the Length object
     * 
     * @return const double Length of the Shape from Derived class
     */
    constexpr double getLength(void)
    {
      return{this->shapeType()->getLength()};
    }

    /**
     * @brief Get the Volume object
     * 
     * @return const double Volume of the Shape from Derived class
     */
    constexpr double getVolume(void)
    {
      return{this->shapeType()->getVolume()};
    }

    /**
     * @brief Get the Surface Area object
     * 
     * @return const double Surface Area of the Shape from Derived class
     */
    constexpr double getSurfaceArea(void)
    {
      return{this->shapeType()->getSurfaceArea()};
    }

    /**
     * @brief Destroy the Shape object
     * 
     */
    ~Shape(void) = default;

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

    /**
     * @brief Shift operator template overload, for the base class Shape
     * 
     */
    template <typename TShape>
    friend std::ostream &operator << (std::ostream &os, const Shape<TShape> &obj);

    template <typename TShape>
    friend std::ostream &operator << (std::ostream& os, const typename Shape<TShape>:: Type &type);

    private:
    Type type_;

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

  };

  template <typename TShape>
  std::ostream &operator << (std::ostream &os, const Shape<TShape> &obj)
  {
    os << "\n" "Shape" "\n" << obj.thisTShapeType();
    return os;
  }

  template <typename TShape>
  std::ostream &operator << (std::ostream& os, const typename Shape<TShape>:: Type &type)
  {
      switch(type)
      {
        case Shape<TShape>::Type::SquareBar: os << Constants::SquareBar; break;
        case Shape<TShape>::Type::Bar: os << Constants::Bar; break;
        case Shape<TShape>::Type::Cylinder: os << Constants::Cylinder; break;
        case Shape<TShape>::Type::SquareTubing: os << Constants::SquareTubing; break;
        case Shape<TShape>::Type::Pipe: os << Constants::Pipe; break;
        case Shape<TShape>::Type::Ellipse: os << Constants::Ellipse; break;
        case Shape<TShape>::Type::TBar: os << Constants::TBar; break;
        case Shape<TShape>::Type::Beam: os << Constants::Beam; break;
        case Shape<TShape>::Type::Channel: os << Constants::Channel; break;
        case Shape<TShape>::Type::Angle: os << Constants::Angle; break;
        case Shape<TShape>::Type::HexagonBar: os << Constants::HexagonBar; break;
        case Shape<TShape>::Type::OctagonBar: os << Constants::OctagonBar; break;
        case Shape<TShape>::Type::Sheet: os << Constants::Sheet; break;
        case Shape<TShape>::Type::UNSPECIFIED: os << Constants::S_UNSPECIFIED; break;
        default: os << "Name cannot be found";
      }
      return os;
  }
}//end namespace MassCalculator::Shapes
#endif//___SHAPE_H___