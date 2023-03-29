set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)

doxygen_add_docs(docs
    ${PROJECT_SOURCE_DIR}/libmasscalculator/include/materials/alloy_coppers.hpp
    ${PROJECT_SOURCE_DIR}/libmasscalculator/include/materials/alloy_steels.hpp
    "${PROJECT_SOURCE_DIR}/libmasscalculator/README.md"
    WORKING_DIRECTORY
    "${PROJECT_SOURCE_DIR}/libmasscalculator/include"
)
