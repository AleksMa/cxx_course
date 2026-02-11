#include <iostream>

int main() {
    int a[5] = {1, 2, 3, 4, 5}; //\0

    for (int* it = a; it != a + 5; ++it) {
        std::cout << *it << " ";
    }

    for (int& x : a) {
        std::cout << x++ << "\n";
    }
    for (const int& x : a) {
        std::cout << x << "\n";
    }
}
