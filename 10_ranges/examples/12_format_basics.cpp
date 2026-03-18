#include <format>
#include <iostream>
#include <string>

int main() {
    const std::string name = "Alice";
    const std::string name2 = "Bob";
    int solved = 7;
    double score = 93.4567;

    std::cout << std::format("Student: {} }}{{\n", name);
    std::cout << std::format("Solved: {}\n", solved);
    std::cout << std::format("Score: {:.2f}\n", score);
    std::cout << std::format("Table: |{:>40}|{:>8.1f}|\n", name, score);
    std::cout << std::format("Table: |{:>40}|{:>8.1f}|\n", name2, score);
}
