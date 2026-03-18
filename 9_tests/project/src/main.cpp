#include "math_utils.h"
#include <iostream>
#include <vector>

int main() {
    std::cout << add(2,3) << "\n";
    std::cout << divide(10,2) << "\n";

    std::vector<int> v{1,2,3};
    std::cout << sum(v) << "\n";
}
