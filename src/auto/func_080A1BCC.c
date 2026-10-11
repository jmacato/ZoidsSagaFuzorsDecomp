#include "m2c.h"

extern struct { u8 pad_0[0x8C4]; s8 f_8C4; } D_02036E7C;

void func_080A1BCC(void)
{
    D_02036E7C.f_8C4 = 1;
}
