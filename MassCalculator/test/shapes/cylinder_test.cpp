/**
 * @file cylinder_test.cpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief TODO
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

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}