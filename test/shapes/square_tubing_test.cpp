#include "square_tubing_test.hpp"

/**
 * @brief Default Shapes test namespace
 * 
 */
namespace MassCalculatorTest::ShapesTest
{
  /**
   * @brief Construct a new SquareTubing object
   * 
   */
  TEST_F(SquareTubingTest, TypeConstructorTest)
  {
    EXPECT_DOUBLE_EQ(5.0, 5.0);
  }

  /**
   * @brief Get Type for SquareTubing Shape
   * 
   */
  TEST_F(SquareTubingTest, GetTypeTest)
  {
    EXPECT_EQ(MassCalculator::Shapes::Constants::Shape::SquareTubing, square_tubing_.getType());
  }

  /**
   * @brief Get inner diagonal for SquareTubing Shape
   * 
   */
  TEST_F(SquareTubingTest, GetInnerDiagonalTest)
  {
    EXPECT_TRUE(units::traits::is_length_unit<decltype(square_tubing_.getInnerDiagonal())>::value);
    EXPECT_NEAR(meter_t{0.127279_m}.to<double>(), square_tubing_.getInnerDiagonal().to<double>(), meter_t{0.0001_m}.to<double>());
  }

  /**
   * @brief Get outter diagonal for SquareTubing Shape
   * 
   */
  TEST_F(SquareTubingTest, GetOutterDiagonalTest)
  {
    EXPECT_TRUE(units::traits::is_length_unit<decltype(square_tubing_.getOutterDiagonal())>::value);
    EXPECT_NEAR(meter_t{0.141421_m}.to<double>(), square_tubing_.getOutterDiagonal().to<double>(), meter_t{0.0001_m}.to<double>());
  }

  /**
   * @brief Get side for SquareTubing Shape
   * 
   */
  TEST_F(SquareTubingTest, GetSideTest)
  {
    EXPECT_TRUE(units::traits::is_length_unit<decltype(square_tubing_.getSide())>::value);
    EXPECT_EQ(meter_t{0.1_m}, square_tubing_.getSide());
  }

  /**
   * @brief Get thickness for SquareTubing Shape
   * 
   */
  TEST_F(SquareTubingTest, GetThicknessTest)
  {
    EXPECT_TRUE(units::traits::is_length_unit<decltype(square_tubing_.getThickness())>::value);
    EXPECT_EQ(meter_t{0.01_m}, square_tubing_.getThickness());
  }

  /**
   * @brief Get length for SquareTubing Shape
   * 
   */
  TEST_F(SquareTubingTest, GetLengthTest)
  {
    EXPECT_TRUE(units::traits::is_length_unit<decltype(square_tubing_.getLength())>::value);
    EXPECT_EQ(meter_t{1.0_m}, square_tubing_.getLength());
  }

  /**
   * @brief Get volume for SquareTubing Shape
   * 
   */
  TEST_F(SquareTubingTest, GetVolumeTest)
  {
    EXPECT_TRUE(units::traits::is_volume_unit<decltype(square_tubing_.getVolume())>::value);
    EXPECT_NEAR(cubic_meter_t{0.001900_cu_m}.to<double>(), square_tubing_.getVolume().to<double>(), cubic_meter_t{0.00001_cu_m}.to<double>());
  }

  /**
   * @brief Get surface area for SquareTubing Shape
   * 
   */
  TEST_F(SquareTubingTest, GetSurfaceAreaTest)
  {
    EXPECT_TRUE(units::traits::is_area_unit<decltype(square_tubing_.getSurfaceArea())>::value);
    EXPECT_NEAR(square_meter_t{0.043800_sq_m}.to<double>(), square_tubing_.getSurfaceArea().to<double>(), square_meter_t{0.00001_sq_m}.to<double>());
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