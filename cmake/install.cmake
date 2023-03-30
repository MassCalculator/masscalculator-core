install(
  TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}-config
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  INCLUDES DESTINATION include
)

install(
  DIRECTORY include/
  DESTINATION include/${PROJECT_NAME}/libmasscalculator
  PATTERN "CMakeLists.txt" EXCLUDE
)

install(
 EXPORT ${PROJECT_NAME}-config
 DESTINATION share/cmake/${PROJECT_NAME}
)

install(
  FILES ${CMAKE_SOURCE_DIR}/docs/man/libmasscalculator.1.gz
  DESTINATION share/man/man1 COMPONENT docs
)

install(
  DIRECTORY ${CMAKE_SOURCE_DIR}/resources
  DESTINATION share/masscalculator
)