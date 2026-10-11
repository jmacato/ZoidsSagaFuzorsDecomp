#include "types.h"

extern u16 D_03000056;
extern u16 D_03000058;
extern u16 D_0300005A;
extern u32 *D_0200C4E8;
void func_080C8FCC(u32);

void func_08096548(void)
{
    u8 i = 0;

    D_03000056 = 0x790;
    D_03000058 = 0x10;
    for (;;)
    {
        if (i < 16)
            D_0300005A = i;
        else
            D_0300005A = 16 - (i & 15);
        i = (i + 1) % 32;
        *D_0200C4E8 |= 0x400;
        func_080C8FCC(1);
    }
}
