#ifndef ___HELPER_CLASSES_H___
#define ___HELPER_CLASSES_H___

// Lua is written in C, so compiler needs to know how to link its libraries
// extern "C" {
  #include "lua5.1/lua.h"
  #include "lua5.1/lualib.h"
  #include "lua5.1/lauxlib.h"
// }

namespace MassCalculator
{
  namespace HelperClasses
  {
    class LuaHandler
    {
      private:
        lua_State *lua_state_ptr;

      public:
        // get function
        template<typename TGet>
        TGet get(const char * varname) 
        {
          char temp[64];
          // TGet::memset(temp, 0, sizeof(temp));
          int i=0;
          int j=0;
          int n=0;
          while (varname[i] != '\0') {
            char c = varname[i];
            if (c == '.') {
              if (n == 0)
                lua_getglobal(lua_state_ptr, temp);
              else
                lua_getfield(lua_state_ptr, -1, temp);
              ++n;
              // TGet::memset(temp, 0, sizeof(temp));
              j = 0;

              if (lua_isnil(lua_state_ptr, -1))
                return 0;
            }
            else {
              temp[j] = c;
              ++j;
            }
            ++i;
          }
          if (n == 1)
            lua_getglobal(lua_state_ptr, temp);
          else
            lua_getfield(lua_state_ptr, -1, temp);
          return lua_get<TGet>();
        }

        // Generic get
        template<typename TLuaGet>
        TLuaGet lua_get() {
          return 0;
        }

    };

    //Functions

    template<typename Lhs, typename Rhs> class return_;

    // Specializations
    template <>
    float LuaHandler::lua_get<float>()
    {
      return lua_tonumber(lua_state_ptr, -1);
    }

    template <> double LuaHandler::lua_get<double>() {
      return lua_tonumber(lua_state_ptr, -1);
    }
    template <> bool LuaHandler::lua_get<bool>() {
      return lua_toboolean(lua_state_ptr, -1);
    }
    template <> int LuaHandler::lua_get<int>() {
      return lua_tointeger(lua_state_ptr, -1);
    }
    template <> unsigned int LuaHandler::lua_get<unsigned int>() {
      return static_cast<unsigned int>(lua_tonumber(lua_state_ptr, -1));
    }
    template <> const char * LuaHandler::lua_get<const char *>() {
      return lua_tostring(lua_state_ptr, -1);
    }
  
    
    // {
    //   // LuaHandler
    //   return 0;
    // }

  }// End namespace HelperClasses
}// End namespace MassCalculator
#endif