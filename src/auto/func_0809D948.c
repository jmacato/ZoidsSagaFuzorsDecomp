#include "m2c.h"

extern struct { u8 pad_0[0x4]; s32 f_4; s32 f_8; } D_02020E3C;

void func_0809D948(u8 arg0, s32 arg1)
{
    u8 temp_r0;

    temp_r0 = arg0;
    D_02020E3C.f_4 = (s32) (D_02020E3C.f_4 | (1 << temp_r0));
    if (temp_r0 == 0x14)
    {
        D_02020E3C.f_8 = arg1;
    }
}
