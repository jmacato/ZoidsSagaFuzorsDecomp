#include "types.h"

struct Script
{
    u8 pad_0[0x11C];
    u8 *pcs[0x46];
    u8 pad_234[0x50];
    u8 field_284[0x46];
};

extern struct Script D_0201F6DC;
u8 func_08082F4C(u8);
void func_08083C5C(u8, s32, s32);

s32 func_08084914(u8 id, u8 **pc)
{
    if (D_0201F6DC.field_284[id] != 0 && !func_08082F4C((*pc)[1]))
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
            D_0201F6DC.field_284[id] = 0;
            return 1;
        }
    }
    return 0;
}
