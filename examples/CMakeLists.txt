#Example_1

add_executable(${PROJECT_NAME}_example_1
  example_1.cc
)

target_link_libraries(${PROJECT_NAME}_example_1
  PRIVATE
    masscalculator::masscalculator-base
    masscalculator::${PROJECT_NAME}
    masscalculator::third_party::units
)
