cmake_minimum_required(VERSION 3.20)
project(UnitTestsSeminar LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

add_library(math_utils
    src/math_utils.cpp
)

target_include_directories(math_utils PUBLIC src)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)

FetchContent_MakeAvailable(googletest)

add_executable(gtest_tests
    tests/test_math_gtest.cpp
)

target_link_libraries(gtest_tests
    PRIVATE
        math_utils
        GTest::gtest_main
)

include(CTest)
include(GoogleTest)

gtest_discover_tests(gtest_tests)
