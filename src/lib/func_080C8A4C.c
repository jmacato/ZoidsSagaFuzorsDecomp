#include "types.h"

#define REG_WAITCNT (*(vu16 *)0x04000204)

u32 func_080C8A4C(const u8 *src, u8 *dest, u32 size)
{
    REG_WAITCNT = (REG_WAITCNT & ~3) | 3;
    while (--size != -1)
    {
        if (*dest++ != *src++)
            return (u32)(dest - 1);
    }
    return 0;
}
