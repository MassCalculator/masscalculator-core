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
        std::cout << "Error: failed to load (" << filename << ")" << std::endl;
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
        std::clog << "Lua is initialized for specific material" << std::endl;
        return true;
      }
      else
      {
        std::cerr << "Lua is not initialized" << std::endl;
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
      std::cerr << "Error: can't get [" << variableName << "]. " << reason << std::endl;
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
