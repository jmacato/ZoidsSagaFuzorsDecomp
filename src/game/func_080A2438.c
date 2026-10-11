#include "types.h"

struct State
{
    u8 pad_0[0x8CC];
    u8 field_8CC;
    u8 field_8CD;
};

struct Display
{
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_C;
};

extern struct State D_02036E7C;
extern u16 D_0300004C;
extern u16 D_03000050;
extern u16 D_0300004E;
extern struct Display D_03000060;
extern u16 D_03000056;
extern u16 D_03000058;

void func_080A2438(void)
{
    D_02036E7C.field_8CC = 1;
    D_02036E7C.field_8CD = 0;
    D_0300004C |= 0x200;
    D_03000050 = (D_0300004E & ~3) | 3;
    D_03000060.field_8 = D_03000060.field_0;
    D_03000060.field_C = D_03000060.field_4;
    D_03000056 = 0x442;
    D_03000058 = 0x1010;
}
