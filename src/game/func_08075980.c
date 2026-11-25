#include "types.h"

struct FillArgs
{
    u16 value;
    void *dst;
    s32 size;
};

void func_080C8B7C(const void *, void *, u32);

void func_08075980(struct FillArgs *a)
{
    vu16 value = a->value;
    func_080C8B7C((void *)&value, a->dst, ((a->size / 2) & 0x1FFFFF) | 0x01000000);
}
