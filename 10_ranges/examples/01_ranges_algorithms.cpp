#include <algorithm>
#include <list>
#include <iostream>
#include <ranges>
#include <vector>
#include <list>

template <typename T>
void PrintContainer(T& values) {
    std::ranges::copy(values, std::ostream_iterator<int>(std::cout, " "));
}

class MyClass {
public:
    std::vector<int>& GetData() { return data_; }
private:
    std::vector<int> data_;
};

int main() {
    std::vector<int> values = {7, 2, 9, 1, 5, 2, 8};
    std::list<int> list_values = {7, 2, 9, 1, 5, 2, 8};

    // PrintContainer(list_values);

    std::cout << "Data: ";
    PrintContainer(values);
    std::cout << "\n";

    std::ranges::sort(values);

    std::cout << "After std::ranges::sort: ";
    PrintContainer(values);
    std::cout << "\n";

    auto it = std::ranges::find(values, 5);
    if (it != values.end()) {
        std::cout << "5 was found: " << /*std::distance(values.begin(), it)*/ (it - values.begin()) << "\n";
    }

    int count_twos = std::ranges::count(values, 2);
    std::cout << "Count of 2s: " << count_twos << "\n";

    bool has_10 = std::ranges::binary_search(values, 10);
    std::cout << "Has 10? " << std::boolalpha << has_10 << "\n";
}
