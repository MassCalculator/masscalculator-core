#include "brass_test.hpp"

/**
 * @brief Construct a new Brass object
 * 
 */
TEST_F(BrassTest, TypeConstructorTest)
{
  EXPECT_DOUBLE_EQ( 5.0, 5.0);
}

TEST_F(BrassTest, GetSpecificTypeTest)
{
  std::pair<std::string, MassCalculator::Materials::Brass::Type> 
    type{"B_240Low", MassCalculator::Materials::Brass::Type::B_240Low};

  EXPECT_EQ(type.first, material_B_240Low.getType().first);
  EXPECT_EQ(type.second, material_B_240Low.getType().second);
}

TEST_F(BrassTest, GetSpecificColorTest)
{
  EXPECT_EQ(std::string{"Metallic"}, material_B_240Low.getSpecificColor());
}

TEST_F(BrassTest, GetSpecificDensityTest)
{
  EXPECT_EQ(kilograms_per_cubic_meter_t{2.71_kg_per_cu_m}, material_B_240Low.getSpecificDensity());
}

TEST_F(BrassTest, GetSpecificGravityTest)
{
  EXPECT_EQ(meters_per_second_squared_t{2.83_mps_sq}, material_B_240Low.getSpecificGravity());
}

TEST_F(BrassTest, GetSpecificMeltingPointTest)
{
  EXPECT_EQ(kelvin_t{537.778_K}, material_B_240Low.getSpecificMeltingPoint());
}

TEST_F(BrassTest, GetSpecificPoissonsRatioTest)
{
  EXPECT_EQ(double{0.33}, material_B_240Low.getSpecificPoissonsRatio());
}

TEST_F(BrassTest, GetSpecificThermalConductivityTest)
{
  EXPECT_EQ(watt_t{990.0_W}, material_B_240Low.getSpecificThermalConductivity());
}

TEST_F(BrassTest, GetSpecificModOfElasticityTensionTest)
{
  EXPECT_EQ(pascal_t{9.9_Pa}, material_B_240Low.getSpecificModOfElasticityTension());
}

TEST_F(BrassTest, GetSpecificModOfElasticityTorsionTest)
{
  EXPECT_EQ(pascal_t{3.8_Pa}, material_B_240Low.getSpecificModOfElasticityTorsion());
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}