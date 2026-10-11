#include "types.h"

extern u8 D_02036867[];
extern u8 D_020288AC[];

void func_0807F810(void)
{
    u8 i;

    for (i = 0; i < 10; i++)
        D_02036867[i] = D_020288AC[i];
}
