project(MassCalculatorGUI)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/src)
set(FORM_DIR ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/form)
set(PIC_DIR ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/picture)

# System dependencies
#find_package(OpenGL REQUIRED)
# https://code.qt.io/cgit/qt/qt3d.git/tree/examples/qt3d/basicshapes-cpp?h=5.13

# Next lines needed for building all Qt projects
find_package( Qt5 COMPONENTS REQUIRED Core Gui Widgets )

###########
## Build ##
###########

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/MassCalculator/include/
  ${CMAKE_SOURCE_DIR}/MassCalculator/helper_classes
  include/
  form/
)

# Forms
qt5_wrap_ui( MOC_FORMS 
  ${FORM_DIR}/mainwindow.ui
)

# Headers
set ( MOC_HEADERS
  include/mainwindow.h
)
qt5_wrap_cpp(MOC_SOURCES ${MOC_HEADERS})

set ( RESOURCES
#  ${PIC_DIR}/main.qrc
)

# Sources
set( SRC
  ${SRC_DIR}/main.cpp
  ${SRC_DIR}/mainwindow.cpp
  ${RESOURCES}
  ${MOC_SOURCES}
  ${MOC_FORMS}
  #src/main.cpp
  #src/MassCalculator.cpp
)

add_executable( ${PROJECT_NAME}
  ${SRC}
)

# or use line below instead, if you using Windows ™ Operating System.
#add_executable( PROJECT_NAME WIN32 ${SOURCES} ${MOC_SRCS} ${RES_SOURCES} ${UI_HEADERS} )

target_include_directories( ${PROJECT_NAME}
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/MassCalculatorGUI/>
         $<INSTALL_INTERFACE:include/MassCalculatorGUI/>
)

target_include_directories( ${PROJECT_NAME}
  SYSTEM
  PUBLIC ${EIGEN3_INCLUDE_DIR}
)

target_link_libraries ( ${PROJECT_NAME} 
  PUBLIC
  MassCalculator
  Qt5::Core
  Qt5::Gui 
  Qt5::Widgets
)

#############
## TESTING ##
#############

#add_subdirectory(test)

#############
## Install ##
#############

# to be discussed, we want to expose data types only!
install(
  TARGETS ${PROJECT_NAME} EXPORT MassCalculatorGUI-config
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  INCLUDES DESTINATION include
)

## install headers
install(
  DIRECTORY include/
  DESTINATION include/MassCalculatorGUI/
  PATTERN "CMakeLists.txt" EXCLUDE
)

###############
## Packaging ##
###############
#

install(
 EXPORT ${PROJECT_NAME}-config
 DESTINATION share/cmake/${PROJECT_NAME}
)

set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Mergim Halimi") #required

include(CPack)
