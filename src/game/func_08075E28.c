#include "types.h"

struct Task
{
    u32 state;
    s32 wait;
    s32 next;
    u8 pad_C[0x40];
};

extern struct Task D_03000BB4[];

void func_08075E28(u8 id)
{
    D_03000BB4[id].wait = -1;
    D_03000BB4[id].next = -1;
}
