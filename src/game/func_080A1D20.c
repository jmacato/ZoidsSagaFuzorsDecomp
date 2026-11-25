#include "types.h"

struct State
{
    u8 pad_0[0x8C4];
    u8 field_8C4;
};

extern struct State D_02036E7C;

s32 func_080A1D20(void)
{
    s32 r = 0;
    if ((u8)(D_02036E7C.field_8C4 - 1) > 0x1F)
        r = 1;
    return r;
}
