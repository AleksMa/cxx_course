#include <cassert>

struct SimpleVector {
    SimpleVector(int capacity);
    ~SimpleVector();

    void push_back(int x);
    int size() const;
    int& at(int index);
};

int main() {
    SimpleVector v(5);

    assert(v.size() == 0);

    v.push_back(10);
    v.push_back(20);

    assert(v.size() == 2);
    assert(v.at(0) == 10);
    assert(v.at(1) == 20);
}

