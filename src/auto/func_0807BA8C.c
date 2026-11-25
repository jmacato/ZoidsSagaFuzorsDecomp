#include "m2c.h"

M2C_UNK func_0807A0C8(u8);
M2C_UNK func_0807B048(u8 *, s32);
M2C_UNK func_0807B830(M2C_UNK, u8, u8, s32);

void func_0807BA8C(M2C_UNK arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4)
{
    u8 temp_r4;
    u8 *temp_r0;

    temp_r4 = (u8) arg4;
    func_0807B830(arg0, arg1, arg3, 0x0201F5D6);
    temp_r0 = (temp_r4 * 0x4D0) + 0x02009480;
    M2C_FIELD(temp_r0, u8 *, 0x12) = arg2;
    func_0807B048(temp_r0, 0x0201F5D6);
    func_0807A0C8(temp_r4);
}
