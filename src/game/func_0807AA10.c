#include "types.h"

extern u32 D_0200C524[];

void func_0807AA10(u16 id)
{
    D_0200C524[id >> 5] |= 1 << (id & 0x1F);
}
