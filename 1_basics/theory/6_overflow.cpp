#include <iostream>
#include <limits>

int main() {
    int x = std::numeric_limits<int>::max();
    std::cout << "max int = " << x << "\n";

    int y = x + 1;
    std::cout << "y = " << y << "\n";
}
