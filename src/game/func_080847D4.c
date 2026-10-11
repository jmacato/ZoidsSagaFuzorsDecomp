#include "types.h"

struct Actor
{
    u8 flags;
    u8 id;
    u8 pad_2[0x17];
    u8 field_19;
};

struct Map
{
    u8 pad_0[0x424];
    struct Actor *current;
};

struct Script
{
    u8 pad_0[0x11C];
    u8 *pcs[0x46];
};

extern struct Map D_020209D8;
extern struct Script D_0201F6DC;
void func_08083C5C(u8, s32, s32);

s32 func_080847D4(u8 id, u8 **pc)
{
    struct Actor *a = D_020209D8.current;
    if (a != 0 && a->id != 0x8A && (a->field_19 & 0x40) && (a->field_19 & 0x3F) == (*pc)[1])
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
