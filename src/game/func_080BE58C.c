#include "types.h"

struct Item
{
    u8 field_0;
    u8 pad1[3];
    u16 field_4;
    u8 pad6[0x8E];
};

struct Unit
{
    u8 id;
    u8 pad[0x107];
};

struct Group
{
    struct Unit units[7];
};

struct Cell
{
    u8 field_0;
    u8 pad1[0x3F];
};

struct Data
{
    u8 pad0[0x258];
    struct Group groups[2];
    struct Item items[2][11];
    struct Cell cells[2][7];
};

extern struct Data D_02031A0C;

void func_0809B720(u8, u8);

void func_080BE58C(u8 g)
{
    u8 i;
    for (i = 0; i < 11; i++)
    {
        D_02031A0C.items[g][i].field_0 = 0;
        D_02031A0C.items[g][i].field_4 = 0;
    }
    for (i = 0; i < 6; i++)
    {
        D_02031A0C.cells[g][i].field_0 = 0;
        D_02031A0C.groups[g].units[i].id = 0xFF;
        func_0809B720(g, i);
    }
}
