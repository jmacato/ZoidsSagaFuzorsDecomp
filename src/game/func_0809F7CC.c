#include "types.h"

struct Slot
{
    u8 flags;
    u8 pad_1[0x17];
};

extern struct Slot D_02037B6C[][6];

void func_0809F7CC(u8 side, u8 slot)
{
    D_02037B6C[side][slot].flags &= ~0x20;
}
