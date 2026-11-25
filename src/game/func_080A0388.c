#include "types.h"

void *func_08077180(const void *data, u16 a, u16 b, s16 x, s16 y, u16 c, u16 d, u32 flags, s32 e);

void *func_080A0388(const void *data, u16 a, u16 b, u16 x, u16 y, u16 c, u16 d, u32 flags, s32 e, u8 flip)
{
    s32 px;
    if (flip)
    {
        s32 sx = (s16)x;
        s32 t;
        if (flags & 0x1000)
        {
            t = 0x100 - sx;
            px = (s16)t;
        }
        else
        {
            t = 0xF0 - sx;
            px = (s16)t;
        }
    }
    else
        px = (s16)x;
    return func_08077180(data, a, b, px, y, c, d, flags, e);
}
