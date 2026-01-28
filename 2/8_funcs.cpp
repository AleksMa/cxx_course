#include <iostream>

void f(int x) {
    std::cout << "int\n";
}

void f(double x) {
    std::cout << "double\n";
}

void divmod(int a, int b, int& div, int& mod) {
    div = a / b;
    mod = a % b;
}

int main() {
    f(10);
    f(3.14);
}
