#include "types.h"

struct Glyphs
{
    u8 start;
    u8 count;
    u8 pad2[2];
    const u8 *data;
};

extern const struct Glyphs D_087346FC[];

u8 func_0807ACE4(u8);

u32 func_0807AD1C(u8 ch, u8 color, u16 *dst)
{
    u8 set;
    const u8 *src;
    u8 i;

    color = color % 3 + 1;
    set = func_0807ACE4(ch);
    if (set != 0xFF)
    {
    src = D_087346FC[set].data + (ch - D_087346FC[set].start) * 16;
    for (i = 0; i < 16; i++)
    {
        *dst = (*src & 3) | (color << 2) | (((*src & 0xC) | (color << 4)) << 2) | (((*src & 0x30) | (color << 6)) << 4) | (((*src & 0xC0) | (color << 8)) << 6);
        src++;
        dst++;
    }
    return 1;
    }
    return 0;
}
