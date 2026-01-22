#include <iostream>
#include <bitset>
#include <cstdint>

int main() {
    std::int8_t x = -5;
    std::uint8_t y = static_cast<std::uint8_t>(x);

    std::cout << "x = " << int(x) << "\n";
    std::cout << "y = " << unsigned(y) << "\n";

    std::bitset<8> bx(x);
    std::cout << "bits(x) = " << bx << "\n";
    std::bitset<8> by(y);
    std::cout << "bits(y) = " << by << "\n";
}
