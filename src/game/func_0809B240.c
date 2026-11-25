#include "types.h"

struct Game
{
    u8 pad_0[0x244];
    u8 field_244;
};

struct Flags
{
    u8 pad_0[0xC];
    u8 field_C;
};

extern struct Game D_02031A0C;
extern struct Flags D_02020E3C;

s32 func_0809B240(void)
{
    s32 r = 0;
    if (D_02031A0C.field_244 == 1 || D_02020E3C.field_C != 0)
        r = 1;
    return r;
}
