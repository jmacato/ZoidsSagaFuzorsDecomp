#include "types.h"

struct Save
{
    u8 pad0[0x7A50];
    u32 flags[4];
    u8 team[10];
};

extern struct Save D_02020E4C;
extern u8 D_020288AC[];

u32 func_0807F26C(u8 id, u8 slot)
{
    u8 i;

    if (id == 0 || (D_02020E4C.flags[id >> 5] & (1 << (id & 0x1F))))
    {
        for (i = 0; i < 10; i++)
        {
            if (D_020288AC[i] == id)
                D_020288AC[i] = 0;
        }
        D_02020E4C.team[slot] = id;
        return 1;
    }
    return 0;
}
