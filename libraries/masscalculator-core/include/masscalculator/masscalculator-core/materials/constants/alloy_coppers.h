/**
 * @file alloy_coppers.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains constant expressions that define the keys to get
 * the values of the different types of alloy coppers.
 * @version 0.2
 * @date 2023-04-03
 *
 * @copyright Copyright (c) 2023, MassCalculator, Org., All rights reserved.
 * @license This project is released under the  MIT license (MIT).
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_CONSTANTS_ALLOY_COPPERS_H_
#define MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_CONSTANTS_ALLOY_COPPERS_H_
#include <string> // for std::string

#include "masscalculator/masscalculator-core/resources.h" // for core::kResourcesPath

namespace masscalculator::core::materials::constants::alloycopper {
// ! String constant for material AlloyCopper type 145Tellvirum.
constexpr auto k145Telluirum{"k145Telluirum"};
// ! String constant for material AlloyCopper type 194Iron.
constexpr auto k194Iron{"k194Iron"};
// ! String constant for material AlloyCopper type 195Iron.
constexpr auto k195Iron{"k195Iron"};
// ! String constant for material AlloyCopper type 172Beryllium.
constexpr auto k172Beryllium{"k172Beryllium"};
// ! String constant for material AlloyCopper type 182Class2.
constexpr auto k182Class2{"k182Class2"};
// ! String constant for material AlloyCopper type 655Silicon.
constexpr auto k655Silicon{"k655Silicon"};
// ! String constant for material AlloyCopper type 706Nickel.
constexpr auto k706Nickel{"k706Nickel"};
// ! String constant for material AlloyCopper type 715NickelSilver.
constexpr auto k715NickelSilver{"k715NickelSilver"};
// ! String constant for material AlloyCopper type 725NickelSilver.
constexpr auto k725NickelSilver{"k725NickelSilver"};
// ! String constant for material AlloyCopper type 735NickelSilver.
constexpr auto k735NickelSilver{"k735NickelSilver"};
// ! String constant for material AlloyCopper type 752NickelSilver.
constexpr auto k752NickelSilver{"k752NickelSilver"};
// ! String constant for material AlloyCopper type 762NickelSilver.
constexpr auto k762NickelSilver{"k762NickelSilver"};
// ! String constant for material AlloyCopper type 770NickelSilver.
constexpr auto k770NickelSilver{"k770NickelSilver"};
// ! String constant for material AlloyCopper type 1751Class3.
constexpr auto k1751Class3{"k1751Class3"};
// ! String constant for material AlloyCopper type 1758Nickel.
constexpr auto k1758Nickel{"k1758Nickel"};
// ! String constant for material AlloyCopper type MoldmaxBeCu.
constexpr auto kMoldmaxBeCu{"kMoldmaxBeCu"};
// ! String constant for material AlloyCopper type ProthermBeCu.
constexpr auto kProthermBeCu{"kProthermBeCu"};
// ! String constant for Unspecified AlloyCopper type.
constexpr auto kUnspecified{"Unspecified"};
// ! Key to get the config suffix for this material type.
constexpr auto kConfigKey{"materials/alloy_coppers_config.lua"};
// ! String constant to get path to the configuration for this material type.
const std::string kConfigPath{std::string(core::kResourcesPath) +
                              std::string(kConfigKey)};
} // namespace masscalculator::core::materials::constants::alloycopper
#endif // MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_CONSTANTS_ALLOY_COPPERS_H_
