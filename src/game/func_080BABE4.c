#include "types.h"

struct State
{
    u8 id;
    u8 field_1;
    u8 field_2;
};

struct UnitDef
{
    u8 id;
    u8 level;
    u8 pilot;
    u8 pilot_level;
    u16 mods[4];
    u32 rate;
    u8 items[4];
};

struct Reward
{
    struct UnitDef units[2][6];
    u8 list1[10];
    u8 list2[10];
    u8 pad104[0x10];
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
    u8 pad1[7];
    u8 skills[5][2];
    u8 pad12[0x2E];
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

struct Data
{
    u8 pad0[0x258];
    struct Group groups[2];
    struct Item items[2][11];
    struct Pilot cells[2][7];
    u8 pad2100[0x4E5B - 0x2100];
    u8 list1[10];
    u8 pad4E65[0x4E92 - 0x4E65];
    u8 list2[10];
    u8 pad4E9C[0x4FF8 - 0x4E9C];
    char name1[0x12];
    char name2[0x12];
    char names1[11][0x2E];
    char names2[11][0x2E];
};

struct Save
{
    u8 pad0[0x20];
    u8 field_20;
};

struct Game
{
    u8 field_0;
    u8 field_1;
    u8 pad2[2];
    u32 field_4;
    u8 pad8[4];
    u8 field_C;
    u8 field_D;
    u8 field_E;
};

extern struct State D_02030ACC;
extern struct Reward D_087A0DF8[][5];
extern struct Data D_02031A0C;
extern struct Pilot D_0203378C[][7];
extern struct Save D_02020E4C;
extern struct Game D_02020E3C;
extern char D_02030586[];
extern char D_02030598[11][0x2E];
extern u8 D_02033C1A[9][3];

void func_080BE58C(u8);
void func_080BD488(u8, u8, struct Item *);
void func_080BF608(u8, u8, struct Pilot *);
void func_080BE46C(u8, u8);
void func_0809B720(u8, u8);
char *func_080C8F78(char *, const char *);

void func_080BABE4(void)
{
    struct Reward *rec = &D_087A0DF8[D_02030ACC.id][D_02030ACC.field_2];
    struct UnitDef *e;
    struct Item *item;
    struct Pilot *pilot;
    struct Unit *unit;
    u8 g, i, j, k;

    for (g = 0; g < 2; g++)
    {
        func_080BE58C(g);
        for (i = 0; i < 6; i++)
        {
            e = &rec->units[g][i];
            if (e->id == 0)
                continue;
            item = &D_02031A0C.items[g][i];
            func_080BD488(e->id, e->level, item);
            item->flags |= 1;
            for (k = 0; k < 4; k++)
                item->slots[k].item = e->items[k];
            item->mods[0] = e->mods[0];
            item->mods[1] = e->mods[1];
            item->mods[2] = e->mods[2];
            item->mods[3] = e->mods[3];
            item->rate = e->rate;
            pilot = &D_0203378C[g][i];
            if (e->pilot != 0xFF)
                func_080BF608(e->pilot, e->pilot_level, pilot);
            else
            {
                func_080BF608(0, 1, pilot);
                pilot->field_0 |= 0xFF;
            }
            for (j = 0; j < 5; j++)
                pilot->skills[j][0] = 0;
            unit = &D_02031A0C.groups[g].units[i];
            unit->id = i;
            unit->list[0] = item->owner = i;
            unit->list[3] |= 0xFF;
            unit->list[2] |= 0xFF;
            unit->list[1] |= 0xFF;
            func_080BE46C(g, i);
            item->field_6 = item->stats[0];
            item->field_8 = item->stats[1] / 2;
        }
    }
    D_02031A0C.groups[0].units[6].id = 0xFF;
    D_02031A0C.groups[0].units[6].list[2] = D_02031A0C.groups[0].units[6].list[3] = -1;
    D_02031A0C.groups[0].units[6].list[0] = D_02031A0C.groups[0].units[6].list[1] = -1;
    func_0809B720(0, 6);
    func_080BD488(D_02020E4C.field_20 == 0x88 ? 0x94 : 0x95, D_02020E4C.field_20 == 0x88 ? 1 : 0, &D_02031A0C.items[0][9]);
    func_080BD488(0x96, 0, &D_02031A0C.items[0][10]);
    func_080BF608(0, 1, &D_02031A0C.cells[0][6]);
    D_02031A0C.cells[0][6].field_0 = 1;
    func_080C8F78(D_02031A0C.name1, D_02030586);
    func_080C8F78(D_02031A0C.name2, D_02030586);
    for (j = 0; j < 11; j++)
    {
        func_080C8F78(D_02031A0C.names1[j], D_02030598[j]);
        func_080C8F78(D_02031A0C.names2[j], D_02030598[j]);
    }
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 3; j++)
            D_02033C1A[i][j] |= 0xFF;
    }
    for (j = 0; j < 10; j++)
        D_02031A0C.list1[j] = rec->list1[j];
    for (j = 0; j < 10; j++)
        D_02031A0C.list2[j] = rec->list2[j];
    D_02020E3C.field_0 = 1;
    D_02020E3C.field_1 = 0x10;
    D_02020E3C.field_4 = 0;
    D_02020E3C.field_C = 0;
    D_02020E3C.field_D = 0;
    D_02020E3C.field_E = 0;
}
