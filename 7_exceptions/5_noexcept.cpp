#include <iostream>

void foo() noexcept {
    std::cout << "foo\n";
    // throw 42;
}

int main() {
    try {
        foo();
    } catch (...) {

    }
}
