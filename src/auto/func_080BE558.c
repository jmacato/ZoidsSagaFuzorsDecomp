#include "m2c.h"

s32 func_0809A99C(u8, u8);
M2C_UNK func_080BE46C(u8, u8);

void func_080BE558(void)
{
    u8 var_r4;
    u8 var_r5;

    var_r5 = 0;
    do
    {
        var_r4 = 0;
loop_2:
        if (func_0809A99C(var_r5, var_r4) != 0)
        {
            func_080BE46C(var_r5, var_r4);
        }
        var_r4 += 1;
        if ((u32) var_r4 <= 5U)
        {
            goto loop_2;
        }
        var_r5 += 1;
    } while ((u32) var_r5 <= 1U);
}
