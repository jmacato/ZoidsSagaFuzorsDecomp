#include "types.h"

struct Item
{
    u8 field_0;
    u8 pad1[5];
    s16 field_6;
    s16 field_8;
    u8 padA[0x58];
    s16 stats[7];
    u8 pad70[0x24];
};

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

struct Link
{
    u8 g;
    u8 u;
    u8 pad[6];
};

struct Data
{
    u8 pad0[2];
    u8 count;
    u8 pad3;
    struct Link links[1];
    u8 pad[0x258 - 0xC];
    struct Group groups[2];
    struct Item items[2][11];
    u8 pad1D80[0x4E3D - 0x1D80];
    u8 parts[2][9];
    u8 owner[2][6];
};

extern struct Data D_02031A0C;

u8 func_0809B834(u8, u8, u8, u8);
void func_0809ACCC(u8, u8, u8);
void func_0809B720(u8, u8);
void func_0809B26C(u8, u8, u8, u8, u8, u8, u8, u8, u8);
void func_080BE46C(u8, u8);
void func_0809AC04(u8, u8, u8, s16);
void func_0809D6A8(u8, u8);

void func_080BF170(u8 g, u8 u)
{
    struct Unit *unit = &D_02031A0C.groups[g].units[u];
    struct Item *item = &D_02031A0C.items[g][unit->id];
    u8 flag = func_0809B834(g, u, 0x28, 0) != 0xFF;
    struct Item *it;
    u8 i, s;

    item->field_0 = 0;
    unit->id = 0xFF;
    for (i = 0; i < D_02031A0C.count; i++)
    {
        if (D_02031A0C.links[i].g == g && D_02031A0C.links[i].u == u)
            func_0809ACCC(g, u, 0xFF);
    }
    for (i = 1; i < 4 && unit->list[i] != 0xFF; i++)
    {
        D_02031A0C.groups[g].units[D_02031A0C.owner[g][unit->list[i]]].list[0] = unit->list[i];
        D_02031A0C.owner[g][unit->list[i]] |= 0xFF;
        unit->list[i] |= 0xFF;
    }
    for (i = 0; i < 9; i++)
    {
        if ((D_02031A0C.parts[g][i] >> 4) == u)
        {
            s = D_02031A0C.parts[g][i] & 0xF;
            unit = &D_02031A0C.groups[g].units[s];
            it = &D_02031A0C.items[g][i];
            unit->id = i;
            func_0809B720(g, s);
            if (flag)
                func_0809B26C(g, s, 0x28, 0, 1, 0, 0xFF, 0xFF, 0xFF);
            func_080BE46C(g, s);
            if (item->field_6 != 0)
            {
                it->field_6 = it->stats[0] * item->field_6 / item->stats[0];
                if (it->field_6 <= 0)
                    it->field_6 = 1;
                it->field_8 = it->stats[1] * item->field_8 / item->stats[1];
                func_0809AC04(g, s, unit->list[0], it->stats[3]);
            }
            else
            {
                it->field_6 = 0;
                func_0809D6A8(g, s);
            }
            D_02031A0C.parts[g][i] = 0xFF;
        }
    }
}
