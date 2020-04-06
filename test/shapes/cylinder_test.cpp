#include "cylinder_test.hpp"

/**
 * @brief Default Shapes test namespace
 * 
 */
namespace MassCalculatorTest::ShapesTest
{
  /**
   * @brief Construct a new Cylinder object
   * 
   */
  TEST_F(CylinderTest, TypeConstructorTest)
  {
    EXPECT_DOUBLE_EQ(5.0, 5.0);
  }

  /**
   * @brief Get Type for Cylinder Shape
   * 
   */
  TEST_F(CylinderTest, GetTypeTest)
  {
    EXPECT_EQ(MassCalculator::Shapes::Constants::Cylinder, cylinder_.getType());
  }

  /**
   * @brief Get radius for Cylinder Shape
   * 
   */
  TEST_F(CylinderTest, GetRadiusTest)
  {
    EXPECT_EQ(meter_t{0.05}, cylinder_.getRadius());
  }

  /**
   * @brief Get diameter for Cylinder Shape
   * 
   */
  TEST_F(CylinderTest, GetDiameterTest)
  {
    EXPECT_EQ(meter_t{0.1}, cylinder_.getDiameter());
  }

  /**
   * @brief Get length for Cylinder Shape
   * 
   */
  TEST_F(CylinderTest, GetLengthTest)
  {
    EXPECT_EQ(meter_t{1.0}, cylinder_.getLength());
  }

  /**
   * @brief Get volume for Cylinder Shape
   * 
   */
  TEST_F(CylinderTest, GetVolumeTest)
  {
    EXPECT_NEAR(static_cast<double>(cubic_meter_t{0.007853}), static_cast<double>(cylinder_.getVolume()), static_cast<double>(cubic_meter_t{0.01}));
  }

  /**
   * @brief Get surface area for Cylinder Shape
   * 
   */
  TEST_F(CylinderTest, GetSurfaceAreaTest)
  {
    EXPECT_NEAR(static_cast<double>(square_meter_t{0.329867}), static_cast<double>(cylinder_.getSurfaceArea()), static_cast<double>(square_meter_t{0.01}));
  }
}//end namespace MassCalculatorTest::ShapesTest

/**
 * @brief Main function to run these tests
 * 
 */
int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}