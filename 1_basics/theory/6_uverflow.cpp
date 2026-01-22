#include <iostream>
#include <limits>

int main() {
    unsigned u = std::numeric_limits<unsigned>::max();
    std::cout << "max unsigned = " << u << "\n";
    std::cout << "u+1 = " << (u + 1) << "\n";
    std::cout << "u+10= " << (u + 10) << "\n";
}
