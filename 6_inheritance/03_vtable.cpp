#include <iostream>
#include <cstdint>

class Base {
public:
    virtual ~Base() = default;
    virtual void f() const { std::cout << "Base::f\n"; }
    virtual void g() const { std::cout << "Base::g\n"; }
};

class Derived final : public Base {
public:
    void f() const override { std::cout << "Derived::f\n"; }
    void g() const override { std::cout << "Derived::g\n"; }
};

void callThroughBase(const Base& b) {
    b.f();
    b.g();
}

int main() {
    Base b;
    Derived d;

    std::cout << "sizeof(Base)   = " << sizeof(Base) << "\n";
    std::cout << "sizeof(Derived)= " << sizeof(Derived) << "\n";
    std::cout << "\n";

    std::cout << "Calling through Base&:\n";
    callThroughBase(b);
    callThroughBase(d);

    std::cout << "\n";
}