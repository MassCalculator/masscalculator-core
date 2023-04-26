/**
 * @file alloy_steels.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains constant expressions that define the keys to get
 * the values of the different types of alloy steels.
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
#ifndef MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_CONSTANTS_ALLOY_STEELS_H_
#define MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_CONSTANTS_ALLOY_STEELS_H_
#include <string> // for std::string

#include "masscalculator/masscalculator-core/resources.h" // for core::kResourcesPath

/**
 * @brief MassCalculator Core Materials Constants AlloySteel namespace
 */
namespace masscalculator::core::materials::constants::alloysteel {
// ! String constant for material AlloySteel type 4135.
constexpr auto k4135{"k4135"};
// ! String constant for material AlloySteel type 4140.
constexpr auto k4140{"k4140"};
// ! String constant for material AlloySteel type 4340.
constexpr auto k4340{"k4340"};
// ! String constant for Unspecified AlloySteel type.
constexpr auto kUnspecified{"Unspecified"};
// ! Key to get the config suffix for this material type.
constexpr auto kConfigKey{"materials/alloy_steels_config.lua"};
// ! String constant to get path to the configuration for this material type.
const std::string kConfigPath{std::string(core::kResourcesPath) +
                              std::string(kConfigKey)};
} // namespace masscalculator::core::materials::constants::alloysteel
#endif // MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_CONSTANTS_ALLOY_STEELS_H_
