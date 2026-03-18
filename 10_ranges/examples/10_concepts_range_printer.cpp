#include <iostream>
#include <list>
#include <ranges>
#include <string>
#include <vector>

template <std::ranges::input_range R>
void print_range(R&& range, const std::string& label) {
    std::cout << label << ": ";
    for (const auto& value : range) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

int main() {
    // int* arr = new int[3];
    std::vector<int> vec = {1, 2, 3};
    std::list<std::string> words = {"modern", "cpp", "rocks"};

    // print_range(arr, "c_array");
    print_range(vec, "vector");
    print_range(words, "list");

    auto even_squares = vec
        | std::views::filter([](int x) { return x % 2 == 0; })
        | std::views::transform([](int x) { return x * x; });

    print_range(even_squares, "view");

    // print_range(3.14, "float");
}
