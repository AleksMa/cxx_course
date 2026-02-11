#include <iostream>
#include <map>
#include <unordered_map>

int main() {
    std::map<int, std::string> ordered;
    std::unordered_map<int, std::string> unordered;

    ordered[3] = "three";
    ordered[1] = "one";
    ordered[2] = "two";

    unordered[3] = "three";
    unordered[1] = "one";
    unordered[2] = "two";

    std::cout << "std::map iteration:\n";
    for (const auto& [key, value] : ordered) {
        std::cout << key << " -> " << value << "\n";
    }

    std::cout << "\nstd::unordered_map iteration:\n";
    for (const auto& [key, value] : unordered) {
        std::cout << key << " -> " << value << "\n";
    }
}
