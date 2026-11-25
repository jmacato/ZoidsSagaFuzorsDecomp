#include "types.h"

s32 func_08075A30(s32 a, s32 b)
{
    s32 x, y, result, i;

    x = a;
    if (x < 0)
        x = -x;
    y = b;
    if (b < 0)
        y = -b;
    if (x == 0 || y == 0)
        return 0;
    asm volatile("" :: "r"(x));
    result = 0;
    asm volatile("" : "+r"(result));
    i = result;
    do
    {
        result <<= 4;
        result += x / y;
        x %= y;
        x <<= 4;
        i++;
    } while (i <= 3 && x != 0);
    while (i <= 3)
    {
        result <<= 4;
        i++;
    }
    if (a < 0)
    {
        if (b >= 0)
            result = -result;
    }
    else if (b < 0)
    {
        result = -result;
    }
    return result;
}
