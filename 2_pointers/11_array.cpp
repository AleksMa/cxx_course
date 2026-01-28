#include <iostream>

void print_size(int arr[]) {
    std::cout << sizeof(arr) << "\n";
}

int main() {
    int a[5] = {10, 20, 30};
    std::cout << a[0] << "\n";
    std::cout << a[3] << "\n";
    std::cout << a[10] << "\n";
    std::cout << a[-1] << "\n";

    int* p = a;
    int* p2 = &a[0];

    std::cout << sizeof(a) << "\n";
    std::cout << sizeof(p) << "\n";

    print_size(a);

    std::cout << 2[a] << "\n";
}
