#include <iostream>
#include <string>

class Named {
public:
    virtual ~Named() = default;
    virtual std::string name() const = 0;
};

class Printable {
public:
    virtual ~Printable() = default;
    virtual void print() const = 0;
};

class Widget final
: public Named
, public Printable
{
public:
    std::string name() const override { return "Widget"; }
    void print() const override { std::cout << "I am a Widget\n"; }
};

static void greet(const Named& n) {
    std::cout << "Hello, " << n.name() << "!\n";
}

int main() {
    Widget w;
    greet(w);
    w.print();

    Named* pn = &w;
    Printable* pp = &w;

    std::cout << pn->name() << std::endl;
    pp->print();

    std::cout << "Done.\n";
}
