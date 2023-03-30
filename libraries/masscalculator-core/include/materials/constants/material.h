#ifndef LIBRARIES_MASSCALCULATOR_CORE_INCLUDE_MATERIALS_CONSTANTS_MATERIAL_H_
#define LIBRARIES_MASSCALCULATOR_CORE_INCLUDE_MATERIALS_CONSTANTS_MATERIAL_H_

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
constexpr auto kUnspecified{"UNSPECIFIED"};
}  // namespace material

namespace color {
/** @brief String constant for Metallic color */
constexpr auto kMetallic{"Metallic"};

/** @brief String constant for Darktone color */
constexpr auto kDarkTone{"DarkTone"};
}  // namespace color

}  // namespace masscalculator::materials::constants
#endif  // LIBRARIES_MASSCALCULATOR_CORE_INCLUDE_MATERIALS_CONSTANTS_MATERIAL_H_
