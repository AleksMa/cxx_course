#include <iostream>
#include <string>

int main() {
    std::cout << "Enter age: ";
    int age;
    std::cin >> age;

    std::cout << "Enter name: ";
    std::string name;
    std::cin >> name;

    std::cout << "Hello, " << name << ", age=" << age << "\n";
}
