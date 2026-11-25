#include "types.h"

extern u8 D_030056B6;
extern u8 D_02000000[2][0x500];
extern s16 (*D_030056A8[2])[2];
extern u16 D_0300568E[2];
extern u16 D_03005692[2];

u16 func_080C8B80(s32, s32);

void func_08078910(void)
{
    u16 *out = (u16 *)D_02000000[D_030056B6 ^ 1];
    u8 w;
    s16 y;
    s16 (*shape)[2];
    u16 sx, sy;
    s32 v;
    s16 left, right;

    for (w = 0; w < 2; w++)
    {
        shape = D_030056A8[w];
        if (shape == 0)
            continue;
        sx = D_0300568E[w];
        sy = D_03005692[w];
        if (sx == 0 || sy == 0)
        {
            for (y = 0; y < 160; y++)
            {
                *out = 0;
                out += 4;
            }
        }
        else
        {
            sy = func_080C8B80(0x10000, sy);
            v = -(sy * 80) + 0x5000;
            for (y = 0; y < 160; y++)
            {
                v += sy;
                if (v < 0 || v > 0x9FFF)
                {
                    *out = 0;
                }
                else
                {
                    left = shape[v / 256][0];
                    right = shape[v / 256][1];
                    if (left < right)
                    {
                        left = (left - 120) * sx / 256 + 120;
                        right = (right - 120) * sx / 256 + 120;
                        if (left < 0)
                            left = 0;
                        else if (left > 240)
                            left = 240;
                        if (right < 0)
                            right = 0;
                        else if (right > 240)
                            right = 240;
                        *out = (left << 8) | right;
                    }
                    else
                    {
                        *out = 0;
                    }
                }
                out += 4;
            }
        }
        out = (u16 *)((u8 *)out - 0x4FE);
    }
}
