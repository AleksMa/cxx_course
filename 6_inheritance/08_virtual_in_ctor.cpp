#include <iostream>

struct Base {
    virtual void f() { std::cout << "Base::f\n"; }

    Base() {
        std::cout << "Base() calls f(): ";
        f();
    }
    virtual ~Base() {
        std::cout << "~Base() calls f(): ";
        f();
    }

    void applyF() {
        std::cout << "Base::applyF\n";
        f();
    }
};

struct Derived : Base {
    Derived() { 
        std::cout << "Derived()\n";
    }
    ~Derived() override {
        std::cout << "~Derived()\n";
    }
    void f() override { std::cout << "Derived::f\n"; }
};

int main() {
    Derived d;
    Base& b = d;
    b.applyF();
}
