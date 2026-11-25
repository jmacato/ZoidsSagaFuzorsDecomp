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
    u8 pad4[0x2A];
    u8 unit;
    u8 pad2F[0x11];
};

struct Data
{
    u8 pad0[0x3C];
    struct Unit units[0xBA];
    struct Pilot pilots[0x3A];
};

extern struct Data D_02020E4C;

void func_080BDDE4(struct Unit *unit, u32 a, u8 b);

void func_080BF888(u8 id, u8 reset)
{
    struct Pilot *pilot = &D_02020E4C.pilots[id];
    if (pilot->unit != 0)
    {
        struct Unit *unit = &D_02020E4C.units[pilot->unit];
        if (unit->owner == id)
        {
            if (unit->flags & 1)
                pilot->flags &= ~1;
            unit->owner = 0;
            pilot->unit = 0;
            if (reset)
                func_080BDDE4(unit, 0, 0);
        }
    }
}
