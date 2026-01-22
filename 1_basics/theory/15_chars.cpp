#include <iostream>
#include <cstdint>

int main() {
    unsigned char ch = 'A';
    std::uint8_t u = 65;
    std::int8_t s = 'B';

    // std::cout << "ch=" << ch << "\n";
    // std::cout << "u=" << static_cast<uint16_t>(ch) << "\n";
    // std::cout << "s=" << static_cast<uint16_t>(s) << "\n";
    std::cout << "ch==u: " << (ch == u) << "\n";

    std::cout << (
        1 << 2 == 8 >> 1
    ) << std::endl;
}
