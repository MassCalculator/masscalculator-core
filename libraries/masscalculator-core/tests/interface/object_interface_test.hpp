/**
 * @file object_interface_test.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class ObjectInterface, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2020-03-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___OBJECT_INTERFACE_TEST_H___
#define ___OBJECT_INTERFACE_TEST_H___
#include "interface/object_interface.hpp"
#include <gtest/gtest.h>

using namespace MassCalculator;
using namespace MassCalculator::Materials;
using namespace MassCalculator::Shapes;

/**
 * @brief Default Object Interface test namespace
 * 
 */
namespace MassCalculatorTest::ObjectInterfaceTest
{
  /**
   * @brief The test fixture for testing class ObjectInterface.
   * 
   */
  class ObjectInterfaceTest : public ::testing::Test 
  {
    protected:
    /**
     * @brief Construct a new ObjectInterfaceTest object
     * 
     */
    ObjectInterfaceTest() 
    {
      //Create a unique pointer for the shape
      std::unique_ptr<Shape<Cylinder>> shape = std::make_unique<Shape<Cylinder>>(Cylinder(0.1, 1.0));

      //Create a unique pointer for the material
      std::unique_ptr<Material<Aluminium>> material = std::make_unique<Material<Aluminium>>(Aluminium(Aluminium::Type::A_1100));

      // Construct a unique pointer for Object while parsing the arguments from above as parameters
      this->obj_ = std::make_unique<Interface::Object<Shape<Cylinder>, 
                                                      Material<Aluminium>>>(shape,
                                                                            material);
    }

    /**
     * @brief Destroy the ObjectInterfaceTest object
     * 
     */
    ~ObjectInterfaceTest() = default;

    /**
     * @brief Rename the object to obj_cylinder_aluminium_ 'cuz we are going to create objects for other materials and other shapes too
     * obj_cylinder_steel_, obj_cylinder_brass_, obj_hexagon_aluminium_
     */
    std::unique_ptr<Interface::Object<Shape<Cylinder>, 
                                      Material<Aluminium>>> obj_;
  };
  }//end namespace MassCalculatorTest::ObjectInterfaceTest
#endif//___OBJECT_INTERFACE_TEST_H___