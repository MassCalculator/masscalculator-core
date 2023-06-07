/**
 * @file aluminium.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains constant expressions that define the keys to get
 * the values of the different types of aluminium.
 * @version 0.1
 * @date 2023-06-01
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
#ifndef MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_CONSTANTS_ALUMINIUM_H_
#define MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_CONSTANTS_ALUMINIUM_H_
#include <string> // for std::string

#include "masscalculator/masscalculator-core/resources.h" // for core::kResourcesPath

/**
 * @brief MassCalculator Core Materials Constants Aluminium namespace
 */
namespace masscalculator::core::materials::constants::aluminium {
// ! String constant for material Aluminium type 1100.
constexpr auto k1100{"k1100"};
// ! String constant for material Aluminium type 2011.
constexpr auto k2011{"k2011"};
// ! String constant for material Aluminium type 2014.
constexpr auto k2014{"k2014"};
// ! String constant for material Aluminium type 2024.
constexpr auto k2024{"k2024"};
// ! String constant for material Aluminium type 3003.
constexpr auto k3003{"k3003"};
// ! String constant for material Aluminium type 5052.
constexpr auto k5052{"k5052"};
// ! String constant for material Aluminium type 6061.
constexpr auto k6061{"k6061"};
// ! String constant for material Aluminium type 6063.
constexpr auto k6063{"k6063"};
// ! String constant for material Aluminium type 7075.
constexpr auto k7075{"k7075"};
// ! String constant for Unspecified Aluminium type.
constexpr auto kUnspecified{"Unspecified"};
// ! Key to get the config suffix for this material type.
constexpr auto kConfigKey{"materials/aluminium_config.lua"};
// ! String constant to get path to the configuration for this material type.
const std::string kConfigPath{std::string(core::kResourcesPath) +
                              std::string(kConfigKey)};
} // namespace masscalculator::core::materials::constants::aluminium
#endif // MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_CONSTANTS_ALUMINIUM_H_
