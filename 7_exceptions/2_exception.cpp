#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero");
    }
    return a / b;
}

int main() {
    // std::cout << divide(10, 0) << "\n";
    try {
        std::cout << divide(10, 0) << "\n";
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    } catch (...) {
        std::cout << "Some other exception" << "\n";
    }
}
