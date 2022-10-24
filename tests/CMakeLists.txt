enable_testing()

add_executable(
        PTrackTest
        ptrack_tests.cpp
)
target_link_libraries(
        PTrackTest
        GTest::gtest_main
        PTrackLib
)

include(GoogleTest)
gtest_discover_tests(PTrackTest)