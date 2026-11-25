#include "types.h"

extern const u16 D_080C8FD4[];

s16 func_08075AAC(u16 angle)
{
    s16 a = angle & 0xFF;
    s16 idx;
    s16 val;

    if ((a & 0x7F) < 0x40)
        idx = a & 0x3F;
    else
        idx = 0x40 - (a & 0x3F);
    val = D_080C8FD4[idx];
    if (a > 0x7F)
        return -val;
    return val;
}
