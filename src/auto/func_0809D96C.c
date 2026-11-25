#include "m2c.h"

extern struct { u8 pad_0[0x4]; s32 f_4; } D_02020E3C;

void func_0809D96C(u8 arg0)
{
    D_02020E3C.f_4 = (s32) (D_02020E3C.f_4 & ~(1 << arg0));
}
