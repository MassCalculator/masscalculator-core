#include "object_interface_test.hpp"

namespace MassCalculatorTest::ObjectInterfaceTest
{
  /**
   * @brief Construct a new ObjectInterface object
   * 
   */
  TEST_F(ObjectInterfaceTest, TypeConstructorTest)
  {
    EXPECT_DOUBLE_EQ( 5.0, 5.0);
  }

  /**
   * @brief Get calculated weight specific material and shape
   * 
   */
  TEST_F(ObjectInterfaceTest, GetWeightTest)
  {
    EXPECT_NEAR( static_cast<double>(kilogram_t{2.12_kg}), static_cast<double>(this->obj_->getWeight()), static_cast<double>(kilogram_t{1_g}));
  }
}//end namespace MassCalculatorTest::ObjectInterfaceTest

/**
 * @brief Main function to run these tests
 * 
 */
int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}