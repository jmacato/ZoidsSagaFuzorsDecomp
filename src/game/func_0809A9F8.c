#include "types.h"

struct Zoid
{
    u8 type;
    u8 field_1;
};

struct ZoidInfo
{
    u8 pad_0[2];
    u8 field_2;
    u8 pad_3[0x31];
};

extern struct ZoidInfo D_0873FCC8[];

s32 func_0809A99C(u8 side, u8 slot);
struct Zoid *func_0809A908(u8 side, u8 slot);
void func_0809F530(u8 type, u8 a, u8 b, u8 side, u8 slot, s32 c, s32 d);

void func_0809A9F8(u8 side, u8 slot)
{
    struct Zoid *zoid;
    if (func_0809A99C(side, slot))
    {
        zoid = func_0809A908(side, slot);
        func_0809F530(zoid->type, zoid->field_1, D_0873FCC8[zoid->type].field_2, side, slot, 0, 0);
    }
}
