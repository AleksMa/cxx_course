#include <optional>
#include <string>
#include <iostream>

std::vector<std::string> cache = {
    "Alice",
};

std::optional<std::string> getName(bool ok) {
    if (!ok) {
        return std::nullopt;
    }
    return cache[0];
}

int main() {
    auto name = getName(true);

    if (name) {
        std::string s = *name;
        std::cout << s << "\n";
    }
}