#include "m2c.h"

extern struct { u8 pad_0[0x4]; s16 f_4; u8 pad_6[0x2]; s32 f_8; s32 f_C; u8 pad_10[0x11]; s8 f_21; } D_02020E4C;

void func_08088D98(s16 arg0, s32 arg1, s32 arg2, s8 arg3)
{
    D_02020E4C.f_4 = arg0;
    D_02020E4C.f_8 = arg1;
    D_02020E4C.f_C = arg2;
    D_02020E4C.f_21 = arg3;
}
