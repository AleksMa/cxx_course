#include <iostream>
#include <string>

int main() {
    std::string s = "hello";
    s += " world";

    std::cout << s << "\n";

    const char* p1 = s.c_str();
    const char* p2 = s.data();

    std::cout << p1 << "\n";
    std::cout << p2 << "\n";

    // const char* p = s.c_str();
    // const char* p = s.data();
    // s += "!";
    // std::cout << p;

    // std::string s = "  hello world  ";

    // std::cout << s.empty() << "\n";
    // std::cout << s.at(2) << "\n";
    // std::cout << s[2] << "\n";

    // std::cout << s.at(20) << "\n";
    // std::cout << s[20] << "\n";

    // std::cout << s.substr(2, 5) << "\n";

    // if (s.starts_with("  he")) {
    //     std::cout << "starts\n";
    // }

    // std::erase_if(s, [](char c) {
    //     return c == ' ';
    // });

    // std::cout << s << "\n";

    // std::string a = "hello";
    // std::string b = "привет";

    // std::cout << "a.size() = " << a.size() << "\n";
    // std::cout << "b.size() = " << b.size() << "\n";

    // std::string s2 = "привет";

    // for (size_t i = 0; i < s2.size(); ++i) {
    //     unsigned char c = s2[i];
    //     std::cout << "byte[" << i << "] = 0x"
    //               << std::hex << std::setw(2) << std::setfill('0')
    //               << static_cast<int>(c) << "\n";
    // }

    // std::string s = "привет мир";

    // if (s.starts_with("при")) {
    //     std::cout << "starts\n";
    // }
}
