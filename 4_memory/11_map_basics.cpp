#include <map>
#include <cassert>
#include <iostream>

int main() {
    // std::map<int, int> m = {  // tree
    //     {1, 10},
    // };
    std::unordered_map<int, int> m = {  // hash-table
        {1, 10},
        {2, 20},
    };

    if (m[2] == 0) {
        std::cout << "Key 2 exists 🤔" << std::endl;
        assert(m.count(2) == 1);
        return 0;
    }

    auto it = m.find(2);
    assert(it != m.end());
    assert(it->first == 2);
    assert(it->second == 20);
    // m.erase(2);
    assert(m.at(2) == 20);

    auto it2 = m.find(42);
    assert(it2 == m.end());
}
