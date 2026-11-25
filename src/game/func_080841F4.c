#include "types.h"

struct Actor
{
    u8 flags;
    u8 pad_1[3];
    s32 x;
    s32 y;
    u8 pad_C[0x38];
};

struct Map
{
    u8 pad_0[0x6C];
    struct Actor actors[14];
};

extern struct Map D_020209D8;
u8 func_08080C54(u8);
void func_08084164(u8, u8, s32, s32, u8, u8, u8);
void func_08083C5C(u8, s32, s32);

s32 func_080841F4(u8 id, u8 **pc)
{
    u8 slot;
    s16 dx, dy;
    if ((*pc)[1] <= 12)
    {
        slot = func_08080C54((*pc)[3]);
        dx = (*pc)[4] | ((*pc)[5] << 8);
        dy = (*pc)[6] | ((*pc)[7] << 8);
        func_08084164((*pc)[2], (*pc)[1], (dx << 11) + D_020209D8.actors[slot].x, (dy << 11) + D_020209D8.actors[slot].y, (*pc)[8], (*pc)[9], 0);
    }
    func_08083C5C(id, -1, 0);
    return 0;
}
