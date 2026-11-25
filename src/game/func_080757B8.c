#include "types.h"

struct Unk03000014
{
    u8 pad0[0xC];
    u32 field_C;
};

extern u16 D_03000B18;
extern u32 D_03000B14;
extern struct Unk03000014 D_03000014;
extern u8 D_03000AC4[];
extern u8 D_03000AD4[];

void func_08076018(void);
void func_08076108(void);

void func_080757B8(void)
{
    vu32 zero;
    vu32 *dma;

    if (D_03000B18 & 1)
    {
        D_03000014.field_C = 0x03002399;
        D_03000B14 = 0;
        zero = 0;
        dma = (vu32 *)0x040000D4;
        dma[0] = (u32)&zero;
        dma[1] = (u32)D_03000AC4;
        dma[2] = 0x85000004;
        dma[2];
        zero = 0;
        dma[0] = (u32)&zero;
        dma[1] = (u32)D_03000AD4;
        dma[2] = 0x85000010;
        dma[2];
        func_08076018();
        D_03000B18 = (D_03000B18 & ~1) | 2;
    }
    else if (D_03000B18 & 4)
    {
        func_08076108();
        D_03000B14 = D_03000B18 = 0;
    }
}
