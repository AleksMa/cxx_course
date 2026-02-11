#include <iostream>

int main() {
    int* p = new int(5);
    std::cout << *p << "\n";
    delete p;

    int* a = new int[3]{1, 2, 3};

    for (int i = 0; i < 3; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n" << sizeof(a) << "\n";

    delete[] a;
}
