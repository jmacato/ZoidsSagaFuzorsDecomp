#include "m2c.h"

extern struct { u8 pad_0[0x9C]; u8 f_9C; } D_02036E7C;

u8 func_080A0B54(void)
{
    return D_02036E7C.f_9C;
}
