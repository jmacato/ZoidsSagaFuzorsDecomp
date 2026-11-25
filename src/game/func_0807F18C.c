#include "types.h"

extern u32 D_02028888[];

u32 func_080BD3C0(u8);
void func_0807F318(u32);

u32 func_0807F18C(u8 arg)
{
    u32 id = func_080BD3C0(arg);
    u32 *flags = &D_02028888[(u8)(id >> 5)];
    u32 bit = 1 << (id & 0x1F);

    if (*flags & bit)
        return 0;
    *flags |= bit;
    func_0807F318(id);
    return 1;
}
