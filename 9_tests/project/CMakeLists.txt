cmake_minimum_required(VERSION 3.20)
project(UnitTestsSeminar LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

# --------------------------
# Testing frameworks
# --------------------------

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.4
)

FetchContent_MakeAvailable(googletest Catch2)

enable_testing()
include(CTest)
include(GoogleTest)
include(Catch)

# --------------------------
# Production library
# --------------------------

add_library(seminar_lib
    src/math_utils.cpp
    src/config_reader.cpp
    src/text_formatter.cpp
)

target_include_directories(seminar_lib PUBLIC src)

# --------------------------
# Production executable
# --------------------------

add_executable(seminar_app
    src/main.cpp
)

target_link_libraries(seminar_app PRIVATE seminar_lib)

# --------------------------
# Example 01: plain assert
# --------------------------

add_executable(example_01_plain_assert
    examples/01_plain_assert/test_plain_assert.cpp
)

# --------------------------
# Example 02: EXPECT_EQ
# --------------------------

add_executable(example_02_gtest_expect_eq
    examples/02_gtest_expect_eq/test_expect_eq.cpp
)
target_link_libraries(example_02_gtest_expect_eq PRIVATE GTest::gtest_main)
gtest_discover_tests(example_02_gtest_expect_eq)

# --------------------------
# Example 03: exceptions
# --------------------------

add_executable(example_03_gtest_exceptions
    examples/03_gtest_exceptions/test_exceptions.cpp
)
target_link_libraries(example_03_gtest_exceptions PRIVATE GTest::gtest_main)
gtest_discover_tests(example_03_gtest_exceptions)

# --------------------------
# Example 04: ASSERT before index
# --------------------------

add_executable(example_04_gtest_assert_before_index
    examples/04_gtest_assert_before_index/test_assert_before_index.cpp
)
target_link_libraries(example_04_gtest_assert_before_index PRIVATE GTest::gtest_main)
gtest_discover_tests(example_04_gtest_assert_before_index)

# --------------------------
# Example 05: private fields
# --------------------------

add_executable(example_05_private_friend
    examples/05_private_fields/test_friend_access.cpp
)
target_include_directories(example_05_private_friend PRIVATE examples/05_private_fields)
target_link_libraries(example_05_private_friend PRIVATE GTest::gtest_main)
gtest_discover_tests(example_05_private_friend)

add_executable(example_05_private_public_api
    examples/05_private_fields/test_public_api_instead.cpp
)
target_include_directories(example_05_private_public_api PRIVATE examples/05_private_fields)
target_link_libraries(example_05_private_public_api PRIVATE GTest::gtest_main)
gtest_discover_tests(example_05_private_public_api)

# --------------------------
# Example 06: parameterized
# --------------------------

add_executable(example_06_parameterized
    examples/06_parameterized/test_parameterized.cpp
)
target_link_libraries(example_06_parameterized PRIVATE GTest::gtest_main)
gtest_discover_tests(example_06_parameterized)

# --------------------------
# Example 07: file reading
# --------------------------

add_executable(example_07_file_reading
    examples/07_file_reading/test_file_reading.cpp
)
target_link_libraries(example_07_file_reading PRIVATE seminar_lib GTest::gtest_main)
gtest_discover_tests(example_07_file_reading)

# --------------------------
# Example 08: snapshot
# --------------------------

add_executable(example_08_snapshot
    examples/08_snapshot/test_snapshot.cpp
)
target_link_libraries(example_08_snapshot PRIVATE seminar_lib GTest::gtest_main)
gtest_discover_tests(example_08_snapshot)

# --------------------------
# Example 09: Catch2
# --------------------------

add_executable(example_09_catch
    examples/09_catch/test_catch.cpp
)
target_link_libraries(example_09_catch PRIVATE seminar_lib Catch2::Catch2WithMain)
catch_discover_tests(example_09_catch)

# --------------------------
# Example 09: Catch2
# --------------------------

add_executable(example_10_setup
    examples/10_setup/test_setup.cpp
)
target_link_libraries(example_10_setup PRIVATE seminar_lib GTest::gtest_main)
gtest_discover_tests(example_10_setup)
