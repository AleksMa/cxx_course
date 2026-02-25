#include <iostream>
#include <type_traits>

template <class T>
void show(T x) {
    const bool is_const = std::is_const_v<T>;
    std::cout << "T is const? " << is_const << "\n";
}

template <class T>
void showRef(T& x) {
    const bool is_const = std::is_const_v<T>;
    std::cout << "T is const? " << is_const << "\n";
}

int main() {
    const int a = 5;
    int b = 7;

    show(a);     // T = int (copy)
    showRef(a);  // T = const int
    showRef(b);  // T = int
}
