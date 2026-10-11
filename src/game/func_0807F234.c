#include "types.h"

extern u32 D_0202889C[];

u32 func_0807F234(u8 id)
{
    u32 *flags = &D_0202889C[id >> 5];
    u32 bit = 1 << (id & 0x1F);

    if (*flags & bit)
        return 0;
    *flags |= bit;
    return 1;
}
