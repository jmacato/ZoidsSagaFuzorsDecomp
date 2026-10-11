#include "types.h"

struct Actor
{
    u8 flags;
    u8 pad_1[0xB];
    s32 field_C;
    s32 field_10;
    u8 field_14;
    u8 pad_15;
    u8 field_16;
    u8 pad_17[0xD];
    s32 field_24;
};

struct Map
{
    u8 pad_0[0x424];
    struct Actor *current;
};

extern struct Map D_020209D8;
extern u32 (*D_03000010)(void);

void func_08081410(struct Actor *a)
{
    s32 v;
    if ((a->flags & 2) || D_020209D8.current == 0)
        goto clear;
    if (a->field_14 == 0)
    {
        if ((D_03000010() >> 8) != 0)
            return;
        a->field_16 = (D_03000010() >> 13) * 2;
        a->field_14 = 2;
        v = (D_03000010() >> 8) + 0x40;
    }
    else if ((a->field_C == 0 && a->field_10 == 0) || a->field_24 == 0)
    {
    clear:
        a->field_14 = 0;
        return;
    }
    else
        v = a->field_24 - 1;
    a->field_24 = v;
}
