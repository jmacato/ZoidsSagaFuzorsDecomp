#include "types.h"

struct Pilot
{
    u8 id;
    u8 pad1[2];
    u8 flags;
    u8 pad4[0x2A];
    u8 zoid;
    u8 pad2F[0x11];
};

struct Zoid
{
    u8 species;
    u8 pad1[0x93];
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
u8 func_0807EE04(u8);
void func_080BF888(u8, u8);

u8 func_0807EF5C(u8 id)
{
    struct Pilot *pilot = &D_02020E4C.pilots[id];
    u8 i;

    if (pilot->flags & 1)
    {
        for (i = 0; i < 6; i++)
        {
            if (D_02020E4C.team[i] == pilot->zoid)
            {
                func_080BDEB0(i);
                break;
            }
        }
    }
    pilot->id = 0;
    if (D_02020E4C.zoids[pilot->zoid].species != 0)
    {
        if (pilot->flags & 2)
        {
            i = D_02020E4C.zoids[pilot->zoid].species;
            func_0807EE04(pilot->zoid);
            return i;
        }
        func_080BF888(id, 1);
    }
    return 0;
}
