#include "m2c.h"

extern struct { u8 f_0; u8 f_1; } D_02030AE8;

M2C_UNK func_080C8FCC(s32);

void func_080C5B44(void)
{
    if (D_02030AE8.f_0 != 0)
    {
        D_02030AE8.f_1 = 1U;
        do
        {
            func_080C8FCC(1);
        } while (D_02030AE8.f_1 != 0);
    }
}
