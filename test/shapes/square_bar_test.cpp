#include "square_bar_test.hpp"

/**
 * @brief Default Shapes test namespace
 * 
 */
namespace MassCalculatorTest::ShapesTest
{
  /**
   * @brief Construct a new SquareBar object
   * 
   */
  TEST_F(SquareBarTest, TypeConstructorTest)
  {
    EXPECT_DOUBLE_EQ(5.0, 5.0);
  }

  /**
   * @brief Get Type for Cylinder Shape
   * 
   */
  TEST_F(SquareBarTest, GetTypeTest)
  {
    EXPECT_EQ(MassCalculator::Shapes::Constants::Shape::SquareBar, square_bar_.getType());
  }

  /**
   * @brief Get diagonal for SquareBar Shape
   * 
   */
  TEST_F(SquareBarTest, GetDiagonalTest)
  {
    EXPECT_NEAR(static_cast<double>(meter_t{0.141421_m}), static_cast<double>(square_bar_.getDiagonal()), static_cast<double>(meter_t{0.0001_m}));
  }

  /**
   * @brief Get side for SquareBar Shape
   * 
   */
  TEST_F(SquareBarTest, GetSideTest)
  {
    EXPECT_EQ(meter_t{0.1_m}, square_bar_.getSide());
  }

  /**
   * @brief Get length for SquareBar Shape
   * 
   */
  TEST_F(SquareBarTest, GetLengthTest)
  {
    EXPECT_EQ(meter_t{1.0_m}, square_bar_.getLength());
  }

  /**
   * @brief Get volume for SquareBar Shape
   * 
   */
  TEST_F(SquareBarTest, GetVolumeTest)
  {
    EXPECT_NEAR(static_cast<double>(cubic_meter_t{0.0100000_cu_m}), static_cast<double>(square_bar_.getVolume()), static_cast<double>(cubic_meter_t{0.0001_cu_m}));
  }

  /**
   * @brief Get surface area for SquareBar Shape
   * 
   */
  TEST_F(SquareBarTest, GetSurfaceAreaTest)
  {
    EXPECT_NEAR(static_cast<double>(square_meter_t{0.420000_sq_m}), static_cast<double>(square_bar_.getSurfaceArea()), static_cast<double>(square_meter_t{0.01_sq_m}));
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