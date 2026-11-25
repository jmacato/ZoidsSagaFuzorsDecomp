#include "types.h"

void func_0809F814(u8 value, u8 *dst)
{
    s32 filled = 0;
    u8 i;
    for (i = 10; i < 30; i++)
    {
        if (value != 0xFF)
        {
            if (value + 10 <= i)
                filled = 1;
            if (!(i & 1))
            {
                if (filled)
                {
                    dst[0] = (dst[0] & 0xF0) | 3;
                    dst[4] = (dst[4] & 0xF0) | 0xA;
                    if (i > 16)
                        dst[8] = (dst[8] & 0xF0) | 0xA;
                }
            }
            else
            {
                if (filled)
                {
                    dst[0] = (dst[0] & 0xF) | 0x30;
                    dst[4] = (dst[4] & 0xF) | 0xA0;
                    if (i > 16)
                        dst[8] = (dst[8] & 0xF) | 0xA0;
                }
                if ((i & 7) <= 6)
                    dst++;
                else
                    dst += 0x1D;
            }
        }
        else
        {
            if (!(i & 1))
            {
                dst[0] = (dst[0] & 0xF0) | 0xE;
                dst[4] = (dst[4] & 0xF0) | 0xE;
                if (i > 16)
                    dst[8] = (dst[8] & 0xF0) | 0xE;
            }
            else
            {
                dst[0] = (dst[0] & 0xF) | 0xE0;
                dst[4] = (dst[4] & 0xF) | 0xE0;
                if (i > 16)
                    dst[8] = (dst[8] & 0xF) | 0xE0;
                if ((i & 7) <= 6)
                    dst++;
                else
                    dst += 0x1D;
            }
        }
    }
}
