#include <iostream>
#include <expected>
#include <string>

std::expected<int, std::string> divide(int a, int b) {
    if (b == 0) {
        return std::unexpected("Division by zero");
    }
    return a / b;
}

int main() {
    std::expected<int, std::string> result = divide(1, 1);

    if (result.has_value()) {
        std::cout << result.value() << "\n";
    } else {
        std::cout << "Error: " << result.error() << "\n";
    }

    // std::cout << result.value_or(-1) << "\n";
}
