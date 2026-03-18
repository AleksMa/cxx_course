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
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.4
)

FetchContent_MakeAvailable(Catch2)

add_executable(catch_tests
    tests/test_math_catch.cpp
)

target_link_libraries(catch_tests
    PRIVATE
        math_utils
        Catch2::Catch2WithMain
)

include(CTest)
include(Catch)

catch_discover_tests(catch_tests)
