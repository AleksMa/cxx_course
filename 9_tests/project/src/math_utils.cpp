#include "math_utils.h"
#include <stdexcept>

int add(int a, int b) {
    return a + b;
}

int divide(int a, int b) {
    if (b == 0)
        throw std::invalid_argument("division by zero");

    return a / b;
}

int sum(const std::vector<int>& values) {
    int result = 0;
    for (int v : values)
        result += v;

    return result;
}
