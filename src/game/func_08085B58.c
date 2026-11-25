#include "types.h"

struct ZoidInfo
{
    u8 pad_0[2];
    u8 field_2;
    u8 pad_3[0x31];
};

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
    u8 pad_2[0x92];
};

struct Game
{
    u8 pad_0[0x258];
    struct Unit units[2][7];
    struct Zoid zoids[2][11];
};

extern struct ZoidInfo D_0873FCC8[];
struct Cell
{
    u8 flags;
    u8 pad_1[0x17];
};

extern struct Cell D_02037B6C[][6];
extern struct Game D_02031A0C;
void func_0809F530(u8, u8, u8, u8, u8, s32, u8);

s32 func_08085B58(u8 zoid, u8 pilot, u8 side, u8 slot, u8 mode)
{
    switch (mode)
    {
    case 0:
        func_0809F530(zoid, pilot, D_0873FCC8[zoid].field_2, side, slot, 0, 0);
        break;
    case 1:
        if (side == 0)
        {
            func_0809F530(zoid, pilot, D_0873FCC8[zoid].field_2, 0, slot, 0x10000, side);
            D_02037B6C[0][slot].flags |= 4;
        }
        else
        {
            func_0809F530(zoid, pilot, D_0873FCC8[zoid].field_2, 1, slot, -0x10000, 0);
            D_02037B6C[1][slot].flags |= 4;
        }
        break;
    }
    D_02031A0C.units[side][slot].zoid = slot;
    D_02031A0C.zoids[side][slot].field_0 = zoid;
    D_02031A0C.zoids[side][slot].field_1 = pilot;
}
