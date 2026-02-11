#include <map>
#include <cassert>

int main() {
    {
        std::map<int, int> m = {{1, 10}, {2, 20}, {3, 30}};

        auto it = m.begin();

        assert(it->first == 1);
        ++it;
        assert(it->first == 2);

        --it;
        assert(it->first == 1);

        // it + 1;
    }
    {
        std::unordered_map<int, int> m = {{1, 10}, {2, 20}};

        auto it = m.begin();
        ++it;

        // --it;
    }
}
