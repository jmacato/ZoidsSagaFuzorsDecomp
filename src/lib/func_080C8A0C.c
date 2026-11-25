#include "types.h"

#define REG_WAITCNT (*(vu16 *)0x04000204)

void func_080C8A0C(const u8 *src, u8 *dest, u32 size)
{
    REG_WAITCNT = (REG_WAITCNT & ~3) | 3;
    while (--size != -1)
        *dest++ = *src++;
}
