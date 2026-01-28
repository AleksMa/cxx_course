#include <iostream>

int& bad() {
    int x = 10;
    return x;
}

int& counter() {
    static int c = 0;
    return c;
}

int main() {
    int x = 10;
    int& r = x;

    r = 20;
    std::cout << x << "\n";

    // int* p2 = nullptr;
    // int& r2 = *p;
    // std::cout << r2 << "\n";

    // std::cout << bad() << "\n";

    // std::cout << counter() << "\n";
    // std::cout << counter() << "\n";
}
