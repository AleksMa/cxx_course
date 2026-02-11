#include <array>
#include <cassert>
#include <iterator> // std::distance, std::advance

int main() {
    std::array<int, 6> a = {10, 11, 12, 13, 14, 15};

    auto it = a.begin();          // random access iterator
    assert(*it == 10);

    // it + N
    auto it3 = it + 3;
    assert(*it3 == 13);

    auto diff = it3 - it;         // ptrdiff_t
    assert(diff == 3);

    // it[i] как "смещение" относительно it
    assert(it[0] == 10);
    assert(it[5] == 15);
    assert(it[2] == 12);

    // std::distance тоже работает
    assert(std::distance(a.begin(), a.end()) == 6);

    // std::advance двигает итератор на N
    auto it2 = a.begin();
    std::advance(it2, 2);
    assert(*it2 == 12);

    // auto bad = a.begin() + 100; // UB
}
