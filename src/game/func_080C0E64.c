#include "types.h"

s32 func_080C0E64(s32 x)
{
    u32 n, r;
    u8 neg;
    if (x == 0)
        return 0;
    if (x > 0)
        neg = 0;
    else
    {
        x = -x;
        neg = 1;
    }
    n = 1;
    r = x;
    while (n < r)
    {
        n <<= 1;
        r >>= 2;
    }
    do
    {
        r = n;
        n = ((u32)x / (r * r) + r * 2) / 3;
    } while (n < r);
    if (neg == 0)
        return r;
    return -r;
}
