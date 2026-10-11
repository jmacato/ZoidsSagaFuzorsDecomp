#include "types.h"

struct Unit
{
    u8 active;
    u8 field_1;
    u8 owner;
    u8 field_3;
    u16 flags;
    u16 field_6;
    u8 pad8[0x8C];
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

void func_080BF888(u8, u8);
void func_080BDDE4(struct Unit *unit, struct Pilot *pilot, u8 b);

void func_080BF814(u8 id, u8 index)
{
    struct Pilot *pilot = &D_02020E4C.pilots[id];
    struct Unit *unit = &D_02020E4C.units[index];
    u16 save = unit->field_6;
    func_080BF888(id, 1);
    func_080BF888(unit->owner, 0);
    unit->owner = id;
    pilot->unit = index;
    unit->field_6 = save;
    func_080BDDE4(unit, pilot, 0);
    if (unit->flags & 1)
        pilot->flags |= 1;
}
