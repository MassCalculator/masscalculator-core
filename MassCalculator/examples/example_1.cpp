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
using namespace MassCalculator::Materials;
using namespace MassCalculator::Shapes;

int main(/*int argc, char** argv*/)
{
  //@todo: explanation here, the object created is temporary, and is cleared from unique pointer destructor right after, this is th reason of the errors.
  //Create a unique pointer for the shape
  Cylinder temp(10.0, 10.0);
  std::unique_ptr<Shape<Cylinder>> shape = std::make_unique<Shape<Cylinder>>(std::move(temp));
  // std::unique_ptr<Shape<Cylinder>> shape = std::make_unique<Shape<Cylinder>>(std::move(Cylinder(10.0, 10.0)));

  //Create a unique pointer for the material
  AlloySteels tempa(AlloySteels::Type::AS_4135);
  std::unique_ptr<Material<AlloySteels>> material = std::make_unique<Material<AlloySteels>>(std::move(tempa));
  // std::unique_ptr<Material<AlloySteels>> material = std::make_unique<Material<AlloySteels>>(std::move(AlloySteels(AlloySteels::Type::AS_4135)));

  // Construct a unique pointer for Object while parsing the arguments from above as parameters
  const auto obj = std::make_unique<Interface::Object<Shape<Cylinder>, 
                                                      Material<AlloySteels>>>(shape, 
                                                                              material);

  std::cout << "Object: " << *obj << std::endl;

  std::cout << "Material: " << *material << std::endl;

  std::cout << "Shape: " << *shape << std::endl;

  return 0;
}