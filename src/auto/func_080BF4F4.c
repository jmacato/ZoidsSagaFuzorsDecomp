#include "m2c.h"

M2C_UNK func_080BF4C4(u8, u8);

void func_080BF4F4(void)
{
    u8 var_r4;
    u8 var_r5;

    var_r5 = 0;
    do
    {
        var_r4 = 0;
loop_2:
        func_080BF4C4(var_r5, var_r4);
        var_r4 += 1;
        if ((u32) var_r4 <= 5U)
        {
            goto loop_2;
        }
        var_r5 += 1;
    } while ((u32) var_r5 <= 1U);
}
