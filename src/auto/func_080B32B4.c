#include "m2c.h"

M2C_UNK func_0807B830(s32, s32, s32, s32);
M2C_UNK func_0807DB94(s32, s32);
M2C_UNK func_080B2B5C(s32, u8 *, s32);
M2C_UNK func_080C8E88(s32, M2C_UNK, s32);

void func_080B32B4(u8 *arg0)
{
    func_080C8E88(0x0203198C, 0x080F516C, 4);
    func_0807B830(M2C_FIELD(arg0, s32 *, 0xA0), 4, 0x14, 0x020319CC);
    func_0807DB94(0x0203198C, 0x020319CC);
    func_080B2B5C(0x0203198C, arg0, 0);
    M2C_FIELD(arg0, s32 *, 0x8C) = 0;
}
