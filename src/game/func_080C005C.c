#include "types.h"

u8 func_080C005C(u8 a, u8 b, u8 c, u8 d)
{
    u8 r;
    if (b <= 5)
    {
        r = 0;
        if (a != c)
        {
            r = 1;
            if (d > 2)
                r = 2;
            if (b > 2)
                r++;
        }
        else if ((b <= 2 && d > 2) || (b > 2 && d <= 2))
            r++;
    }
    else
        r = 1;
    return r;
}
