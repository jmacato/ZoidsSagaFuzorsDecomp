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

struct Data
{
    u8 pad0[0x258];
    struct Group groups[2];
    struct Item items[2][11];
    struct Cell cells[2][7];
};

struct Result
{
    u8 pad0[6];
    s16 field_6;
};

extern struct Data D_02031A0C;
extern struct Result D_02031408;

void func_080BD57C(struct Item *);
void func_0809B834(u8, u8, u8, struct Result *);
void func_080BD98C(struct Item *, struct Cell **, s16, u8);
void func_080BD790(struct Item *, struct Cell **, u32);
void func_0809BB30(u8, u8);
void func_080BDC78(struct Item *);
void func_080BDCD8(struct Item *);

void func_080BE46C(u8 g, u8 i)
{
    struct Cell *cells[4];
    struct Unit *unit = &D_02031A0C.groups[g].units[i];
    struct Item *item;
    u8 j;
    if (unit->id != 0xFF)
    {
        item = &D_02031A0C.items[g][unit->id];
        func_080BD57C(item);
        for (j = 0; j < 4 && unit->list[j] != 0xFF; j++)
            cells[j] = &D_02031A0C.cells[g][unit->list[j]];
        if (j < 4)
            cells[j] = 0;
        func_0809B834(g, i, 0x25, &D_02031408);
        func_080BD98C(item, cells, D_02031408.field_6, 1);
        func_080BD790(item, cells, 1);
        func_0809BB30(g, i);
        func_080BDC78(item);
        func_080BDCD8(item);
    }
}
