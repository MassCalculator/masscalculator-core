#Example_1

add_executable(${PROJECT_NAME}_example_1
  example_1.cc
)

target_link_libraries(${PROJECT_NAME}_example_1
  PRIVATE
    ${PROJECT_NAME}
    masscalculator::masscalculator-base
    masscalculator::masscalculator-core
    masscalculator::third_party::units
)
