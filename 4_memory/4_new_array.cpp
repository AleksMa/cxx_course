#include <iostream>

int main() {
    uint64_t* a = new uint64_t[100];

    uint64_t* meta = a - 1;
    std::cout << *meta << std::endl;

    delete[] a;
}
