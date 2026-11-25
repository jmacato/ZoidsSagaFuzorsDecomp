#include "types.h"

struct Task
{
    u8 id;
    u8 active;
    u8 pad2[2];
    u32 stack;
    u32 next;
    u8 padC[0x40];
};

extern struct Task D_03000BB4[];
extern u8 D_03000E48[][0x380];
extern void (*D_03000E14[])(u32);
extern u32 D_03000E2C[];
extern const u32 D_087345DC[];

void func_08075DB8(u8 id, void (*func)(u32), u32 arg)
{
    if (id != 0)
    {
        D_03000BB4[id].stack = (u32)D_03000E48[id];
        D_03000E14[id - 1] = func;
        D_03000E2C[id - 1] = arg;
    }
    D_03000BB4[id].next = D_087345DC[id];
    D_03000BB4[id].active = 1;
}
