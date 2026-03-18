#include <iostream>
#include <ranges>

int main() {
    auto numbers = std::views::iota(0, 11) // 0 1 2 3 4 5 6 7 8 9 10
        | std::views::drop(2) // 2 3 4 5 6 7 8 9 10
        | std::views::take(5) // 2 3 4 5 6
        | std::views::reverse;

    std::ranges::copy(numbers, std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}
