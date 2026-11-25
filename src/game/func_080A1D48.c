#include "types.h"

struct Display
{
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_C;
};

extern u16 D_0300004C;
extern u16 D_03000050;
extern u16 D_0300004E;
extern struct Display D_03000060;
extern u16 D_03000056;
extern u16 D_03000058;
struct State
{
    u8 pad_0[0x98];
    u8 mirror;
};

extern struct State D_02036E7C;

void func_080C8FCC(u32 frames);

void func_080A1D48(void)
{
    u8 i;
    D_0300004C |= 0x200;
    D_03000050 = D_0300004E;
    D_03000060.field_8 = D_03000060.field_0;
    D_03000060.field_C = D_03000060.field_4;
    D_03000056 = 0x641;
    for (i = 0; i < 32; i++)
    {
        D_03000058 = ((i / 2) << 8) | 0x10;
        func_080C8FCC(1);
    }
    for (i = 0; i < 32; i++)
    {
        D_03000058 = (((32 - i) / 2) << 8) | 0x10;
        if (D_02036E7C.mirror == 0)
            D_03000060.field_8 -= 0x800;
        else
            D_03000060.field_8 += 0x800;
        func_080C8FCC(1);
    }
    D_03000056 = 0x740;
    D_03000058 = 0x810;
    D_0300004C &= ~0x200;
}
