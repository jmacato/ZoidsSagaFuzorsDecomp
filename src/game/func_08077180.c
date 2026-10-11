#include "types.h"

s32 func_08076FE0(u32, u16, u16, s32, s32, u16, u16, u32, u32);

s32 func_08077180(u32 a0, u16 a1, u16 a2, s16 x, s16 y, u16 a5, u16 a6, u32 a7, u32 a8)
{
    return func_08076FE0(a0, a1, a2, x << 8, y << 8, a5, a6, a7, a8);
}
