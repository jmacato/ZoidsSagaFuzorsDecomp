#include "m2c.h"

s16 func_08075AAC(s32);
s16 func_08075AF8(s16);
u8 *func_080A34A8(M2C_UNK, M2C_UNK, u16, s16, s32, s32, s32, s32);

u8 *func_080A37EC(M2C_UNK arg0, M2C_UNK arg1, u16 arg2, s16 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8)
{
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r4;
    u8 *temp_r0;

    temp_r0 = func_080A34A8(arg0, arg1, arg2, arg3, (s32) (s16) arg4, arg5, 0x080A37A9, arg8);
    if (!(M2C_FIELD(temp_r0, s32 *, 0) & 0x8000))
    {
        var_r4 = arg6 << 0x10;
        var_r0 = arg7 * func_08075AF8((s16) arg6);
    }
    else
    {
        var_r4 = arg6 << 0x10;
        var_r0 = (0 - arg7) * func_08075AF8((s16) arg6);
    }
    if (var_r0 < 0)
    {
        var_r0 += 0xFF;
    }
    M2C_FIELD(temp_r0, s32 *, 0x30) = (s32) (var_r0 >> 8);
    var_r0_2 = arg7 * func_08075AAC(var_r4 >> 0x10);
    if (var_r0_2 < 0)
    {
        var_r0_2 += 0xFF;
    }
    M2C_FIELD(temp_r0, s32 *, 0x34) = (s32) (var_r0_2 >> 8);
    return temp_r0;
}
