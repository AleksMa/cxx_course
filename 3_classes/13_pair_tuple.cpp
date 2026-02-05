#include <iostream>
#include <utility>
#include <tuple>
#include <string>

std::pair<int,int> minmax2(int a, int b) {
    if (a < b) {
        return {a, b};
    }
    return {b, a};
}

std::tuple<int, int, int> parse_rgb() {
    return std::make_tuple(120, 200, 255);
}

int main() {
    std::pair<std::string, int> p1 = {"Alice", 20};
    auto p2 = std::make_pair(std::string("Bob"), 12);

    std::cout << sizeof(p1.first) << " " << p1.first << " " << p1.second << "\n";
    std::cout << sizeof(p2.first) << " " << p2.first << " " << p2.second << "\n";

    // Лексикографическое сравнение
    std::cout << std::boolalpha << (p1 < p2) << "\n";

    // structured bindings for pair
    auto [name, score] = p2;
    std::cout << "name=" << name << " score=" << score << "\n";

    auto [mn, mx] = minmax2(7, 3);
    std::cout << "min=" << mn << " max=" << mx << "\n";

    std::tuple<int, int, int> t = parse_rgb();
    std::cout << "R=" << std::get<0>(t) << " G=" << std::get<1>(t) << " B=" << std::get<2>(t) << "\n";

    // structured bindings for tuple
    int r = 0, b = 0;
    auto [_, g, __] = t;
    std::cout << "r=" << r << " g=" << g << " b=" << b << "\n";

    // tie + ignore
    int rr = 0, gg = 0, bb = 0;
    std::tie(std::ignore, gg, std::ignore) = t;
    std::cout << "rr=" << rr << " gg=" << gg << " bb=" << bb << "\n";

    return 0;
}
