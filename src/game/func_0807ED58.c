#include "types.h"

struct Zoid
{
    u8 species;
    u8 level;
    u8 pilot;
    u8 pad3;
    u16 flags;
    u16 hp;
    u16 en;
    u8 padA[0x58];
    u16 maxHp;
    u16 maxEn;
    u8 pad66[0x2E];
};

struct Pilot
{
    u8 id;
    u8 pad1[2];
    u8 flags;
    u8 pad4[0x3C];
};

struct Save
{
    u8 pad0[0x3C];
    struct Zoid zoids[186];
    struct Pilot pilots[58];
};

extern struct Save D_02020E4C;

u32 func_0807EC90(u8, u8);
u32 func_0807EE90(u8, u8);
void func_080BF814(u8, u8);

u32 func_0807ED58(u8 species, u8 level, u8 pilot, u8 pilotLevel)
{
    u32 slot = func_0807EC90(species, level);
    u32 p;

    if (pilot == 0xFF)
    {
        D_02020E4C.zoids[slot].pilot = 0xFF;
        D_02020E4C.zoids[slot].flags |= 4;
        return slot;
    }
    p = func_0807EE90(pilot, pilotLevel);
    if (slot != 0 && p != 0)
    {
        func_080BF814(p, slot);
        D_02020E4C.zoids[slot].hp = D_02020E4C.zoids[slot].maxHp;
        D_02020E4C.zoids[slot].en = D_02020E4C.zoids[slot].maxEn;
        D_02020E4C.zoids[slot].flags |= 4;
        D_02020E4C.pilots[p].flags |= 2;
        return slot;
    }
    return 0;
}
