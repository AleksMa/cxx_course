// ({ 1, 2, 3, 4, 5 }, 2) -> {3, 4, 5, 1, 2}`
#include <cassert>

void shiftArray(int* const array, size_t size) {
    // Write your code here
    return;
}

int main() {
    constexpr size_t SIZE = 5;
    int array[SIZE] = {1, 2, 3, 4, 5};
    int expected[SIZE] = {3, 4, 5, 1, 2};

    int* arr_ptr = array;
    int* expected_ptr = expected;

    shiftArray(array, 2);

    for (int i = 0; i < SIZE; ++i) {
        assert(*arr_ptr++ == *expected_ptr++);
    }
}
