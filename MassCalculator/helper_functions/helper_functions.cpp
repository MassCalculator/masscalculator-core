#include "helper_functions.hpp"

namespace MassCalculator
{
  namespace HelperFunctions
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

    const std::string getDebugLuaRootPath(void)
    {
      return std::string(xstr(ROOT_PATH));
    }

    unsigned int getLibInterfaceVersion(void)
    {
      return 0;
      // return LIBINTERFACE_VERSION;
    }
  }// End namespace HelperFunctions
}// End namespace MassCalculator
