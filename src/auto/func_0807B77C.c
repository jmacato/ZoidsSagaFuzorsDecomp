#include "m2c.h"

M2C_UNK func_0807A0C8(u8);
M2C_UNK func_0807B048(u8 *, s32);

void func_0807B77C(s32 arg0, s8 arg1, u8 arg2)
{
    u8 temp_r4;
    u8 *temp_r0;

    temp_r4 = arg2;
    temp_r0 = (temp_r4 * 0x4D0) + 0x02009480;
    M2C_FIELD(temp_r0, s8 *, 0x12) = arg1;
    func_0807B048(temp_r0, arg0);
    func_0807A0C8(temp_r4);
}
