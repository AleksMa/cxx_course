#pragma once
#include <cstdint>
#include <string>

struct BmpMeta {
    std::uint32_t fileSize = 0;
    std::uint32_t pixelOffset = 0;
};

BmpMeta ReadBmpMeta(const std::string& path);
