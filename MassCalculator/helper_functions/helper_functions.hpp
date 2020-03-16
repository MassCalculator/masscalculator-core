#ifndef ___HELPER_FUNCTIONS_H___
#define ___HELPER_FUNCTIONS_H___

#include <string>

#include "lua_handler.hpp"
using namespace MassCalculator::HelperClasses;

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator
{
  /**
   * @brief HelperClasses namespace
   * 
   */
  namespace HelperFunctions
  {
    bool initLuaConfig(LuaScriptHandler &&lua_state, const std::string &config_path);

    bool checkFromLuaConfig(LuaScriptHandler &&lua_state, const std::string &value);

    template<typename TLuaReturnType>
    constexpr TLuaReturnType getFromLuaConfig(LuaScriptHandler &&lua_state, const std::string &value)
    {
      return lua_state.get<TLuaReturnType>(value);
    }

    void destroyLuaConfig(LuaScriptHandler *lua_state);

    template<class T> T& TTernaryOperator(bool b, T&x, T&y) { return b ? x : y; }
    template<class T> const T& TTernaryOperator(bool b, const T&x, const T&y) { return b ? x : y; }
  }// End namespace HelperFunctions
}// End namespace MassCalculator
#endif