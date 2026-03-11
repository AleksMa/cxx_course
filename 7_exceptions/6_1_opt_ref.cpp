#include <optional>
#include <string>
#include <iostream>
#include <vector>

std::vector<std::string> cache = {
    "Alice",
};

std::optional<std::reference_wrapper<std::string>> getName(bool ok) {
    if (!ok) {
        return std::nullopt;
    }
    return cache[0];
}

int main() {
    const auto nameOrNullopt = getName(true);

    if (nameOrNullopt.has_value()) {
        const std::string& name = *nameOrNullopt;
        std::cout << name << "\n";
    }
}
