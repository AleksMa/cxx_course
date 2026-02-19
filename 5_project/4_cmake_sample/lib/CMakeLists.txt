add_library(bmpio bmp_io.cpp)

# add lib to include path (and for dep)
target_include_directories(bmpio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
