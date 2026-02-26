#include <iostream>
#include <string>

struct Base {
    virtual ~Base() = default;

    virtual void set(int x) { std::cout << "Base::set(int) " << x << "\n"; }
    void set(const std::string& s) { std::cout << "Base::set(string) " << s << "\n"; }
};

struct DerivedBad : public Base {
    void set(int x) override { std::cout << "DerivedBad::set(int) " << x << "\n"; }
};

struct DerivedGood : public Base {
    using Base::set;

    void set(int x) override { std::cout << "DerivedGood::set(int) " << x << "\n"; }
};

int main() {
    DerivedBad a;
    a.set(1);
    // a.set(std::string("hi"));

    DerivedGood b;
    b.set(2);
    b.set(std::string("hi"));
}
