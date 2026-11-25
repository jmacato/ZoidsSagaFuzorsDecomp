#include "types.h"

struct Save
{
    u8 pad0[0x79D6];
    u8 items[1];
};

extern struct Save D_02020E4C;

u32 func_0807F204(u8 id, u8 count)
{
    s32 left = D_02020E4C.items[id] - count;
    u32 result;

    if (left < 0)
    {
        D_02020E4C.items[id] = 0;
        result = 0;
    }
    else
    {
        D_02020E4C.items[id] = left;
        result = 1;
    }
    return result;
}
