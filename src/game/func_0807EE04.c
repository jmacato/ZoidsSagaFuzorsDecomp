#include "types.h"

struct Zoid
{
    u8 species;
    u8 level;
    u8 pilot;
    u8 pad3;
    u16 flags;
    u8 pad6[0x8E];
};

struct Pilot
{
    u8 id;
    u8 pad1[0x3F];
};

struct Save
{
    u8 pad0[0x3C];
    struct Zoid zoids[186];
    struct Pilot pilots[58];
    u8 pad7A44[0x26];
    u8 team[6];
};

extern struct Save D_02020E4C;

void func_080BDEB0(u8);
void func_0807EF5C(u8);
void func_080BF888(u8, u8);

u8 func_0807EE04(u8 slot)
{
    u8 i;
    struct Zoid *zoid = &D_02020E4C.zoids[slot];

    if (zoid->flags & 1)
    {
        for (i = 0; i < 6; i++)
        {
            if (D_02020E4C.team[i] == slot)
            {
                func_080BDEB0(i);
                break;
            }
        }
    }
    zoid->species = 0;
    if (zoid->pilot != 0xFF && D_02020E4C.pilots[zoid->pilot].id != 0)
    {
        if (zoid->flags & 4)
        {
            i = D_02020E4C.pilots[zoid->pilot].id;
            func_0807EF5C(zoid->pilot);
            return i;
        }
        func_080BF888(zoid->pilot, 1);
    }
    return 0;
}
