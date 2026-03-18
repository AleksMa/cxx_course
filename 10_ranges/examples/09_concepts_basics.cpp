#include <concepts>
#include <iostream>

template <std::unsigned_integral T>
T add_one(T value) {
    return value + 1;
}

int main() {
    std::cout << "add_one(41) = " << add_one(41l) << '\n';
    // std::cout << "add_one('A') = " << add_one('A') << '\n';

    // std::cout << add_one(3.14) << '\n';
}
