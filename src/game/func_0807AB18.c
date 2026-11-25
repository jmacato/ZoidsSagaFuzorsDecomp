#include "types.h"

struct Glyphs
{
    u16 start;
    u8 count;
    u8 pad3;
    const u8 *data;
};

extern const struct Glyphs D_0873463C[];

u8 func_0807AAE0(u16);

u32 func_0807AB18(u16 ch, u8 color, u16 *dst0, u16 *dst1)
{
    u16 *dst[2];
    const u8 *src;
    u8 i, j;

    dst[0] = dst0;
    dst[1] = dst1;
    color = color % 3 + 1;
    i = func_0807AAE0(ch);
    if (i != 0xFF)
    {
        src = D_0873463C[i].data + (ch - D_0873463C[i].start) * 32;
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 16; j++)
            {
                *dst[i] = (*src & 3) | (color << 2) | (((*src & 0xC) | (color << 4)) << 2) | (((*src & 0x30) | (color << 6)) << 4) | (((*src & 0xC0) | (color << 8)) << 6);
                src++;
                dst[i]++;
            }
        }
        return 1;
    }
    return 0;
}
