#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>
#include <array>

#pragma pack(push, 1)
struct BmpFileHeader {
    std::uint16_t bfType;      // 'BM' = 0x4D42 (little-endian)
    std::uint32_t bfSize;      // size of file in bytes
    std::uint16_t bfReserved1; // must be 0
    std::uint16_t bfReserved2; // must be 0
    std::uint32_t bfOffBits;   // offset to pixel data
};
#pragma pack(pop)

static_assert(sizeof(BmpFileHeader) == 14, "BmpFileHeader must be exactly 14 bytes");

int main(int argc, char** argv) {
    const char* outPath = (argc >= 2) ? argv[1] : "header_only.bmp";

    BmpFileHeader hdr{};
    hdr.bfType = 0x4D42; // 'BM'
    hdr.bfSize = 14;
    hdr.bfReserved1 = 0;
    hdr.bfReserved2 = 0;
    hdr.bfOffBits = 14;

    std::array<char, sizeof(BmpFileHeader)> buf{};
    std::memcpy(buf.data(), &hdr, sizeof(hdr));

    std::ofstream out(outPath, std::ios::binary);
    if (!out) {
        return 2;
    }

    out.write(buf.data(), buf.size());

    if (!out) {
        return 1;
    }

    std::cout << "Wrote " << buf.size() << " bytes to " << outPath << "\n";
    return 0;
}
