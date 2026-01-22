#include <iostream>

int f(int x, int y) {
    return x + y;
}

int g() {
    std::cout << "g\n";
    return 1;
}

int h() {
    std::cout << "h\n";
    return 2;
}

int main() {
    std::cout << f(h(), g()) << "\n";
}
