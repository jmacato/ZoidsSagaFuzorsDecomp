#include "types.h"

struct Script
{
    u8 pad_0[0x12AC];
    u32 *objs[16];
};

extern struct Script D_0201F6DC;
void func_08083C5C(u8, s32, s32);

s32 func_08086E38(u8 id, u8 **pc)
{
    u32 *obj = D_0201F6DC.objs[(*pc)[1]];
    if ((*pc)[2] <= 3)
        *obj = (*obj & 0xFFFBFCFF) | ((*pc)[2] << 8);
    else
        *obj = (*obj & 0xFFFFFCFF) | 0x40200;
    func_08083C5C(id, -1, 0);
    return 0;
}
