// 05_constructors_basics.cpp
#include <iostream>

class Person {
private:
    int age_;
public:
    Person() : age_(0) {}                 // default ctor
    explicit Person(int age) : age_(age) {} // explicit

    int age() const { return age_; }
};

class Rect {
    int w_;
    int h_;
public:
    Rect() : Rect(1, 1) { } // delegating ctor
    Rect(int s) : Rect(s, s) {}
    Rect(int w, int h) : w_(w), h_(h) {}

    int area() const {
        return w_ * h_;
    }
};

int showAge(Person p) {
    return p.age();
}

int main() {
    Person p;          // Person()
    Person q(25);      // Person(int)
    // Person r = 25;  // no ctor: explicit!

    // std::cout << showAge(25) << "\n";

    std::cout << "p.age=" << p.age() << ", q.age=" << q.age() << "\n";

    Rect a;
    Rect b(3, 4);
    std::cout << "a.area=" << a.area() << ", b.area=" << b.area() << "\n";

    return 0;
}
