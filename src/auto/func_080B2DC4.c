#include "m2c.h"

M2C_UNK func_08075F20(s32);
M2C_UNK func_0807B830(u32, s32, s32, s32);
M2C_UNK func_080B2B5C(s32, u8 *, s32);
s32 func_080B2C38(u8 *, s32, s32, s32, s32, s32, s32, s32);

void func_080B2DC4(u8 *arg0)
{
    u32 var_r0;

    M2C_FIELD(arg0, s32 *, 0xC) = func_080B2C38(arg0, 0, 0, 0, -0x20, 0, 0x200, 0);
    var_r0 = M2C_FIELD(arg0, u32 *, 0xA0);
    if (var_r0 > 0x270FU)
    {
        var_r0 = 0x270F;
    }
    func_0807B830(var_r0, 4, 0x12, 0x0203198C);
    func_080B2B5C(0x0203198C, arg0, 1);
    func_08075F20(0xEC);
    M2C_FIELD(arg0, s32 *, 0x8C) = 0;
}
