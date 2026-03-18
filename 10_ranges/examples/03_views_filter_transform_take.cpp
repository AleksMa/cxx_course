#include <iostream>
#include <ranges>
#include <vector>

int main() {
    const std::vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto pipeline = values
        | std::views::filter([](int x) { return x % 2 == 0; })
        | std::views::transform([](int x) -> double { return x * x; })
        | std::views::take(3);

    std::ranges::copy(pipeline, std::ostream_iterator<double>(std::cout, " "));
    std::cout << '\n';
}
