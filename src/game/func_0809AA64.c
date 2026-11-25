#include "types.h"

struct Zoid
{
    u8 pad_0[0x68];
    s16 field_68;
    s16 field_6A;
};

struct Game
{
    u8 field_0;
    u8 winner;
};

extern struct Game D_02031A0C;
extern u8 D_02020E3C;
extern u8 D_030057F4;

s32 func_0809A99C(u8 side, u8 slot);
struct Zoid *func_0809A908(u8 side, u8 slot);

void func_0809AA64(void)
{
    u32 totals[2];
    u8 side, slot;
    for (side = 0; side < 2; side++)
    {
        totals[side] = 0;
        for (slot = 0; slot < 6; slot++)
        {
            if (func_0809A99C(side, slot))
            {
                struct Zoid *zoid = func_0809A908(side, slot);
                totals[side] += zoid->field_68 + zoid->field_6A;
            }
        }
    }
    if (totals[0] > totals[1])
        D_02031A0C.winner = 0;
    else if (totals[0] < totals[1])
        D_02031A0C.winner = 1;
    else if (D_02020E3C == 2 && D_030057F4 != 1)
        D_02031A0C.winner = 1;
    else
        D_02031A0C.winner = 0;
}
