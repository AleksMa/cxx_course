#include <iostream>
#include <algorithm>

class Date {
public:
    int y;
    int m;
    int d;

    bool operator==(const Date& other) const {
        return y == other.y && m == other.m && d == other.d;
    }

    // <, >, <=, >=
    auto operator<=>(const Date& other) const {
        return std::tie(y, m, d) <=> std::tie(other.y, other.m, other.d);
    }

    // *this < other
    // bool operator<(const Date& other) const {
    //     return std::tie(y, m, d) < std::tie(other.y, other.m, other.d);
    // }
    // bool operator>(const Date& other) const {
    //     return std::tie(y, m, d) > std::tie(other.y, other.m, other.d);
    // }
    // bool operator>=(const Date& other) const {
    //     return std::tie(y, m, d) >= std::tie(other.y, other.m, other.d);
    // }
    // bool operator<=(const Date& other) const {
    //     return std::tie(y, m, d) <= std::tie(other.y, other.m, other.d);
    // }
};

std::ostream& operator<<(std::ostream& os, const Date& dt) {
    return os << dt.y << "-" << dt.m << "-" << dt.d;
}

int main() {
    Date a[] = {
        {2026, 2, 3},
        {2025, 12, 31},
        {2026, 1, 1},
        {2026, 2, 1}
    };
    const int n = static_cast<int>(sizeof(a) / sizeof(a[0]));

    std::ranges::sort(a);

    std::cout << "\nASC:\n";
    for (int i = 0; i < n; ++i) std::cout << a[i] << "\n";

    std::cout << "Check: " << (Date{2026,2,3} == a[n-1]) << "\n";

    std::sort(a, a + n, [](const Date& lhs, const Date& rhs) {
        return lhs > rhs;
    });
    std::cout << "\nDESC:\n";
    for (int i = 0; i < n; ++i) std::cout << a[i] << "\n";

    return 0;
}
