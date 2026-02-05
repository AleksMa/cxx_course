#include <iostream>
#include <algorithm>
#include <cstring>

struct Student {
    std::string name;
    int score;
    int id;
};

bool sortByScore(const Student& a, const Student& b) {
    return a.score > b.score;
}

int main() {
    Student s[] = {
        {"Alice", 100, 2},
        {"Bob",   120, 1},
        {"Alice", 100, 1},
        {"Catherine",   120, 3},
    };

    const int n = static_cast<int>(sizeof(s) / sizeof(s[0]));

    // std::ranges::sort(
    //     s,
    //     [](const Student& a, const Student& b) {
    //         if (a.score != b.score) {
    //             return a.score > b.score;
    //         }

    //         if (a.name != b.name) {
    //             return a.name < b.name;
    //         }

    //         return a.id < b.id;

    //         // return std::tie(a.score, a.name, a.id) < std::tie(b.score, b.name, b.id);
    //     }
    // );

    std::ranges::sort(
        s,
        [](const Student& a, const Student& b) {
            return std::tie(a.name, a.id) < std::tie(b.name, b.id);
        }
    );

    std::ranges::stable_sort(
        s,
        sortByScore
    );

    for (int i = 0; i < n; ++i) {
        std::cout << s[i].name << " score=" << s[i].score << " id=" << s[i].id << "\n";
    }
    return 0;
}
