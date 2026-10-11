#include "types.h"

void func_0807AB18(u16, u8, u32, u32);

s32 func_0807ACB4(const u8 *str, u8 palette, u32 dst)
{
    while (*str != 0)
    {
        func_0807AB18((str[0] << 8) | str[1], palette, dst, dst + 0x20);
        dst += 0x40;
        str += 2;
    }
}
