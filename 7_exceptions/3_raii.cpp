#include <iostream>
#include <stdexcept>

struct Resource {
    Resource() { 
        std::cout << "Acquired\n"; 
    }
    ~Resource() noexcept { 
        std::cout << "Released\n"; 
    }
};

void foo() {
    std::unique_ptr<int> uptr;
    Resource r;
    std::cout << "Exception" << std::endl;
    throw std::runtime_error("Boom"); // ~uptr ~r
    std::cout << "After exception" << std::endl;
}

void bar() {
    foo();
}

int main() {
    try {
        bar(); // <- bar <- foo <- runtime_error
    } catch (...) {
        std::cout << "Caught\n";
    }
}
