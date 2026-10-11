#include "types.h"

struct Save
{
    u8 pad_0[0x7A50];
    u32 flags[1];
};

extern struct Save D_02020E4C;
void func_08083C5C(u8, s32, s32);

s32 func_080849F4(u8 id, u8 **pc)
{
    struct Save *save = &D_02020E4C;
    u8 n = (*pc)[1];
    if (save->flags[n >> 5] & (1 << (n & 0x1F)))
        func_08083C5C(id, 0xF, 0);
    else
        func_08083C5C(id, 0x10, 0);
    return 0;
}
