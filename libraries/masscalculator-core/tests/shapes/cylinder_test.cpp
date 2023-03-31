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
    EXPECT_EQ(MassCalculator::Shapes::Constants::Shape::Cylinder, cylinder_.getType());
  }

  /**
   * @brief Get radius for Cylinder Shape
   * 
   */
  TEST_F(CylinderTest, GetRadiusTest)
  {
    EXPECT_EQ(meter_t{0.05_m}, cylinder_.getRadius());
  }

  /**
   * @brief Get diameter for Cylinder Shape
   * 
   */
  TEST_F(CylinderTest, GetDiameterTest)
  {
    EXPECT_EQ(meter_t{0.1_m}, cylinder_.getDiameter());
  }

  /**
   * @brief Get length for Cylinder Shape
   * 
   */
  TEST_F(CylinderTest, GetLengthTest)
  {
    EXPECT_EQ(meter_t{1.0_m}, cylinder_.getLength());
  }

  /**
   * @brief Get volume for Cylinder Shape
   * 
   */
  TEST_F(CylinderTest, GetVolumeTest)
  {
    EXPECT_NEAR(static_cast<double>(cubic_meter_t{0.007853_cu_m}), static_cast<double>(cylinder_.getVolume()), static_cast<double>(cubic_meter_t{0.01_cu_m}));
  }

  /**
   * @brief Get surface area for Cylinder Shape
   * 
   */
  TEST_F(CylinderTest, GetSurfaceAreaTest)
  {
    EXPECT_NEAR(static_cast<double>(square_meter_t{0.329867_sq_m}), static_cast<double>(cylinder_.getSurfaceArea()), static_cast<double>(square_meter_t{0.01_sq_m}));
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