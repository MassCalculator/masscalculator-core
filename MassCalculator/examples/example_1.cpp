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

  //Create a shared pointer for the shape
  std::unique_ptr<Shape<Cylinder>> shape(new Cylinder(10.0, 10.0));

  //Create a shared pointer for the material
  std::unique_ptr<Material<Aluminium>> material(new Aluminium(Aluminium::Type::A_1100));

  // Interface::Object<Shape<Cylinder>, 
  //                   Material<Aluminium>> obj(shape,
  //                                            material);

  //Construct a shared pointer for Object while parsing the arguments from above as parameters
  const auto obj = std::make_unique<Interface::Object<Shape<Cylinder>, 
                                                      Material<Aluminium>>>(shape, 
                                                                            material);

  std::cout << "Object: " << *obj << std::endl;

  std::cout << "Material: " << *material << std::endl;

  std::cout << "Shape: " << *shape << std::endl;

  //std::make_shared<Object>;
  return 0;
}