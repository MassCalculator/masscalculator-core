#ifndef MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_INCLUDE_MATERIALS_CONSTANTS_MATERIAL_H_
#define MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_INCLUDE_MATERIALS_CONSTANTS_MATERIAL_H_

namespace masscalculator::materials::constants {
namespace material {
// ! String constant for AlloyCoppers material.
constexpr auto kAlloyCoppers{"AlloyCoppers"};
// ! String constant for AlloySteels material.
constexpr auto kAlloySteels{"AlloySteels"};
// ! String constant for Aluminium material.
constexpr auto kAluminium{"Aluminium"};
// ! String constant for Brass material.
constexpr auto kBrass{"Brass"};
// ! String constant for Bronz material.
constexpr auto kBronz{"Bronz"};
// ! String constant for Copper material.
constexpr auto kCopper{"Copper"};
// ! String constant for Magnesium material.
constexpr auto kMagnesium{"Magnesium"};
// ! String constant for Nickel material.
constexpr auto kNickel{"Nickel"};
// ! String constant for Plastic material.
constexpr auto kPlastic{"Plastic"};
// ! String constant for StainlessSteel material.
constexpr auto kStainlessSteel{"StainlessSteel"};
// ! String constant for Steel material.
constexpr auto kSteel{"Steel"};
// ! String constant for Titanium material.
constexpr auto kTitanium{"Titanium"};
// ! String constant for Zinc material.
constexpr auto kZinc{"Zinc"};
// ! String constant for UNSPECIFIED material.
constexpr auto kUnspecified{"Unspecified"};
} // namespace material

namespace color {
// ! String constant for Metallic color.
constexpr auto kMetallic{"Metallic"};
// ! String constant for Darktone color.
constexpr auto kDarkTone{"Darktone"};
} // namespace color

namespace properties {
// ! Key to get the type.
constexpr auto kTypeKey{"type"};
// ! Key to get the color.
constexpr auto kColorKey{"color"};
// ! Key to get the density.
constexpr auto kDensityKey{"density"};
// ! Key to get the gravity.
constexpr auto kGravityKey{"gravity"};
// ! Key to get the melting point.
constexpr auto kMeltingPointKey{"melting_point"};
// ! Key to get the poissons ratio.
constexpr auto kPoissonsRatioKey{"poissons_ratio"};
// ! Key to get the thermal conductivity.
constexpr auto kThermalConductivityKey{"thermal_conductivity"};
// ! Key to get the modulus of elasticity tension.
constexpr auto kModOfElasticityTensionKey{"mod_of_elasticity_tension"};
} // namespace properties
} // namespace masscalculator::materials::constants
#endif // MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_INCLUDE_MATERIALS_CONSTANTS_MATERIAL_H_
