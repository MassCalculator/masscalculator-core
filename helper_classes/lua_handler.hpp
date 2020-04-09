/**
 * @file lua_handler.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief LuaScriptHandler Class that holds all the nessesary functions and specialisations to get from lua files
 * @version 0.1
 * @date 2020-03-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___HELPER_CLASSES_H___
#define ___HELPER_CLASSES_H___
#include <string>
#include <vector>

#include "../helper_headers/macro_logger.hpp"

// Lua is written in C, so compiler needs to know how to link its libraries
extern "C" 
{
  #include "lua5.1/lua.h"
  #include "lua5.1/lualib.h"
  #include "lua5.1/lauxlib.h"
}

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
  namespace HelperClasses
  {
    /**
     * @brief Class LuaScriptHandler, that holds all the nessesary functions and specialisations to get from lua files
     * @todo Refactor the class, check the names and add documentation
     * 
     */
    class LuaScriptHandler 
    {
      public:
        /**
         * @brief Construct a new Lua Script Handler object
         * 
         */
        LuaScriptHandler(void) = default;

        /**
         * @brief Destroy the Lua Script Handler object
         * 
         */
        ~LuaScriptHandler();
        
        /**
         * @brief @todo add documentation
         * 
         * @param filename 
         * @return true 
         * @return false 
         */
        bool openScript(const std::string &filename);

        /**
         * @brief @todo add documentation
         * 
         * @return true 
         * @return false 
         */
        bool isInitialized(void);

        /**
         * @brief @todo add documentation
         * 
         * @return true 
         * @return false 
         */
        bool closeScript(void);

        /**
         * @brief @todo add documentation
         * 
         * @param variableName 
         * @param reason 
         */
        void printError(const std::string& variableName, const std::string& reason);

        /**
         * @brief Get the Int Vector object
         * 
         * @param name 
         * @return std::vector<int> 
         */
        std::vector<int> getIntVector(const std::string& name);
        
        /**
         * @brief @todo add documentation
         * 
         */
        inline void clean() 
        {
          int n = lua_gettop(L);
          lua_pop(L, n);
        }

        /**
         * @brief @todo add documentation
         * 
         * @tparam T 
         * @param variableName 
         * @return T 
         */
        template<typename T>
        T get(const std::string& variableName) 
        {
          if(!L) 
          {
            printError(variableName, "Script is not loaded");
            return lua_getdefault<T>();
          }
          
          T result;
          if(lua_gettostack(variableName))
          {
            result = lua_get<T>(variableName);  
          } 
          else 
          {
            result = lua_getdefault<T>();
          }
        
          clean();
          return result;
        }

        /**
         * @brief @todo add documentation
         * 
         * @param variableName 
         * @return true 
         * @return false 
         */
        bool lua_gettostack(const std::string& variableName) 
        {
          level = 0;
          std::string var = "";
          
          for(unsigned int i = 0; i < variableName.size(); i++) 
          {
            if(variableName.at(i) == '.') 
            {
              if(level == 0) 
              {
                lua_getglobal(L, var.c_str());
              }
              else
              {
                lua_getfield(L, -1, var.c_str());
              }
              
              if(lua_isnil(L, -1)) 
              {
                printError(variableName, var + " is not defined");
                return false;
              }
              else 
              {
                var = "";
                level++;
              }
            }
            else
            {
              var += variableName.at(i);
            }
          }

          if(level == 0) 
          {
            lua_getglobal(L, var.c_str());
          } 
          else
          {
            lua_getfield(L, -1, var.c_str());
          }

          if(lua_isnil(L, -1)) 
          {
            printError(variableName, var + " is not defined");
            return false;
          }

          return true;       
        }

        /**
         * @brief Generic get function
         * 
         * @tparam T 
         * @param variableName 
         * @return T 
         */
        template<typename T>
        T lua_get(const std::string& variableName)
        {
          return 0;
        }

        /**
         * @brief @todo add documentation
         * 
         * @tparam T 
         * @return T 
         */
        template<typename T>
        T lua_getdefault()
        {
          return 0;
        }

      private:
        /**
         * @brief @todo add documentation
         * 
         */
        lua_State* L;

        /**
         * @brief @todo add documentation
         * 
         */
        std::string filename_;

        /**
         * @brief @todo add documentation
         * 
         */
        int level;
    };

    //Specialisations

    /**
     * @brief @todo add documentation
     * 
     * @tparam test
     * @param variableName 
     * @return true 
     * @return false 
     */
    template <> 
    inline bool LuaScriptHandler::lua_get<bool>(const std::string& variableName) 
    {
      return static_cast<bool>(lua_toboolean(L, -1));
    }

    /**
     * @brief @todo add documentation
     * 
     * @tparam test
     * @param variableName 
     * @return float 
     */
    template <> 
    inline float LuaScriptHandler::lua_get<float>(const std::string& variableName) 
    {
      if(!lua_isnumber(L, -1)) 
      {
        printError(variableName, "Not a number");
      }

      return static_cast<float>(lua_tonumber(L, -1));
    }

    /**
     * @brief @todo add documentation
     * 
     * @tparam test
     * @param variableName 
     * @return double 
     */
    template <>
    inline double LuaScriptHandler::lua_get<double>(const std::string& variableName) 
    {
      if(!lua_isnumber(L, -1)) 
      {
        printError(variableName, "Not a number");
      }

      return static_cast<double>(lua_tonumber(L, -1));
    }

    /**
     * @brief @todo add documentation
     * 
     * @tparam test
     * @param variableName 
     * @return int 
     */
    template <>
    inline int LuaScriptHandler::lua_get<int>(const std::string& variableName) 
    {
      if(!lua_isnumber(L, -1)) 
      {
        printError(variableName, "Not a number");
      }

      return static_cast<int>(lua_tonumber(L, -1));
    }

    /**
     * @brief @todo add documentation
     * 
     * @tparam test
     * @param variableName 
     * @return std::string 
     */
    template <>
    inline std::string LuaScriptHandler::lua_get<std::string>(const std::string& variableName) 
    {
      std::string s = "null";
      if(lua_isstring(L, -1)) 
      {
        s = std::string(lua_tostring(L, -1));
      } 
      else 
      {
        printError(variableName, "Not a string");
      }

      return s;
    }

    /**
     * @brief @todo add documentation
     * 
     * @tparam test
     * @return std::string 
     */
    template<>
    inline std::string LuaScriptHandler::lua_getdefault<std::string>() 
    {
      return "null";
    }

  }// End namespace HelperClasses
}// End namespace MassCalculator
#endif//___HELPER_CLASSES_H___