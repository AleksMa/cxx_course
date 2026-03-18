#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int score;
};

int main() {
    std::vector<Student> students = {
        {"Alice", 83},
        {"Bob", 91},
        {"Clare", 77},
        {"Dan", 95},
    };

    std::ranges::sort(students, std::ranges::greater{}, &Student::score);

    std::cout << "Sorted with projection:\n";
    for (const Student& s : students) {
        std::cout << s.name << ": " << s.score << '\n';
    }

    auto best_it = std::ranges::max_element(students, {}, &Student::score);
    if (best_it != students.end()) {
        std::cout << "\nBest: " << best_it->name
                  << " (" << best_it->score << ")\n";
    }
}
