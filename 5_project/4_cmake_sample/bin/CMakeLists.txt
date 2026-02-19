add_executable(app main.cpp)
target_link_libraries(app PRIVATE bmpio)  # include + link

set_target_properties(app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)
