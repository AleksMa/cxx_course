#include <array>
#include <cassert>

int main() {
    std::array<int, 4> a = {1, 2, 3, 4};

    for (int& x : a) {
        x *= 10;
    }
    assert((a == std::array<int, 4>{10, 20, 30, 40}));

    std::array<int, 3> b = {5, 6, 7};
    int sum = 0;

    for (auto it = b.begin(); it != b.end(); ++it) {
        int& x = *it;
        sum += x;
    }
    assert(sum == 18);
}
