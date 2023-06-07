/**
 * @file aluminium.cc
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file contains the implementation for the aluminium class.
 * The aluminium class holds all the specific properties for the different
 * types of aluminium. It inherits from the base class Material and provides
 * the getters and setters for the aluminium properties.
 * @version 0.3
 * @date 2023-06-02
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
#include "masscalculator/masscalculator-core/materials/aluminium.h" // for Aluminium

#include <memory>      // for std::make_unique
#include <stdexcept>   // for std::runtime_error
#include <string>      // for std::string
#include <string_view> // for std::string_view

#include "masscalculator/masscalculator-base/lua_handler.h" // for LuaScriptHandler
#include "masscalculator/masscalculator-base/macro_logger.h" // for LOG_*
#include "masscalculator/masscalculator-core/materials/constants/aluminium.h" // for aluminium::k*

namespace masscalculator::core::materials {
Aluminium::Aluminium(const std::string_view& sub_type) {
  specific_properties = std::make_unique<Properties>();
  lua_state = std::make_unique<base::LuaScriptHandler>(
      constants::aluminium::kConfigPath);

  if (specific_properties == nullptr || lua_state == nullptr) {
    throw std::runtime_error{"Aluminium failed to initialize..."};
  }

  if (const auto success = SetSubType(sub_type); !success) {
    LOG_ERROR("Construction of the object failed. %s", __PRETTY_FUNCTION__);
    throw std::runtime_error{"Aluminium failed to initialize..."};
  }
}

bool Aluminium::SetSubType(const std::string_view& sub_type) {
  auto pair = sub_type2func_.find(kSubType.at(sub_type));

  if (pair != sub_type2func_.end()) {
    pair->second();
  } else {
    LOG_ERROR("Could not set the values for type: %s.",
              std::string(GetSubType()).c_str());
  }

  return true;
}
} // namespace masscalculator::core::materials
