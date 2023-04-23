cmake_minimum_required(VERSION 3.15)

set(LUA_REQUIRED_VERSION 5.4.4)

# Check that Lua is installed in the system.
# This call cannot fail.
find_package(Lua ${LUA_REQUIRED_VERSION} REQUIRED)
