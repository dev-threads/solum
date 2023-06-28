#pragma once

#include <span>

/// Common structure for Solum-provided image data.
/// Not necessarily a raw bitmap.
struct SolumImage
{
    std::span<uint8_t> img_;
    int width_;
    int height_;
    int bpp_;

    bool isRawBitmap() const
    {
        return (img_.size_bytes() == size_t(width_ * height_ * (bpp_ / 8)));
    }
};
