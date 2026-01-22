#include <iostream>

int X;

int main() {
    int a = 0;      // copy-init
    int b(0);       // direct-init
    int c{0};       // list-init (лучше, ловит narrowing)
    int d{};        // value-init => 0

    // int x = 3.14;
    // int x(3.14);
    int x{3.14};

    std::cout << x << std::endl;
    // std::cout << X << std::endl;
}