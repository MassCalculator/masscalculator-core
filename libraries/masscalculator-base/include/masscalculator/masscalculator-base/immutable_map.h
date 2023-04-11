/**
 * @file immutable_map.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Defines the ImmutableMap template class, which is a simple map
 * structure that can be declared as constexpr. This is a useful object to hold
 * pairs of matching values known at compile time.
 * @version 0.2
 * @date 2023-04-04
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
#ifndef MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_BASE_IMMUTABLE_MAP_H_
#define MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_BASE_IMMUTABLE_MAP_H_
#include <algorithm> // for std::find_if, begin and end
#include <array>     // for std::array

namespace masscalculator::base {

template <typename Key, typename Value, std::size_t Size>

/**
 * @brief A simple map structure that can be declared as constexpr.
 *  This is a useful object to hold pairs of matching values known at compile
 *  time.
 */
struct ImmutableMap {
  std::array<std::pair<Key, Value>, Size> data;

  // Map item accessors. Naming is kept lower case to intuitively map it to the
  // equivalent std::map accessor
  // NOLINTNEXTLINE(readability-identifier-naming)
  [[nodiscard]] constexpr Value at(const Key& key) const {
    const auto it = std::find_if(begin(data), end(data), [&key](const auto& v) {
      return v.first == key;
    });
    return it->second;
  }
};
} // namespace masscalculator::base
#endif // MASSCALCULATOR_CORE_LIBRARIES_MASSCALCULATOR_BASE_IMMUTABLE_MAP_H_
