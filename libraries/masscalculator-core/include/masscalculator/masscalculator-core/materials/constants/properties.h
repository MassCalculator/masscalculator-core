/**
 * @file properties.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains constant expressions that define the keys to get
 * the values of the different properties of a material.
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
#ifndef MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_CONSTANTS_PROPERTIES_H_
#define MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_CONSTANTS_PROPERTIES_H_
namespace masscalculator::core::materials::constants::properties {
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
} // namespace masscalculator::core::materials::constants::properties
#endif // MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_MATERIALS_CONSTANTS_PROPERTIES_H_
