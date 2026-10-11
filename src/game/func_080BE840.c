#include "types.h"

struct EnemyPart
{
    u16 a;
    u16 b;
};

struct Enemy
{
    u8 id;
    u8 level;
    u8 pilot;
    u8 pilot_level;
    u8 boss;
    u8 pad5[3];
    u16 mods[4];
    struct EnemyPart parts[4];
    u32 rate;
    u8 items[4];
    u8 pad28[8];
};

struct Wave
{
    u8 pad0[4];
    struct Enemy enemies[6];
};

struct Slot
{
    u16 field_0;
    u16 item;
};

struct Item
{
    u8 id;
    u8 field_1;
    u8 owner;
    u8 field_3;
    u16 flags;
    s16 field_6;
    s16 field_8;
    s16 mods[4];
    s16 a[5][4];
    s16 b[5][4];
    s16 stats[7];
    u32 rate;
    struct Slot slots[8];
};

struct Pilot
{
    u8 field_0;
    u8 pad1[0x3F];
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

struct Rec
{
    u8 field_0;
    u8 owner;
    u8 field_2;
    s8 members[4];
    u8 field_7;
};

struct Data
{
    u8 pad0[0x258];
    struct Group groups[2];
    struct Item items[2][11];
    struct Pilot cells[2][7];
    u8 pad2100[0x4DDC - 0x2100];
    struct Rec recs[12];
    u8 count;
};

extern struct Data D_02031A0C;
extern struct Wave D_0875A0C4[][15];

void func_080BE58C(u8);
void func_080BD488(u8, u8, struct Item *);
u8 func_080BD368(u8);
void func_080BF608(u8, u8, struct Pilot *);
void func_080BE46C(u8, u8);
u32 func_0809A99C(u8, u8);
void func_080BEB6C(u8, u8);
struct Item *func_0809A908(u8, u8);
void func_080BEE40(u8, u8);
void func_0809B720(u8, u8);

void func_080BE840(u8 stage, u8 wave)
{
    u8 i, j, k, m, row;
    struct Enemy *e;
    struct Item *item;
    struct Pilot *pilot;
    struct Unit *unit;

    func_080BE58C(1);
    for (i = 0; i < 6; i++)
    {
        e = &D_0875A0C4[stage][wave].enemies[i];
        if (e->id == 0)
            continue;
        item = &D_02031A0C.items[1][i];
        func_080BD488(e->id, e->level, item);
        for (j = 0; j < 4; j++)
            item->slots[j].item = e->items[j];
        item->mods[0] = e->mods[0];
        item->mods[1] = e->mods[1];
        item->mods[2] = e->mods[2];
        item->mods[3] = e->mods[3];
        row = func_080BD368(e->id);
        for (j = 0; j < 4; j++)
        {
            item->a[row][j] = e->parts[j].a;
            item->b[row][j] = e->parts[j].b;
        }
        item->rate = e->rate;
        if (e->boss)
            item->flags |= 0x10;
        pilot = &D_02031A0C.cells[1][i];
        if (e->pilot != 0xFF)
            func_080BF608(e->pilot, e->pilot_level, pilot);
        else
        {
            func_080BF608(0, 1, pilot);
            pilot->field_0 |= 0xFF;
        }
        unit = &D_02031A0C.groups[1].units[i];
        unit->id = i;
        unit->list[0] = item->owner = i;
        unit->list[3] |= 0xFF;
        unit->list[2] |= 0xFF;
        unit->list[1] |= 0xFF;
        func_080BE46C(1, i);
        item->field_6 = item->stats[0];
        item->field_8 = item->stats[1] / 2;
    }
    for (i = 0; i < 6; i++)
    {
        if (!func_0809A99C(1, i))
            continue;
        func_080BEB6C(1, i);
        for (k = 0; k < D_02031A0C.count; k++)
        {
            for (m = 0; m < 4 && D_02031A0C.recs[k].members[m] != -1; m++)
            {
                if (!(func_0809A908(1, D_02031A0C.recs[k].members[m])->flags & 0x10))
                    break;
            }
            if (m == 4 || D_02031A0C.recs[k].members[m] == -1)
            {
                func_080BEE40(1, k);
                func_0809A908(1, D_02031A0C.recs[k].owner)->flags |= 0x10;
                break;
            }
        }
    }
    D_02031A0C.groups[1].units[6].id = 0xFF;
    D_02031A0C.groups[1].units[6].list[2] = D_02031A0C.groups[1].units[6].list[3] = -1;
    D_02031A0C.groups[1].units[6].list[0] = D_02031A0C.groups[1].units[6].list[1] = -1;
    func_0809B720(1, 6);
}
