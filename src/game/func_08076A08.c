#include "types.h"

s16 func_08075AAC(s16);
u16 func_080C8B74(s16, s16);
s32 func_080C8B80(s32, s32);
u16 func_080C8B8C(u32);

s32 func_08076A08(const u16 *a, const u16 *b, const u16 *c)
{
    s16 dx1, dy1, dx2, dy2;
    u16 len1, len2;
    u8 ang1, ang2;
    u16 diff;

    dx1 = b[0] - a[0];
    dy1 = a[1] - b[1];
    dx2 = b[0] - c[0];
    dy2 = c[1] - b[1];
    len1 = func_080C8B8C(dx1 * dx1 + dy1 * dy1);
    len2 = func_080C8B8C(dx2 * dx2 + dy2 * dy2);
    ang1 = func_080C8B74(func_080C8B80(dx1 << 14, len1), func_080C8B80(dy1 << 14, len1)) >> 8;
    ang2 = func_080C8B74(func_080C8B80(dx2 << 14, len2), func_080C8B80(dy2 << 14, len2)) >> 8;
    if (ang1 < ang2)
        diff = ang2 - ang1;
    else
        diff = (u16)(ang2 + 256) - ang1;
    return len1 * len2 * func_08075AAC(diff) / 256;
}
