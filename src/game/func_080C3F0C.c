#include "types.h"

struct Item
{
    u8 data[0x94];
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

struct Cell
{
    u8 data[0x40];
};

struct Entry
{
    u8 active;
    s8 field_1;
    s8 field_2;
    u8 field_3;
};

struct Data
{
    u8 pad0[0x244];
    u8 index;
    u8 field_245;
    u8 field_246;
    u8 pad247;
    struct Unit *unit;
    struct Item *item;
    struct Cell *cell;
    u8 pad254[4];
    struct Group groups[2];
    struct Item items[2][11];
    struct Cell cells[2][7];
    u8 pad2100[0x4F84 - 0x2100];
    struct Entry entries[2];
};

extern struct Data D_02031A0C;

void func_0809C650(void);

void func_080C3F0C(u8 g, u8 id, u8 cell, u8 c)
{
    D_02031A0C.field_245 = 6;
    D_02031A0C.field_246 = 0;
    D_02031A0C.unit = &D_02031A0C.groups[g].units[6];
    D_02031A0C.unit->id = id;
    D_02031A0C.unit->list[0] = cell;
    D_02031A0C.unit->list[1] = 0xFF;
    D_02031A0C.item = &D_02031A0C.items[g][D_02031A0C.unit->id];
    D_02031A0C.cell = &D_02031A0C.cells[g][D_02031A0C.unit->list[0]];
    func_0809C650();
    D_02031A0C.entries[g].field_1 = c;
    D_02031A0C.entries[g].field_2 = -1;
}
