#include "types.h"

void func_08075C64(u16 val, u16 *dst, s32 count)
{
    while (--count != -1)
        *dst++ = val;
}
