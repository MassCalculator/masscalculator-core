#include "materials/aluminium.hpp"
#include <gtest/gtest.h>

// The fixture for testing class Aluminium.
class AluminiumTest : public ::testing::Test 
{
  protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  AluminiumTest() 
  {
   // You can do set-up work for each test here.
   material_A_1100.setType(MassCalculator::Aluminium::Type::A_1100);
   material_A_2011.setType(MassCalculator::Aluminium::Type::A_2011);
   material_A_2014.setType(MassCalculator::Aluminium::Type::A_2014);
   material_A_2024.setType(MassCalculator::Aluminium::Type::A_2024);
   material_A_3003.setType(MassCalculator::Aluminium::Type::A_3003);
   material_A_5052.setType(MassCalculator::Aluminium::Type::A_5052);
   material_A_6061.setType(MassCalculator::Aluminium::Type::A_6061);
   material_A_6063.setType(MassCalculator::Aluminium::Type::A_6063);
   material_A_7075.setType(MassCalculator::Aluminium::Type::A_7075);
  }

  ~AluminiumTest() override 
  {
   // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override 
  {
   // Code here will be called immediately after the constructor (right
   // before each test).
  }

  void TearDown() override 
  {
   // Code here will be called immediately after each test (right
   // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for Foo.
  MassCalculator::Aluminium material_A_1100,
                            material_A_2011,
                            material_A_2014,
                            material_A_2024,
                            material_A_3003,
                            material_A_5052,
                            material_A_6061,
                            material_A_6063,
                            material_A_7075;
};