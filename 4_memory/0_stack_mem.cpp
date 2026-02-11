#include <iostream>

int main() {
    size_t a[1'000'000] = {0};
    size_t* b = new size_t[1'000'000];

    std::cout << sizeof(a) << std::endl;
    std::cout << sizeof(b) << std::endl;

    delete[] b;
}
