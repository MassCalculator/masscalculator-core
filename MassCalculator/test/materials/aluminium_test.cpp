/**
 * @file aluminium_test.cpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief TODO
 * @version 0.1
 * @date 2019-04-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "aluminium_test.hpp"

/**
 * @brief Construct a new TEST object
 * 
 */
TEST_F(AluminiumTest, TypeConstructorTest)
{
  EXPECT_DOUBLE_EQ( 5.0, 5.0);
}

TEST_F(AluminiumTest, GetSpecificTypeTest)
{
  std::pair<std::string, MassCalculator::Aluminium::Type> 
    type{"A_1100", MassCalculator::Aluminium::Type::A_1100};

  EXPECT_EQ( type.first, material_A_1100.getType().first);
  EXPECT_EQ( type.second, material_A_1100.getType().second);
}

TEST_F(AluminiumTest, GetSpecificColorTest)
{
  EXPECT_EQ( std::string{"Metallic"}, material_A_1100.getSpecificColor());
}

TEST_F(AluminiumTest, GetSpecificDensityTest)
{
  EXPECT_EQ( double{2.71}, material_A_1100.getSpecificDensity());
}

TEST_F(AluminiumTest, GetSpecificGravityTest)
{
  EXPECT_EQ( double{2.83}, material_A_1100.getSpecificGravity());
}

TEST_F(AluminiumTest, GetSpecificMeltingPointTest)
{
  EXPECT_EQ( double{537.778}, material_A_1100.getSpecificMeltingPoint());
}

TEST_F(AluminiumTest, GetSpecificPoissonsRatioTest)
{
  EXPECT_EQ( double{0.33}, material_A_1100.getSpecificPoissonsRatio());
}

TEST_F(AluminiumTest, GetSpecificThermalConductivityTest)
{
  EXPECT_EQ( double{990.0}, material_A_1100.getSpecificThermalConductivity());
}

TEST_F(AluminiumTest, GetSpecificModOfElasticityTensionTest)
{
  EXPECT_EQ( double{9.9}, material_A_1100.getSpecificModOfElasticityTension());
}

TEST_F(AluminiumTest, GetSpecificModOfElasticityTorsionTest)
{
  EXPECT_EQ( double{3.8}, material_A_1100.getSpecificModOfElasticityTorsion());
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}