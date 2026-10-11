#include "types.h"

struct State
{
    u8 pad_000[0x8F4];
    u8 field_8F4;
};

extern struct State D_02036E7C;

s32 func_080A3338(void)
{
    s32 result = 0;

    if (D_02036E7C.field_8F4 == 0)
        result = 1;
    return result;
}
