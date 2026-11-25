#include "types.h"


extern u8 D_03002611;
extern u8 D_03002610;
extern u8 *D_0300260C;

void func_080C8B7C(const void *, void *, u32);

void func_08076DB4(u8 swap)
{
    if (D_03002611 == 0)
    {
        vu16 *dma = (vu16 *)0x040000B0;
        dma[5] &= 0xC5FF;
        dma[5] &= 0x7FFF;
        dma[5];
    }
    if (swap)
        D_03002610 ^= 1;
    if (D_03002611 == 0)
    {
        vu32 *dma = (vu32 *)0x040000B0;
        dma[0] = (u32)(D_0300260C + D_03002610 * 0xA00 + 0x10);
        dma[1] = 0x04000020;
        dma[2] = 0xA6600004;
        dma[2];
    }
    func_080C8B7C(D_0300260C + D_03002610 * 0xA00, (void *)0x04000020, 0x04000004);
}
