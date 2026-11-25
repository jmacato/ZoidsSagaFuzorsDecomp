#include "types.h"

struct State
{
    u8 pad_0[0x98];
    u8 mirror;
    u8 pad_99[0x82B];
    u8 field_8C4;
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
extern struct Display D_03000060;
extern u16 D_03000056;
extern u16 D_03000058;
extern const u8 D_080F44B0[];
extern const u8 D_080F45E0[];
extern const u8 D_080F4608[];
extern u8 D_02001480[];

void func_080C8B84(const void *src, void *dst);
void func_08080168(const void *src, u8 a, u8 b, void *buf);

void func_080A1BE0(void)
{
    if (D_02036E7C.field_8C4 == 0)
        return;
    if (D_02036E7C.field_8C4 == 1)
    {
        D_0300004C |= 0x200;
        D_03000050 = 0x170B;
        D_03000060.field_C = 0;
        D_03000060.field_8 = 0;
        func_080C8B84(D_080F44B0, (void *)0x0600A980);
        func_080C8B84(D_080F45E0, (void *)0x05000100);
        func_08080168(D_080F4608, 0x17, D_02036E7C.mirror, D_02001480);
        D_03000056 = 0x442;
        D_03000058 = 0x1000;
        D_02036E7C.field_8C4++;
        return;
    }
    if (D_02036E7C.field_8C4 <= 0x20)
    {
        if (D_02036E7C.field_8C4 != 0x20)
            D_03000058 = (((0x20 - D_02036E7C.field_8C4) / 2) << 8) | (D_02036E7C.field_8C4 / 2);
        else
        {
            D_03000056 = 0x740;
            D_03000058 = 0x810;
            D_0300004C &= ~0x400;
        }
        D_02036E7C.field_8C4++;
    }
    if (D_02036E7C.mirror == 0)
        D_03000060.field_8 -= 0x1000;
    else
        D_03000060.field_8 += 0x1000;
}
