#include <iostream>

enum TUniversity {
    NotFound = 0,
    HSE = 1,
    MSU = 2,
}

int findValue(bool found) {
    // std::map<TKey, int> = {};
    if (!found) {
        return 0;
    }
    return int(42);
}

int main() {
    int p = findValue(false);

    if (p) {
        std::cout << *p << "\n";
    } else {
        std::cout << "Not found\n";
    }
}
