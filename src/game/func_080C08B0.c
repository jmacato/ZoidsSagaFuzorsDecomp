#include "types.h"

s32 func_080C8BE8(s32, s32);
s16 func_08075AAC(s16);

s32 func_080C08B0(s32 a, s32 b)
{
    s32 v = func_08075AAC(func_080C8BE8(b << 7, a * 20)) * b;
    return a - func_080C8BE8(b + v / 1024, 20);
}
