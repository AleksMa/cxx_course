#include <iostream>

int main() {
    int x = 10;
    int* p = &x;

    std::cout << x << "\n";   // 10
    std::cout << *p << "\n";  // 10

    *p = 20;
    std::cout << x << "\n";   // 20

    // int* p2 = nullptr;
    // std::cout << *p2 << "\n";
}
