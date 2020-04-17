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
      std::stringstream ss;
      ss << xstr(ROOT_PATH);
      return{std::string(ss.str())};
    }

    std::string getName(void)
    {
      std::stringstream ss;
      ss << "libMassCalculator";
      return{std::string(ss.str())};
    }

    std::string getVersion(void)
    {
      std::stringstream ss;
      ss << getName() << " version: " << LIBMASSCALCULATOR_MAJOR_VERSION << "." << LIBMASSCALCULATOR_MINOR_VERSION << "." << LIBMASSCALCULATOR_PATCH_VERSION;
      return{std::string(ss.str())};
    }
  }// End namespace HelperFunctions
}// End namespace MassCalculator
