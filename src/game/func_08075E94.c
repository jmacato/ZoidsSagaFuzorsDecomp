#include "types.h"

extern u16 D_03002350;
void func_080C7628(u16);

void func_08075E94(void)
{
    if (D_03002350 != 0)
        func_080C7628(D_03002350);
}
