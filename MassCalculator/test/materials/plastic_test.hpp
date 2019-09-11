#include <gtest/gtest.h>

#include "materials/plastic.hpp"

// The fixture for testing class Plastic.
class PlasticTest : public ::testing::Test 
{
  protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  PlasticTest() 
  {
   // You can do set-up work for each test here.
   material_P_ABS.setType(MassCalculator::Plastic::Type::P_ABS);
  }

  ~PlasticTest() override 
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
  MassCalculator::Plastic material_P_ABS;
};