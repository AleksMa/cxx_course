#include <iostream>

struct Point {
    double x;
    double y;

    void move(double dx, double dy) {
        x += dx;
        y += dy;
    }
};

class Counter {
    int value_;
public:
    Counter() : value_(0) {}

    void inc() { ++value_; }

    int value() const { return value_; }
};

int main() {
    // Point p{1.0, 2.0};
    Point p {
        .y = 1.0,
        .x = 2.0,
    };
    p.move(10.0, -1.0);
    std::cout << "Point: (" << p.x << ", " << p.y << ")\n";

    Counter c;
    c.inc();
    c.inc();
    std::cout << "Counter=" << c.value() << "\n";

    // c.value_ = 123;

    return 0;
}
