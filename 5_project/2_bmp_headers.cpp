#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>
#include <array>

#pragma pack(push, 1)
struct BmpFileHeader {
    std::uint16_t bfSignature; // 'BM' = 0x4D42 (little-endian)
    std::uint32_t bfSize;      // size of file in bytes
    std::uint32_t bfReserved;  // must be 0
    std::uint32_t bfOffBits;   // offset to pixel data
};
#pragma pack(pop)

static_assert(sizeof(BmpFileHeader) == 14, "BmpFileHeader must be 14 bytes");

int main(int argc, char** argv) {
    std::cout << "sizeof(BmpFileHeader)=" << sizeof(BmpFileHeader) << std::endl;

    // if (argc < 2) {
    //     std::cerr << "Usage: " << argv[0] << " <image.bmp>\n";
    //     return 2;
    // }

    std::ifstream in("flag.bmp", std::ios::binary);
    if (!in) {
        std::cerr << "Can't open file: " << argv[1] << "\n";
        return 2;
    }

    std::array<char, sizeof(BmpFileHeader)> buf{};
    in.read(buf.data(), buf.size());
    if (in.gcount() != buf.size()) {
        std::cerr << "File is too small for BMP header\n";
        return 1;
    }

    // bad style: auto* hdr = reinterpret_cast<BmpFileHeader*>(buf.data());
    // POD struct

    // auto* hdrp = reinterpret_cast<BmpFileHeader*>(buf.data());

    BmpFileHeader hdr; // = *hdrp;
    std::memcpy(&hdr, buf.data(), sizeof(hdr));

    if (hdr.bfSignature != 0x4D42) { // 'BM'
        std::cerr << "Not a BMP (bfSignature != 'BM')\n";
        return 1;
    }

    std::cout << "BMP FileHeader:\n";
    std::cout << "  bfSize    = " << hdr.bfSize << "\n";
    std::cout << "  bfOffBits = " << hdr.bfOffBits << "\n";
    std::cout << "  reserved1 = " << hdr.bfReserved << "\n";

    return 0;
}
