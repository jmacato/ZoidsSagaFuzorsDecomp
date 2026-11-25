#include "types.h"

struct Unk02030504
{
    u8 pad0[0x14];
    u32 flags[8];
};

extern struct Unk02030504 D_02030504;

void func_0807F420(u8 id)
{
    D_02030504.flags[id >> 5] |= 1 << (id & 0x1F);
}
