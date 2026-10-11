#include "types.h"

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

struct Unit
{
    u8 pad0[8];
    s16 field_8;
};

struct Entry
{
    u8 active;
    u8 sub[3];
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
    u8 pad[0x4F84 - 0x4E82];
    struct Entry entries[1];
};

extern struct Data D_02031A0C;

struct Unit *func_0809A908(u8, u8);
void func_080BE0A0(struct Unit *, s16);

void func_080C2508(void)
{
    u8 i;
    u8 j;
    struct Unit *unit;
    if (D_02031A0C.entries[D_02031A0C.index].active != 0)
        return;
    switch (D_02031A0C.types[D_02031A0C.index])
    {
    case 0x26:
        if (D_02031A0C.mode == 1 && D_02031A0C.obj->slots[D_02031A0C.entries[D_02031A0C.index].sub[0] & 7].item == D_02031A0C.bonus[D_02031A0C.index][4])
        {
            D_02031A0C.types[D_02031A0C.index] = 0;
            for (i = 1; i < 6; i += 2)
            {
                unit = func_0809A908(D_02031A0C.index, i);
                func_080BE0A0(unit, -unit->field_8);
            }
        }
        break;
    case 0x27:
        if (D_02031A0C.mode == 4 && D_02031A0C.obj->slots[D_02031A0C.entries[D_02031A0C.index].sub[0] & 7].item == D_02031A0C.bonus[D_02031A0C.index][6])
        {
            D_02031A0C.types[D_02031A0C.index] = 0;
            for (i = 0; i < 6; i += 2)
            {
                unit = func_0809A908(D_02031A0C.index, i);
                func_080BE0A0(unit, -unit->field_8);
            }
        }
        break;
    case 0x28:
        if (D_02031A0C.mode == 1)
        {
            for (j = 0; j < 3 && D_02031A0C.entries[D_02031A0C.index].sub[j] != 0xFF; j++)
            {
                if (D_02031A0C.obj->slots[D_02031A0C.entries[D_02031A0C.index].sub[j] & 7].item == 0x51)
                {
                    D_02031A0C.types[D_02031A0C.index] = 0;
                    break;
                }
            }
        }
        break;
    }
}
