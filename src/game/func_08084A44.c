#include "types.h"

struct Zoid
{
    u8 field_0;
    u8 field_1;
    u8 pilot;
    u8 pad_3[0x91];
};

struct Pilot
{
    u8 id;
    u8 pad_1[0x3F];
};

struct Save
{
    u8 pad_0[0x3C];
    struct Zoid zoids[186];
    struct Pilot pilots[58];
    u8 pad_7A44[0x26];
    u8 team[6];
};

extern struct Save D_02020E4C;
void func_08083C5C(u8, s32, s32);

s32 func_08084A44(u8 id, u8 **pc)
{
    u32 i;
    for (i = 0; i < 6; i++)
    {
        if (D_02020E4C.team[i] != 0 && D_02020E4C.zoids[D_02020E4C.team[i]].pilot != 0xFF
            && D_02020E4C.pilots[D_02020E4C.zoids[D_02020E4C.team[i]].pilot].id == (*pc)[1])
            break;
    }
    if (i < 6)
        func_08083C5C(id, 0xF, 0);
    else
        func_08083C5C(id, 0x10, 0);
    return 0;
}
