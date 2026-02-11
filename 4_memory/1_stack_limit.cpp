#include <iostream>

void recurse(int depth) {
    int64_t x = 42;
    std::cout << depth << std::endl;
    recurse(depth + 1);
}

int main() {
    recurse(0);
}
