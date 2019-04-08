#include "object.h"

#include <memory>

using namespace MassCalculator;

int main(int argc, char** argv)
{
  //Create a shared pointer for the shape
  std::shared_ptr<Shape::Shape<Shape::Cylinder>> shape(new Shape::Cylinder(10, 10));

  //Create a shared pointer for the material
  std::shared_ptr<Material::Material<Material::Aluminium>> material(new Material::Aluminium(Material::Aluminium::Type::AL_6080));

  // Interface::Object<Shape::Shape<Shape::Cylinder>, 
  //                   Material::Material<Material::Aluminium>> obj(shape,
  //                                                                material);

  //Construct a shared pointer for Object while parsing the arguments from above as parameters
  const auto obj = std::make_shared<Interface::Object<Shape::Shape<Shape::Cylinder>, 
                                    Material::Material<Material::Aluminium>>>(shape, 
                                                                              material);

  std::cout << "Value: " << obj->getWeight() << std::endl;


  //std::make_shared<Object>;
  return 0;
}