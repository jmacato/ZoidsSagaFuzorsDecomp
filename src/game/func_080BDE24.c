#include "types.h"

struct Unit
{
    u8 active;
    u8 field_1;
    u8 owner;
    u8 field_3;
    u16 flags;
    u8 pad6[0x8E];
};

struct Pilot
{
    u8 field_0;
    u8 field_1;
    u8 level;
    u8 flags;
    u8 pad4[0x3C];
};

struct Data
{
    u8 pad0[0x3C];
    struct Unit units[0xBA];
    struct Pilot pilots[0x3A];
    u8 pad7A44[0x26];
    u8 slots[6];
};

extern struct Data D_02020E4C;

void func_080BDEB0(u8);

void func_080BDE24(u8 index, u8 slot)
{
    struct Unit *unit = &D_02020E4C.units[index];
    u8 i;
    func_080BDEB0(slot);
    if (unit->flags & 1)
    {
        for (i = 0; i < 6; i++)
        {
            if (D_02020E4C.slots[i] == index)
            {
                func_080BDEB0(i);
                break;
            }
        }
    }
    D_02020E4C.slots[slot] = index;
    unit->flags |= 1;
    if (unit->owner != 0 && unit->owner != 0xFF)
        D_02020E4C.pilots[unit->owner].flags |= 1;
}
