#include <iostream>

int divide(int a, int b) {
    if (b == 0) {
        return 0;
    }

    return a / b;
}

int main() {
    int r = divide(10, 0);

    if (!r) {
        std::cout << "error\n";
    } else {
        std::cout << r << "\n";
    }
}
