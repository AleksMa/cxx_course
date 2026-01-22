#include <iostream>
#include <string>

int main() {
    int age;
    std::cin >> age;
    // int height;
    // std::cin >> height;

    std::string line;
    std::getline(std::cin, line);
    std::getline(std::cin, line);
    std::cout << "You typed: " << line << "\n";
    std::cout << "You typed: " << age /*<< " " << height*/ << "\n";
}
