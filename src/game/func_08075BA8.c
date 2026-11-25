#include "types.h"

void func_080C8B7C(const void *, void *, u32);

void func_08075BA8(u16 *dst, const u16 *src, u16 x, u16 y, u16 width, u16 height, u16 add)
{
    u16 w;
    u16 j;

    w = width > 32 ? 32 : width;
    dst += (s16)x + (s16)y * 32;
    for (y = 0; y < height; y++)
    {
        func_080C8B7C(src, dst, w);
        for (j = 0; j < w; j++)
            dst[j] = (dst[j] & 0xC00) | (add + (dst[j] & 0xF3FF));
        src += width;
        dst += 32;
    }
}
