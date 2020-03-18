#include <gtest/gtest.h>

#include "shapes/square_bar.hpp"

// The fixture for testing class Aluminium.
class SquareBarTest : public ::testing::Test 
{
  protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  SquareBarTest() 
  {
    // You can do set-up work for each test here.
    this->square_bar_.setSize(0.1, 1);
  }

  ~SquareBarTest() override 
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

  //Objects declared here can be used by all tests in the test case for Foo.
  MassCalculator::SquareBar square_bar_;
};