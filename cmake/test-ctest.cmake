# Testing
set(CTEST_PROJECT_NAME ${PROJECT_NAME} )
set(BUILDNAME "masscalculator-core-build")
set(SITE "mhrobotics-buildsrv")
# set(CTEST_DROP_METHOD "https")
# set(CTEST_DROP_SITE_CDASH TRUE)
# set(CTEST_DROP_SITE "https://my-cdash-server.com")
# set(CTEST_DROP_LOCATION "/CDash/submit.php?project=masscalculator-core")

# Enable CTest functionalities for the overall repository.
# This will have no impact on how tests are compiled.
# It only enables to run them via ctest.
include(CTest)
