#include "m2c.h"

extern u8 D_02009480[];

M2C_UNK func_0807A0C8(u8);
M2C_UNK func_0807B048(u8 *, s32);

void func_0807B748(s32 arg0, s8 arg1, u8 arg2, s16 arg3, s32 arg4)
{
    u8 temp_r4;
    u8 *temp_r0;

    temp_r4 = arg2;
    temp_r0 = (temp_r4 * 0x4D0) + D_02009480;
    M2C_FIELD(temp_r0, s16 *, 0xC) = arg3;
    M2C_FIELD(temp_r0, s16 *, 0xE) = (s16) arg4;
    M2C_FIELD(temp_r0, s8 *, 0x12) = arg1;
    func_0807B048(temp_r0, arg0);
    func_0807A0C8(temp_r4);
}
