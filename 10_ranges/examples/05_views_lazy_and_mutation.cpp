#include <iostream>
#include <ranges>
#include <vector>

int main() {
    std::vector<int> values = {1, 2, 3, 4};

    auto squares = values | std::views::transform([](int x) {
        std::cout << "transform(" << x << ")\n";
        return x * x;
    });

    std::cout << "View was created.\nFirst process:\n\n";
    std::ranges::copy(squares, std::ostream_iterator<int>(std::cout, "// \n"));

    values[1] = 10;
    std::cout << "Second process:\n\n";
    std::ranges::copy(squares, std::ostream_iterator<int>(std::cout, "// \n"));
}
