/**
 * @file brass.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains constant expressions that define the keys to get
 * the values of the different types of brass.
 * @version 0.1
 * @date 2023-10-18
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
#ifndef MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_CONSTANTS_BRASS_H_
#define MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_CONSTANTS_BRASS_H_
#include <string> // for std::string

#include "masscalculator/masscalculator-core/resources.h" // for core::kResourcesPath

/**
 * @brief MassCalculator Core Materials Constants Brass namespace
 */
namespace masscalculator::core::materials::constants::brass {
// ! String constant for material Brass type 240 Low.
constexpr auto k240Low{"k240Low"};
// ! String constant for material Brass type 260 Cartridge.
constexpr auto k260Cartridge{"k260Cartridge"};
// ! String constant for material Brass type 353 Leaded.
constexpr auto k353Leaded{"k353Leaded"};
// ! String constant for material Brass type 360.
constexpr auto k360{"k360"};
// ! String constant for material Brass type 365.
constexpr auto k365{"k365"};
// ! String constant for material Brass type 380.
constexpr auto k380{"k380"};
// ! String constant for material Brass type 385.
constexpr auto k385{"k385"};
// ! String constant for material Brass type 464.
constexpr auto k464{"k464"};
// ! String constant for Unspecified Brass type.
constexpr auto kUnspecified{"Unspecified"};
// ! Key to get the config suffix for this material type.
constexpr auto kConfigKey{"materials/brass_config.lua"};
// ! String constant to get path to the configuration for this material type.
const std::string kConfigPath{std::string(core::kResourcesPath) +
                              std::string(kConfigKey)};
} // namespace masscalculator::core::materials::constants::brass
#endif // MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_CONSTANTS_BRASS_H_
