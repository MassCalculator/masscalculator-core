# Tests with googletest

Tests for the MassCalculator core codebase are created using the
[`googletest`](https://github.com/google/googletest) framework.  
`googletest` is added to the codebase as a third-party.

## Project Structure

Every library under the `$MASSCALCULATOR_SOURCE/libraries` folder has to contain a
`tests` subfolder which will contain its `CMakeLists.txt` file, defining all
the tests, and all the necessary source files.

## Link Tests to googletest

First of all, CMake functions that support `googlestest` have to be made available with:

```cmake
include(GoogleTest)
```

Tests are defined using the CMake function `add_executable`, just like any
other executable. e.g.,

```cmake
add_executable(demo_test 
  main.cc
)
```

Link your test executable to the required libraries they are using, e.g.,

```cmake
target_link_libraries(demo_test
  PUBLIC
    ${GTEST_BOTH_LIBRARIES}
  PRIVATE
    pthread
    lib_1
    lib_2
)
```

To use `googletest` in a test executable simply call this CMake function
after creating the executable with `add_executable`:

```cmake
gtest_add_tests(TARGET      demo_test
                TEST_SUFFIX .noArgs
                TEST_LIST   noArgsTests
)
```

The following is not necceserily needed, but this is what is used to add the
tests to `CTest`, `gtest_add_tests` does this for you:

```cmake
add_test(
  NAME DemoTestName
  COMMAND demo_test
)
```

## CTest

If the build was configured to build any of the test, you can call CTest from
the build directory to run them.

### Run all the tests

```bash
ctest
```

### Run only the tests for the library called "DemoTestName"

This will use a regular expression to find all tests targets with the name
that contains "DemoTestName". If you added that tag to the `add_gest` calls,
CTest will find the right tests for you.

```bash
ctest -R DemoTestName
```
