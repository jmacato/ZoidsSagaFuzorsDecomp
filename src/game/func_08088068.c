#include "types.h"

struct Map
{
    u8 pad_0[0xC];
    s16 scroll[2][2];
    u16 width;
    u16 height;
};

extern struct Map D_020209D8;
extern s32 D_03000060[];
extern u16 *D_02031A0C[2];
u16 func_08087CB8(u8, s16, s16);

void func_08088068(void)
{
    u8 i;
    s16 d;
    s16 x;
    s16 y;
    s16 j;
    u16 *vram;

    for (i = 0; i < 2; i++)
    {
        if (D_02031A0C[i] != 0)
        {
            vram = (u16 *)(0x06000000 + i * 0x800);
            d = ((D_03000060[i * 2] >> 11) - D_020209D8.scroll[i][0]) % D_020209D8.width;
            while (d < 0)
                d += D_020209D8.width;
            if (d != 0)
            {
                if (d == D_020209D8.width - 1)
                    x = D_020209D8.scroll[i][0] - 1;
                else
                    x = D_020209D8.scroll[i][0] + 31;
                y = D_020209D8.scroll[i][1];
                for (j = 0; j <= 20; j++)
                    *(vram + (x & 31) + ((y + j) & 31) * 32) = func_08087CB8(i, x, y + j);
            }
        }
        D_020209D8.scroll[i][0] = D_03000060[i * 2] >> 11;
    }
    for (i = 0; i < 2; i++)
    {
        if (D_02031A0C[i] != 0)
        {
            vram = (u16 *)(0x06000000 + i * 0x800);
            d = ((D_03000060[i * 2 + 1] >> 11) - D_020209D8.scroll[i][1]) % D_020209D8.height;
            while (d < 0)
                d += D_020209D8.height;
            if (d != 0)
            {
                x = D_020209D8.scroll[i][0];
                if (d == D_020209D8.height - 1)
                    y = D_020209D8.scroll[i][1] - 1;
                else
                    y = D_020209D8.scroll[i][1] + 21;
                for (j = 0; j <= 30; j++)
                    *(vram + ((x + j) & 31) + (y & 31) * 32) = func_08087CB8(i, x + j, y);
            }
        }
        D_020209D8.scroll[i][1] = D_03000060[i * 2 + 1] >> 11;
    }
}
