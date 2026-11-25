#include "types.h"

struct Slot
{
    u8 id;
    u8 pad1[7];
};

struct List
{
    u8 count;
    u8 pad1[3];
    struct Slot slots[1];
};

struct Unit
{
    u8 flags;
    u8 pad1[0x26F];
};

extern struct List D_02036E24;
extern struct Unit D_02033C38[];

void func_080C18C8(u8, u8);

void func_080C1A18(void)
{
    s16 i;
    for (i = 0; i < D_02036E24.count; i++)
    {
        if (!((D_02033C38 + D_02036E24.slots[i].id)->flags & 1))
        {
            func_080C18C8(i, 0xFF);
            i--;
        }
    }
}
