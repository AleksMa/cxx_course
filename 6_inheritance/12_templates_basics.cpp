#include <iostream>
#include <array>
#include <type_traits>

template <class T>
T add(T a, T b) { return a + b; }

template <typename T>
T mul(double a, double b) { return a * b; }

template <int N>
struct FixedBuffer {
    std::array<char, N> data{};
};

constexpr int makeN() {
    return 10;
}

// template <template<class, std::size_t> class Arr, class T, std::size_t N>
// T sum(const Arr<T, N>& a) {
//     T s{};
//     for (const auto& x : a) s += x;
//     return s;
// }

template <class Arr>
Arr::value_type sum(const Arr& a) {
    typename Arr::value_type s{};
    for (const auto& x : a) s += x;
    return s;
}

int main() {
    std::cout << add(2, 3) << "\n";
    std::cout << add<double>(1.5, 2.25) << "\n";

    std::cout << mul<int>(1.5, 2.25) << "\n";
    std::cout << mul<double>(1.5, 2.25) << "\n\n";

    FixedBuffer<makeN()> b;
    b.data[0] = 'A';
    std::cout << b.data[0] << "\n";

    std::array<int, 4> a{1, 2, 3, 4};
    std::cout << sum(a) << "\n";
}
