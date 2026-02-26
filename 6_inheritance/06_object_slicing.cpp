#include <iostream>
#include <vector>
#include <memory>

class Shape {
public:
    virtual ~Shape() = default;
    virtual int area() const { return 0; }
};

class Rectangle : public Shape {
    int w, h;
public:
    Rectangle(int w, int h) : w(w), h(h) {}
    int area() const override { return w * h; }
};

int main() {
    Rectangle r(3, 4);
    Shape s = r;
    std::cout << "s.area() = " << s.area() << "\n";

    std::vector<Shape*> v = {new Rectangle(3, 4)};
    std::cout << "v[0]->area() = " << v[0]->area() << "\n";

    Shape& ref = r;
    std::cout << "ref.area() = " << ref.area() << "\n";
}
