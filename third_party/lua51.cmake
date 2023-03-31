cmake_minimum_required(VERSION 3.15)

set(LUA51_REQUIRED_VERSION 5.1.5)

# Check that Lua51 is installed in the system.
# This call cannot fail.
find_package(Lua51 ${LUA51_REQUIRED_VERSION} REQUIRED)
