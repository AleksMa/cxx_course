#include <iostream>

int main() {
    unsigned int x = 1000;
    if (x + 1 < x) {
        std::cout << "less" << std::endl;
    }

    std::cout << "greater or equal" << std::endl;

    return 0;
}
