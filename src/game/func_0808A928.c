#include "types.h"

s32 func_0808A928(s16 a, s16 b)
{
    s32 r;
    if (a <= b)
    {
        r = 0;
        if (a < b)
            r = 1;
    }
    else
        r = 2;
    return r;
}
