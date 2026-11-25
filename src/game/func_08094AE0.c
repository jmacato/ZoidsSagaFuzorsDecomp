#include "types.h"

extern void *D_02036944[];
void func_080771F4(void *);

void func_08094AE0(void)
{
    u8 i;

    for (i = 0; i < 6; i++)
    {
        if (D_02036944[i] != 0)
            func_080771F4(D_02036944[i]);
    }
}
