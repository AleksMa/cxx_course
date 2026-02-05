#include <iostream>

class Token {
    int id_;
public:
    explicit Token(int id) : id_(id) {
        std::cout << "Token(" << id_ << ")\n";
    }
};

class WithDefault {
    int id_;
public:
    WithDefault() : id_(0) {
        std::cout << "WithDefault()\n";
    }
    explicit WithDefault(int id) : id_(id) {
        std::cout << "WithDefault(" << id_ << ")\n";
    }
};

int main() {
    Token t[3];

    WithDefault c{};
    std::cout << "----\n";

    WithDefault a[3];
    std::cout << "----\n";

    WithDefault b[3] = {WithDefault(10), WithDefault(20)};
    std::cout << "----\n";

    return 0;
}
