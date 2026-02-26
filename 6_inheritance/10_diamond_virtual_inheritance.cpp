#include <iostream>

class A {
public:
    void apply() {}
    int x = 1;
};

class B : public virtual A {}; // x
class C : public virtual A {}; // x
class D : public B, public C {}; // x | x

//.       A
//.     // \\
//. x-> B   C <-x
//.      \ /
//.       D  <-x        // B.x C.x

// D: B, C
// B: A, C: A

// vi: D: B, C, A'

int main() {
    D d;
    d.x = 10;
    std::cout << d.x << "\n";
}
