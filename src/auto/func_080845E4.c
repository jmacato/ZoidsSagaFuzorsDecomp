#include "m2c.h"

M2C_UNK func_0807A1A4();
M2C_UNK func_0807C290(M2C_UNK);
M2C_UNK func_08083C5C(u8, s32, s32);
M2C_UNK func_080C8FCC(s32);

s32 func_080845E4(u8 arg0)
{
    u8 temp_r4;

    temp_r4 = arg0;
    *(s8 *)0x0201F6DC = 1;
    func_0807C290(0x08014B9B);
    func_0807A1A4();
    func_080C8FCC(1);
    if (*(u8 *)0x0200C4A0 == 0)
    {
        func_08083C5C(temp_r4, 0xF, 0);
    }
    else
    {
        func_08083C5C(temp_r4, 0x10, 0);
    }
    return 0;
}
