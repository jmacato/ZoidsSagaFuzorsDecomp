#include "types.h"

struct Unit
{
    u8 id;
    u8 list[4];
    u8 pad[0x103];
};

struct Group
{
    struct Unit units[7];
};

struct Data
{
    u8 pad0[0x258];
    struct Group groups[2];
};

extern struct Data D_02031A0C;

u32 func_0809A99C(u8, u8);

u8 func_080C3E58(u8 g, u8 sel, u8 rnd)
{
    u8 buf[8];
    u8 i, j;
    u8 n = 0;
    u8 start = 0;
    if (sel != 0xFF)
        start = sel;
    for (i = start; i < (sel != 0xFF ? sel + 1 : 6); i++)
    {
        if (func_0809A99C(g, i))
        {
            struct Unit *unit = &D_02031A0C.groups[g].units[i];
            j = 0;
            if (unit->list[0] != 0xFF)
            {
                while (1)
                {
                    buf[n] = unit->list[j];
                    n++;
                    j++;
                    if (j >= 4 || unit->list[j] == 0xFF)
                        break;
                }
            }
        }
    }
    return buf[(rnd * n) >> 8];
}
