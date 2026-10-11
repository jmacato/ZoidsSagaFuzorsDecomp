#include "m2c.h"

M2C_UNK func_08077E6C(u8 *);
s32 func_080A3770(u8 *, s32, s32, s16, s32, s32, s32, s32, s32);
M2C_UNK func_080A38B0(s32);
s32 func_080C8BAC(s32);

void func_080AD260(u8 *arg0)
{
    s32 temp_r6;

    temp_r6 = M2C_FIELD(arg0, s32 *, 0x8C);
    if (temp_r6 == 0)
    {
        M2C_FIELD(arg0, s32 *, 0xC) = func_080A3770(arg0, 0, 0, (s16) (M2C_FIELD(arg0, s32 *, 4) + ((u32) (func_080C8BAC(*(s32 *)0x03000010) * 0x41) >> 0xF)), temp_r6, 0x120, 0x4A, 0xC00, 1);
        func_080A38B0(0);
        M2C_FIELD(arg0, s32 *, 0x8C) = (s32) (M2C_FIELD(arg0, s32 *, 0x8C) + 1);
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0xC) == 0)
    {
        func_08077E6C(arg0);
    }
}
