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
    u8 flags2;
    u8 pad2[0x26E];
};

extern struct List D_02036E24;
extern struct Unit D_02033C38[];

void func_080C18C8(u8, u8);

void func_080C19AC(void)
{
    s16 i;
    for (i = 0; i < D_02036E24.count; i++)
    {
        struct Unit *unit = D_02033C38 + D_02036E24.slots[i].id;
        if ((unit->flags & 1) || (unit->flags2 & 8))
        {
            func_080C18C8(i, 0xFF);
            i--;
        }
    }
}
