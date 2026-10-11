#include "types.h"

struct Slot
{
    u32 flags;
    u32 a;
    u32 b;
    u32 c;
    u8 pad10[0x1C];
};

extern struct Slot D_030053CC[];

u32 func_0807806C(u32 a, u32 b, u16 c)
{
    u8 i;
    struct Slot *slot;

    for (i = 0; i < 16; i++)
    {
        slot = &D_030053CC[i];
        if (!(slot->flags & 1))
            break;
    }
    if (i == 16)
        return 0;
    slot->flags = 1;
    slot->a = a;
    slot->b = b;
    slot->c = c;
    return 1;
}
