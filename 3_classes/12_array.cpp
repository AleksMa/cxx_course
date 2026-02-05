#include <iostream>
#include <array>
#include <cstddef>

// using weights_t = std::array<double, 3>;

template <std::size_t N>
void print_arr(const std::array<int, N>& a) {
    std::cout << "std::array N=" << N << " : ";
    for (int x : a) std::cout << x << " ";
    std::cout << "\n";
}

template <std::size_t N>
void print_carr(const int (&a)[N]) {
    std::cout << "C-array N=" << N << " : ";
    for (std::size_t i = 0; i < N; ++i) std::cout << a[i] << " ";
    std::cout << "\n";
}

int main() {
    std::array<int, 5> a = {1, 2, 3};
    a[0] = 10;
    // a.at(100) = 1;

    print_arr(a);

    a.fill(7);
    print_arr(a);

    int b[3] = {9, 8, 7};
    print_carr(b);

    std::cout << "std::array size=" << a.size() << "\n";

    int* p = a.data();
    std::cout << "a.data()[0]=" << p[0] << "\n";

    return 0;
}
