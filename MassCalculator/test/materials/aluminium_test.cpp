/**
 * @file aluminium_test.cpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains all the tests for the class Aluminium, it tests all the functions and the constructors of the class
 * @version 0.1
 * @date 2019-09-03
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

  type = {"A_2011", MassCalculator::Aluminium::Type::A_2011};
  EXPECT_EQ( type.first, material_A_2011.getType().first);
  EXPECT_EQ( type.second, material_A_2011.getType().second);

  type = {"A_2014", MassCalculator::Aluminium::Type::A_2014};
  EXPECT_EQ( type.first, material_A_2014.getType().first);
  EXPECT_EQ( type.second, material_A_2014.getType().second);

  type = {"A_2024", MassCalculator::Aluminium::Type::A_2024};
  EXPECT_EQ( type.first, material_A_2024.getType().first);
  EXPECT_EQ( type.second, material_A_2024.getType().second);

  type = {"A_3003", MassCalculator::Aluminium::Type::A_3003};
  EXPECT_EQ( type.first, material_A_3003.getType().first);
  EXPECT_EQ( type.second, material_A_3003.getType().second);

  type = {"A_5052", MassCalculator::Aluminium::Type::A_5052};
  EXPECT_EQ( type.first, material_A_5052.getType().first);
  EXPECT_EQ( type.second, material_A_5052.getType().second);

  type = {"A_6061", MassCalculator::Aluminium::Type::A_6061};
  EXPECT_EQ( type.first, material_A_6061.getType().first);
  EXPECT_EQ( type.second, material_A_6061.getType().second);

  type = {"A_6063", MassCalculator::Aluminium::Type::A_6063};
  EXPECT_EQ( type.first, material_A_6063.getType().first);
  EXPECT_EQ( type.second, material_A_6063.getType().second);

  type = {"A_7075", MassCalculator::Aluminium::Type::A_7075};
  EXPECT_EQ( type.first, material_A_7075.getType().first);
  EXPECT_EQ( type.second, material_A_7075.getType().second);
}

TEST_F(AluminiumTest, GetSpecificColorTest)
{
  EXPECT_EQ( std::string{"Metallic"}, material_A_1100.getSpecificColor());
  EXPECT_EQ( std::string{"DarkTone"}, material_A_2011.getSpecificColor());
  EXPECT_EQ( std::string{"Metallic"}, material_A_2014.getSpecificColor());
  EXPECT_EQ( std::string{"Metallic"}, material_A_2024.getSpecificColor());
  EXPECT_EQ( std::string{"Metallic"}, material_A_3003.getSpecificColor());
  EXPECT_EQ( std::string{"Metallic"}, material_A_5052.getSpecificColor());
  EXPECT_EQ( std::string{"Metallic"}, material_A_6061.getSpecificColor());
  EXPECT_EQ( std::string{"Metallic"}, material_A_6063.getSpecificColor());
  EXPECT_EQ( std::string{"Metallic"}, material_A_7075.getSpecificColor());
}

TEST_F(AluminiumTest, GetSpecificDensityTest)
{
  EXPECT_EQ( double{2.71}, material_A_1100.getSpecificDensity());
  EXPECT_EQ( double{2.82}, material_A_2011.getSpecificDensity());
  EXPECT_EQ( double{2.71}, material_A_2014.getSpecificDensity());
  EXPECT_EQ( double{2.71}, material_A_2024.getSpecificDensity());
  EXPECT_EQ( double{2.71}, material_A_3003.getSpecificDensity());
  EXPECT_EQ( double{2.71}, material_A_5052.getSpecificDensity());
  EXPECT_EQ( double{2.71}, material_A_6061.getSpecificDensity());
  EXPECT_EQ( double{2.71}, material_A_6063.getSpecificDensity());
  EXPECT_EQ( double{2.71}, material_A_7075.getSpecificDensity());
}

TEST_F(AluminiumTest, GetSpecificGravityTest)
{
  EXPECT_EQ( double{2.83}, material_A_1100.getSpecificGravity());
  EXPECT_EQ( double{2.83}, material_A_2011.getSpecificGravity());
  EXPECT_EQ( double{2.83}, material_A_2014.getSpecificGravity());
  EXPECT_EQ( double{2.83}, material_A_2024.getSpecificGravity());
  EXPECT_EQ( double{2.83}, material_A_3003.getSpecificGravity());
  EXPECT_EQ( double{2.83}, material_A_5052.getSpecificGravity());
  EXPECT_EQ( double{2.83}, material_A_6061.getSpecificGravity());
  EXPECT_EQ( double{2.83}, material_A_6063.getSpecificGravity());
  EXPECT_EQ( double{2.83}, material_A_7075.getSpecificGravity());
}

TEST_F(AluminiumTest, GetSpecificMeltingPointTest)
{
  EXPECT_EQ( double{537.778}, material_A_1100.getSpecificMeltingPoint());
  EXPECT_EQ( double{1000.0}, material_A_2011.getSpecificMeltingPoint());
  EXPECT_EQ( double{537.778}, material_A_2014.getSpecificMeltingPoint());
  EXPECT_EQ( double{537.778}, material_A_2024.getSpecificMeltingPoint());
  EXPECT_EQ( double{537.778}, material_A_3003.getSpecificMeltingPoint());
  EXPECT_EQ( double{537.778}, material_A_5052.getSpecificMeltingPoint());
  EXPECT_EQ( double{537.778}, material_A_6061.getSpecificMeltingPoint());
  EXPECT_EQ( double{537.778}, material_A_6063.getSpecificMeltingPoint());
  EXPECT_EQ( double{537.778}, material_A_7075.getSpecificMeltingPoint());
}

TEST_F(AluminiumTest, GetSpecificPoissonsRatioTest)
{
  EXPECT_EQ( double{0.33}, material_A_1100.getSpecificPoissonsRatio());
  EXPECT_EQ( double{0.33}, material_A_2011.getSpecificPoissonsRatio());
  EXPECT_EQ( double{0.33}, material_A_2014.getSpecificPoissonsRatio());
  EXPECT_EQ( double{0.33}, material_A_2024.getSpecificPoissonsRatio());
  EXPECT_EQ( double{0.33}, material_A_3003.getSpecificPoissonsRatio());
  EXPECT_EQ( double{0.33}, material_A_5052.getSpecificPoissonsRatio());
  EXPECT_EQ( double{0.33}, material_A_6061.getSpecificPoissonsRatio());
  EXPECT_EQ( double{0.33}, material_A_6063.getSpecificPoissonsRatio());
  EXPECT_EQ( double{0.33}, material_A_7075.getSpecificPoissonsRatio());
}

TEST_F(AluminiumTest, GetSpecificThermalConductivityTest)
{
  EXPECT_EQ( double{990.0}, material_A_1100.getSpecificThermalConductivity());
  EXPECT_EQ( double{990.0}, material_A_2011.getSpecificThermalConductivity());
  EXPECT_EQ( double{990.0}, material_A_2014.getSpecificThermalConductivity());
  EXPECT_EQ( double{990.0}, material_A_2024.getSpecificThermalConductivity());
  EXPECT_EQ( double{990.0}, material_A_3003.getSpecificThermalConductivity());
  EXPECT_EQ( double{990.0}, material_A_5052.getSpecificThermalConductivity());
  EXPECT_EQ( double{990.0}, material_A_6061.getSpecificThermalConductivity());
  EXPECT_EQ( double{990.0}, material_A_6063.getSpecificThermalConductivity());
  EXPECT_EQ( double{990.0}, material_A_7075.getSpecificThermalConductivity());
}

TEST_F(AluminiumTest, GetSpecificModOfElasticityTensionTest)
{
  EXPECT_EQ( double{9.9}, material_A_1100.getSpecificModOfElasticityTension());
  EXPECT_EQ( double{10.2}, material_A_2011.getSpecificModOfElasticityTension());
  EXPECT_EQ( double{9.9}, material_A_2014.getSpecificModOfElasticityTension());
  EXPECT_EQ( double{9.9}, material_A_2024.getSpecificModOfElasticityTension());
  EXPECT_EQ( double{9.9}, material_A_3003.getSpecificModOfElasticityTension());
  EXPECT_EQ( double{9.9}, material_A_5052.getSpecificModOfElasticityTension());
  EXPECT_EQ( double{9.9}, material_A_6061.getSpecificModOfElasticityTension());
  EXPECT_EQ( double{9.9}, material_A_6063.getSpecificModOfElasticityTension());
  EXPECT_EQ( double{9.9}, material_A_7075.getSpecificModOfElasticityTension());
}

TEST_F(AluminiumTest, GetSpecificModOfElasticityTorsionTest)
{
  EXPECT_EQ( double{3.8}, material_A_1100.getSpecificModOfElasticityTorsion());
  EXPECT_EQ( double{3.85}, material_A_2011.getSpecificModOfElasticityTorsion());
  EXPECT_EQ( double{3.8}, material_A_2014.getSpecificModOfElasticityTorsion());
  EXPECT_EQ( double{3.8}, material_A_2024.getSpecificModOfElasticityTorsion());
  EXPECT_EQ( double{3.8}, material_A_3003.getSpecificModOfElasticityTorsion());
  EXPECT_EQ( double{3.8}, material_A_5052.getSpecificModOfElasticityTorsion());
  EXPECT_EQ( double{3.8}, material_A_6061.getSpecificModOfElasticityTorsion());
  EXPECT_EQ( double{3.8}, material_A_6063.getSpecificModOfElasticityTorsion());
  EXPECT_EQ( double{3.8}, material_A_7075.getSpecificModOfElasticityTorsion());
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}