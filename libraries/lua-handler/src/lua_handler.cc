/**
 * @file lua_handler.cc
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Implementation of the LuaScriptHandler class, which encapsulates
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
#include "lua_handler.h" // for LuaScriptHandler

#include "masscalculator/base/macro_logger.hpp" // for LOG_*

extern "C" {
#include "lua5.1/lauxlib.h" // for luaL_newstate, luaL_loadfile
#include "lua5.1/lua.h"     // for lua_State and lua_*
#include "lua5.1/lualib.h"  // for luaL_openlibs
}

namespace masscalculator {

LuaScriptHandler::LuaScriptHandler(const std::string& filename) {
  if (!LuaOpen(filename)) {
    LOG_ERROR("Failed to open file: %s", filename.c_str());
  }
}

bool LuaScriptHandler::LuaOpen(const std::string& filename) {
  lua_state_ = luaL_newstate();

  if ((luaL_loadfile(lua_state_, filename.c_str()) != 0) ||
      (lua_pcall(lua_state_, 0, 0, 0) != 0)) {
    LOG_ERROR("Error: failed to load (%s)", filename.c_str());
    lua_state_ = nullptr;
  }

  if (lua_state_ != nullptr) {
    luaL_openlibs(lua_state_);
  }

  return true;
}

bool LuaScriptHandler::LuaGetToStack(const std::string& variable_name) {
  int level = 0;
  std::string var = "";

  for (unsigned int i = 0; i < variable_name.size(); i++) {
    if (variable_name.at(i) == '.') {
      if (level == 0) {
        lua_getglobal(lua_state_, var.c_str());
      } else {
        lua_getfield(lua_state_, -1, var.c_str());
      }

      if (lua_isnil(lua_state_, -1)) {
        LOG_ERROR("Can't get [%s]. %s is not defined", variable_name.c_str(),
                  var.c_str());
        return false;
      }
      var = "";
      level++;

    } else {
      var += variable_name.at(i);
    }
  }

  if (level == 0) {
    lua_getglobal(lua_state_, var.c_str());
  } else {
    lua_getfield(lua_state_, -1, var.c_str());
  }

  if (lua_isnil(lua_state_, -1)) {
    LOG_ERROR("Can't get [%s]. %s is not defined", variable_name.c_str(),
              var.c_str());
    return false;
  }

  return true;
}

bool LuaScriptHandler::LuaClean() {
  int n = lua_gettop(lua_state_);
  lua_pop(lua_state_, n);

  return true;
}

bool LuaScriptHandler::LuaClose() {
  if (lua_state_ != nullptr) {
    lua_close(lua_state_);
  }

  return true;
}

LuaScriptHandler::~LuaScriptHandler() {
  if (!LuaClose()) {
    LOG_ERROR("Failed to close Lua Script");
  }
}
} // namespace masscalculator
