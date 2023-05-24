cmake_minimum_required(VERSION 3.15)

set(GOOGLETEST_REQUIRED_VERSION 1.13.0)

# Check that GoogleTest is installed in the system.
# This call cannot fail.
find_package(GTest ${GOOGLETEST_REQUIRED_VERSION} REQUIRED)
