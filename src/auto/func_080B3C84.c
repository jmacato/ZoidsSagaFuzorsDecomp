#include "m2c.h"

s32 func_080B3C4C();
M2C_UNK func_080C8FCC(s32);

void func_080B3C84(void)
{
    while ((func_080B3C4C() << 0x18) == 0)
    {
        func_080C8FCC(1);
    }
}
