#include "math_utils.h"

int divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("division by zero");
    }
    return a / b;
}

int sum(const std::vector<int>& values) {
    int result = 0;
    for (int x : values) {
        result += x;
    }
    return result;
}
