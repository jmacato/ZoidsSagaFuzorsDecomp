#include "m2c.h"

s32 func_080796EC();
M2C_UNK func_080C8FCC(s32);

void func_0807970C(void)
{
    while ((func_080796EC() << 0x18) == 0)
    {
        func_080C8FCC(1);
    }
}
