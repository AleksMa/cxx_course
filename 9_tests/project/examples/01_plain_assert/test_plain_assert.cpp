#include <cassert>
#include <vector>

int add(int a, int b) {
    return a + b;
}

struct TestCase {
    int A;
    int B;
    int Expected;
};

int main() {
    const std::vector<TestCase> testCases = {
        {
            .A = 2,
            .B = 3,
            .Expected = 6,
        },
        {
            .A = -1,
            .B = 1,
            .Expected = 0,
        },
    };

    for (auto& [a, b, expected] : testCases) {
        assert(add(a, b) == expected);
    }
    
    // assert(add(2, 3) == 6);
    // assert(add(-1, 1) == 0);
    // assert(add(0, 0) == 0);
}
