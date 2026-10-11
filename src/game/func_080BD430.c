#include "types.h"

struct Item
{
    u8 pad0[8];
    s16 value;
    u8 padA[0xE];
};

struct Slot
{
    u16 field_0;
    u16 item;
};

struct Obj
{
    u8 pad0[0x74];
    struct Slot slots[4];
};

extern struct Item D_08741EF4[];

s16 func_080BD430(struct Obj *obj)
{
    s16 total = 0;
    u8 i;
    for (i = 0; i < 4; i++)
    {
        if (obj->slots[i].item != 0)
        {
            total += D_08741EF4[obj->slots[i].item].value;
            if (total > 9998)
            {
                total = 9999;
                break;
            }
        }
    }
    return total;
}
