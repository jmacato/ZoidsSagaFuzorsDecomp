#include "types.h"

struct Data
{
    u8 pad0[0x7B54];
    u32 flags[8];
};

extern struct Data D_02020E4C;

s32 func_080BA970(u8 a, u8 b)
{
    u8 n = b + a * 5;
    D_02020E4C.flags[n >> 5] |= 1 << (n & 0x1F);
}
