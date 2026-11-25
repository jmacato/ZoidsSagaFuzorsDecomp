#include "types.h"

struct Cam
{
    s32 x;
    s32 y;
};

extern struct Cam D_03000060;
extern s32 D_0203772C;
void func_080A12B0(s32, s32);
void func_080C8FCC(s32);

void func_08087BF8(void)
{
    s32 v = 0;
    while (D_03000060.y > -0x8000)
    {
        func_080A12B0(0, 0);
        D_0203772C -= 0x20;
        v -= 0x10;
        D_03000060.y += v;
        func_080C8FCC(1);
    }
}
