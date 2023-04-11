/**
 * @file lua_handler.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Definition of the LuaScriptHandler class, which encapsulates
 * the definition and specializations for handling Lua scripts. It provides
 * an interface to interact with Lua scripts and execute Lua functions from
 * C++ code.
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
#ifndef MASSCALCULATOR_LIBRARIES_LUA_HANDLER_INCLUDE_LUA_HANDLER_H_
#define MASSCALCULATOR_LIBRARIES_LUA_HANDLER_INCLUDE_LUA_HANDLER_H_
#include <string> // for std::string
#include <vector> // for std::vector

#include "masscalculator/masscalculator-base/macro_logger.h" // for LOG_*

extern "C" {
#include "lua5.1/lauxlib.h" // for luaL_newstate, luaL_loadfile
#include "lua5.1/lua.h"     // for lua_State and lua_*
#include "lua5.1/lualib.h"  // for luaL_openlibs
}

/**
 * @brief Default namespace
 */
namespace masscalculator::base {

/**
 * @brief Class LuaScriptHandler, that holds all the nessesary functions and
 * specialisations to get from lua files
 */
class LuaScriptHandler {
 public:
  /**
   * @brief Construct a new Lua Script Handler object
   */
  explicit LuaScriptHandler(const std::string& filename);

  /**
   * @brief Destroy the Lua Script Handler object
   */
  ~LuaScriptHandler();

  /**
   * @brief Get a value from Lua config.
   *
   * @tparam TLuaReturnType The return type.
   * @param value The name of the value in Lua config.
   * @return The value of the specified type.
   */
  template <typename TLuaReturnType>
  TLuaReturnType Get(const std::string& variable_name) {
    if (lua_state_ != nullptr) {
      if (LuaGetToStack(variable_name)) {
        return LuaGet<TLuaReturnType>(variable_name.c_str());
      }
    }

    LuaClean();
    return TLuaReturnType{};
  }

  /**
   * @brief Get a value from Lua config, or a default value if Lua config is not
   * used.
   *
   * @tparam TLuaReturnType The return type.
   * @tparam TValue The type of the default value.
   * @param value The name of the value in Lua config.
   * @param default_value The default value.
   * @return The value from Lua config if available, otherwise the default
   * value.
   */
  template <typename TLuaReturnType, typename TValue>
  TLuaReturnType GetOrDefault(const std::string& value,
                              const TValue& default_value) {
    auto pos = value.find_last_of(".");
    if (pos == std::string::npos) {
      // handle error case where '.' is not found in the string
    }
    std::string new_value = value.substr(0, pos) + ".UseLuaConfig";
    if (Get<bool>(new_value.c_str())) {
      return static_cast<TLuaReturnType>(Get<TLuaReturnType>({value}));
    }
    return static_cast<TLuaReturnType>(default_value);
  }

 private:
  /**
   * @brief Opens the Lua state and standard libraries, and loads the specified
   * Lua script file into the state.
   *
   * @param filename The name of the Lua script file to load.
   * @return true if the Lua state was opened and the script was loaded
   * successfully, false otherwise.
   */
  bool LuaOpen(const std::string& filename);

  /**
   * @brief Retrieves a variable from the Lua script and pushes it onto the Lua
   * stack.
   *
   * @param variable_name The name of the variable to retrieve from the Lua
   * script.
   * @return true if the variable was found and pushed onto the stack
   * successfully, false otherwise.
   */
  bool LuaGetToStack(const std::string& variable_name);

  /**
   * @brief Cleans the Lua stack by removing all values from it.
   *
   * @return true if the Lua stack was cleaned successfully, false otherwise.
   */
  bool LuaClean();

  /**
   * @brief Closes the Lua state and frees all associated resources.
   *
   * @return true if the Lua state was closed successfully, false otherwise.
   */
  bool LuaClose();

  /**
   * @brief Generic function template to retrieve a Lua parameter of type `T`.
   *
   * @tparam TLuaReturnType The type of the parameter to retrieve.
   * @param variable_name The name of the Lua parameter to retrieve.
   * @return TLuaReturnType The value of the Lua parameter as type
   * `TLuaReturnType`.
   */
  template <typename TLuaReturnType>
  TLuaReturnType LuaGet(const std::string& variable_name) {
    if (lua_isnumber(lua_state_, -1) == 0) {
      LOG_ERROR("Can't get [%s]. Not a number", variable_name.c_str());
    }

    return static_cast<TLuaReturnType>(lua_tonumber(lua_state_, -1));
  }

  /**
   * @brief Pointer to the Lua state object.
   *
   * This data member is used to store the pointer to the Lua state object
   * created by `luaL_newstate`. It is used to interact with the Lua interpreter
   * API functions.
   */
  lua_State* lua_state_;
};

/**
 * @brief Specialization of the `LuaGet` function template to retrieve a Lua
 * parameter as a `bool`.
 *
 * @tparam bool The type of the parameter to retrieve.
 * @param variable_name The name of the Lua parameter to retrieve.
 * @return bool The value of the Lua parameter as a `bool`.
 */
template <>
inline bool LuaScriptHandler::LuaGet<bool>(const std::string& variable_name) {
  if (!lua_isboolean(lua_state_, -1)) {
    LOG_ERROR("Can't get [%s]. Not a boolean", variable_name.c_str());
  }

  return static_cast<bool>(lua_toboolean(lua_state_, -1));
}

/**
 * @brief Specialization of the `LuaGet` function template to retrieve a Lua
 * parameter as a `std::string`.
 *
 * @tparam std::string The type of the parameter to retrieve.
 * @param variable_name The name of the Lua parameter to retrieve.
 * @return std::string The value of the Lua parameter as a `std::string`.
 */
template <>
inline std::string LuaScriptHandler::LuaGet<std::string>(
    const std::string& variable_name) {
  if (lua_isstring(lua_state_, -1) == 0) {
    LOG_ERROR("Can't get [%s]. Not a string", variable_name.c_str());
  }

  return lua_tostring(lua_state_, -1);
}

/**
 * @brief Specialization of the `LuaGet` function template to retrieve a Lua
 * parameter as a `std::string_view`.
 *
 * @tparam std::string_view The type of the parameter to retrieve.
 * @param variable_name The name of the Lua parameter to retrieve.
 * @return std::string_view The value of the Lua parameter as a
 * `std::string_view`.
 */
template <>
inline std::string_view LuaScriptHandler::LuaGet<std::string_view>(
    const std::string& variable_name) {
  if (lua_isstring(lua_state_, -1) == 0) {
    LOG_ERROR("Can't get [%s]. Not a string", variable_name.c_str());
  }

  const char* str = lua_tostring(lua_state_, -1);
  size_t len = lua_strlen(lua_state_, -1);
  return {str, len};
}
} // namespace masscalculator::base
#endif // MASSCALCULATOR_LIBRARIES_LUA_HANDLER_INCLUDE_LUA_HANDLER_H_
