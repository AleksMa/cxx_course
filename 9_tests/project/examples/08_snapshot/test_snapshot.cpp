#include <gtest/gtest.h>
#include "text_formatter.h"

#include <fstream>
#include <sstream>
#include <string>

std::string read_all(const std::string& path) {
    std::ifstream input(path);
    if (!input) {
        throw std::runtime_error("cannot open file");
    }

    std::ostringstream buffer;
    buffer << input.rdbuf();
    return buffer.str();
}

TEST(TextFormatterTest, MatchesCanonicalOutput) {
//     const std::string expectedStr = "User report\n-----------\nName: Alice\nAge: 30\n";
//     const std::string expectedRawStr = R"(User report
// -----------
// Name: Alice
// Age: 30
// )";
//     const std::string expectedMultilineStr = "User report\n"
// "-----------\n"
// "Name: Alice\n"
// "Age: 30\n";

    const std::string actual = make_greeting_report("Alice", 30);
    const std::string expected = read_all("data/greeting_expected.txt");
    // const auto expected = expectedStr;

    EXPECT_EQ(actual, expected);
}
