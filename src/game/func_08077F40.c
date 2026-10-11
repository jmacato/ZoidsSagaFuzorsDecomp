#include "types.h"

struct Group
{
    u32 flags;
    u8 pad4[8];
    s32 objs[32];
};

s32 func_08077180(u32, u16, u16, s16, s16, u16, u16, u32, u32);

s32 func_08077F40(struct Group *group, u32 a1, u16 a2, u16 a3, s16 x, s16 y, u16 a6, u16 a7, u32 a8, u32 a9)
{
    u8 i;

    for (i = 0; i < 32; i++)
    {
        if (group->objs[i] == 0)
            return group->objs[i] = func_08077180(a1, a2, a3, x, y, a6, a7, a8, a9);
    }
}
