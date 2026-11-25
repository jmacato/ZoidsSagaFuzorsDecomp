#include "m2c.h"

M2C_UNK func_0807806C(M2C_UNK, s32, s32);

void func_080830A0(u8 *arg0)
{
    s32 temp_r1;

    temp_r1 = *(s32 *)0x03000084;
    if (!(1 & temp_r1))
    {
        if (!(temp_r1 & 2))
        {
            func_0807806C(0x0863B0E4, (M2C_FIELD(arg0, u8 *, 0x16) << 5) + 0x05000200, 0x20);
            return;
        }
        func_0807806C(0x0863B104, (M2C_FIELD(arg0, u8 *, 0x16) << 5) + 0x05000200, 0x20);
    }
}
