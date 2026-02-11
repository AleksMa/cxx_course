#include <array>
#include <cassert>

int main() {
    std::array<int, 5> a = {10, 20, 30, 40, 50};

    int sum = 0;
    for (auto it = a.begin(); it != a.end(); ++it) {
        sum += *it;
    }
    assert(sum == 150);

    const std::array<int, 3> b = {1, 2, 3};
    int prod = 1;
    for (auto it = b.cbegin(); it != b.cend(); ++it) {
        prod *= *it;
        // *it = 10;
    }
    assert(prod == 6);
}
