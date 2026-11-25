#include "m2c.h"

extern struct { u8 pad_0[0x9A]; u8 f_9A; u8 pad_9B[0x85A]; u8 f_8F5; u8 pad_8F6[0x16]; s16 f_90C; u8 pad_90E[0x1]; s8 f_90F; u8 pad_910[0x1]; u8 f_911; } D_02036E7C;

M2C_UNK func_080A05BC(s32);
M2C_UNK func_080A0B60(s32, u16, s32, u8);
M2C_UNK func_080A3380();

void func_080A0D0C(u16 arg0, u8 arg1, u8 arg2)
{
    u16 temp_r5;
    u8 temp_r6;

    temp_r5 = arg0;
    temp_r6 = arg1;
    D_02036E7C.f_90F = 1;
    func_080A3380();
    D_02036E7C.f_90C = 0x40;
    if (D_02036E7C.f_8F5 != 0xD)
    {
        func_080A0B60((temp_r5 * 0x60) + 0x0878C7A8, temp_r5, 0, temp_r6);
    }
    else
    {
        func_080A0B60((temp_r5 * 0x60) + 0x0878C7B4, temp_r5, 0, temp_r6);
    }
    if (D_02036E7C.f_9A != 8)
    {
        func_080A05BC(8);
    }
    D_02036E7C.f_911 = arg2;
}
