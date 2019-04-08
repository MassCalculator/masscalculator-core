project(MassCalculatorGUI)

###########
## Build ##
###########

message(STATUS ${GTEST_INCLUDE_DIRS})
message(STATUS ${GTEST_BOTH_LIBRARIES})

# Sources
set(SRC
  src/main.cpp
)

add_executable(${PROJECT_NAME}
  ${SRC}
)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include/MassCalculatorGUI/>
)

target_include_directories(
  ${PROJECT_NAME}
  SYSTEM
  PUBLIC ${EIGEN3_INCLUDE_DIR}
)

target_link_libraries (${PROJECT_NAME} 
  ${OPENGL_LIBRARIES}
  ${GLUT_LIBRARY}
  glui::glui_static
  MassCalculator
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
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  INCLUDES DESTINATION include
)

## install headers
install(
  DIRECTORY include/MassCalculatorGUI
  DESTINATION include/MassCalculatorGUI/
  PATTERN "CMakeLists.txt" EXCLUDE
)
