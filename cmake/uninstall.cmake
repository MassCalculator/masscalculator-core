if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/install_manifest.txt")
    message(FATAL_ERROR "Cannot find install manifest: ${CMAKE_CURRENT_BINARY_DIR}/install_manifest.txt")
endif()

file(READ "${CMAKE_CURRENT_BINARY_DIR}/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")

foreach(file IN LISTS files)
    message(STATUS "Removing file: ${file}")
    if(EXISTS "${file}")
        execute_process(
            COMMAND ${CMAKE_COMMAND} -E remove "${file}"
            RESULT_VARIABLE result
        )
        if(NOT result EQUAL 0)
            message(FATAL_ERROR "Failed to remove file: ${file}")
        endif()
    endif()
endforeach()
