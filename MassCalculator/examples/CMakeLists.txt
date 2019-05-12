#Example_1
set(SRC
  example_1.cpp
)

add_executable(
  ${PROJECT_NAME}_example_1
  ${SRC}
)

target_link_libraries(
  ${PROJECT_NAME}_example_1
  ${PROJECT_NAME}
)