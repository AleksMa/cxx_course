#include <concepts>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
concept HasSize = requires(const T& x) {
    { x.size() } -> std::integral;
};

template <HasSize T>
void print_size(const T& x) {
    std::cout << "size = " << x.size() << '\n';
}

class MyClass {
public:
    int size() const { return 42; }
};

int main() {
    // std::vector<int> v = {1, 2, 3};
    std::string s = "hello";
    MyClass m;

    // print_size(v);
    print_size(s);
    print_size(m);

    int x = 42;
    // print_size(x);
}
