#include "m2c.h"

extern u8 D_02036E7C[];
extern u8 D_0878C7D8[];
extern u8 D_0878C7E4[];

M2C_UNK func_080A0B60(s32, u16, s32, u8);
M2C_UNK func_080A3380();

void func_080A0DA4(u16 arg0, u8 arg1)
{
    u16 var_r5;
    u8 *var_r4;
    u8 var_r6;

    var_r5 = arg0;
    var_r6 = arg1;
    var_r4 = (u8 *)D_02036E7C;
    *(s8 *)(D_02036E7C + 0x90F) = 4;
    func_080A3380();
    *(s16 *)(D_02036E7C + 0x90C) = 0x40;
    var_r4 = (u8 *)(D_02036E7C + 0x8F5);
    if (*(u8 *)(D_02036E7C + 0x8F5) != 0xD)
    {
        func_080A0B60((var_r5 * 0x60) + D_0878C7D8, var_r5, 0, var_r6);
        return;
    }
    func_080A0B60((var_r5 * 0x60) + D_0878C7E4, var_r5, 0, var_r6);
}
