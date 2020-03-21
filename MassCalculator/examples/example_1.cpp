/**
 * @file example_1.cpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief The example that uses interface, creates material and shape objects, and combines to get the weight
 * TODO: This is just for test only, it needs to change to a proper example
 * @version 0.1
 * @date 2019-05-12
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "interface/object_interface.hpp"

using namespace MassCalculator;

int main(/*int argc, char** argv*/)
{
  //Create a unique pointer for the shape
  std::unique_ptr<Shape<Cylinder>> shape = std::make_unique<Shape<Cylinder>>(Cylinder(10.0, 10.0));

  //Create a unique pointer for the material
  std::unique_ptr<Material<AlloyCoppers>> material = std::make_unique<Material<AlloyCoppers>>(AlloyCoppers(AlloyCoppers::Type::AC_145Tellvirum));

  // Construct a unique pointer for Object while parsing the arguments from above as parameters
  const auto obj = std::make_unique<Interface::Object<Shape<Cylinder>, 
                                                      Material<AlloyCoppers>>>(shape, 
                                                                            material);

  std::cout << "Object: " << *obj << std::endl;

  std::cout << "Material: " << *material << std::endl;

  std::cout << "Shape: " << *shape << std::endl;

  return 0;
}