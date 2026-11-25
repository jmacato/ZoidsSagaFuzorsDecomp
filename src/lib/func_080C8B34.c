#include "types.h"

extern u32 (*D_030076F4)(const u8 *, u8 *, u32);

void func_080C8A0C(const u8 *, u8 *, u32);

u32 func_080C8B34(const u8 *src, u8 *dest, u32 size)
{
    u8 i;
    u32 errorAddr;

    for (i = 0; i < 3; i++)
    {
        func_080C8A0C(src, dest, size);
        errorAddr = D_030076F4(src, dest, size);
        if (errorAddr == 0)
            break;
    }
    return errorAddr;
}
