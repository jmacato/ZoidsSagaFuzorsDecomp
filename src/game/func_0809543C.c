#include "types.h"

extern void *D_02036960[];
void func_08077E6C(void *);

void func_0809543C(void)
{
    u8 i;

    for (i = 0; i < 6; i++)
        func_08077E6C(D_02036960[i]);
}
