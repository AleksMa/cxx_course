#include <iostream>
#include <vector>
#include <memory>

struct Shape {
    virtual ~Shape() = default;
    virtual int area() const { return 0; }
};

struct Rectangle : Shape {
    int w, h;
    Rectangle(int w, int h) : w(w), h(h) {}
    int area() const override { return w * h; }
};

int main() {
    Rectangle r(3, 4);

    Shape s = r;
    std::cout << "s.area() = " << s.area() << "\n";

    std::vector<std::unique_ptr<Shape>> v;
    v.push_back(std::make_unique<Rectangle>(3, 4));
    std::cout << "v[0]->area() = " << v[0]->area() << "\n";

    Shape& ref = r;
    std::cout << "ref.area() = " << ref.area() << "\n";
}
