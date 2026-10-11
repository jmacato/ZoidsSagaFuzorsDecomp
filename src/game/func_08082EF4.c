#include "types.h"

struct Save
{
    u8 pad_0[0x7AE0];
    u32 flags[1];
};

extern struct Save D_02020E4C;

void func_08082EF4(u8 id)
{
    D_02020E4C.flags[id >> 5] |= 1 << (id & 0x1F);
}
