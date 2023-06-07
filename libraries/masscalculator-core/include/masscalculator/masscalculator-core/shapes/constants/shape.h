/**
 * @file shape.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains constant expressions that define the keys to get
 * the the different types of shapes.
 * @version 0.1
 * @date 2023-04-13
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
#ifndef MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_SHAPES_CONSTANTS_SHAPE_H_
#define MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_SHAPES_CONSTANTS_SHAPE_H_

/**
 * @brief MassCalculator Core Shapes Constants Shape namespace
 */
namespace masscalculator::core::shapes::constants::shape {
// ! String constant for Angle shape.
constexpr auto kAngle{"Angle"};
// ! String constant for Bar shape.
constexpr auto kBar{"Bar"};
// ! String constant for Beam shape.
constexpr auto kBeam{"Beam"};
// ! String constant for Channel shape.
constexpr auto kChannel{"Channel"};
// ! String constant for Cylinder shape.
constexpr auto kCylinder{"Cylinder"};
// ! String constant for DxfShape shape.
constexpr auto kDxfShape{"DxfShape"};
// ! String constant for Ellipse shape.
constexpr auto kEllipse{"Ellipse"};
// ! String constant for HexagonBar shape.
constexpr auto kHexagonBar{"HexagonBar"};
// ! String constant for OctagonBar shape.
constexpr auto kOctagonBar{"OctagonBar"};
// ! String constant for Pipe shape.
constexpr auto kPipe{"Pipe"};
// ! String constant for Sheet shape.
constexpr auto kSheet{"Sheet"};
// ! String constant for SquareBar shape.
constexpr auto kSquareBar{"SquareBar"};
// ! String constant for SquareTubing shape.
constexpr auto kSquareTubing{"SquareTubing"};
// ! String constant for StlShape shape.
constexpr auto kStlShape{"StlShape"};
// ! String constant for TBar shape.
constexpr auto kTBar{"TBar"};
// ! String constant for Unspecified shape.
constexpr auto kUnspecified{"Unspecified"};
} // namespace masscalculator::core::shapes::constants::shape
#endif // MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_CORE_SHAPES_CONSTANTS_SHAPE_H_
