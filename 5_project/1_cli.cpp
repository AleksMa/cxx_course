#include <iostream>
#include <string>

struct Args {
    std::string input;
    std::string output;
    int width = 0;
    int height = 0;
};

static void PrintUsage(const char* prog) {
    std::cerr << "Usage:\n"
              << "  " << prog << " -in <file.bmp> -out <out.bmp> [-size <width> <height>]\n";
}

int main(int argc, char** argv) { // char[][]
    Args a;

    for (int i = 1; i < argc; ++i) {
        std::string key = argv[i];

        auto needValue = [&](const char* name) -> const char* {
            if (i + 1 >= argc) {
                std::cerr << "Missing value for " << name << "\n";
                PrintUsage(argv[0]);
                std::exit(2);
            }
            return argv[++i];
        };

        if (key == "-in") {
            a.input = needValue("-in");
        } else if (key == "-out") {
            a.output = needValue("-out");
        } else if (key == "-size") {
            a.width = std::stoi(needValue("width"));
            a.height = std::stoi(needValue("height"));
        } else if (key == "-help" || key == "-h") {
            PrintUsage(argv[0]);
            return 0;
        } else {
            std::cerr << "Unknown arg: " << key << "\n";
            PrintUsage(argv[0]);
            return 2;
        }
    }

    if (a.input.empty() || a.output.empty()) {
        std::cerr << "Both -in and -out are required\n";
        PrintUsage(argv[0]);
        return 2;
    }

    std::cout << "in=" << a.input << "\n"
              << "out=" << a.output << "\n"
              << "width=" << a.width << "\n"
              << "height=" << a.height << "\n";

    return 0;
}
