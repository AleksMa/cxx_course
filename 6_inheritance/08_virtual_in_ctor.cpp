#include <iostream>

struct Base {
    Base() {
        std::cout << "Base() calls f(): ";
        f();
    }
    virtual ~Base() {
        std::cout << "~Base() calls f(): ";
        f();
    }
    virtual void f() { std::cout << "Base::f\n"; }
};

struct Derived : Base {
    Derived() { 
        std::cout << "Derived()\n";
        f();
    }
    ~Derived() override {
        std::cout << "~Derived()\n";
        f();
    }
    void f() override { std::cout << "Derived::f\n"; }
};

int main() {
    Derived d;
}
