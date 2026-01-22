#include <iostream>

enum class University : uint8_t {
    HSE,
    MIPT,
    BMSTU = 20,
    MSU,
};

enum class Response {
    OK = 200,
    BadRequest = 400,
    NotFound = 404,
};

enum class Liceum {
    HSE,
    MIPT,
    BMSTU,
    MSU,
};

void print(University u) {
    switch (u) {
        case University::HSE:
        case University::MIPT:
            std::cout << "HSE or MIPT\n";
            break;
        case University::BMSTU:
            std::cout << "BMSTU\n";
            break;
        default:
            std::cout << "MSU or smth else\n";
    }
}

int main() {
    University u = University::HSE;

    std::cout << static_cast<uint32_t>(u) << "\n";
    std::cout << static_cast<uint32_t>(University::MIPT) << "\n";
    std::cout << static_cast<uint32_t>(University::BMSTU) << "\n";
    std::cout << static_cast<uint32_t>(University::MSU) << "\n";

    print(University::HSE);

    std::cout << "\n" << sizeof(University) << "\n";

    return 0;
}
