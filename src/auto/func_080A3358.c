#include "m2c.h"

s32 func_080A3338();
M2C_UNK func_080C8FCC(s32);

void func_080A3358(void)
{
    while ((func_080A3338() << 0x18) == 0)
    {
        func_080C8FCC(1);
    }
}
