#include "types.h"

extern u8 D_0203689E[];
extern u8 D_02028818[];

void func_0807F838(void)
{
    u8 i;

    for (i = 0; i < 10; i++)
        D_0203689E[i] = D_02028818[i];
}
