cmake_minimum_required(VERSION 3.15)

set(DOXYGEN_REQUIRED_VERSION 1.8.17)

# Check that GoogleTest is installed in the system.
# This call cannot fail.
find_package(Doxygen ${DOXYGEN_REQUIRED_VERSION} REQUIRED)
