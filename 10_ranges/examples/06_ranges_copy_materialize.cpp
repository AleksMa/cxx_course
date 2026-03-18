#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

int main() {
    std::vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8};

    auto odd_cubes = values
        | std::views::filter([](int x) { return x % 2 == 1; })
        | std::views::transform([](int x) { return x * x * x; });

    std::vector<int> materialized;
    std::ranges::copy(odd_cubes, std::back_inserter(materialized));

    std::cout << "Materialized vector: ";
    for (int x : materialized) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}
