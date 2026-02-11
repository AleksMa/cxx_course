#include <cassert>
#include <iostream>

struct IntArray {
    IntArray(int size);
    ~IntArray();

    int& at(int index);
    int size() const;

    // iterator 🤔
};

int main() {
    IntArray a(3);
    a.at(0) = 10;
    a.at(1) = 20;
    a.at(2) = 30;

    assert(a.size() == 3);
    assert(a.at(1) == 20);

    int v = 1;
    for (int& x : a) {
        x = v++;
    }
    assert(a.at(1) == 2);
}
