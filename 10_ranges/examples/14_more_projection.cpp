#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

enum class Kind {
    Word,
    Number,
    Plus
};

struct Token {
    Kind kind;
    std::string text;
};

struct PatternElem {
    Kind expected_kind;
    std::string comment;
};

int main() {
    std::vector<Token> tokens = {
        {Kind::Word,   "x"},
        {Kind::Plus,   "+"},
        {Kind::Number, "42"},
        {Kind::Plus,   "+"},
        {Kind::Number, "13"},
    };

    std::vector<Token> pattern = {
        {Kind::Plus,   "plus sign"},
        {Kind::Number, "some number"},
    };

    auto result = std::ranges::search(
        tokens,
        pattern,
        std::ranges::equal_to{},
        &Token::kind,
        &Token::kind
    );

    if (!result.empty()) {
        std::cout << "Found at position "
                  << std::distance(tokens.begin(), result.begin()) << "\n";

        for (const auto& t : result) {
            std::cout << t.text << ' ';
        }
        std::cout << "\n";
    } else {
        std::cout << "Not found\n";
    }
}
