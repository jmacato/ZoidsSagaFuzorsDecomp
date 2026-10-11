#include "types.h"

struct CpuSetArgs
{
    const void *src;
    void *dst;
    s32 size;
};

void func_080C8B7C(const void *, void *, u32);

void func_08075964(struct CpuSetArgs *a)
{
    func_080C8B7C(a->src, a->dst, (a->size / 2) & 0x1FFFFF);
}
