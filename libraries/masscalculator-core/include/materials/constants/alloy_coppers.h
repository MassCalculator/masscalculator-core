#ifndef MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_INCLUDE_MATERIALS_CONSTANTS_ALLOY_COPPERS_H_
#define MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_INCLUDE_MATERIALS_CONSTANTS_ALLOY_COPPERS_H_

namespace masscalculator::materials::constants::alloycopper {

/** @brief String constant for AC_145Tellvirum type */
constexpr auto k145Telluirum{"AlloyCopper145Tellvirum"};

/** @brief String constant for AC_194Iron type */
constexpr auto AC_194Iron{"AC_194Iron"};

/** @brief String constant for AC_195Iron type */
constexpr auto AC_195Iron{"AC_195Iron"};

/** @brief String constant for AC_172Beryllium type */
constexpr auto AC_172Beryllium{"AC_172Beryllium"};

/** @brief String constant for AC_182Class2 type */
constexpr auto AC_182Class2{"AC_182Class2"};

/** @brief String constant for AC_655Silicon type */
constexpr auto AC_655Silicon{"AC_655Silicon"};

/** @brief String constant for AC_706Nickel type */
constexpr auto AC_706Nickel{"AC_706Nickel"};

/** @brief String constant for AC_715NickelSilver type */
constexpr auto AC_715NickelSilver{"AC_715NickelSilver"};

/** @brief String constant for AC_725NickelSilver type */
constexpr auto AC_725NickelSilver{"AC_725NickelSilver"};

/** @brief String constant for AC_735NickelSilver type */
constexpr auto AC_735NickelSilver{"AC_735NickelSilver"};

/** @brief String constant for AC_752NickelSilver type */
constexpr auto AC_752NickelSilver{"AC_752NickelSilver"};

/** @brief String constant for AC_762NickelSilver type */
constexpr auto AC_762NickelSilver{"AC_762NickelSilver"};

/** @brief String constant for AC_770NickelSilver type */
constexpr auto AC_770NickelSilver{"AC_770NickelSilver"};

/** @brief String constant for AC_1751Class3 type */
constexpr auto AC_1751Class3{"AC_1751Class3"};

/** @brief String constant for AC_1758Nickel type */
constexpr auto AC_1758Nickel{"AC_1758Nickel"};

/** @brief String constant for AC_MoldmaxBeCu type */
constexpr auto AC_MoldmaxBeCu{"AC_MoldmaxBeCu"};

/** @brief String constant for AC_ProthermBeCu type */
constexpr auto AC_ProthermBeCu{"AC_ProthermBeCu"};

/** @brief String constant for UNSPECIFIED type */
constexpr auto UNSPECIFIED{"UNSPECIFIED"};

}  // namespace masscalculator::materials::constants::alloycopper
#endif  // MASSCALCULATOR_LIBRARIES_MASSCALCULATOR_CORE_INCLUDE_MATERIALS_CONSTANTS_ALLOY_COPPERS_H_

// /**
//  * @brief @todo It will come a time that we will cross_compile, add a Windows
//  * tag to.
//  *
//  */
// #ifdef DEBUG
// /**
//  * @brief Lua config path when we are in debug mode, it will get the
//  resources
//  * from source directory
//  *
//  */
// constexpr auto LuaConfigPath{
//     std::string(getDebugLuaRootPath()) +
//     "/MassCalculator/resources/materials/alloy_coppers_config.lua"};
// #else
// /**
//  * @brief Lua config path when we are in release mode, it will get the
//  resources
//  * from the install directory
//  *
//  */
// constexpr char[] kEnvironment{getenv("HOME")};
// constexpr auto LuaConfigPath{   +
// "/.MassCalculator/resources/materials/alloy_coppers_config.lua"};
