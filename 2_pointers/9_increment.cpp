#include <iostream>

int main() {
    int i = 0;
    int a = ++i;
    int b = i++;

    std::cout << a << " " << b << "\n";

    // {
    //     int i = 0;
    //     i = i++;

    //     std::cout << i << std::endl;
    // }

    // {
    //     int a = 1;
    //     int b = a++ + a++;

    //     std::cout << i << std::endl;
    // }
}
