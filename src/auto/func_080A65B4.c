#include "m2c.h"

M2C_UNK func_08077E6C(u8 *);
s32 func_080A34A8(u8 *, s32, s32, s16, s32, s32, s32, s32);
M2C_UNK func_080A38B0(s32);

void func_080A65B4(u8 *arg0)
{
    s32 temp_r1;

    temp_r1 = M2C_FIELD(arg0, s32 *, 0x8C);
    if (temp_r1 == 0)
    {
        M2C_FIELD(arg0, s32 *, 0xC) = func_080A34A8(arg0, 0, 0, M2C_FIELD(arg0, s16 *, 4), (s32) M2C_FIELD(arg0, s16 *, 8), temp_r1, temp_r1, 1);
        func_080A38B0(0);
        M2C_FIELD(arg0, s32 *, 0x8C) = (s32) (M2C_FIELD(arg0, s32 *, 0x8C) + 1);
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0xC) == 0)
    {
        func_08077E6C(arg0);
    }
}
