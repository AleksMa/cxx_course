// 02_arrays_function_params.cpp
#include <iostream>
#include <cstddef>

// void print_arr(const int a[]) {
//     std::cout << "print_ptr: n=" << sizeof(a) / sizeof(a[0]) << " : ";
//     for (std::size_t i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
//         std::cout << a[i] << " ";
//     }
//     std::cout << "\n";
// }

void print_ptr(const int* a, std::size_t n) {
    std::cout << "print_ptr: n=" << n << " : ";
    for (std::size_t i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

template <std::size_t N>
void print_arr(const int (&a)[N]) {
    std::cout << sizeof(a) << "\n";
    std::cout << "print_arr: N=" << N << " : ";
    for (std::size_t i = 0; i < N; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int a[5] = {1, 2, 3, 4};
    int b[4] = {1, 2, 3, 4};

    // print_ptr(a, 5);
    print_arr(a);
    print_arr(b);
    // print_arr(a);

    return 0;
}
