#include "types.h"

void func_080C8B84(const void *, void *);
void func_080C8B88(const void *, void *);

void func_08080168(const void *src, u8 bg, u8 flip, u16 *buf)
{
    u16 *dst;
    u8 y, x;

    if (flip == 0)
    {
        func_080C8B84(src, (void *)(0x06000000 + bg * 0x800));
        return;
    }
    func_080C8B88(src, buf);
    dst = (u16 *)(0x06000000 + bg * 0x800);
    for (y = 0; y < 32; y++)
    {
        for (x = 0; x < 32; x++)
            *dst++ = (buf + (31 - x))[y * 32] ^ 0x400;
    }
}
