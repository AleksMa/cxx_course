// Зачем нам UB?
// почему не всегда есть defined behavior?

#include <iostream>

void f() {
    int a = 42;
}

void g() {
    int x;
    std::cout << x << "\n";
}

int main() {
    int x = 100;
    f();
    g();
    return 0;
}
