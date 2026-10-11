#include "types.h"

struct Unit
{
    u8 pad0[0x3C];
    u8 active;
    u8 pad3D[0x94 - 0x3D];
};

extern struct Unit D_02020E4C[];

s32 func_080BE144(void)
{
    s32 count = 0;
    u8 i;
    for (i = 1; i < 0xBA; i++)
    {
        if (D_02020E4C[i].active)
            count++;
    }
    return count;
}
