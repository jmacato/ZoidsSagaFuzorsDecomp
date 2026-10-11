#include "types.h"

struct Item
{
    u8 pad_0[4];
    u16 flags;
    s16 field_6;
};

struct Obj
{
    u8 pad_0[0x8C];
    s32 field_8C;
    s32 field_90;
    s32 field_94;
    s32 field_98;
};

struct Slot
{
    u8 id;
    u8 pad_1;
    s16 field_2;
    u8 pad_4[4];
};

struct Side
{
    struct Slot slots[6];
};

struct Row
{
    u8 pad_0[4];
    struct Side sides[2];
};

struct Table
{
    struct Row rows[6];
    u8 pad_258[0x18];
};

struct Big
{
    u8 pad_0[0x2244];
    struct Table tables[18];
    u8 pad_4E24[0x130];
    struct Obj *objs[6];
};

extern struct Big D_02031A0C;
struct Item *func_0809A908(u8, u8);

void func_08095460(u8 side, u8 row, u8 table)
{
    u8 i;
    struct Slot *slot;
    struct Table *t;
    struct Item *item;

    for (i = 0; i < 6; i++)
    {
        t = &D_02031A0C.tables[table];
        slot = &t->rows[row].sides[side].slots[i];
        if (slot->id != 0)
        {
            if (D_02031A0C.objs[i]->field_94 == 0 && D_02031A0C.objs[i]->field_98 == 0)
            {
                item = func_0809A908(side, i);
                if (!(item->flags & 0x10))
                    D_02031A0C.objs[i]->field_94 = item->field_6;
                else
                    D_02031A0C.objs[i]->field_94 = -1;
                D_02031A0C.objs[i]->field_98 = slot->field_2;
                D_02031A0C.objs[i]->field_8C = D_02031A0C.objs[i]->field_90 = 0;
            }
        }
        else
        {
            D_02031A0C.objs[i]->field_94 = D_02031A0C.objs[i]->field_98 = 0;
        }
    }
}
