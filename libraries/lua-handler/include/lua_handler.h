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

#include "macro_logger.hpp"

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
namespace masscalculator
{

    /**
     * @brief Class LuaScriptHandler, that holds all the nessesary functions and specialisations to get from lua files
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
         * @brief Function that opens the Lua script
         * 
         * @param filename Path to the Lua script
         * @return true if script is opened successfully
         * @return false if script failed to open
         */
        bool openScript(const std::string &filename);

        /**
         * @brief Function that initializes the Lua script
         * 
         * @return true if initialization is successful
         * @return false if initialization failed
         */
        bool isInitialized(void);

        /**
         * @brief Function to close the Lua script
         * 
         * @return true if the script closed successfully
         * @return false if script failed to close
         */
        bool closeScript(void);

        /**
         * @brief Function to print the error
         * 
         * @param variableName Lua parameter
         * @param reason Reason of error
         */
        void printError(const std::string& variableName, const std::string& reason);

        /**
         * @brief Get the Int Vector object
         * 
         * @param name Lua vector parameter
         * @return std::vector<int> with the values from Lua script
         */
        std::vector<int> getIntVector(const std::string& name);
        
        /**
         * @brief Clean Lua stack
         * 
         */
        inline void clean() 
        {
          int n = lua_gettop(L);
          lua_pop(L, n);
        }

        /**
         * @brief Generic getter for Lua parameter
         * 
         * @tparam T Type of the Lua parameter
         * @param variableName Name of the Lua parameter
         * @return T Type of Lua parameter
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
         * @brief Function to get to the Lua script stack
         * 
         * @param variableName Parameter from Lua script
         * @return true If the parameter found successfully
         * @return false If parameter failed to get
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
         * @tparam T Type for Lua parameter
         * @param variableName Parameter from Lua script
         * @return T Type for return parameter
         */
        template<typename T>
        T lua_get(const std::string& /*variableName*/)
        {
          return 0;
        }

        /**
         * @brief Function to get default
         * 
         * @tparam T Type for Lua parameter
         * @return T Type for return parameter
         */
        template<typename T>
        T lua_getdefault()
        {
          return 0;
        }

      private:
        /**
         * @brief Variable to store the Lua state
         * 
         */
        lua_State* L;

        /**
         * @brief Variable to store the script filename
         * 
         */
        std::string filename_;

        /**
         * @brief Variable to store the Lua stack level
         * 
         */
        int level;
    };

    /**
     * @brief Specialisation to get Lua parameter as bool
     * 
     * @tparam bool
     * @param variableName Parameter name in Lua script
     * @return true if parameter get is successfully
     * @return false if parameter failed to get
     */
    template <> 
    inline bool LuaScriptHandler::lua_get<bool>(const std::string& variableName) 
    {
      if(!lua_isboolean(L, -1)) 
      {
        printError(variableName, "Not a boolean");
      }

      return static_cast<bool>(lua_toboolean(L, -1));
    }

    /**
     * @brief Specialisation to get Lua parameter as float
     * 
     * @tparam float
     * @param variableName Parameter name in Lua script
     * @return float Parameter as float type
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
     * @brief Specialisation to get Lua parameter as double
     * 
     * @tparam double
     * @param variableName Parameter name in Lua script
     * @return double Parameter as double type
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
     * @brief Specialisation to get Lua parameter as int
     * 
     * @tparam int
     * @param variableName Parameter name in Lua script
     * @return int Parameter as int type
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
     * @brief Specialisation to get Lua parameter as std::string
     * 
     * @tparam std::string
     * @param variableName Parameter name in Lua script
     * @return std::string Parameter as std::string type
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
     * @brief Specialisation to get Lua parameter as default
     * 
     * @tparam std::string
     * @param variableName Parameter name in Lua script
     * @return std::string Parameter as default std::string type
     */
    template<>
    inline std::string LuaScriptHandler::lua_getdefault<std::string>() 
    {
      return "null";
    }

}// End namespace masscalculator
#endif//___HELPER_CLASSES_H___
