# Include the default CMAKE_INSTALL_LIBDIR and CMAKE_INSTALL_INCLUDEDIR values.
include(GNUInstallDirs)

############################################################
# INSTALL THIRD PARTY HEADERS
############################################################

# Include paths coming from Conan installations
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

############################################################
# GOOGLE TEST
############################################################

# Install the Google Test headers.
install(
  DIRECTORY ${GTest_INCLUDE_DIRS}/
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}
)

############################################################
# LUA
############################################################

# Install the Lua headers.
install(
  DIRECTORY ${lua_INCLUDE_DIR}/
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}
)

############################################################
# INSTALL THIRD PARTY LIBRARIES
############################################################

install(
  DIRECTORY ${CMAKE_LIBRARY_PATH}
  DESTINATION ${CMAKE_INSTALL_PREFIX}
)

############################################################
# INSTALL MASSCALCULATOR-CORE LIBRARY
############################################################

# Set the RPATH when installing packages
set_target_properties(masscalculator-base PROPERTIES
  INSTALL_RPATH "$ORIGIN"
)

set_target_properties(${PROJECT_NAME} PROPERTIES
  INSTALL_RPATH "$ORIGIN"
)

set_target_properties(units PROPERTIES
  INSTALL_RPATH "$ORIGIN"
)

# Install the library targets and their corresponding headers
install(
  TARGETS
    masscalculator-base
    ${PROJECT_NAME}
    units
  EXPORT ${PROJECT_NAME}-config
  INCLUDES DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}
)

install(
  EXPORT ${PROJECT_NAME}-config
  DESTINATION share/cmake/${PROJECT_NAME}
  NAMESPACE masscalculator::
  FILE ${PROJECT_NAME}-config.cmake
)

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libraries/masscalculator-base/include/masscalculator
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING PATTERN "*.h*"
  PATTERN "CMakeLists.txt" EXCLUDE
)

install(
  DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/libraries/masscalculator-base/include/masscalculator
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING PATTERN "*.h*"
  PATTERN "CMakeLists.txt" EXCLUDE
)

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libraries/${PROJECT_NAME}/include/masscalculator
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING PATTERN "*.h*"
  PATTERN "CMakeLists.txt" EXCLUDE
)

install(
  DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/libraries/${PROJECT_NAME}/include/masscalculator
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING PATTERN "*.h*"
  PATTERN "CMakeLists.txt" EXCLUDE
)

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libraries/third_party/units/include/masscalculator
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING PATTERN "*.h*"
  PATTERN "CMakeLists.txt" EXCLUDE
)

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libraries/${PROJECT_NAME}/resources
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/masscalculator
)

add_custom_target(
  uninstall
  COMMAND ${CMAKE_COMMAND} -P ${CMAKE_SOURCE_DIR}/cmake/uninstall.cmake
)
