#include "lua_handler.hpp"

namespace MassCalculator
{
  namespace HelperClasses
  {
    LuaScriptHandler::~LuaScriptHandler() 
    {
      if(L)
      {
        lua_close(L);
      }
    }

    bool LuaScriptHandler::openScript(const std::string &filename)
    {
      L = luaL_newstate();
      if (luaL_loadfile(L, filename.c_str()) || lua_pcall(L, 0, 0, 0)) 
      {
        LOG_ERROR("Error: failed to load (%s)", filename.c_str());
        L = 0;
      }

      if(L)
      {
        luaL_openlibs(L);
        return true;
      }

      return false;
    }

    bool LuaScriptHandler::isInitialized(void)
    {
      if(this->L)
      {
        //@todo: check if the log shows in release
        // std::clog << "Lua is initialized for specific material" << std::endl;
        return true;
      }
      else
      {
        LOG_ERROR("Lua is not initialized: %s", __PRETTY_FUNCTION__);
        return false;
      }
    }

    bool LuaScriptHandler::closeScript(void)
    {
      this->~LuaScriptHandler();
      return true;
    }

    void LuaScriptHandler::printError(const std::string& variableName, const std::string& reason) 
    {
      LOG_ERROR("Error: can't get [%s]. %s", variableName.c_str(), reason.c_str());
    }

    std::vector<int> LuaScriptHandler::getIntVector(const std::string& name) 
    {
      std::vector<int> v;
      lua_gettostack(name.c_str());
      if(lua_isnil(L, -1)) 
      {
        return std::vector<int>();
      }

      lua_pushnil(L);
      while(lua_next(L, -2)) 
      {
        v.push_back(static_cast<int>(lua_tonumber(L, -1)));
        lua_pop(L, 1);
      }

      clean();
      return v;
    }
  }// End namespace HelperClasses
}// End namespace MassCalculator
