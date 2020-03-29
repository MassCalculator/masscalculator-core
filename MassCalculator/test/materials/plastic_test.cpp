#include "plastic_test.hpp"

namespace MassCalculatorTest
{
  /**
   * @brief Construct a new Plastic object
   * 
   */
  TEST_F(PlasticTest, TypeConstructorTest)
  {
    EXPECT_DOUBLE_EQ(5.0, 5.0);
  }

  /**
   * @brief Get Specific Type for specific material
   * 
   */
  TEST_F(PlasticTest, GetSpecificTypeTest)
  {
    std::pair<std::string, MassCalculator::Materials::Plastic::Type> 
      type{"P_ABS", MassCalculator::Materials::Plastic::Type::P_ABS};

    EXPECT_EQ( type.first, material_P_ABS.getType().first);
    EXPECT_EQ( type.second, material_P_ABS.getType().second);
  }

  /**
   * @brief Get Specific Color for specific material
   * 
   */
  TEST_F(PlasticTest, GetSpecificColorTest)
  {
    EXPECT_EQ( std::string{"Metallic"}, material_P_ABS.getSpecificColor());
  }

  /**
   * @brief Get Specific Density for specific material
   * 
   */
  TEST_F(PlasticTest, GetSpecificDensityTest)
  {
    EXPECT_EQ(kilograms_per_cubic_meter_t{2.71}, material_P_ABS.getSpecificDensity());
  }

  /**
   * @brief Get Specific Gravity for specific material
   * 
   */
  TEST_F(PlasticTest, GetSpecificGravityTest)
  {
    EXPECT_EQ(meters_per_second_squared_t{2.83}, material_P_ABS.getSpecificGravity());
  }

  /**
   * @brief Get Specific Melting Point for specific material
   * 
   */
  TEST_F(PlasticTest, GetSpecificMeltingPointTest)
  {
    EXPECT_EQ(kelvin_t{537.778}, material_P_ABS.getSpecificMeltingPoint());
  }

  /**
   * @brief Get Specific Poissons Ratio for specific material
   * 
   */
  TEST_F(PlasticTest, GetSpecificPoissonsRatioTest)
  {
    EXPECT_EQ(double{0.33}, material_P_ABS.getSpecificPoissonsRatio());
  }

  /**
   * @brief Get Specific Thermal Conductivity for specific material
   * 
   */
  TEST_F(PlasticTest, GetSpecificThermalConductivityTest)
  {
    EXPECT_EQ(watt_t{990.0}, material_P_ABS.getSpecificThermalConductivity());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Tension for specific material
   * 
   */
  TEST_F(PlasticTest, GetSpecificModOfElasticityTensionTest)
  {
    EXPECT_EQ(pascal_t{9.9}, material_P_ABS.getSpecificModOfElasticityTension());
  }

  /**
   * @brief Get Specific Modulus of Elasticity Torsion for specific material
   * 
   */
  TEST_F(PlasticTest, GetSpecificModOfElasticityTorsionTest)
  {
    EXPECT_EQ(pascal_t{3.8}, material_P_ABS.getSpecificModOfElasticityTorsion());
  }
}//end namespace MassCalculatorTest

/**
 * @brief Main function to run these tests
 * 
 */
int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}