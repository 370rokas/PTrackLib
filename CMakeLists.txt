cmake_minimum_required(VERSION 3.21)
project(PTrackLib)

option(BUILD_TESTS "Build test programs" OFF)

if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

add_library(PTrackLib src/ptracklib.cpp)
target_include_directories(PTrackLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (BUILD_TESTS)
    include(FetchContent)

    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG release-1.12.1
    )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    add_subdirectory(tests)
endif ()