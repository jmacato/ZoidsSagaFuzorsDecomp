#include "types.h"

s16 func_080C8B80(s32, s32);

s16 func_08075B20(u16 a, s16 b)
{
    s32 result;

    if (b != 0)
        result = func_080C8B80((s16)a << 8, b);
    else
        result = 0x7FFF;
    return result;
}
