#include "types.h"

extern void *D_020368B0[];
void func_080771F4(void *);

void func_08094920(void)
{
    u8 i;

    for (i = 0; i < 7; i++)
        func_080771F4(D_020368B0[i]);
}
