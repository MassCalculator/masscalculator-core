/**
 * @file square_bar_test.cpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Cylinder, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2019-04-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "square_bar_test.hpp"

/**
 * @brief Construct a new TEST object
 * 
 */
TEST_F(SquareBarTest, TypeConstructorTest)
{
  EXPECT_DOUBLE_EQ( 5.0, 5.0);
}

TEST_F(SquareBarTest, GetDiagonalTest)
{
  EXPECT_DOUBLE_EQ( double{0.05}, square_bar_.getDiagonal());
}

TEST_F(SquareBarTest, GetTypeTest)
{
  EXPECT_EQ( "SquareBar", square_bar_.getType());
}

TEST_F(SquareBarTest, GetSideTest)
{
  EXPECT_DOUBLE_EQ( double{0.1}, square_bar_.getSide());
}

TEST_F(SquareBarTest, GetLengthTest)
{
  EXPECT_DOUBLE_EQ( double{1.0}, square_bar_.getLength());
}

TEST_F(SquareBarTest, GetVolumeTest)
{
  // EXPECT_DOUBLE_EQ( double{0.007853}, square_bar_.getVolume());
  EXPECT_NEAR( double{0.0314159}, square_bar_.getVolume(), 0.01);
}

TEST_F(SquareBarTest, GetSurfaceAreaTest)
{
  EXPECT_NEAR( double{0.6911503}, square_bar_.getSurfaceArea(), 0.01);
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}