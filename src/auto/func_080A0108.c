#include "m2c.h"

s32 func_080A00FC();
M2C_UNK func_080C8FCC(s32);

void func_080A0108(void)
{
    while (func_080A00FC() == 0)
    {
        func_080C8FCC(1);
    }
}
