#include "m2c.h"

M2C_UNK func_0807970C();
M2C_UNK func_08083C5C(u8, s32, s32);
M2C_UNK func_080C8FCC(s32);

s32 func_080852E4(u8 arg0)
{
    u16 temp_r8;
    u16 temp_sb;

    *(s8 *)0x0201F6DC = 1;
    func_0807970C();
    temp_sb = *(u16 *)0x03000056;
    temp_r8 = *(u16 *)0x0300005A;
    *(u16 *)0x03000056 = 0xBF;
    *(u16 *)0x0300005A = 0x10;
    func_080C8FCC(2);
    *(u16 *)0x03000056 = temp_sb;
    *(u16 *)0x0300005A = temp_r8;
    func_080C8FCC(2);
    func_08083C5C(arg0, -1, 0);
    return 0;
}
