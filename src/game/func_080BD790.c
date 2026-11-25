#include "types.h"

struct Slot
{
    u16 field_0;
    u16 item;
};

struct Obj
{
    u8 pad0[0x62];
    s16 stats[7];
    u8 pad70[4];
    struct Slot slots[8];
};

struct Item
{
    u8 flags;
    u8 field_1;
    u16 type;
    u8 pad4[8];
    s16 value;
    s16 value2;
    s16 field_10;
    u8 pad12[6];
};

struct Data
{
    u8 pad0[0x4E6F];
    u8 types[2];
};

extern struct Data D_02031A0C;
extern struct Item D_08741EF4[];

s16 func_080BFADC(void *, u8);
s32 func_080BD2F4(s16, s16);

void func_080BD790(struct Obj *obj, void **cells, u8 flag)
{
    s16 v20 = 100;
    s16 v25 = 100;
    s16 v24 = 100;
    u8 i;
    u8 j;
    struct Item *item;

    for (i = 0; i < 4 && cells[i] != 0; i++)
    {
        v24 += func_080BFADC(cells[i], 0x24);
        v25 += func_080BFADC(cells[i], 0x25);
        v20 += func_080BFADC(cells[i], 0x20);
    }
    for (j = 0; j < 8; j++)
    {
        if (flag && j < 4 && (D_02031A0C.types[0] == 0x3A || D_02031A0C.types[1] == 0x3A))
            continue;
        if (obj->slots[j].item == 0)
            continue;
        item = &D_08741EF4[obj->slots[j].item];
        if (!(item->flags & 1))
            continue;
        if (item->field_10 != 1)
            continue;
        if (item->field_1 != 0)
            continue;
        switch (item->type)
        {
        case 1:
            obj->stats[5] += func_080BD2F4(item->value, v20);
            break;
        case 2:
            obj->stats[3] += func_080BD2F4(item->value, v24);
            break;
        case 3:
            obj->stats[4] += func_080BD2F4(item->value, v25);
            break;
        case 4:
            obj->stats[3] += func_080BD2F4(item->value, v24);
            obj->stats[4] += func_080BD2F4(item->value2, v25);
            break;
        case 8:
            obj->stats[2] += item->value;
            break;
        case 10:
            obj->stats[0] += item->value;
            break;
        case 11:
            obj->stats[1] += item->value;
            break;
        case 12:
            obj->stats[0] += item->value;
            obj->stats[1] += item->value2;
            break;
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
            break;
        }
    }
}
