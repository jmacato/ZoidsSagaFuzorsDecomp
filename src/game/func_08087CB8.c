#include "types.h"

struct Map
{
    u8 pad_0[0x14];
    u16 width;
    u16 height;
    u8 mode;
};

extern struct Map D_020209D8;
extern u16 *D_02031A0C[2];
extern u16 (*D_02031A14)[4];

u16 func_08087CB8(u8 side, u16 x0, u16 y0)
{
    u32 x = x0;
    u32 y = y0;

    x = (u16)((s16)x % D_020209D8.width);
    y = (u16)((s16)y % D_020209D8.height);
    while ((s16)x < 0)
        x = (u16)(D_020209D8.width + x);
    while ((s16)y < 0)
        y = (u16)(D_020209D8.height + y);
    if (D_020209D8.mode != 2 && ((s16)x >= D_020209D8.width || (s16)y >= D_020209D8.height))
        return 0;
    {
        s16 sx = x;
        s16 sy = y;
        return D_02031A14[*(D_02031A0C[side] + sx / 2 + (sy / 2) * (D_020209D8.width >> 1))][(sx & 1) + (sy & 1) * 2];
    }
}
