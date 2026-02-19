#include "bmp_io.h"
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <image.bmp>\n";
        return 2;
    }

    try {
        const auto meta = ReadBmpMeta(argv[1]);
        std::cout << "fileSize=" << meta.fileSize << "\n";
        std::cout << "pixelOffset=" << meta.pixelOffset << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
