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

struct Cell
{
    u8 owner;
    u8 pad1[0x3F];
};

struct Data
{
    u8 pad0[0x258];
    struct Group groups[2];
    u8 items[2][11][0x94];
    struct Cell cells[2][7];
};

extern struct Data D_02031A0C;

u32 func_0809A99C(u8, u8);

u8 func_080C1C68(u8 g, u8 id)
{
    u8 i, j;
    for (i = 0; i < 6; i++)
    {
        if (func_0809A99C(g, i))
        {
            struct Unit *unit = &D_02031A0C.groups[g].units[i];
            for (j = 0; j < 4 && unit->list[j] != 0xFF; j++)
            {
                if (D_02031A0C.cells[g][unit->list[j]].owner == id)
                    return i;
            }
        }
    }
    return 0xFF;
}
