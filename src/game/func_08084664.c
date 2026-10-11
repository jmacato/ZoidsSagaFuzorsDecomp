#include "types.h"

struct Map
{
    u8 pad_0[0x429];
    u8 field_429;
};

struct Script
{
    u8 pad_0[0x11C];
    u8 *pcs[0x46];
};

extern struct Map D_020209D8;
extern struct Script D_0201F6DC;
void func_08083C5C(u8, s32, s32);

s32 func_08084664(u8 id, u8 **pc)
{
    if (D_020209D8.field_429 == (*pc)[1])
    {
        func_08083C5C(id, -1, 0);
        while (**pc == 0x18)
        {
            func_08083C5C(id, -1, 0);
            func_08083C5C(id, -1, 0);
        }
    }
    else
    {
        func_08083C5C(id, -1, 0);
        if (**pc != 0x18)
        {
            *pc = D_0201F6DC.pcs[id];
            return 1;
        }
    }
    return 0;
}
