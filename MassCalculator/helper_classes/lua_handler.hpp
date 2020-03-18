#ifndef ___HELPER_CLASSES_H___
#define ___HELPER_CLASSES_H___

#include <string>
#include <vector>
#include <iostream>

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
     * 
     */
    class LuaScriptHandler 
    {
      public:
        LuaScriptHandler(void) = default;
        ~LuaScriptHandler();
        
        bool openScript(const std::string &filename);
        bool isInitialized(void);
        bool closeScript(void);

        void printError(const std::string& variableName, const std::string& reason);
        std::vector<int> getIntVector(const std::string& name);
        
        inline void clean() 
        {
          int n = lua_gettop(L);
          lua_pop(L, n);
        }

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

        // Generic get
        template<typename T>
        T lua_get(const std::string& variableName) {
          return 0;
        }

        template<typename T>
        T lua_getdefault() {
          return 0;
        }

      private:
        lua_State* L;
        std::string filename_;
        int level;
    };

    //Specialisations
    template <> 
    inline bool LuaScriptHandler::lua_get<bool>(const std::string& variableName) 
    {
      return static_cast<bool>(lua_toboolean(L, -1));
    }

    template <> 
    inline float LuaScriptHandler::lua_get<float>(const std::string& variableName) 
    {
      if(!lua_isnumber(L, -1)) 
      {
        printError(variableName, "Not a number");
      }

      return static_cast<float>(lua_tonumber(L, -1));
    }

    template <>
    inline double LuaScriptHandler::lua_get<double>(const std::string& variableName) 
    {
      if(!lua_isnumber(L, -1)) 
      {
        printError(variableName, "Not a number");
      }

      return static_cast<double>(lua_tonumber(L, -1));
    }

    template <>
    inline int LuaScriptHandler::lua_get<int>(const std::string& variableName) 
    {
      if(!lua_isnumber(L, -1)) 
      {
        printError(variableName, "Not a number");
      }

      return static_cast<int>(lua_tonumber(L, -1));
    }

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

    template<>
    inline std::string LuaScriptHandler::lua_getdefault<std::string>() 
    {
      return "null";
    }

  }// End namespace HelperClasses
}// End namespace MassCalculator
#endif
