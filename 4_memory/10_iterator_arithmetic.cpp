#include <array>
#include <cassert>
#include <iterator>
#include <iostream>

int main() {
    std::array<int, 6> a = {10, 11, 12, 13, 14, 15};

    auto it = a.begin();
    assert(*it == 10);

    // it + N
    auto it3 = it + 3;
    assert(*it3 == 13);

    auto diff = it3 - it; // ptrdiff_t
    assert(diff == 3);

    assert(it[0] == 10);
    assert(it[5] == 15);
    assert(it[2] == 12);

    assert(std::distance(it, it3) == 3);

    auto it2 = a.begin();
    std::advance(it2, 2);
    assert(*it2 == 12);

    // std::vector<int> v = {1, 2, 3};
    // auto bad = v.begin() + 100; // UB
    // std::cout << *bad << "\n";
}
