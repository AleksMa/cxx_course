#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

static void print_usage(const char* prog) {
    std::cout
        << "Usage:\n"
        << "  " << prog << " [--repeat N] [--upper] <text>\n\n"
        << "Examples:\n"
        << "  " << prog << " hello\n"
        << "  " << prog << " --repeat 3 hi\n"
        << "  " << prog << " --upper \"Hello, world!\"\n";
}

static int parse_int(const std::string& s) {
    std::size_t pos = 0;
    int x = std::stoi(s, &pos, 10);
    if (pos != s.size()) {
        throw std::invalid_argument("not a pure integer: " + s);
    }
    return x;
}

static void to_upper_ascii(std::string& s) {
    for (char& c : s) {
        if ('a' <= c && c <= 'z') c = static_cast<char>(c - 'a' + 'A');
    }
}

int main(int argc, char** argv) {
    std::cout << argv[0] << "\n\n";
    if (argc <= 1) {
        print_usage(argv[0]);
        return 1;
    }

    int repeat = 1;
    bool upper = false;

    std::string positional;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "--help" || arg == "-h") {
            print_usage(argv[0]);
            return 0;
        } else if (arg == "--upper") {
            upper = true;
        } else if (arg == "--repeat") {
            if (i + 1 >= argc) {
                std::cerr << "Error: --repeat expects a number\n";
                return 2;
            }
            try {
                repeat = parse_int(argv[++i]);
            } catch (const std::exception& e) {
                std::cerr << "Error: bad --repeat value: " << e.what() << "\n";
                return 2;
            }
            if (repeat < 0) {
                std::cerr << "Error: repeat must be >= 0\n";
                return 2;
            }
        } else if (!arg.empty() && arg[0] == '-') {
            std::cerr << "Error: unknown option: " << arg << "\n";
            return 2;
        } else if (positional.empty()) {
            positional = arg;
        } else {
            std::cerr << "Error: expected exactly one <text>\n";
            print_usage(argv[0]);
            return 2;
        }
    }

    if (positional.empty()) {
        std::cerr << "Error: expected exactly one <text>\n";
        print_usage(argv[0]);
        return 2;
    }

    if (upper) {
        to_upper_ascii(positional);
    }

    for (int k = 0; k < repeat; ++k) {
        std::cout << positional << "\n";
    }

    return 0;
}
