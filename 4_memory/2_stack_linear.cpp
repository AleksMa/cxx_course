#include <iostream>

void f() {
    int x;
    static int* first = nullptr;
    if (!first) first = &x;

    std::cout << (first - &x) << std::endl;
    f();
}

int main() {
    f();
}

// ulimit -s
