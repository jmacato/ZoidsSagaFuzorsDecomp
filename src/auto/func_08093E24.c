#include "m2c.h"

M2C_UNK func_0807FF9C(M2C_UNK, s32, s32, s32);
M2C_UNK func_0809BCA4(u8, u8);
M2C_UNK func_0809FCD4(s32, u8, s32, s32);

s32 func_08093E24(u8 arg0, u8 arg1)
{
    u8 temp_r4;

    temp_r4 = arg0;
    func_0807FF9C(0x087B4C9C, 0, 0x360, 0xD);
    func_0809FCD4(2, temp_r4, 0, 0);
    return func_0809BCA4(temp_r4, arg1);
}
