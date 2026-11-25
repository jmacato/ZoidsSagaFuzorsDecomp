#include "m2c.h"

extern struct { u8 pad_0[0x3]; u8 f_3; } D_02037C8C;

u8 func_080A00FC(void)
{
    return D_02037C8C.f_3;
}
