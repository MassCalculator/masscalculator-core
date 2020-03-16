#include "helper_functions.hpp"

namespace MassCalculator
{
  namespace HelperClasses
  {
    bool initLuaConfig(LuaScriptHandler &&lua_state, const std::string &config_path)
    {
      lua_state.openScript(config_path);
      return true;
    }

    bool checkFromLuaConfig(LuaScriptHandler &&lua_state, const std::string &value)
    {
      if(lua_state.isInitialized())
      {
        if(lua_state.get<bool>(value.c_str()))
        {
          return true;
        }
        else
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }

    void destroyLuaConfig(LuaScriptHandler *lua_state)
    {
      lua_state->closeScript();
    }
  }// End namespace HelperClasses
}// End namespace MassCalculator
