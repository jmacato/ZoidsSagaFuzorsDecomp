#include "m2c.h"

extern struct { u8 pad_0[0x8CC]; s8 f_8CC; } D_02036E7C;

void func_080A24B4(void)
{
    D_02036E7C.f_8CC = 2;
}
