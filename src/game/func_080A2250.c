#include "types.h"

struct State
{
    u8 pad_0[0x8C6];
    u8 field_8C6;
};

extern struct State D_02036E7C;

s32 func_080A2250(void)
{
    u8 v = D_02036E7C.field_8C6;
    s32 r;
    if (v != 0)
    {
        r = 0;
        if (v == 2)
            r = 1;
    }
    else
        r = 2;
    return r;
}
