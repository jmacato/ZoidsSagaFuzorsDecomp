#include "types.h"

struct Save
{
    u8 pad0[0x7904];
    u8 items[1];
};

extern struct Save D_02020E4C;

u32 func_0807F0C4(u8 id, u8 count)
{
    s32 total = count + D_02020E4C.items[id];
    u32 result;

    if (total > 99)
    {
        D_02020E4C.items[id] = 99;
        result = 0;
    }
    else
    {
        D_02020E4C.items[id] = total;
        result = 1;
    }
    return result;
}
