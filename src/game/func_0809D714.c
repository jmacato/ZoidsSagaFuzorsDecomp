#include "types.h"

struct Zoid
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[2];
    u16 flags;
    s16 hp;
};

struct Game
{
    u8 pad_0[0x4F76];
    u8 lostCount;
};

extern struct Game D_02031A0C;

s32 func_0809A99C(u8 side, u8 slot);
struct Zoid *func_0809A908(u8 side, u8 slot);
u8 func_0809B834(u8 side, u8 slot, u8 id, void *out);
void func_0809D6A8(u8 side, u8 slot);
void func_080BF170(u8 side, u8 slot);
void func_0809B62C(u8 side, u8 slot, u8 k);

void func_0809D714(u8 side)
{
    u8 slot, k;
    D_02031A0C.lostCount = 0;
    for (slot = 0; slot < 6; slot++)
    {
        if (func_0809A99C(side, slot) && func_0809A908(side, slot)->hp <= 0)
        {
            if (func_0809B834(side, slot, 0x2A, 0) == 0xFF)
                func_0809D6A8(side, slot);
            else
                func_080BF170(side, slot);
            for (k = 0; k < 8; k++)
                func_0809B62C(side, slot, k);
        }
    }
}
