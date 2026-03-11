cmake_minimum_required(VERSION 3.20)

project(MyApp)

add_executable(MyApp main.cpp)



add_library(MathLib STATIC my_math/my_math.cpp)

target_link_libraries(MyApp PRIVATE MathLib)

target_include_directories(MathLib PUBLIC my_math)
