#include "types.h"

extern u8 D_02020A08[25];
extern u32 D_02020A24[4];

void func_08087D90(void)
{
    u8 i;
    for (i = 0; i < 25; i++)
        D_02020A08[i] |= 0xFF;
    for (i = 0; i < 4; i++)
        D_02020A24[i] = 0;
}
