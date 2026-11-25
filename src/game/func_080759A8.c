#include "types.h"

struct DmaArgs
{
    const void *src;
    void *dst;
    s32 size;
};

void func_080759A8(struct DmaArgs *a)
{
    vu32 *dma = (vu32 *)0x040000D4;
    dma[0] = (u32)a->src;
    dma[1] = (u32)a->dst;
    dma[2] = (a->size / 2) | 0x80000000;
    dma[2];
}
