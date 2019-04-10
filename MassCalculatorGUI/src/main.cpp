#include "object.h"

#include <memory>

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
  const auto obj = std::make_shared<Interface::Object<Shape<Cylinder>, 
                                    Material<Aluminium>>>(shape, 
                                                          material);

  std::cout << "Value: " << *material << std::endl;


  //std::make_shared<Object>;
  return 0;
}