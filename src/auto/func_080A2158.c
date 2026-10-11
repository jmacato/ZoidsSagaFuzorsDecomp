#include "m2c.h"

extern struct { u8 pad_0[0x8C6]; s8 f_8C6; u8 pad_8C7[0x1]; s16 f_8C8; } D_02036E7C;

void func_080A2158(void)
{
    D_02036E7C.f_8C6 = 3;
    D_02036E7C.f_8C8 = 0x40;
}
