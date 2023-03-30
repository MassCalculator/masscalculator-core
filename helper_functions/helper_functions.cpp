#include "helper_functions.hpp"

namespace MassCalculator
{
  namespace HelperFunctions
  {

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


todo: incorporate this into luahandler
find a way to globalise functios for getVersion and getName, find a better way.
finalise the cmakes and make a commit
add comments in toplevel cmake
add a todo to cmakelists to add the install target
add tests initial structure, and 