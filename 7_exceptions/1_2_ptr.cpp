#include <iostream>

int* findValue(bool found) {
    if (!found) {
        return nullptr;
    }
    return new int(42);
}

int main() {
    int* p = findValue(false);

    if (p) {
        std::cout << *p << "\n";
    } else {
        std::cout << "Not found\n";
    }

    delete p;
}