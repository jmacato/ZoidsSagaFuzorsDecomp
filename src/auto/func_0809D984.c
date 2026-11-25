#include "m2c.h"

extern struct { u8 pad_0[0x4]; s32 f_4; } D_02020E3C;

s32 func_0809D984(u8 arg0)
{
    return D_02020E3C.f_4 & (1 << arg0);
}
