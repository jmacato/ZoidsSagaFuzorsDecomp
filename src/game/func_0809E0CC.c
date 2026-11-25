#include "types.h"

struct Zoid
{
    u8 pad_0[6];
    s16 hp;
    u8 pad_8[0x5A];
    s16 maxHp;
};

struct Part
{
    u8 type;
};

struct Flags
{
    u8 mode;
    u8 pad_1[0xC];
    u8 rule;
};

extern struct Flags D_02020E3C;

s32 func_0809A99C(u8 side, u8 slot);
struct Zoid *func_0809A908(u8 side, u8 slot);
struct Part *func_0809A954(u8 side, u8 slot, u8 k);

s32 func_0809E0CC(void)
{
    u8 i, j;
    struct Zoid *zoid;
    for (i = 0; i < 6 && !func_0809A99C(0, i); i++)
        ;
    if (D_02020E3C.mode != 2 && i == 6)
        return 2;
    for (j = 0; j < 6; j++)
    {
        if (D_02020E3C.rule == 1)
        {
            zoid = func_0809A908(1, j);
            if (func_0809A954(1, j, 0)->type == 0x19 && zoid->hp < zoid->maxHp / 4)
                continue;
        }
        else if (D_02020E3C.rule == 2)
        {
            zoid = func_0809A908(1, j);
            if (func_0809A954(1, j, 0)->type == 6 && zoid->hp < zoid->maxHp / 4)
                continue;
        }
        else if (D_02020E3C.rule == 3)
        {
            zoid = func_0809A908(1, j);
            if ((u8)(func_0809A954(1, j, 0)->type - 0x20) <= 1 && zoid->hp < zoid->maxHp / 4)
                continue;
        }
        if (func_0809A99C(1, j))
            break;
    }
    if (j == 6)
    {
        if (i == 6)
            return 3;
        return 1;
    }
    if (i == 6)
        return 2;
    return 0;
}
