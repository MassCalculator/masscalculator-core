#include <gtest/gtest.h>

#include "interface/object_interface.hpp"

using namespace MassCalculator;

// The fixture for testing class Aluminium.
class ObjectInterfaceTest : public ::testing::Test 
{
  protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  ObjectInterfaceTest() 
  {
   // You can do set-up work for each test here.
  }

  ~ObjectInterfaceTest() override 
  {
   // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override 
  {
   // Code here will be called immediately after the constructor (right
   // before each test).

    //Create a unique pointer for the shape
    std::unique_ptr<Shape<Cylinder>> shape = std::make_unique<Shape<Cylinder>>(Cylinder(0.1, 1.0));

    //Create a unique pointer for the material
    std::unique_ptr<Material<Aluminium>> material = std::make_unique<Material<Aluminium>>(Aluminium(Aluminium::Type::A_1100));

    // Construct a unique pointer for Object while parsing the arguments from above as parameters
    this->obj_ = std::make_unique<Interface::Object<Shape<Cylinder>, 
                                                    Material<Aluminium>>>(shape,
                                                                          material);
  }

  void TearDown() override 
  {
   // Code here will be called immediately after each test (right
   // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for Foo.
  //Rename the object to obj_cylinder_aluminium_ 'cuz we are going to create objects for other materials and other shapes too
  //obj_cylinder_steel_, obj_cylinder_brass_, obj_hexagon_aluminium_
  std::unique_ptr<Interface::Object<Shape<Cylinder>, 
                                    Material<Aluminium>>> obj_;
};