#include "types.h"

struct Item
{
    u8 flags;
    u8 pad1[0x17];
};

struct Slot
{
    u16 field_0;
    u16 item;
};

struct Obj
{
    u8 pad0[0x74];
    struct Slot slots[8];
};

struct Data
{
    u8 pad0[0x244];
    u8 index;
    u8 mode;
    u8 pad246[6];
    struct Obj *obj;
    u8 pad250[0x4E6F - 0x250];
    u8 types[3];
    s16 bonus[1][8];
};

extern struct Data D_02031A0C;
extern struct Item D_08741EF4[];

s32 func_080C269C(u8 n, u8 slot, u8 *list)
{
    u8 i;
    if ((D_08741EF4 + D_02031A0C.obj->slots[slot].item)->flags & 1)
        return 0;
    if (D_02031A0C.types[D_02031A0C.index] == 0x26 && D_02031A0C.mode == 1)
    {
        if (n == 0 && D_02031A0C.obj->slots[slot].item == D_02031A0C.bonus[D_02031A0C.index][4])
            return 1;
    }
    else if (D_02031A0C.types[D_02031A0C.index] == 0x27 && D_02031A0C.mode == 4)
    {
        if (n == 0 && D_02031A0C.obj->slots[slot].item == D_02031A0C.bonus[D_02031A0C.index][6])
            return 2;
    }
    else if (D_02031A0C.types[D_02031A0C.index] == 0x28 && D_02031A0C.mode == 1)
    {
        for (i = 0; i < n; i++)
        {
            if (D_02031A0C.obj->slots[list[i] & 0xF].item == 0x51)
                break;
        }
        if (n == i && D_02031A0C.obj->slots[slot].item == 0x51)
            return 3;
    }
    return 0;
}
