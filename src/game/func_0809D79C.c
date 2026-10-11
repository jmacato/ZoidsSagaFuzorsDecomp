#include "types.h"

extern u8 D_02034FB8[];

void func_080C8B7C(const void *src, void *dst, u32 ctrl);

void func_0809D79C(void)
{
    u32 zero = 0;
    func_080C8B7C(&zero, D_02034FB8, 0x0500060C);
}
