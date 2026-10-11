#include "types.h"

struct Item
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 pad3;
    u16 field_4;
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

struct Recipe
{
    u8 id;
    u8 unit;
    u8 field_2;
    s8 parts[4];
    u8 pad7;
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
    u8 pad1D80[0x4DDC - 0x1D80];
    struct Recipe recipes[12];
    u8 pad4E3C;
    u8 parts[2][9];
    u8 owner[2][6];
};

extern struct Data D_02031A0C;
extern u8 D_02020E3C;

void func_0807F444(u8, u32);
void func_0809B720(u8, u8);
void func_080BE46C(u8, u8);
void func_0809B26C(u8, u8, u8, u16, u8, u8, u8, u8, u8);

void func_080BEE40(u8 g, u8 r)
{
    struct Item *item;
    struct Unit *dst;
    struct Unit *src;
    struct Item *it;
    u8 k;
    s16 hp, maxhp, en, maxen;
    u8 n, i, j;

    for (k = 6; k <= 8; k++)
    {
        item = &D_02031A0C.items[g][k];
        if (item->field_0 == 0)
        {
            item->field_0 = D_02031A0C.recipes[r].id;
            if (D_02020E3C == 0 && g == 0)
                func_0807F444(item->field_0, 1);
            break;
        }
    }
    dst = &D_02031A0C.groups[g].units[D_02031A0C.recipes[r].unit];
    maxen = 0;
    en = 0;
    maxhp = 0;
    hp = 0;

    for (i = 0, n = 1; i <= 3 && D_02031A0C.recipes[r].parts[i] != -1; i++)
    {
        src = &D_02031A0C.groups[g].units[D_02031A0C.recipes[r].parts[i]];
        it = &D_02031A0C.items[g][src->id];
        for (j = 0; j < D_02031A0C.count; j++)
        {
            if (D_02031A0C.links[j].g == g && D_02031A0C.links[j].u == D_02031A0C.recipes[r].parts[i])
                D_02031A0C.links[j].u = D_02031A0C.recipes[r].unit;
        }
        if (D_02031A0C.recipes[r].parts[i] == D_02031A0C.recipes[r].unit)
        {
            item->field_1 = it->field_1;
        }
        else
        {
            dst->list[n] = src->list[0];
            D_02031A0C.owner[g][src->list[0]] = D_02031A0C.recipes[r].parts[i];
            src->list[0] = 0xFF;
            n++;
        }
        D_02031A0C.parts[g][src->id] = (D_02031A0C.recipes[r].unit << 4) | (u8)D_02031A0C.recipes[r].parts[i];
        src->id = 0xFF;
        hp += it->field_6;
        maxhp += it->stats[0];
        en += it->field_8;
        maxen += it->stats[1];
    }
    dst->id = k;
    func_0809B720(g, D_02031A0C.recipes[r].unit);
    func_080BE46C(g, D_02031A0C.recipes[r].unit);
    item->field_6 = item->stats[0] * hp / maxhp;
    if (item->field_6 <= 0)
        item->field_6 = 1;
    item->field_8 = item->stats[1] * en / maxen;
    item->field_2 = dst->list[0];
    item->field_4 |= 1;
    func_0809B26C(g, D_02031A0C.recipes[r].unit, 0x2A, 0, D_02031A0C.recipes[r].field_2, 0, 0xFF, 0xFF, 0xFF);
}
