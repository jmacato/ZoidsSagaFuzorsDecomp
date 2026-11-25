#include "types.h"

extern u16 D_03000B18;
extern u32 D_03000B14;
extern u8 D_0300068C;
extern u16 D_0300004C;
extern u8 D_0300028C[];

void func_0807636C(void);
void func_080C8B7C(const void *, void *, u32);

void func_08075158(void)
{
    if (D_03000B18 & 2)
    {
        if (D_03000B14 & 0x80)
            func_0807636C();
        if ((D_0300068C & 1) && (D_0300004C & 0x1000))
            func_080C8B7C(D_0300028C, (void *)0x07000000, 0x04000100);
    }
    else if ((D_0300068C & 1) && (D_0300004C & 0x1000))
    {
        vu32 *dma = (vu32 *)0x040000D4;
        dma[0] = (u32)D_0300028C;
        dma[1] = 0x07000000;
        dma[2] = 0x84000100;
        dma[2];
    }
}
