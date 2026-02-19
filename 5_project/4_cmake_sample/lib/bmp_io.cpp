#include "bmp_io.h"
#include <array>
#include <cstring>
#include <fstream>
#include <stdexcept>

#pragma pack(push, 1)
struct BmpFileHeader {
    std::uint16_t bfType;
    std::uint32_t bfSize;
    std::uint16_t bfReserved1;
    std::uint16_t bfReserved2;
    std::uint32_t bfOffBits;
};
#pragma pack(pop)

static_assert(sizeof(BmpFileHeader) == 14);

BmpMeta ReadBmpMeta(const std::string& path) {
    std::ifstream in(path, std::ios::binary);
    if (!in) throw std::runtime_error("Can't open file: " + path);

    std::array<std::uint8_t, sizeof(BmpFileHeader)> buf{};
    in.read(reinterpret_cast<char*>(buf.data()), static_cast<std::streamsize>(buf.size()));
    if (in.gcount() != static_cast<std::streamsize>(buf.size()))
        throw std::runtime_error("File too small");

    BmpFileHeader hdr{};
    std::memcpy(&hdr, buf.data(), sizeof(hdr));
    if (hdr.bfType != 0x4D42) throw std::runtime_error("Not a BMP");

    return BmpMeta{hdr.bfSize, hdr.bfOffBits};
}
