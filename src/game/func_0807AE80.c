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

u32 func_0807AE80(u8 ch, u8 color, u16 *dst0, u16 *dst1)
{
    u16 *dst[2];
    const u8 *src;
    u8 i, j;

    dst[0] = dst0;
    dst[1] = dst1;
    color = color % 3 + 1;
    i = func_0807ACE4(ch);
    if (i != 0xFF)
    {
        src = D_087346FC[i].data + (ch - D_087346FC[i].start) * 16;
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 16; j++)
            {
                if ((i == 0 && j < 8) || (i != 0 && j > 7))
                {
                    *dst[i] = (color << 2) | (color << 6) | (color << 10) | (color << 14);
                }
                else
                {
                    *dst[i] = (*src & 3) | (color << 2) | (((*src & 0xC) | (color << 4)) << 2) | (((*src & 0x30) | (color << 6)) << 4) | (((*src & 0xC0) | (color << 8)) << 6);
                    src++;
                }
                dst[i]++;
            }
        }
        return 1;
    }
    return 0;
}
