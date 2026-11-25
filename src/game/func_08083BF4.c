#include "types.h"

struct Actor
{
    u8 flags;
    u8 pad_1;
    u8 id;
    u8 field_3;
    u8 pad_4[0x40];
};

struct Map
{
    u8 pad_0[0x6C];
    struct Actor actors[14];
    struct Actor *current;
    u8 pad_3BC;
    u8 field_429;
};

extern struct Map D_020209D8;

void func_08083BF4(void)
{
    u8 i;
    if (D_020209D8.field_429 != 0xFF)
    {
        for (i = 0; i < 14; i++)
        {
            if (D_020209D8.actors[i].flags & 1)
            {
                if (D_020209D8.actors[i].field_3 == 0 || D_020209D8.actors[i].id == D_020209D8.field_429)
                    D_020209D8.actors[i].flags &= ~2;
            }
        }
        D_020209D8.field_429 = 0xFF;
    }
}
