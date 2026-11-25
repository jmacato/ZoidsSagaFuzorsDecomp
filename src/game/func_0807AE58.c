#include "types.h"

void func_0807AD1C(u8, u8, u32);

s32 func_0807AE58(const u8 *str, u8 palette, u32 dst)
{
    while (*str != 0)
    {
        func_0807AD1C(*str, palette, dst);
        dst += 0x20;
        str++;
    }
}
