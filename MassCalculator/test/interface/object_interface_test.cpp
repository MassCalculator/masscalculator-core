#include "object_interface_test.hpp"

/**
 * @brief Construct a new TEST object
 * 
 */
TEST_F(ObjectInterfaceTest, TypeConstructorTest)
{
  EXPECT_DOUBLE_EQ( 5.0, 5.0);
}

TEST_F(ObjectInterfaceTest, GetWeightTest)
{
  EXPECT_NEAR( double{2.12}, obj_->getWeight(), 0.01);
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}