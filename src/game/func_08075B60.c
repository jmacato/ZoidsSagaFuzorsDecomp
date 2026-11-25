#include "types.h"

void func_080C8B7C(const void *, void *, u32);

void func_08075B60(u16 *dst, const u16 *src, u16 width, u16 height)
{
    u16 i;

    for (i = 0; i < height; i++)
    {
        func_080C8B7C(src, dst, width);
        src += width;
        dst += 32;
    }
}
