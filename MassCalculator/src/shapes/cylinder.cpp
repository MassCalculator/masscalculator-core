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
    os << "  Cylinder object properties: " "\n";
          // "   - Type    : " + obj.getType().first + "\n"
          // "   - Color   : " + obj.getSpecificColor() + "\n"
          // "   - Density : " + std::to_string(obj.getSpecificDensity()) + "\n"
          // "   - Gravity : " + std::to_string(obj.getSpecificGravity()) + "\n"
          // "   - Melting point : " + std::to_string(obj.getSpecificMeltingPoint()) + "\n"
          // "   - Poissons ratio: " + std::to_string(obj.getSpecificPoissonsRatio()) + "\n"
          // "   - Thermal conductivity         : " + std::to_string(obj.getSpecificThermalConductivity()) + "\n"
          // "   - Modulus of elasticity tension: " + std::to_string(obj.getSpecificModOfElasticityTension()) + "\n"
          // "   - Modulus of elasticity torsion: " + std::to_string(obj.getSpecificModOfElasticityTorsion()) + "\n";
    return os;
  }

}//end namespace MassCalculator