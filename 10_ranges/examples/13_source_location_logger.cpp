#include <iostream>
#include <source_location>
#include <string_view>

void log(std::string_view message, std::source_location location = std::source_location::current()) {
    std::cout << location.file_name() << ':' << location.line()
              << " [" << location.function_name() << "] "
              << message << '\n';
}

void helper_function() {
    log("Msg from helper_function");
}

int main() {
    log("Msg from main", std::source_location::current());
    helper_function();
}
