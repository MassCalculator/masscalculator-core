/**
 * @file cylinder_test.cpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Cylinder, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2019-04-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "cylinder_test.hpp"

/**
 * @brief Construct a new TEST object
 * 
 */
TEST_F(CylinderTest, TypeConstructorTest)
{
  EXPECT_DOUBLE_EQ( 5.0, 5.0);
}

TEST_F(CylinderTest, GetRadiusTest)
{
  EXPECT_DOUBLE_EQ( double{0.05}, cylinder_.getRadius());
}

TEST_F(CylinderTest, GetDiameterTest)
{
  EXPECT_DOUBLE_EQ( double{0.1}, cylinder_.getDiameter());
}

TEST_F(CylinderTest, GetLengthTest)
{
  EXPECT_DOUBLE_EQ( double{1.0}, cylinder_.getLength());
}

TEST_F(CylinderTest, GetVolumeTest)
{
  // EXPECT_DOUBLE_EQ( double{0.007853}, cylinder_.getVolume());
  EXPECT_NEAR( double{0.007853}, cylinder_.getVolume(), 0.01);
}

TEST_F(CylinderTest, GetSurfaceAreaTest)
{
  EXPECT_NEAR( double{0.329867}, cylinder_.getSurfaceArea(), 0.01);
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}