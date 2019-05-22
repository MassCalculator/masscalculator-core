#include "shapes/cylinder.hpp"

namespace MassCalculator
{

  Cylinder::Cylinder(double diameter, double length)
  {
    std::cout << "From constructor: " << diameter * length << std::endl;
  }

  bool Cylinder::setSize(double diameter, double length)
  {
    std::cout << "I just set the size of cylinder\n"
              << diameter * length << std::endl;

    this->properties_.diameter_ = diameter;
    this->properties_.length_ = length;

    return true;
  }

  const double Cylinder::getRadius(void) const
  {
    return this->properties_.diameter_/2;
  }

  const double Cylinder::getDiameter(void) const
  {
    return this->properties_.diameter_;
  }

  const double Cylinder::getLength(void) const
  {
    return this->properties_.length_;
  }

  const double Cylinder::getVolume(void) const
  {
    //Volume π*r^2*h. Note: diameter = 2 * r	(Note: Check for Eigen if there are build in functions to calculate, and use those instead)
    return (M_PI * std::pow(this->getRadius(), 2) * this->getLength());
  }

  const double Cylinder::getSurfaceArea(void) const
  {
    //2	π	r	 (	r	+	h	)
    return (2 * M_PI * this->getRadius() * (this->getRadius() + this->getLength()));
  }

  std::ostream &operator << (std::ostream &os, const Cylinder &obj)
  {
    os << "  Cylinder object properties: " "\n"
          "   - Radius  : " + std::to_string(obj.getRadius()) + "\n"
          "   - Diameter: " + std::to_string(obj.getDiameter()) + "\n"
          "   - Length  : " + std::to_string(obj.getLength()) + "\n"
          "   - Volume  : " + std::to_string(obj.getVolume()) + "\n"
          "   - Surface area: " + std::to_string(obj.getSurfaceArea()) + "\n";
    return os;
  }

}//end namespace MassCalculator