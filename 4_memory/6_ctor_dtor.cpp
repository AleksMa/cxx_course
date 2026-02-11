#include <iostream>

struct Int {
    int* data;

    Int(int n) {
        data = new int(n);
        std::cout << "ctor " <<  *data << "\n";
    }

    ~Int() {
        std::cout << "dtor " <<  *data << "\n";
        delete data;
    }
};

int main() {
    Int b(10);
    {
        Int a(5);
    }
    Int c(20);
}
