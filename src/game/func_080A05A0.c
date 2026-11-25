#include "types.h"

struct State
{
    u8 pad_0[0x9A];
    u8 field_9A;
    u8 field_9B;
    u8 field_9C;
};

extern struct State D_02036E7C;

void func_080A05A0(void)
{
    D_02036E7C.field_9A = 0xFF;
    D_02036E7C.field_9B = 0;
    D_02036E7C.field_9C = 1;
}
