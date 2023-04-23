# @todo(jimmyhalimi): Update the list with macros.

if(EXISTS "/usr/local/lib/masscalculator/libmasscalculator-base.so")
  file(REMOVE "/usr/local/lib/masscalculator/libmasscalculator-base.so")
endif()

if(EXISTS "/usr/local/lib/masscalculator/libmasscalculator-core.so")
  file(REMOVE "/usr/local/lib/masscalculator/libmasscalculator-core.so")
endif()

if(EXISTS "/usr/local/include/gtest")
  file(REMOVE_RECURSE "/usr/local/include/gtest")
endif()

if(EXISTS "/usr/local/include/gmock")
  file(REMOVE_RECURSE "/usr/local/include/gmock")
endif()

file(GLOB LUA_FILES "/usr/local/include/l*lib.h")
foreach(LUA_FILE ${LUA_FILES})
  file(REMOVE ${LUA_FILE})
endforeach()

if(EXISTS "/usr/local/include/masscalculator/third_party")
  file(REMOVE_RECURSE "/usr/local/include/masscalculator/third_party")
endif()

if(EXISTS "/usr/local/include/masscalculator/masscalculator-base")
  file(REMOVE_RECURSE "/usr/local/include/masscalculator/masscalculator-base")
endif()

if(EXISTS "/usr/local/include/masscalculator/masscalculator-core")
  file(REMOVE_RECURSE "/usr/local/include/masscalculator/masscalculator-core")
endif()

if(EXISTS "${MASSCALCULATOR_HOME}")
  file(REMOVE_RECURSE "${MASSCALCULATOR_HOME}")
endif()

if(EXISTS "/usr/local/share/cmake/masscalculator/masscalculator-core")
  file(REMOVE_RECURSE "/usr/local/share/cmake/masscalculator/masscalculator-core")
endif()

if(EXISTS "/usr/local/share/man/man1/masscalculator-core.1.gz")
  file(REMOVE "/usr/local/share/man/man1/masscalculator-core.1.gz")
endif()
