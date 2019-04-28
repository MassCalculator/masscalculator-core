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

  const double Cylinder::getRadius(void)
  {
    return this->properties_.diameter_/2;
  }

  const double Cylinder::getDiameter(void)
  {
    return this->properties_.diameter_;
  }

  const double Cylinder::getLength(void)
  {
    return this->properties_.length_;
  }

  double Cylinder::getVolume(void)
  {
    //Volume π*r^2*h. Note: diameter = 2 * r	(Note: Check for Eigen if there are build in functions to calculate, and use those instead)
    return (M_PI * std::pow(this->getRadius(), 2) * this->getLength());
  }

  double Cylinder::getSurfaceArea(void)
  {
    //2	π	r	 (	r	+	h	)
    return (2 * M_PI * this->getRadius() * (this->getRadius() + this->getLength()));
  }

  double Cylinder::getMass(void)
  {
    return{5};
  };

}//end namespace MassCalculator