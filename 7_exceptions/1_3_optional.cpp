#include <iostream>
#include <optional>

std::optional<int> findValue(bool found) {
    if (!found) {
        return std::nullopt;
    }

    return 42;
}

int main() {
    std::optional<int> v = findValue(false);

    if (v) {
        std::cout << v.value() << "\n";
    } else {
        std::cout << "Not found\n";
    }
}
