# Include the default CMAKE_INSTALL_LIBDIR and CMAKE_INSTALL_INCLUDEDIR values.
include(GNUInstallDirs)

############################################################
# INSTALL THIRD PARTY LIBRARIES
############################################################

# Include paths coming from Conan installations
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

############################################################
# GOOGLE TEST
############################################################

# # Install the Google Test libraries.
# install(
#     DIRECTORY ${GTest_LIBRARIES}
#     DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}
# )

# Install the Google Test headers.
install(
    DIRECTORY ${GTest_INCLUDE_DIRS}/
    DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}
)

############################################################
# LUA
############################################################

# # Install the Lua libraries.
# install(
#     DIRECTORY ${lua_LIBRARIES}
#     DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}
# )

# Install the Lua headers.
install(
    DIRECTORY ${lua_INCLUDE_DIR}/
    DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}
)

############################################################
# INSTALL MASSCALCULATOR-CORE LIBRARY
############################################################

# Install the library targets and their corresponding headers
install(
  TARGETS masscalculator-base
  EXPORT ${PROJECT_NAME}-config
  LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/masscalculator
  INCLUDES DESTINATION ${CMAKE_INSTALL_PREFIX}/${${CMAKE_INSTALL_INCLUDEDIR}}
)

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libraries/masscalculator-base/include/masscalculator
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING PATTERN "*.h"
  PATTERN "CMakeLists.txt" EXCLUDE
)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}-config
  LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/masscalculator
  INCLUDES DESTINATION ${CMAKE_INSTALL_PREFIX}/${${CMAKE_INSTALL_INCLUDEDIR}}
)

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libraries/${PROJECT_NAME}/include/masscalculator
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING PATTERN "*.h"
  PATTERN "CMakeLists.txt" EXCLUDE
)

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libraries/${PROJECT_NAME}/resources
  DESTINATION ${MASSCALCULATOR_HOME}
)

install(
 EXPORT ${PROJECT_NAME}-config
 DESTINATION share/cmake/masscalculator/${PROJECT_NAME}
)

install(
  FILES ${CMAKE_SOURCE_DIR}/docs/assets/man/masscalculator-core.1.gz
  DESTINATION share/man/man1
  COMPONENT ${PROJECT_NAME}
)

add_custom_target(
  uninstall
  COMMAND ${CMAKE_COMMAND} -P ${CMAKE_SOURCE_DIR}/cmake/uninstall.cmake
)
