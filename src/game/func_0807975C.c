#include "types.h"

extern u8 D_03005716;
extern s16 D_030057C4[10];

s16 func_08075AAC(u16);
s16 func_08075AF8(u16);

void func_0807975C(u16 x, u16 y, u16 radius)
{
    s16 sx = x;
    s16 sy = y;
    s16 r = radius;
    s32 s, c;

    s = func_08075AAC(D_03005716 * 4) * r;
    c = func_08075AF8(D_03005716 * 4) * r;
    D_030057C4[0] = 4;
    D_030057C4[1] = sx + (c + s) / 256;
    D_030057C4[2] = sy + (s - c) / 256;
    D_030057C4[3] = sx + (c - s) / 256;
    D_030057C4[4] = sy + (c + s) / 256;
    D_030057C4[5] = sx - (c + s) / 256;
    D_030057C4[6] = sy - (s - c) / 256;
    D_030057C4[7] = sx - (c - s) / 256;
    D_030057C4[8] = sy - (c + s) / 256;
    D_030057C4[9] = 0;
}
