#include "shapes/sheet.hpp"

namespace MassCalculator::Shapes
{

  Sheet::Sheet(double side, double length)
  {
    std::cout << "From constructor: " << side * length << std::endl;
  }

  bool Sheet::setSize(double side, double length)
  {
    std::cout << "I just set the size of Sheet\n"
              << 4 * side * length << std::endl;

    this->properties_.side_ = side;
    this->properties_.length_ = length;

    return true;
  }

  //TODO:
  double Sheet::getDiagonal(void) const
  {
    return this->properties_.side_/2;
  }

  double Sheet::getSide(void) const
  {
    return this->properties_.side_;
  }

  double Sheet::getLength(void) const
  {
    return this->properties_.length_;
  }

  //TODO:
  double Sheet::getVolume(void) const
  {
    //Volume π*r^2*h. Note: diameter = 2 * r	(Note: Check for Eigen if there are build in functions to calculate, and use those instead) TODO:
    return (M_PI * std::pow(this->getSide(), 2) * this->getLength());
  }

  double Sheet::getSurfaceArea(void) const
  {
    //2	π	r	 (	r	+	h	)
    return (2 * M_PI * this->getSide() * (this->getSide() + this->getLength()));
  }

  std::string Sheet::getType(void) const
  {
    return this->properties_.type_.first;
  }

  std::ostream &operator << (std::ostream &os, const Sheet &obj)
  {
    os << "  Sheet object properties: " "\n"
          "   - Radius  : " + std::to_string(obj.getDiagonal()) + "\n"
          "   - Diameter: " + std::to_string(obj.getSide()) + "\n"
          "   - Length  : " + std::to_string(obj.getLength()) + "\n"
          "   - Volume  : " + std::to_string(obj.getVolume()) + "\n"
          "   - Surface area: " + std::to_string(obj.getSurfaceArea()) + "\n";
    return os;
  }

}//end namespace MassCalculator::Shapes