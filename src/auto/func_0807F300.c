#include "m2c.h"

extern struct { u8 pad_0[0x7A5C]; s32 f_7A5C; } D_02020E4C;

s32 func_0807F300(s32 arg0)
{
    D_02020E4C.f_7A5C -= arg0;
    return 1;
}
