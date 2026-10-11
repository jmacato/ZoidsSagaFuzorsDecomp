#include "types.h"

void func_08077E6C(void *);

extern void *D_02037CF4[];

void func_080B3C20(void)
{
    u8 i;

    for (i = 0; i < 6; i++)
    {
        if (D_02037CF4[i] != 0)
        {
            func_08077E6C(D_02037CF4[i]);
            D_02037CF4[i] = 0;
        }
    }
}
