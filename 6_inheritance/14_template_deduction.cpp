#include <iostream>
#include <type_traits>

template <class T>
void show(T x) {
    std::cout << "T is const? " << std::is_const_v<T> << "\n";
}

template <class T>
void showRef(T& x) {
    std::cout << "T is const? " << std::is_const_v<T> << "\n";
}

int main() {
    const int a = 5;
    int b = 7;
    double d = 7.;

    show(a);     // T = int (copy)
    show(b);     // T = int (copy)
    show(d);
    showRef(a);  // T = const int
    showRef(b);  // T = int
    showRef(d);
}
