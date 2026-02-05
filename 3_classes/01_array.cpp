#include <iostream>
#include <cstddef>

int main() {
    int a[5] = {10, 20, 30};

    std::cout << "a[0]=" << a[0] << "\n";
    // type of sizeof?...
    std::cout << "sizeof(a) bytes = " << sizeof(a) << "\n";  // size_t
    std::cout << "sizeof(a[0]) bytes = " << sizeof(a[0]) << "\n";
    std::cout << "length = sizeof(a)/sizeof(a[0]) = " << (sizeof(a) / sizeof(a[0])) << "\n\n";

    std::cout << "Addresses:\n";
    for (std::size_t i = 0; i < 5; ++i) {
        std::cout << "  &a[" << i << "] = " << static_cast<void*>(&a[i]) << "\n";
    }

    // Array-to-pointer decay
    int* p = &a[0];
    std::cout << "\nPointer p = a: p points to a[0], *p = " << *p << "\n";

    // UB
    std::cout << a[2] << "\n";
    std::cout << *(a + 2) << "\n";
    std::cout << *(p + 2) << "\n";
    std::cout << p[2] << "\n";

    std::cout << *(2 + a) << "\n";
    std::cout << 2[a] << "\n";

    return 0;
}
