#include <array>
#include <iostream>
#include <span>
#include <vector>
#include <deque>

int sum(std::span<const int> data) {
    int result = 0;
    for (int x : data) {
        result += x;
    }
    return result;
}

int main() {
    int raw_array[] = {1, 2, 3, 4};
    std::array<int, 3> std_array = {10, 20, 30};
    std::vector<int> vec = {7, 8, 9};

    std::cout << "sum(raw_array) = " << sum(raw_array) << '\n';
    std::cout << "sum(std::array) = " << sum(std_array) << '\n';
    std::cout << "sum(vector) = " << sum(vec) << '\n';
}
