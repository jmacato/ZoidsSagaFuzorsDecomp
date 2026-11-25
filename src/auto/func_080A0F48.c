#include "m2c.h"

extern struct { u8 pad_0[0x90C]; s16 f_90C; u8 pad_90E[0x1]; s8 f_90F; } D_02036E7C;

M2C_UNK func_080A0B60(M2C_UNK, M2C_UNK, u8, s32);
M2C_UNK func_080A3380();

void func_080A0F48(u8 arg0)
{
    D_02036E7C.f_90F = 5;
    func_080A3380();
    D_02036E7C.f_90C = 0x40;
    func_080A0B60(0x0879F930, 0x32F, arg0, 0);
}
