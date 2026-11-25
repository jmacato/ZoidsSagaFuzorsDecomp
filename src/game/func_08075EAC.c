#include "types.h"

extern u16 D_03002350;
void func_080C75D4(u16);

void func_08075EAC(void)
{
    if (D_03002350 != 0)
        func_080C75D4(D_03002350);
}
