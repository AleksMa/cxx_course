#include <iostream>
#include <cstdint>

int main() {
    
    uint32_t a = 1;
    int32_t b = -2;

    auto c = static_cast<int32_t>(a) + b;

    std::cout << c << "\n";
}
