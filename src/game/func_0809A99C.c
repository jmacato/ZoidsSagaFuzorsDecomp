#include "types.h"

struct Unit
{
    u8 zoid;
    u8 parts[7];
    u8 pad_8[0x100];
};

struct Zoid
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[2];
    u16 flags;
    u8 pad_6[0x8E];
};

struct Game
{
    u8 pad_0[0x258];
    struct Unit units[2][7];
    struct Zoid zoids[2][11];
};

extern struct Game D_02031A0C;

s32 func_0809A99C(u8 side, u8 slot)
{
    struct Unit *unit = &D_02031A0C.units[side][slot];
    if (unit->zoid != 0xFF && !(D_02031A0C.zoids[side][unit->zoid].flags & 2))
        return 1;
    return 0;
}
