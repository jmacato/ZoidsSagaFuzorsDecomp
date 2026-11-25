#include "m2c.h"

extern u8 D_02036E7C[];
extern u8 D_0878C790[];

M2C_UNK func_080A0B60(s32, u32, s32, s32);
M2C_UNK func_080A3380();

void func_080A0F00(u32 arg0)
{
    s16 *var_r4;
    u32 var_r5;

    var_r5 = arg0;
    var_r5 <<= 0x10;
    var_r5 = var_r5 >> 0x10;
    var_r4 = (s16 *)D_02036E7C;
    *(s8 *)(D_02036E7C + 0x90F) = 5;
    func_080A3380();
    var_r4 = (s16 *)(D_02036E7C + 0x90C);
    *(s16 *)(D_02036E7C + 0x90C) = 0x40;
    func_080A0B60((var_r5 * 0x60) + D_0878C790, var_r5, 0, 0);
}
