#include "shapes/cylinder.hpp"

namespace MassCalculator::Shapes
{
  Cylinder::Cylinder(meter_t diameter, meter_t length) : properties_{diameter, length}
  {
    std::clog << "I just set the size of cylinder from constructor: " << diameter * length << std::endl;
  }

  bool Cylinder::setSize(meter_t diameter, meter_t length)
  {
    this->properties_.diameter_ = diameter;
    this->properties_.length_ = length;

    if(this->properties_.diameter_ != diameter && this->properties_.length_ != length)
    {
      std::cerr << "Cannot set the size of cylinder\n";
      return false;
    }

    std::clog << "I just set the size of cylinder: " << diameter * length << std::endl;

    return true;
  }

  meter_t Cylinder::getRadius(void) const
  {
    return{this->properties_.diameter_/2};
  }

  meter_t Cylinder::getDiameter(void) const
  {
    return{this->properties_.diameter_};
  }

  meter_t Cylinder::getLength(void) const
  {
    return{this->properties_.length_};
  }

  cubic_meter_t Cylinder::getVolume(void) const
  {
    //Volume π*r^2*h. Note: diameter = 2 * r	(Note: Check for Eigen if there are build in functions to calculate, and use those instead)
    return{M_PI * units::math::pow<2>(this->getRadius()) * this->getLength()};
  }

  square_meter_t Cylinder::getSurfaceArea(void) const
  {
    //2	π	r	 (	r	+	h	)
    return{2 * M_PI * this->getRadius() * (this->getRadius() + this->getLength())};
  }

  std::string Cylinder::getType(void) const
  {
    return{this->properties_.type_.first};
  }

  std::ostream &operator << (std::ostream &os, const Cylinder &obj)
  {
    os << "  Cylinder object properties: " "\n";
          "   - Radius  : " + units::length::to_string(obj.getRadius()) + "\n"
          "   - Diameter: " + units::length::to_string(obj.getDiameter()) + "\n"
          "   - Length  : " + units::length::to_string(obj.getLength()) + "\n"
          "   - Volume  : " + units::volume::to_string(obj.getVolume()) + "\n"
          "   - Surface area: " + units::area::to_string(obj.getSurfaceArea()) + "\n";
    return os;
  }
}//end namespace MassCalculator::Shapes