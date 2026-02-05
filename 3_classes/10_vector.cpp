#include <iostream>
#include <vector>
#include <string>

void print(const std::vector<int>& v) {
    std::cout << "size=" << v.size() << " : ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";
}

int sum(const std::vector<int>& v) {
    int s = 0;
    for (int x : v) s += x;
    return s;
}

int main() {
    std::vector<int> a;
    std::vector<int> b(5);
    std::vector<int> c(3, 42);
    std::vector<int> d = {1, 2, 3, 4};

    a.push_back(10);
    a.push_back(20);
    a.push_back(30);

    print(a);
    print(b);
    print(c);
    print(d);

    std::cout << "d[2]=" << d[2] << "\n";
    // std::cout << d.at(100) << "\n";

    std::cout << "sum(a)=" << sum(a) << "\n";
    std::vector<std::string> names = {"Alice", "Bob"};
    names.emplace_back("Catherine");

    for (const auto& s : names) {
        std::cout << s << "\n";
    }

    return 0;
}
