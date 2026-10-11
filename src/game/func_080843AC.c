#include "types.h"

s32 func_080843AC(u8 id, u8 **pc)
{
    u8 *p = *pc;
    *pc = (u8 *)(p[1] | (p[2] << 8) | (p[3] << 16) | (p[4] << 24));
    return 0;
}
