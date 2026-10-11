#include "types.h"

struct State
{
    u8 pad_0[0x8CC];
    u8 field_8CC;
};

extern struct State D_02036E7C;

s32 func_080A24F0(void)
{
    s32 r = 0;
    if (D_02036E7C.field_8CC == 0)
        r = 1;
    return r;
}
