#include <iostream>

int* first = nullptr;  // 8190216 * 4
                       // 2091272

void f() {
    int x;
    if (!first) first = &x;

    std::cout << (first - &x) << std::endl;
    f();
}

int main() {
    f();
}

// ulimit -s
