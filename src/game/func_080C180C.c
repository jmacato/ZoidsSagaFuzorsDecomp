#include "types.h"

struct Slot
{
    u8 id;
    u8 count;
    u8 subs[6];
};

struct List
{
    u8 count;
    u8 pad1[3];
    struct Slot slots[1];
};

struct Part
{
    u8 flags;
    u8 pad1[0xF];
    s16 field_10;
    u8 pad12[6];
    u8 active;
    u8 pad19[0x4B];
};

struct Unit
{
    struct Part parts[6];
    u8 pad258[0x18];
};

extern struct List D_02036E24;
extern struct Unit D_02033C38[];

u32 func_08095680(struct Unit *, u8);

void func_080C180C(void)
{
    u8 i, j;
    D_02036E24.count = 0;
    for (i = 0; i < 8; i++)
    {
        struct Unit *unit = &D_02033C38[i];
        struct Slot *slot = &D_02036E24.slots[D_02036E24.count];
        slot->count = 0;
        if ((unit->parts[0].flags & 1) && unit->parts[0].field_10 == 1)
            continue;
        if (func_08095680(unit, i))
            continue;
        for (j = 0; j < 6; j++)
        {
            if (unit->parts[j].active)
            {
                slot->subs[slot->count] = j;
                slot->count++;
            }
        }
        if (slot->count != 0)
        {
            slot->id = i;
            D_02036E24.count++;
        }
    }
}
