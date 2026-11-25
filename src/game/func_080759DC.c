#include "types.h"

s32 func_080759DC(s32 a, s32 b)
{
    s32 x, y, xi, yi, result;

    x = a;
    if (a < 0)
        x = -a;
    y = b;
    if (b < 0)
        y = -b;
    xi = x >> 12;
    yi = y >> 12;
    x &= 0xFFF;
    y &= 0xFFF;
    result = ((xi * yi) << 12) + xi * y + x * yi + ((x * y) >> 12);
    if (a >= 0)
    {
        if (b < 0)
            result = -result;
    }
    else if (b >= 0)
    {
        result = -result;
    }
    return result;
}
