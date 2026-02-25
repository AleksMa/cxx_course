#include <iostream>

template <class T>
T twice(T x) {
    return x + x;
}

int main() {
    std::cout << twice(10) << "\n";
    std::cout << twice(1.25) << "\n";
}
