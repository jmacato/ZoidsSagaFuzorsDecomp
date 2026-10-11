#include "types.h"

extern u32 D_0200C5A4[];

void func_0807AA34(u16 id)
{
    D_0200C5A4[id >> 5] |= 1 << (id & 0x1F);
}
