cmake_minimum_required(VERSION 3.20)

project(MyApp)

add_executable(MyApp main.cpp)



add_library(MyMath SHARED my_math.cpp)

target_link_libraries(MyApp PRIVATE MyMath)

target_include_directories(MyMath PUBLIC .)
