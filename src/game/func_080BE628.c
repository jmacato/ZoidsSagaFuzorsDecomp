#include "types.h"

struct Item
{
    u8 field_0;
    u8 field_1;
    u8 owner;
    u8 pad3[5];
    s16 field_8;
    u8 padA[0x58];
    s16 stats[7];
    u8 pad72[0x22];
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

struct Data
{
    u8 pad0[0x258];
    struct Group groups[2];
    struct Item items[2][11];
    struct Pilot cells[2][7];
    u8 pad2100[0x4FF8 - 0x2100];
    char name1[0x12];
    char name2[0x12];
    char names1[11][0x2E];
    char names2[11][0x2E];
};

struct Save
{
    u8 pad0[0x20];
    u8 field_20;
    u8 pad21[0x1B];
    struct Item units[0xBA];
    struct Pilot pilots[0x3A];
    u8 pad7A44[0x26];
    u8 slots[6];
};

extern struct Data D_02031A0C;
extern struct Save D_02020E4C;
extern char D_02030586[];
extern char D_02030598[11][0x2E];
extern u8 D_02033C1A[9][3];
extern u8 D_0202897C[6][3];

void func_080BE58C(u8);
void func_080BF608(u8, u8, struct Pilot *);
void func_080BE46C(u8, u8);
void func_0809B720(u8, u8);
void func_080BD488(u8, u8, struct Item *);
char *func_080C8F78(char *, const char *);

void func_080BE628(void)
{
    u8 i, j;
    struct Item *item;
    struct Pilot *pilot;
    struct Unit *unit;

    func_080BE58C(0);
    for (i = 0; i < 6; i++)
    {
        if (D_02020E4C.slots[i] != 0)
        {
            item = &D_02031A0C.items[0][i];
            *item = D_02020E4C.units[D_02020E4C.slots[i]];
            pilot = &D_02031A0C.cells[0][i];
            if (item->owner != 0xFF)
                *pilot = D_02020E4C.pilots[item->owner];
            else
            {
                func_080BF608(0, 1, pilot);
                pilot->field_0 |= 0xFF;
            }
            unit = &D_02031A0C.groups[0].units[i];
            unit->id = i;
            item->owner = i;
            unit->list[0] = i;
            unit->list[3] |= 0xFF;
            unit->list[2] |= 0xFF;
            unit->list[1] |= 0xFF;
            func_080BE46C(0, i);
            item->field_8 = item->stats[1] / 2;
        }
    }
    D_02031A0C.groups[0].units[6].id = 0xFF;
    D_02031A0C.groups[0].units[6].list[2] = D_02031A0C.groups[0].units[6].list[3] = -1;
    D_02031A0C.groups[0].units[6].list[0] = D_02031A0C.groups[0].units[6].list[1] = -1;
    func_0809B720(0, 6);
    func_080BD488(D_02020E4C.field_20 == 0x88 ? 0x94 : 0x95, D_02020E4C.field_20 == 0x88 ? 1 : 0, &D_02031A0C.items[0][9]);
    func_080BD488(0x96, 0, &D_02031A0C.items[0][10]);
    pilot = &D_02031A0C.cells[0][6];
    func_080BF608(0, 1, pilot);
    pilot->field_0 = 1;
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
        {
            if (i < 6)
                D_02033C1A[i][j] = D_0202897C[i][j];
            else
                D_02033C1A[i][j] |= 0xFF;
        }
    }
}
