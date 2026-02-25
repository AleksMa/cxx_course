#include <iostream>
#include <array>
#include <type_traits>

template <class T>
T add(T a, T b) { return a + b; }

template <int N>
struct FixedBuffer {
    std::array<char, N> data{};
};

template <template <class, std::size_t> class Arr, class T, std::size_t N>
T sum(const Arr<T, N>& a) {
    T s{};
    for (const auto& x : a) s += x;
    return s;
}

int main() {
    std::cout << add<int>(2, 3) << "\n";
    std::cout << add<double>(1.5, 2.25) << "\n";

    FixedBuffer<16> b;
    b.data[0] = 'A';
    std::cout << b.data[0] << "\n";

    std::array<int, 4> a{1, 2, 3, 4};
    std::cout << sum<std::array, int, 4>(a) << "\n";
}
