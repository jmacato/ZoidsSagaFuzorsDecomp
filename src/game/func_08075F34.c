#include "types.h"

extern u16 D_03002354;
void func_080C7628(u16);

void func_08075F34(void)
{
    if (D_03002354 != 0)
        func_080C7628(D_03002354);
}
