#include <iostream>

struct A {
    int x = 1;
};

struct B : virtual A {};
struct C : virtual A {};
struct D : B, C {};

int main() {
    D d;
    d.x = 10;
    std::cout << d.x << "\n";
}
