/**
 * @file helper_functions.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This file holds all the functions that are not specified for a class, but are needed
 * throughout the code as helpers
 * @version 0.1
 * @date 2020-03-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___HELPER_FUNCTIONS_H___
#define ___HELPER_FUNCTIONS_H___
#include "lua_handler.hpp"
using namespace MassCalculator::HelperClasses;

/**
 * @brief Stringify a string macro (Used to stringify the path parset from cmake)
 * 
 */
#define stringify(a) #a
#define xstr(a) stringify(a)

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
    /**
     * @brief @todo add documentation
     * 
     * @param lua_state 
     * @param config_path 
     * @return true 
     * @return false 
     */
    bool initLuaConfig(LuaScriptHandler &&lua_state, const std::string &config_path);

    /**
     * @brief @todo add documentation
     * 
     * @param lua_state 
     * @param value 
     * @return true 
     * @return false 
     */
    bool checkFromLuaConfig(LuaScriptHandler &&lua_state, const std::string &value);

    /**
     * @brief @todo add documentation
     * 
     * @tparam TLuaReturnType 
     * @param lua_state 
     * @param value 
     * @return constexpr TLuaReturnType 
     */
    template<typename TLuaReturnType>
    constexpr TLuaReturnType getFromLuaConfig(LuaScriptHandler &&lua_state, const std::string &value)
    {
      return lua_state.get<TLuaReturnType>(value);
    }

    /**
     * @brief Get the Debug Lua Root Path object
     * 
     * @return const std::string 
     */
    const std::string getDebugLuaRootPath(void);

    /**
     * @brief Get the Lib Interface Version object
     * 
     * @return unsigned int 
     */
    unsigned int getLibInterfaceVersion(void);

    /**
     * @brief @todo add documentation
     * 
     * @param lua_state 
     */
    void destroyLuaConfig(LuaScriptHandler *lua_state);

    /**
     * @brief @todo add documentation
     * 
     * @tparam T 
     * @param b 
     * @param x 
     * @param y 
     * @return T& 
     */
    template<class T> T& TTernaryOperator(bool b, T&x, T&y) { return b ? x : y; }
    template<class T> const T& TTernaryOperator(bool b, const T&x, const T&y) { return b ? x : y; }
  }// End namespace HelperFunctions
}// End namespace MassCalculator
#endif