#include "types.h"

s32 func_08082E58(u8 *p)
{
    s32 r = 0;
    if (p[1] >= 0x88 && p[1] <= 0x8A)
        r = 1;
    return r;
}
