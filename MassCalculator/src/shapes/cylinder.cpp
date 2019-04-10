#include "shapes/cylinder.h"

namespace MassCalculator
{

  Cylinder::Cylinder(double radius, double length)
  {
    std::cout << "From constructor: " << radius * length << std::endl;
  }

  double Cylinder::getMass(void)
  {
    return{5};
  };

  bool Cylinder::setSize(double radius, double length)
  {
    std::cout << "I just set the size of cylinder\n"
              << radius * length << std::endl;

    return true;
  }

}//end namespace MassCalculator