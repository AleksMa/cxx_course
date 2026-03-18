#include <iostream>
#include <span>
#include <vector>

void print_span(std::span<const int> data, const char* label) {
    std::cout << label << ": ";
    for (int x : data) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> values = {100, 200, 300, 400, 500, 600};
    std::span<const int> all(values);

    print_span(all, "all");
    print_span(all.first<2>(), "first 2");
    print_span(all.last<2>(), "last 2");
    print_span(all.subspan(2, 3), "2..5");
}
